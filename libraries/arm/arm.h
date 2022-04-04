
#ifndef arm_h
#define arm_h

#include "Arduino.h"
#include "Servo.h"
//#include "FeedBackServo.h"

class arm
{
public:	
	arm(int sv_PinX, int sv_cntrl_PinY, int sv_read_PinY);
	void currPosition();
	void move(int posX, int posY);

private:
	int readPinY;
	Servo servoX;
	
};


#endif
