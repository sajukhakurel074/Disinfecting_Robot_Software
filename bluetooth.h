#ifndef _bluetooth_H    
#define _bluetooth_H  
#include "steppermotor_init.h"

extern int myStepper1ShouldRun;
int rxpin; 
int txpin;
char value;
float vel=40;
float v = 0;
float w = 0;
float vel_max = 255;


void read_bluetooth()
{
  if(Serial.available())
  {   
    value = Serial.read();
    Serial.print(value);

    if(value == 'W' )
    {
      v = vel;
      w = 0; 
    }
    else if(value == 'S' )
    {
      v = -vel;
      w = 0;
    }
    else if(value == 'D' )
    {
      v = 0;
      w = -vel;
    }
    else if(value == 'A' )
    {
      v = 0;
      w = -vel;
    }
    else if(value == 'T' )
    {
      v = 0;
      w = 0;
    }
    else if ( value == 'I' )                    //ARM UP
    {
      myStepper1ShouldRun = 1;
    } 
    else if ( value == 'K' )                    //ARM DOWN
    {
      myStepper1ShouldRun = 0;
    }
    else if(value == 'J')                       //ARM LEFT
     {
          Serial.print(value);

       digitalWrite(dirPin, HIGH);
      for (int i = 0; i < stepsPerRevolution; i++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(1000);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(1000);
      }
      
     }
      else if(value == 'L')                    //ARM RIGHT
     {
          Serial.print(value);

      digitalWrite(dirPin, LOW);
      for (int i = 0; i < stepsPerRevolution; i++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(1000);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(1000);
      }
     }
  }
 else
  {
    v = 0;
    w = 0;
  }
  
}
#endif // _bluetooth_H   
