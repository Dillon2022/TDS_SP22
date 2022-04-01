#include <motorC.h> 

String msg; 
volatile int encL = 0; 
volatile int encR = 0; 

void encoderCount(motorC* controller, bool motor)
{
   
}

motorC leftControl(); 
motorC rightControl(); 


void setup() 
{
  Serial.begin(9600); 

  //Left Controller 
  attachInterrupt(digitalPinToInterrupt(), encoderCount
  attachInterrupt(digitalPinToInterrupt(), 0),

  //Right Controller 
  attachInterrupt(digitalPinToInterrupt(rightControl, 1), 
  attachInterrupt(digitalPinToInterrupt(rightControl, 0), 

  
}

void loop() 
{
  

}

void readSerialPort(){
  msg = ""; 
  if (Serial.available())
  {
    delay(10); 
    while (Serial.available() > 0)
    {
      msg += (char)Serial.read(); 
    }
    Serial.flush(); 
  }

  
}
