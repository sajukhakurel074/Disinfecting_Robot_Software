#ifndef _steppermotor_init_H    
#define _steppermotor_init_H  

#define RPM 5
#include <Stepper.h>

  int myStepper1ShouldRun = 0;

  const int stepPin = 53;
  const int dirPin = 51;
  const int stepPin1 = 52;
  const int dirPin1 = 50;
  

  const int stepsPerRevolution = 50;
  const int stepsPerRevolution1 = 33;

void steppermotor_init()
{
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  
}


#endif // _steppermotor_init_H   
