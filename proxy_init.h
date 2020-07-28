#ifndef _proxyinit_H    
#define _proxyinit_H 

#include "stdio.h"

int proxy_up;
int proxy_down;

struct proxy
{
  int SIG;
}proxy[8];

enum
{
  PROXY_LEFT = 40, PROXY_RIGHT, PROXY_UP, PROXY_DOWN
};

void proxy_init()
{ 
  proxy[4].SIG = 44;   //base_motor_front
  proxy[5].SIG = 45;   //base_motor_front
  
  proxy[6].SIG = 46;   //base_motor_back
  proxy[7].SIG = 47;   //base_motor_back
  
  pinMode(PROXY_LEFT, INPUT);
  pinMode(PROXY_RIGHT, INPUT);
  pinMode(PROXY_UP, INPUT);
  pinMode(PROXY_DOWN, INPUT);
  pinMode(proxy[4].SIG, INPUT);
  pinMode(proxy[5].SIG, INPUT);
  pinMode(proxy[6].SIG, INPUT);
  pinMode(proxy[7].SIG, INPUT);
  
}


 
#endif // _proxyinit_H   

