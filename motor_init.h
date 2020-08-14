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
  motor[0].EN = 6;
  motor[0].IN1 = 24;
  motor[0].IN2 = 23;
  
  motor[1].EN = 7;
  motor[1].IN1 = 34;
  motor[1].IN2 = 33;                                                                                 ;
  
  motor[2].EN = 8;
  motor[2].IN1 = 28;
  motor[2].IN2 = 27;
  
  motor[3].EN = 10;
  motor[3].IN1 = 31;
  motor[3].IN2 = 30;

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
