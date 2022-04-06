//#include <FeedBackServo.h>
#include <Adafruit_MCP9808.h>
#include <motorC.h> 
#include <Arduino.h>
#include <Servo.h>
#include <arm.h>
#include <Vector.h>
#include <SparkFun_MMA8452Q.h>

//Sensors (IMU & Temp)
Adafruit_MCP9808 temp; 
MMA8452Q IMU; 


//Motor Encoders and Controllers 
volatile int encL = 0; 
volatile int encR = 0; 
motorC leftControl(2, 13, 3, 4); 
motorC rightControl(5, 37, 6, 7); 


//servoX - about the x-axis (0, 180)
//servoY - about the y-axis (0,360)  
arm camera(8, 9, A0); 

void setup() 
{
  Serial.begin(9600); 

  //Check Sensors
  //if(IMU.begin()) Serial.println("IMU successfully connected.");
  //if(temp.begin()) Serial.println("Temperature Sensor successfully connected.");
  
  //Interrupt Setup for Encoder readings 
  
  //Left Controller 
  attachInterrupt(digitalPinToInterrupt(leftControl._f_enA), encCountL, RISING);
  
  //Right Controller 
  attachInterrupt(digitalPinToInterrupt(rightControl._f_enA), encCountR, RISING); 
  
  
  
}

void loop() 
{
  char cmd[20];

  //Serial.println("Enter Command - motor, temp, cam"); 
  analogWrite(13, 0);
  //delay(50); 
  //analogWrite(13, 40);
  //delay(100);
  //analogWrite(13, 0); 

  
  if(Serial.available() > 1)
  {
    int readChars; 
    readChars = Serial.readBytesUntil('\n', cmd, sizeof(cmd)-1);
    cmd[readChars] = '\0';
    //Serial.flush(); 

    if(strcmp(cmd, "motor") == 0)
    {
      Serial.print("Motor");
      leftControl.dutyCycle(20); 
      motorUpdate(); 
    }
    else if (strcmp(cmd, "temp") == 0)
    {
       readTemp(); 
    }
    else if (strcmp(cmd, "cam") == 0)
    {
       //camera.move(); 
    }
  }
  else
  {
   // Serial.println("Incorrect Command, reenter");
  }
   
  
}


/*
 * 
 *  Functions 
 * 
 */

//Data Read 
void readData(int* dataX, int* dataY)
{
    if(Serial.available() > 1)
      {
        *dataX = Serial.parseInt(SKIP_ALL);
        *dataY = Serial.parseInt(SKIP_ALL);
        
        Serial.print("1: ");
        Serial.println(*dataX);
        Serial.print("2: ");
        Serial.println(*dataY);
        Serial.flush();
      }
}



// duty must be 0-100
void vel(int dutyL, int dutyR)
{
  leftControl.dutyCycle(dutyL % 100);
  rightControl.dutyCycle(dutyR % 100);
}

void motorUpdate()
{
  int dataX = 0;
  int dataY = 0;  
  while(true) 
  {
      readData(&dataX, &dataY); 

      if(dataX == -1 && dataY == -1) 
      {
        vel(0, 0); 
        break;
      }

      vel(dataX, dataY); 
      //imu(); 
  }
  Serial.println("Break");
}
  

void encCountL()
{
   if (digitalRead(4) == 0)
   {
       //Serial.println("Fwd");
   }
   else
   {
        //Serial.println("Bwd");
   }
   //encL += 1; 
   
}

void encCountR()
{
   if (digitalRead(4) == 0)
   {
       //Serial.println("Fwd");
   }
   else
   {
        //Serial.println("Bwd");
   }
   //encR += 1; 
}


void readTemp()
{
  temp.wake(); 
  delay(20); 
  temp.setResolution(3); 
  Serial.print("C: "); 
  Serial.print(temp.readTempC(), 3);  
  temp.shutdown_wake(1);
}

void imu()
{
  if(IMU.available())
  {
    Serial.print(IMU.getCalculatedX(), 3); Serial.print("\t");
    Serial.print(IMU.getCalculatedY(), 3); Serial.print("\t");
    Serial.print(IMU.getCalculatedZ(), 3); Serial.println(); 
  }
}


  
