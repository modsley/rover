#pragma once
const byte maxDataLength = 20;
char receivedChars[21];
boolean newData = false;

void BTConnect(){
    BTserial.begin(9600);
    if (DEBUG)  {Serial.println("AltSoftSerial started at 9600 ***");}
    newData = false;
}

void sendInitCommands()
{
	BTserial.print("<T,Rover Control>");    // Control panel title
	BTserial.print("<I,SS,1,MAINS>");          // Mains
	BTserial.print("<I,SS,2,STOP>");          // Stop motors
	BTserial.print("<I,BT,1,FWD,FWD>");
	BTserial.print("<I,BT,2,BWD,BWD>");
//	BTserial.print("<I,BT,3,RIGHT,RIGHT>");
//	BTserial.print("<I,BT,4,LEFT,LEFT>");
	BTserial.print("<I,SL,3,speed,50,255,255250230>");
	BTserial.print("<R,5>");                   // Set the app update speed to 50ms
	BTserial.print("<EOI>");                   // End Of Initialization commands
	delay(100);                                // Small delay to give the app time to set up.
	if (DEBUG) { Serial.println("Init commands sent"); }
	BTserial.print("<D,SL,1,50>");
}


//Process Connect, Disconnect, Reset commands
void processConnectionCommand()
{
	if (DEBUG)
	{
		Serial.print("receivedChars = ");
		Serial.println(receivedChars);
	}

	if (strcmp ("CONNECT",receivedChars) == 0)
	{
		sendInitCommands();
	} else if (strcmp ("RESET",receivedChars) == 0)
	{
		sendInitCommands();
	} else if (strcmp ("SS10",receivedChars) == 0)
	{
		mainsActive = false;
		setMove(0,0,turnSharpness,speed); //stop motors if main program stops
	} else if (strcmp ("SS11",receivedChars) == 0)
	{
		mainsActive = true;
	} else if (strcmp ("SS20",receivedChars) == 0)
	{
		setMove(0,0,turnSharpness,speed); //stop motors
	} else if (strcmp ("BT11",receivedChars) == 0) // Forward
	{
		setMove(1,0,turnSharpness,speed);
		BTserial.print("<D,SS,2,1>");
	} else if (strcmp ("BT21",receivedChars) == 0) // Backward
	{
		setMove(2,0,turnSharpness,speed);
		BTserial.print("<D,SS,2,1>");
	} else if (receivedChars[0]== 'S' && receivedChars[1]== 'L')
	{
		int val =   (receivedChars[3]-48) *1000;
		val = val + (receivedChars[4]-48) * 100;
		val = val + (receivedChars[5]-48) *  10;
		val = val + (receivedChars[6]-48);
		setMove(moveMode,turnMode,turnSharpness,val);
	} else if (strcmp ("SW20",receivedChars) == 0)
	{
	} else if (strcmp ("SW21",receivedChars) == 0)
	{
	}
	receivedChars[0] = '\0';
	newData = false;
}

/*void processMainCommand(){
	if (DEBUG)
	{
		Serial.print("receivedCharsMain = ");
		Serial.println(receivedCharsMain);
	}
	if (strcmp ("SW10",receivedCharsMain) == 0)
	{
		if (DEBUG) { Serial.println("SW10 message received"); }
	} else if (strcmp ("SW11",receivedCharsMain) == 0)
	{
		if (DEBUG) { Serial.println("SW11 message received"); }
	} else if (strcmp ("SW20",receivedCharsMain) == 0)
	{
		if (DEBUG) { Serial.println("SW20 message received"); }
	} else if (strcmp ("SW21",receivedCharsMain) == 0)
	{
		if (DEBUG) { Serial.println("SW21 message received"); }
	}
	receivedCharsMain[0] = '\0';
	newData = false;
}*/

void recvWithStartEndMarkers()
{
	static boolean recvInProgress = false;
	static byte ndx = 0;
	char startMarker = '<';
	char endMarker = '>';
	char rc;
	if (BTserial.available() > 0)
	{
		rc = BTserial.read();
		if (recvInProgress == true)
		{
			if (rc != endMarker)
			{
				receivedChars[ndx] = rc;
				ndx++;
				if (ndx > maxDataLength) { ndx = maxDataLength; }
			}
			else
			{
				receivedChars[ndx] = '\0'; // terminate the string
				recvInProgress = false;
				ndx = 0;
				newData = true;
			}
		}
		else if (rc == startMarker) { recvInProgress = true; }
	}
}


//Process BT Connection state commands
void BTConnection(){
	recvWithStartEndMarkers();
	if (newData)  {processConnectionCommand();}
}

