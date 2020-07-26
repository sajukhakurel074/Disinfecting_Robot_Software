#ifndef _proxyinit_H    
#define _proxyinit_H 

#include "stdio.h"

struct proxy
{
  int SIG;
}proxy[8];

void proxy_init()
{
  proxy[0].SIG = 40;   //stepper_motor_yaxis
  proxy[1].SIG = 41;   //stepper_motor_-yaxis
  proxy[2].SIG = 42;   //stepper_motor_xaxis
  proxy[3].SIG = 43;   //stepper_motor_-xaxis
  proxy[4].SIG = 44;   //base_motor_front
  proxy[5].SIG = 45;   //base_motor_front
  proxy[6].SIG = 46;   //base_motor_back
  proxy[7].SIG = 47;   //base_motor_back
  
  pinMode(proxy[0].SIG, INPUT);
  pinMode(proxy[1].SIG, INPUT);
  pinMode(proxy[2].SIG, INPUT);
  pinMode(proxy[3].SIG, INPUT);
  pinMode(proxy[4].SIG, INPUT);
  pinMode(proxy[5].SIG, INPUT);
  pinMode(proxy[6].SIG, INPUT);
  pinMode(proxy[7].SIG, INPUT);
}


 
#endif // _proxyinit_H   

