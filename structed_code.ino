#include "common.h"
#include "motor_init.h"
#include "bluetooth.h"
#include "steppermotor_init.h"
#include "proxy_init.h"
int mots[4] = {0, 0, 0, 0};
int mot[4] = {0, 0, 0, 0};
#define ROBOT_STATE_ON 1
#define ROBOT_STATE_OFF 0
unsigned char robot_state = ROBOT_STATE_OFF;
#define BLUETOOTH_STATE_PIN 2

void turn_off_robot(void)
{
#if PRINT_DEBUG_INFO
  Serial.println("Turning off robot..");
#endif
  stop_arm_stepper();
  v = 0;
  w = 0;
  stop_servo();
  digitalWrite(pump, LOW);
  robot_state = ROBOT_STATE_OFF;
}

void setup()
{
  Serial.begin(9600);
  pinMode(pump, OUTPUT);
  pinMode(BLUETOOTH_STATE_PIN, INPUT);
  motor_init();
  proxy_init();
  steppermotor_init();
  servo_init();
  digitalWrite(dirx, HIGH);
  enable_xaxis_stepper_setup();
#if 1
  while (digitalRead(PROXY_LEFT))
    ; //stepper_motor_xaxis
  TCCR3A = 0;
  TCCR3B = 0;
#endif
#if PRINT_DEBUG_INFO
  Serial.println("ALL INITIALIZED");
#endif
  digitalWrite(en_x, HIGH);
}

void loop()
{
  if (!digitalRead(BLUETOOTH_STATE_PIN))
  {
    if (robot_state != ROBOT_STATE_OFF)
    {
      turn_off_robot();
    }
  }
  else
  {
    robot_state = ROBOT_STATE_ON;
  }

  read_bluetooth();
  if (digitalRead(PROXY_FRONT))
  {
    if (motor_dir == MOTOR_FORWARD || motor_dir == MOTOR_RIGHT || motor_dir == MOTOR_LEFT)
    {
      v = 0;
      w = 0;
      mots[0] = 0;
      mots[1] = 0;
      mots[2] = 0;
      mots[3] = 0;
      for (int i = dutycycle; i >= 0; i--)
      {
        for (int i = 0; i < 4; i++)
        {
          analogWrite(motor[i].EN, dutycycle);
        }
        i -= 2;
      }
    }
  }

  if (digitalRead(PROXY_BACK))
  {
    if (motor_dir == MOTOR_BACKWARD)
    {
      v = 0;
      w = 0;
      mots[0] = 0;
      mots[1] = 0;
      mots[2] = 0;
      mots[3] = 0;
      for (int i = dutycycle; i >= 0; i--)
      {
        for (int i = 0; i < 4; i++)
        {
          analogWrite(motor[i].EN, dutycycle);
        }
        i -= 2;
      }
    }
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
    for (int j = 0; j < 2; j++)
    {
      mot[i] += velocity[j] * coupling_matrix[i][j];
    }
  }
}

void set_velocity()
{
  for (int i = 0; i < 4; i++)
  {
    if (mot[i] > mots[i])
    {
      mots[i] = mots[i] + 10;
    }
    else if (mot[i] < mots[i])
    {
      mots[i] = mots[i] - 10;
    }
    dutycycle = fabs((mots[i] / vel_max) * 255);
    digitalWrite(motor[i].IN1, mots[i] > 0);
    digitalWrite(motor[i].IN2, mots[i] < 0);

    analogWrite(motor[i].EN, 255 - dutycycle);
#if PRINT_MOTOR_DATA
    Serial.print(dutycycle);
    Serial.print("\t");
#endif
  }
#if PRINT_MOTOR_DATA
  Serial.println();
#endif
  /*
  if (motor_dir == MOTOR_FORWARD || motor_dir == MOTOR_BACKWARD)
  {
    for (int i = 0; i < 4; i++)
    {
      if (mot[i] > mots[i])
      {
        mots[i] = mots[i] + 20;
      }
      else if (mot[i] < mots[i])
      {
        mots[i] = mots[i] - 20;
      }
      dutycycle = fabs((mots[i] / vel_max) * 255);

      digitalWrite(motor[i].IN1, mots[i] > 0);
      digitalWrite(motor[i].IN2, mots[i] < 0);
      analogWrite(motor[i].EN, 255 - dutycycle);
#if PRINT_MOTOR_DATA
      Serial.print(mots[i]);
      //Serial.print(dutycycle);
           Serial.print(" IN1 = ");
       Serial.print( mots[i] > 0 );
           Serial.print(" IN2 = ");
  Serial.print( mots[i] < 0 );
      Serial.print("\t");
#endif
    }
#if PRINT_MOTOR_DATA
    Serial.println("  ");
#endif
  }
  else if (motor_dir == MOTOR_LEFT)
  {
    for (int i = 0; i < 4; i++)
    {
      if (mot[i] > mots[i])
      {
        mots[i] = mots[i] + 20;
      }
      else if (mot[i] < mots[i])
      {
        mots[i] = mots[i] - 20;
      }

      digitalWrite(motor[i].IN1, mots[i] > 0);
      digitalWrite(motor[i].IN2, mots[i] < 0);

      if (i % 2 == 0)
      {
        dutycycle = fabs((mots[i] / (vel_max * 6)) * 255);
        analogWrite(motor[i].EN, 255 - dutycycle);
      }
      else
      {
        dutycycle = fabs(((float)mots[i] / 160) * 255);
        analogWrite(motor[i].EN, 255 - dutycycle);
      }
#if PRINT_MOTOR_DATA
      //Serial.print(dutycycle);
       Serial.print(" IN1 = ");
       Serial.print( motor[i].IN1 );
           Serial.print(" IN2 = ");
  Serial.print( motor[i].IN2 );
Serial.print("\t");
#endif
    }
#if PRINT_MOTOR_DATA
    Serial.println("  ");
#endif
  }

  else if (motor_dir == MOTOR_RIGHT)
  {
    for (int i = 0; i < 4; i++)
    {
      if (mot[i] > mots[i])
      {
        mots[i] = mots[i] + 20;
      }
      else if (mot[i] < mots[i])
      {
        mots[i] = mots[i] - 20;
      }

      digitalWrite(motor[i].IN1, mots[i] > 0);
      digitalWrite(motor[i].IN2, mots[i] < 0);

      if (i % 2 == 0)
      {
        dutycycle = fabs(((float)mots[i] / 160) * 255);
        analogWrite(motor[i].EN, 255 - dutycycle);
#if PRINT_MOTOR_DATA
        Serial.print(dutycycle);
        Serial.print("\t");
#endif
      }
      else
      {
        dutycycle = fabs((mots[i] / (vel_max * 6)) * 255);
        analogWrite(motor[i].EN, 255 - dutycycle);
#if PRINT_MOTOR_DATA
     Serial.print(" IN1 = ");
       Serial.print( motor[i].IN1 );
           Serial.print(" IN2 = ");
  Serial.print( motor[i].IN2 );
        Serial.print(dutycycle);
        Serial.print("\t");
#endif
      }
    }
#if PRINT_MOTOR_DATA
    Serial.println("  ");
#endif
  }
  */
}
