#include "motor_init.h"
#include "bluetooth.h"
#include "steppermotor_init.h"
#include "proxy_init.h"


int mots[4] = {0, 0, 0, 0};
int mot[4] = {0, 0, 0, 0};
int s = 0;

void setup()
{
  Serial.begin(9600);
  void motor_init(); 
  Serial.println("ALL INITIALIZED");
}

void loop()
{
  //set_flag();
  //movearm_stepper1();
  Serial.print("hello");
  read_bluetooth();
  calculate_velocity();
  set_velocity();
}

/*void set_flag()
{
  //proxy_init();
  front_flag = digitalRead(proxy.SIG[0]);
  
}*/

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
    

