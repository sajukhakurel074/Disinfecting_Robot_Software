#ifndef _Servo_H
#define _Servo_H
#include "common.h"
#define SERVO_PIN 45
enum
{
  SERVO_MOVING_UP = 1,
  SERVO_MOVING_DOWN = -1,
  PIN_CHECK = 46,
  SERVO_INITIAL = 60,
  SERVO_FINAL = 200
};

int servo_steps = SERVO_INITIAL;
int servo_state = SERVO_MOVING_UP;
int servo_increment = SERVO_MOVING_UP;
ISR(TIMER5_OVF_vect)
{
  servo_steps += servo_increment;
  OCR5B = servo_steps;

  if (servo_steps > SERVO_FINAL)
  {
    servo_increment = -1;
  }
  else if (servo_steps <= SERVO_INITIAL)
  {
    servo_increment = 1;
  }
}

inline void move_servo()
{
  TIMSK5 = _BV(TOIE5);
}

inline void stop_servo()
{
  TIMSK5 = 0;
}

void servo_init()
{
  DDRL |= (1 << PL4);
  TCCR5A = _BV(COM1B1);
  TCCR5B = _BV(CS51) | _BV(CS50) | _BV(WGM53);
  ICR5 = 2500;         // this determines Frequency
  OCR5B = servo_steps; // this determines duty cycle, Servo at 0 degrees
  /*
  // This is for moving the servo
  TCNT1 = 0;
  TCCR1A = 0; // Let OC3X pins be used for other purposes
  TCCR1B = _BV(CS11)|_BV(CS10)|_BV(WGM13);
  ICR1 = 1875; // 
  */
}

/*
void servo_init()
{
  pinMode( PIN_CHECK , OUTPUT );
  servo_init();   
  delay( 1000 );
  move_servo();
}

*/
#endif // _Servo_H
