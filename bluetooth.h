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

    if(value == 'F' )
    {
      v = vel;
      w = 0; 
    }
    else if(value == 'B' )
    {
      v = -vel;
      w = 0;
    }
    else if(value == 'R' )
    {
      v = 0;
      w = -vel;
    }
    else if(value == 'L' )
    {
      v = 0;
      w = -vel;
    }
    else if(value == 'S' )
    {
      v = 0;
      w = 0;
    }
    } else if ( value == 'T' )
    {
      myStepper1ShouldRun = 1;
    } 
    else if ( value == 'Y' )
    {
      myStepper1ShouldRun = 0;
    }
    else if(value == 'M')
     {
      for(int i = 0; i < max_RPM+1; i++)
      {
        myStepper.setSpeed(i);
        myStepper.step(1);
      }
      myStepper.step(30);
      for(int i = max_RPM; i > 0; i--)
      {
        myStepper.setSpeed(i);
        myStepper.step(1);
      }
     }

      else if(value == 'N')
     {
      for(int i = 0; i < max_RPM+1; i++)
      {
        myStepper.setSpeed(i);
        myStepper.step(-1);
      }
      myStepper.step(-30);
      for(int i = max_RPM; i > 0; i--)
      {
        myStepper.setSpeed(i);
        myStepper.step(-1);
     }
   }
 else
  {
    v = 0;
    w = 0;
  }
  
}
#endif // _bluetooth_H   
