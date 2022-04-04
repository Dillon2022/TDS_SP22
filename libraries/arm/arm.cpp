#include "Arduino.h"
#include "arm.h"
//#include "FeedBackServo.h"

arm::arm(int sv_PinX, int sv_cntrl_PinY, int sv_read_PinY)
{
	servoX.attach(sv_PinX);
	
	//FeedBackServo servoY(sv_read_PinY);
	//servoY.setServoControl(sv_cntrl_PinY);
}
void arm::currPosition()
{
	Serial.print("(");
	Serial.print(servoX.read());
	Serial.print(", ");
	Serial.print((analogRead(readPinY) / 500) * 360);
	Serial.println(")");
}
void arm::move(int posX, int posY)
{
	if (posX > 180)
	{
		posX = 180;
	}
	else if (posX < 0)
	{
		posX = 0;
	}

	if (posY > 270)
	{
		posY = 270;
	}
	else if (posY < 0)
	{
		posY = 0;
	}

	servoX.write(posX);
	//servoY.rotate(posY);
	
	
	delay(10);
}