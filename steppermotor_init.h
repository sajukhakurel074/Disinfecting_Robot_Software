#ifndef _steppermotor_init_H    
#define _steppermotor_init_H  

#define RPM 5
#include <Stepper.h>

  const int stepPin = 51;
  const int dirPin = 53;

  const int max_RPM = 10;
  
  const int stepPin1 = 52;
  const int dirPin1 = 50;
  
  const int stepsPerRevolution = 50;
  const int stepsPerRevolution1 = 33;

  char value1;

  Stepper myStepper(stepsPerRevolution, stepPin, dirPin);
  Stepper myStepper1(stepsPerRevolution1, stepPin1, dirPin1);

#endif // _steppermotor_init_H   
