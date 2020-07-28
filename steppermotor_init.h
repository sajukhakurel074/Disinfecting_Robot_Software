#ifndef _steppermotor_init_H    
#define _steppermotor_init_H  
#include "proxy_init.h"

  const int stepy = 11;
  const int diry = 31;

  const int stepx = 5;
  const int dirx = 30;
  
  int steps = 0;
  const int stepsPerRevolution = 17;

  
void steppermotor_init()
{ 
 pinMode(dirx, OUTPUT);
 pinMode(diry, OUTPUT);
}


void enable_yaxis_stepper()
{
  DDRB |= (1 << PB5);
  cli(); 
  TCNT1 = 0;

  TCCR1A = 0b01000001;
  TCCR1B = 0b00010101;

  //TIMSK1 |= (1 << OCIE1A);
  OCR1A = 260;

  sei();
}

void enable_xaxis_stepper()
{
  DDRE |= (1 << PE3);
  cli(); 
  TCNT3 = 0;

  TCCR3A = 0b01000001;
  TCCR3B = 0b00010101;

  TIMSK3 |= (1 << OCIE1A);
  OCR3A = 260;

  sei();
}

ISR(TIMER3_COMPA_vect)
{
  int proxy_right = digitalRead(PROXY_RIGHT);
  int proxy_left = digitalRead(PROXY_LEFT);
  if ( !proxy_right || !proxy_left || steps == stepsPerRevolution) 
   {
      TCCR3A = 0;
      TCCR3B = 0;
      steps = 0;
    }
  else
  {
    steps++;
  }
}

#endif // _steppermotor_````````111111111111111111111111111111init_H   
