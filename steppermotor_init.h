#ifndef _steppermotor_init_H    
#define _steppermotor_init_H  

#define RPM 5
#include <Stepper.h>

  int myStepper1Steps = 0;
  int myStepper1RPM = 1;
  int myStepper1Dir = 1;
  int myStepper1ShouldRun = 0;

  const int stepPin = 53;
  const int dirPin = 51;

  const int stepsPerRevolution = 50;
  const int stepsPerRevolution1 = 33;

  char value1;

void steppermotor_init()
{
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}


#endif // _steppermotor_init_H   
