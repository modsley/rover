#ifdef __IN_ECLIPSE__
//This is a automatic generated file
//Please do not modify this file
//If you touch this file your change will be overwritten during the next build
//This file has been generated on 2018-03-22 12:40:38

#include "Arduino.h"
#include "Arduino.h"
#include <AltSoftSerial.h>
#include <leOS2.h>
#define BMX055_DISABLE_BMM;
#include <iarduino_Position_BMX055.h>
extern AltSoftSerial BTserial;
extern boolean DEBUG;
extern boolean mainsActive;
extern const byte motorL1;
extern const byte motorL2;
extern const byte motorR1;
extern const byte motorR2;
extern const byte motorLE;
extern const byte motorRE;
extern const byte SWSRX;
extern const byte SWSTW;
extern leOS2 myOS;
extern iarduino_Position_BMX055 imu;
#include "Motors.h"
#include "BTControlPanel.h"
#include "imu.h";

void setup() ;
void loop() ;

#include "rover.ino"


#endif
