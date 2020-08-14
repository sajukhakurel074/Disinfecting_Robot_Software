#ifndef _steppermotor_init_H    
#define _steppermotor_init_H  
#include "proxy_init.h"

  const int stepy = 11;
  const int diry = 37;

  const int stepx = 5;
  const int dirx = 38;

  const int en_x = 35;
  const int en_y = 36;
  
  int steps = 0;
  const int stepsPerRevolution = 100;

  int side;
  int proxy_to_read;

  
void steppermotor_init()
{ 
 pinMode(dirx, OUTPUT);
 pinMode(diry, OUTPUT);
 digitalWrite(diry, HIGH);
 digitalWrite(dirx, HIGH);

}


/*/void enable_yaxis_stepper()
{
  digitalWrite(en_y, LOW);
  
  DDRB |= (1 << PB5);
  cli(); 
  TCNT1 = 0;

  TCCR1A = 0b01000001;
  TCCR1B = 0b00010101;

  //TIMSK1 |= (1 << OCIE1A);
  OCR1A = 100;

  sei();
}

void enable_xaxis_stepper_setup()
{
  digitalWrite(en_x, LOW);
  
  DDRE |= (1 << PE3);
  cli(); 
  TCNT3 = 0;

  TCCR3A = 0b01000001;
  TCCR3B = 0b00010101;

  OCR3A = 100;

  sei();
}

void enable_xaxis_stepper()
{
  digitalWrite(en_x, LOW);
  DDRE |= (1 << PE3);
  cli(); 
  TCNT3 = 0;

  TCCR3A = 0b01000001;
  TCCR3B = 0b00010101;

  TIMSK3 |= (1 << OCIE1A);    // for interrupt call
  OCR3A = 100;

  sei();
}

ISR(TIMER3_COMPA_vect)
{
  if ( !digitalRead(proxy_to_read)|| steps == stepsPerRevolution)  
   //if ( steps == stepsPerRevolution)
   {
        TCCR3A = 0;
        TCCR3B = 0;
        steps = 0;
        digitalWrite(en_x, HIGH);
      }
      else
       {
        steps++;
       }
}*/

#endif // _steppermotor_init_H   
