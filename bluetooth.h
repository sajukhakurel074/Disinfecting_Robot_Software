#ifndef _bluetooth_H    
#define _bluetooth_H  

//#include "steppermotor_init.h"
 
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
    else if(value == 'A')
    {
      myStepper.setSpeed(RPM);
      myStepper.step(stepsPerRevolution);
    }
    else if(value == 'D')
    {
      movestepper_motorright();
    }*/
  }
  else
  {
    v = 0;
    w = 0;
  }
  
}
#endif // _bluetooth_H   
