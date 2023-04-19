# Disinfecting_Robot_Software
Code in Arduino for disinfecting robot project 

This code contains seperate header and source files for the individual features of the Robot. 

Bluetooth
-------------------------------------
The HC-05 module is used for communicating with Mobile Application. All the features of the robot is controlled through the command code received through the bluetooth.

DC Motor
-------------------------------------
The base of the robot are 4 DC motor of 24V. They are simple DC motors which are controlled through L298n motor controller. The L298N is a dual H-Bridge motor driver which allows speed and direction control of two DC motors at the same time. 

Servo Motor
-------------------------------------
MG995 Metal Gear Servo Motor is used in the arm of robot for disinfectant spray. PWM controlled servo motor is programmed for 2D motion of the arm (Up-Down, Y-axis).

Stepper Motor
-------------------------------------
NEMA 17-size hybrid bipolar stepping motor has a 1.8° step angle (200 steps/revolution). It is controlled with the help of A4988 driver for 2D motion of the arm in horizontal direction (Left-Right x-axis). 

Proxymity Sensor
-------------------------------------
There are 2 types of proximity sensor in the robot based on there ranges and detection. Two 40cm proxymity are placed at the front and back of the robot for collision safety. Two inductive proximity sensors are placed respectively on either side of stepper motor for 180 rotation control of the arm.

Micro Controller
-------------------------------------
Arduino Mega is used as the main controller of the robot. All the switchings, processing the data from sensors and controlling the motor driver and so on is done through the Arduino Mega.

#Mobile Application
Raspberry pi cam was used for video streaming.
![120199789_743618656485503_3487129591991445372_n](https://user-images.githubusercontent.com/57697867/233013464-092fc5b7-4288-44f7-b040-07b2ef911854.png)

