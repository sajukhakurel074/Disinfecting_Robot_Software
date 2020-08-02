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
  PROXY_LEFT = 40, PROXY_RIGHT, PROXY_UP, PROXY_DOWN, PROXY_FRONT, PROXY_BACK
};

void proxy_init()
{ 
  
  pinMode(PROXY_LEFT, INPUT);
  pinMode(PROXY_RIGHT, INPUT);
  pinMode(PROXY_UP, INPUT);
  pinMode(PROXY_DOWN, INPUT);
  pinMode(PROXY_FRONT, INPUT);
  pinMode(PROXY_BACK, INPUT);
  /*pinMode(proxy[6].SIG, INPUT);
  pinMode(proxy[7].SIG, INPUT);*/
  
}


 
#endif // _proxyinit_H   

