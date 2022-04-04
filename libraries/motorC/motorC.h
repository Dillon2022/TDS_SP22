#ifndef motorC_h 
#define motorC_h

#include "Arduino.h"

class motorC
{
public:
    int _f_enA, _f_enB;


    // dir - pin to determine direction of both motors
    // sp - pin to determine speed of both motors 
    motorC(int dir, int sp, int f_enA, int f_enB);

    //Changes Duty Cycle of PWM 
    void dutyCycle(int duty);

    //State = !State 
    void invDir();

    //Sets dir pin to HIGH 
    void fwd();

    //Sets dir pin to LOW 
    void bwd();

    // Sets Speed to 0 
    void halt();

    //Displays Current Duty Cycle
    int currSpeed();

private:
    int _dir;
    bool currDir;
    int _sp;
    int speed; 

};

#endif