#ifndef _bluetooth_H    
#define _bluetooth_H  
#include "steppermotor_init.h"

extern int myStepper1ShouldRun;
char value;
float vel=40;
float v = 0;
float w = 0;
float vel_max = 255;
int motor_dir;
enum
{
  MOTOR_FORWARD=0 , MOTOR_BACKWARD, MOTOR_LEFT, MOTOR_RIGHT
};


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
      motor_dir = MOTOR_FORWARD;
    }
    else if(value == 'S' )
    {
      v = -vel;
      w = 0;
      motor_dir = MOTOR_BACKWARD;
    }
    else if(value == 'D' )
    {
      v = 0;
      w = -vel;
      motor_dir = MOTOR_LEFT;
    }
    else if(value == 'A' )
    {
      v = 0;
      w = -vel;
      motor_dir = MOTOR_RIGHT;
    }
    else if(value == 'T' )                     //Stop_robot
    {
      v = 0;
      w = 0;
    }
    else if ( value == 'I' )                    //ARM UP
    {
      enable_timer1();
    } 
    else if ( value == 'K' )                    //ARM STOP
    {
      TCCR1A = 0;
      TCCR1B = 0;
    }
    else if(value == 'J')                       //ARM LEFT
     {
       enable_timer2();
       digitalWrite(dirPin2, HIGH);
     }
      else if(value == 'L')                    //ARM RIGHT
     {
      enable_timer2();
      digitalWrite(dirPin2, LOW);
     }
  }
 else
  {
    v = 0;
    w = 0;
  }
  
}
#endif // _bluetooth_H   
