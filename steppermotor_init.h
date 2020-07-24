#ifndef _steppermotor_H    
#define _steppermotor_H  
#define RPM 5
#include <Stepper.h>

  const int stepPin = 51;
  const int dirPin = 53;
  
  const int stepPin1 = 52;
  const int dirPin1 = 50;
  
  const int stepsPerRevolution = 50;
  const int stepsPerRevolution1 = 33;

  char value1;

  Stepper myStepper(stepsPerRevolution, stepPin, dirPin);
  Stepper myStepper1(stepsPerRevolution1, stepPin1, dirPin1);



void movearm_stepper1()
{
  if(Serial.available())
  {   
    value1 = Serial.read();
     if(value1 == 'M')
     {
      
      myStepper1.setSpeed(RPM);
      myStepper1.step(2*stepsPerRevolution1);
      myStepper1.step(-2*stepsPerRevolution1);
     }
     else if(value1 == 'N')
     {
      myStepper1.step(0);
     }
   }
}

void movestepper_motorleft()
{
  
}

void movestepper_motorright()
{
  myStepper.setSpeed(RPM);
  myStepper.step(-stepsPerRevolution);
}

#endif // _steppermotor_H 
