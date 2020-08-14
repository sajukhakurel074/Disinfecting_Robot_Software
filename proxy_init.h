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
  PROXY_LEFT = 40, 
  PROXY_RIGHT = 41, 
  PROXY_UP = 42, 
  PROXY_DOWN = 43, 
  PROXY_FRONT = 44,
  PROXY_FRONT1 = 45,
  PROXY_BACK = 46, 
  PROXY_BACK1 = 47
};

void proxy_init()
{ 
  
  pinMode(PROXY_LEFT, INPUT);
  pinMode(PROXY_RIGHT, INPUT);
  pinMode(PROXY_UP, INPUT);
  pinMode(PROXY_DOWN, INPUT);
  pinMode(PROXY_FRONT, INPUT);
  pinMode(PROXY_FRONT1, INPUT);
  pinMode(PROXY_BACK, INPUT);
  pinMode(PROXY_FRONT1, INPUT);
  

}


 
#endif // _proxyinit_H   

