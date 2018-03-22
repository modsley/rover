#include "Arduino.h"
//#include <ThreadController.h>
//#include <Thread.h>
//#include <StaticThreadController.h>
#include <AltSoftSerial.h>
#include <leOS2.h>
// test git

//D0
//D1
//D2
//D3
//D4
//D5 - ENA left green
//D6 - ENB right black
//D7
//D8 - AltsoftSerial RX - BT TX orange
//D9 - AltsoftSerial TX - BT RX yellow
//D10
//D11
//D12
//D13
//A0 - 14 - right IN1 blue
//A1 - 15 - right IN2 violet
//A2 - 16 - left IN3 grey
//A3 - 17 - left IN4 white
//A4
//A5

AltSoftSerial BTserial;
boolean DEBUG = true;
boolean mainsActive = false;


// Pins configuration
const byte motorL1 = 18; // left engine pin 1
const byte motorL2 = 19; // left engine pin 2
const byte motorR1 = 16; // right engine pin 1
const byte motorR2 = 17; // right engine pin 2
const byte motorLE = 5; // left engine en
const byte motorRE = 6; // right engine en
const byte SWSRX = 8; // BT TXD
const byte SWSTW = 9; // BT RXD

leOS2 myOS;


#include "Motors.h"
#include "BTControlPanel.h"
//#include "Threads.h"


void setup()
{
  if (DEBUG)
  {
    // open serial communication for debugging
    Serial.begin(9600);
    Serial.print("Sketch:   ");   Serial.println(__FILE__);
    Serial.print("Uploaded: ");   Serial.println(__DATE__);
    Serial.println(" ");
  }
 myOS.begin();
 myOS.addTask(BTConnection, myOS.convertMs(100));
//  InitThreads();
  BTConnect();
  motorSetup();
}

void loop()
{
  //omlController.run();

	if (mainsActive) // Main program
	{
// START MAIN PROGRAM


// END MAIN PROGRAM
	}
}

