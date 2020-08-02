#ifndef _motorinit_H    
#define _motorinit_H  
  
#include "stdio.h"

struct motor
{
  int EN;
  int IN1;
  int IN2;
}motor[4];

void motor_init()
{
  motor[0].EN = 2;
  motor[0].IN1 = 23;
  motor[0].IN2 = 24;
  
  motor[1].EN = 3;
  motor[1].IN1 = 33;
  motor[1].IN2 = 34                                                                                 ;
  
  motor[2].EN = 4;
  motor[2].IN1 = 27;
  motor[2].IN2 = 28;
  
  motor[3].EN = 5;
  motor[3].IN1 = 30;
  motor[3].IN2 = 31;

  pinMode(motor[0].EN, OUTPUT);
  pinMode(motor[0].IN1, OUTPUT);
  pinMode(motor[0].IN2, OUTPUT);
  pinMode(motor[1].EN, OUTPUT);
  pinMode(motor[1].IN1, OUTPUT);
  pinMode(motor[1].IN2, OUTPUT);
  pinMode(motor[2].EN, OUTPUT);
  pinMode(motor[2].IN1, OUTPUT);
  pinMode(motor[2].IN2, OUTPUT);
  pinMode(motor[3].EN, OUTPUT);
  pinMode(motor[3].IN1, OUTPUT);
  pinMode(motor[3].IN2, OUTPUT);
}


#endif // _motorinit_H    
