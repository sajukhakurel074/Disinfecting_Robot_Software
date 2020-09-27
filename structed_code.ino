#include "motor_init.h"
#include "bluetooth.h"
#include "steppermotor_init.h"
#include "proxy_init.h"

int mots[4] = {0, 0, 0, 0};
int mot[4] = {0, 0, 0, 0};
#define BLUETOOTH_STATE_PIN 2
void setup()
{
  Serial.begin(9600);
  pinMode( pump, OUTPUT );
  pinMode( BLUETOOTH_STATE_PIN, INPUT );
  motor_init(); 
  proxy_init();
  steppermotor_init();
  servo_init();
  digitalWrite(dirx, HIGH);
  enable_xaxis_stepper_setup();
  #if 0
  while(digitalRead(PROXY_LEFT));      //stepper_motor_xaxis
     TCCR3A = 0;
     TCCR3B = 0;
   #endif 
 Serial.println("ALL INITIALIZED");
 digitalWrite(en_x, HIGH);
}
void loop()
{  
  if ( 0 ){
//     turn_off_robot();
  } else { 
#if 1
  read_bluetooth();
  if(digitalRead(PROXY_FRONT))
  {
    if(motor_dir == MOTOR_FORWARD)
    {
      v = 0;
      w = 0;
      for (int i = dutycycle; i >= 0; i--)
      {
        for( int i = 0; i < 4; i++)
        {
          analogWrite(motor[i].EN, dutycycle);
        }
         i--;
         i--;
      }
    }
  }
 
  if(digitalRead(PROXY_BACK))
  {
    if(motor_dir == MOTOR_BACKWARD)
    {
      v = 0;
      w = 0;
    for (int i = dutycycle; i >= 0; i--)
      {
        for( int i = 0; i < 4; i++)
        {
          analogWrite(motor[i].EN, dutycycle);
        }
         i--;
         i--;
      }
    }
  }
 
  calculate_velocity();
  set_velocity();
  #endif
  }
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
  if ( motor_dir == MOTOR_FORWARD || motor_dir == MOTOR_BACKWARD)
  {
      for(int i = 0; i < 4; i++)
      {
        if(mot[i]>mots[i])
        {
          mots[i] = mots[i] + 20 ;
        }
        else if(mot[i]<mots[i])
        {
          mots[i] = mots[i] - 20 ;
        }
        dutycycle = fabs((mots[i]/vel_max)*255 );
        Serial.print(dutycycle);
        Serial.print("\t");
        digitalWrite( motor[i].IN1, mots[i] > 0 );
        digitalWrite( motor[i].IN2, mots[i] < 0 );
        analogWrite( motor[i].EN, 255 - dutycycle);
      }   
      Serial.println("  ");
  } 
   else if (motor_dir == MOTOR_LEFT)
   {
    for(int i = 0; i < 4; i++)
      {
        if(mot[i]>mots[i])
        {
          mots[i] = mots[i] + 20 ;
        }
        else if(mot[i]<mots[i])
        {
          mots[i] = mots[i] - 20 ;
        }   
        
       digitalWrite( motor[i].IN1, mots[i] > 0 );
       digitalWrite( motor[i].IN2, mots[i] < 0 );
       
      if( i%2 == 0)  
      {
        dutycycle = fabs((mots[i]/(vel_max*6))*255 );
        analogWrite( motor[i].EN, 255 - dutycycle);
        Serial.print(dutycycle);
        Serial.print("\t");
      }
      else 
      {
        dutycycle = fabs(((float)mots[i]/160)*255 );
        analogWrite( motor[i].EN, 255 - dutycycle);
        Serial.print(dutycycle);
        Serial.print("\t");
      }   
   }
   Serial.println("  ");
   }
   
   
   else if (motor_dir == MOTOR_RIGHT)
   {
    for(int i = 0; i < 4; i++)
      {
        if(mot[i]>mots[i])
        {
          mots[i] = mots[i] + 20 ;
        }
        else if(mot[i]<mots[i])
        {
          mots[i] = mots[i] - 20 ;
        }   
        
       digitalWrite( motor[i].IN1, mots[i] > 0 );
       digitalWrite( motor[i].IN2, mots[i] < 0 );
       
      if( i%2 == 0)  
      {
        dutycycle = fabs(((float)mots[i]/160)*255 );
        analogWrite( motor[i].EN, 255 - dutycycle);
        Serial.print(dutycycle);
        Serial.print("\t");
      }
      else 
      {
        dutycycle = fabs((mots[i]/(vel_max*6))*255 );
        analogWrite( motor[i].EN, 255 - dutycycle);
        Serial.print(dutycycle);
        Serial.print("\t");
      }
   }
   Serial.println("  ");
   }
}

