#ifndef _proxyinit_H    
#define _proxyinit_H 

#include "stdio.h"

struct proxy
{
  int SIG;
}proxy[4];

void proxy_init()
{
  proxy[0].SIG = 40;
  proxy[1].SIG = 41;
  proxy[2].SIG = 42;
  proxy[3].SIG = 43;
  
  pinMode(proxy[0].SIG, INPUT);
  pinMode(proxy[1].SIG, INPUT);
  pinMode(proxy[2].SIG, INPUT);
  pinMode(proxy[3].SIG, INPUT);
}


 
#endif // _proxyinit_H   

