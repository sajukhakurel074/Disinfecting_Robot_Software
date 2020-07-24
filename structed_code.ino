#include "motor_init.h"
#include "bluetooth.h"
#include "steppermotor_init.h"
#include "proxy_init.h"



int mots[4] = {0, 0, 0, 0};
int mot[4] = {0, 0, 0, 0};
int s = 0;

int myStepper1Steps = 0;
int myStepper1RPM = 1;
int myStepper1Dir = 1;
int myStepper1ShouldRun = 0;
void setup()
{
  Serial.begin(9600);
  void motor_init(); 
  Serial.println("ALL INITIALIZED");
    
}

void loop()
{
    
  read_bluetooth();
 if ( myStepper1ShouldRun )
  {
       if ( myStepper1Steps < 5 )
        {
         myStepper1.setSpeed( myStepper1RPM );
         myStepper1.step(myStepper1Dir * 1);
         myStepper1RPM++;
         myStepper1Steps++;
        }
       else if ( myStepper1Steps > 5 && myStepper1Steps < 28 )
        {
        myStepper.step( myStepper1Dir * 1 );
        myStepper1Steps++;
        } 
       else if ( myStepper1Steps > 28 && myStepper1Steps < 33 )
       {
        myStepper1.setSpeed( myStepper1RPM );
        myStepper1.step( myStepper1Dir * 1 );
        myStepper1RPM--;
        myStepper1Steps++;
      } 
      else {
        myStepper1Dir *= -1;
        myStepper1Steps = 0;
        myStepper1RPM = 1;
      }
  
  } 
  else
  {
    myStepper1.setSpeed( 0 );
  }
  calculate_velocity();
  set_velocity();
}

void calculate_velocity()
{
  float velocity[2] = {v, w};
  int coupling_matrix[4][2] = {{1, 1},
                               {1, -1},
                               {1, 1},
                               {1, -1}};
  for (int i = 0; i < 4; i++)
  {
    mot[i] = 0;
    for(int j = 0; j < 2; j++)
    {
      mot[i] += velocity[j] * coupling_matrix[i][j];                             
    }
  }
}

void set_velocity()
{
    
      for(int i = 0; i < 4; i++)
      {
        if(mot[i]>mots[i])
        {
          mots[i]++;
        }
        else if(mot[i]<mots[i])
        {
          mots[i]--;
        }
        int dutycycle = (mots[i]/vel_max)*255;
        Serial.print("dc:");
        Serial.print(dutycycle);
        Serial.print("\t"); 
        digitalWrite( motor[i].IN1, mot[i] > 0 );
        digitalWrite( motor[i].IN2, mot[i] < 0 );
        analogWrite( motor[i].EN, dutycycle);
      }  
      Serial.println("   ");     
}
    

