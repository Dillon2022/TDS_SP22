#include "Arduino.h"
#include "motorC.h"

motorC::motorC(int dir, int sp,int f_enA,int f_enB,int b_enA, int b_enB)
{
  _dir = dir; 
  _sp = sp; 
  _f_enA = f_enA;
  _f_enB = f_enB; 
  _b_enA = b_enA;
  _b_enB = b_enB;
  currDir = 1; 

  //Speed / Direction Control 
  pinMode(_dir, OUTPUT); 
  pinMode(_sp, OUTPUT);

  //Back Encoder
  pinMode(_f_enA, INPUT); 
  pinMode(_f_enB, INPUT);

  //Back Encoder
  pinMode(_b_enA, INPUT);
  pinMode(_b_enB, INPUT);
    
  this::dutyCycle(0); 
}
//Changes Duty Cycle of PWM 
motorC::void dutyCycle(int duty)
{
  analogWrite(_sp, (duty/100) * 255); 
}

//State = !State 
motorC::void invDir()
{
  curDir = !curDir; 
  digitalWrite(_dir, curDir); 
}

//Sets dir pin to HIGH 
motorC::void fwd()
{
  this::halt();
  delay(1);    
  curDir = true; 
}

//Sets dir pin to LOW 
motorC::void bwd()
{
  this::halt();
  delay(1);    
  curDir = false;
}

motorC::void halt()
{
  analogWrite(_sp, 0); 
}

//True = Front motor; False = Rear motor
motorC::bool checkDir(bool motor)
{
  if(motor)
  {
    if(digitalRead(_f_encA)  
  }
    
}
