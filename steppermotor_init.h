#ifndef _steppermotor_init_H    
#define _steppermotor_init_H  


  const int stepPin2 = 5;
  const int dirPin2 = 4;
  
  const int stepPin1 = 11;
  const int dirPin1 = 3;

  
void steppermotor_init()
{ 
 pinMode(dirPin1, OUTPUT);
 pinMode(dirPin2, OUTPUT);
}


void enable_timer1()
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

void enable_timer2()
{
  DDRE |= (1 << PE3);
  cli(); 
  TCNT3 = 0;

  TCCR3A = 0b01000001;
  TCCR3B = 0b00010101;

  //TIMSK1 |= (1 << OCIE1A);
  OCR3A = 260;

  sei();
}

ISR(TIMER_COMPA_vect)
{
  
}

#endif // _steppermotor_init_H   
