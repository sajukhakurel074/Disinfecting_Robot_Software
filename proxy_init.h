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
  PROXY_LEFT = 41, 
  PROXY_RIGHT = 43, 
  PROXY_FRONT = 49,
  PROXY_BACK = 47
};

void proxy_init()
{ 
  
  pinMode(PROXY_LEFT, INPUT);
  pinMode(PROXY_RIGHT, INPUT);
  pinMode(PROXY_FRONT, INPUT);
  pinMode(PROXY_BACK, INPUT);
  
}


 
#endif // _proxyinit_H   

