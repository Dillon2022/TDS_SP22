#include "Arduino.h"
#include "motorC.h"

motorC::motorC(int dir, int sp, int f_enA, int f_enB)
{
    _dir = dir;
    _sp = sp;
    _f_enA = f_enA;
    _f_enB = f_enB;
    currDir = 1;
    speed = 0; 

    //Speed / Direction Control 
    pinMode(_dir, OUTPUT);
    pinMode(_sp, OUTPUT);

    //Encoder
    pinMode(_f_enA, INPUT);
    pinMode(_f_enB, INPUT);

   
    this->fwd();
}
//Changes Duty Cycle of PWM 
void motorC::dutyCycle(int duty)
{
    if (duty < 0)
    {
        this->halt();
        delay(50);
        this->invDir();
    }
    speed = (duty / 100) * 255; 
    analogWrite(_sp, speed);
}

//State = !State 
void motorC::invDir()
{
    currDir = !currDir;
    if(currDir)
    { 
        digitalWrite(_dir, HIGH);
    }
    else
    {
        digitalWrite(_dir, LOW);
    }
}

//Sets dir pin to HIGH 
void motorC::fwd()
{
    this->halt();
    delay(1);
    currDir = true;
    digitalWrite(_dir, HIGH);
}

//Sets dir pin to LOW 
void motorC::bwd()
{
    this->halt();
    delay(5);
    currDir = false;
    digitalWrite(_dir, LOW);
}

void motorC::halt()
{
    analogWrite(_sp, 0);
}

//True = Front motor; False = Rear motor
int motorC::currSpeed()
{
    return speed;
}