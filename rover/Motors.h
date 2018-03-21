#pragma once
byte rightMotorPin1 = 14;
byte rightMotorPin2 = 15;
byte leftMotorPin1 = 17;
byte leftMotorPin2 = 16;
byte leftMotorEn = 5;
byte rightMotorEn = 6;

/*
moveMode
0 - stop
1 - forward
2 - backward
*/
byte moveMode = 0;

/*turnMode
0 - no turn
1 - left
2 - right
*/
byte turnMode = 0;

/*turnSharpness
ignored when moveMode == 0
*/
byte turnSharpness = 128;

//overall movement speed 50 - 255
byte speed = 255;

void motorSetup(){
	pinMode(rightMotorPin1, OUTPUT);
	pinMode(rightMotorPin2, OUTPUT);
	pinMode(leftMotorPin1, OUTPUT);
	pinMode(leftMotorPin2, OUTPUT);
	pinMode(rightMotorEn, OUTPUT);
	pinMode(leftMotorEn, OUTPUT);
	digitalWrite(rightMotorPin1, LOW);
	digitalWrite(rightMotorPin2, LOW);
	digitalWrite(leftMotorPin1, LOW);
	digitalWrite(leftMotorPin2, LOW);
}

void stop(){
	digitalWrite(rightMotorPin1,LOW);
	digitalWrite(rightMotorPin2,LOW);
	digitalWrite(leftMotorPin1,LOW);
	digitalWrite(leftMotorPin2,LOW);
	analogWrite(leftMotorEn,0);
	analogWrite(rightMotorEn,0);
}

void moveForward(){
	digitalWrite(rightMotorPin1,LOW);
	digitalWrite(rightMotorPin2,HIGH);
	digitalWrite(leftMotorPin1,LOW);
	digitalWrite(leftMotorPin2,HIGH);
	analogWrite(leftMotorEn,speed);
	analogWrite(rightMotorEn,speed);
}

void moveBackward(){
	digitalWrite(rightMotorPin1,HIGH);
	digitalWrite(rightMotorPin2,LOW);
	digitalWrite(leftMotorPin1,HIGH);
	digitalWrite(leftMotorPin2,LOW);
	analogWrite(leftMotorEn,speed);
	analogWrite(rightMotorEn,speed);
}

void setMove(byte setMoveMode, byte setTurnMode, byte setTurnSharpness, byte setSpeed){
	moveMode = setMoveMode;
	turnMode = setTurnMode;
	turnSharpness = setTurnSharpness;
	speed = setSpeed;
	switch (setMoveMode)
	{
	case 0 :
		stop();
		break;
	case 1 :
		moveForward();
		break;
	case 2 :
		moveBackward();
		break;
	}
}


