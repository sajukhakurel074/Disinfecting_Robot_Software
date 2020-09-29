#ifndef _steppermotor_init_H
#define _steppermotor_init_H
#include "proxy_init.h"
#include "common.h"
#define STEPPER_SPEED 50
const int stepx = 5;
const int dirx = 38;

const int en_x = 36;

int steps = 0;
const int stepsPerRevolution = 215;

int side;
int proxy_to_read;

void steppermotor_init()
{
  pinMode(dirx, OUTPUT);
  digitalWrite(dirx, HIGH);
}

inline void stop_arm_stepper()
{
  TCCR3A = 0;
  TCCR3B = 0;
  steps = 0;
  digitalWrite(en_x, HIGH);
}

void enable_xaxis_stepper_setup()
{
  digitalWrite(en_x, LOW);

  DDRE |= (1 << PE3);
  cli();
  TCNT3 = 0;

  TCCR3A = 0b01000001;
  TCCR3B = 0b00010101;

  OCR3A = STEPPER_SPEED;

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

  TIMSK3 |= (1 << OCIE1A); // for interrupt call
  OCR3A = STEPPER_SPEED;

  sei();
}

ISR(TIMER3_COMPA_vect)
{
  if (!digitalRead(proxy_to_read))
  {
    stop_arm_stepper();
  }
}

#endif // _steppermotor_init_H
