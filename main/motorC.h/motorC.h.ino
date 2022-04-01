
#ifndef motorC_h 
#define motorC_h

#include "Arduino.h"

class motorC
{
  public:
    int _f_enA, _f_enB;
    int _b_enA, _b_enB;
    
    // dir - pin to determine direction of both motors
    // sp - pin to determine speed of both motors 
    motorC(int dir, int sp,int f_enA,int f_enB,int b_enA, int b_enB);

    //Changes Duty Cycle of PWM 
    void dutyCycle(int duty);

    //State = !State 
    void invDir();

    //Sets dir pin to HIGH 
    void fwd(); 

    //Sets dir pin to LOW 
    void bwd();

    void halt(); 
    
    //True = Foward; False = Backward
    bool checkDir(bool motor); 
     
  private:
    int _dir;
    bool currDir;
     
    int _sp; 
     
};

#endif
