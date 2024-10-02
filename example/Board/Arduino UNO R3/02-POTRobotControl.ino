/*
Author      : Teeraphat Kullanankanjana
Version     : 1.0
Date        : 02/10/2567
Description : Control 6 Servo with 6 Potentiometer
Copyright (C) 2024 Teeraphat Kullanankanjana. All rights reserved.
*/

// Include the Braccio and Servo library
#include <Braccio.h>
#include <Servo.h>

// Define POT PIN
#define BASE_POT A0
#define SHOULDER_POT A1
#define ELBOW_POT A2
#define WRIST_ROT_POT A3
#define WRIST_VER_POT A4
#define GRIPPER_POT A5

// Potentiometer Variable
int base_ana_val;
int shoulder_ana_val;
int elbow_ana_val;
int wrist_rot_ana_val;
int wrist_ver_ana_val;
int gripper_ana_val;

// Angle Variable
int base_angle;
int shoulder_angle;
int elbow_angle;
int wrist_rot_angle;
int wrist_ver_angle;
int gripper_angle;

// Define Servo Port
Servo base;       // M1
Servo shoulder;   // M2
Servo elbow;      // M3
Servo wrist_ver;  // M4
Servo wrist_rot;  // M5
Servo gripper;    // M6

void setup() {
  // Initialize the serial communication at 9600 baud rate
  Serial.begin(9600);
  Serial.println("\nRobot Begin...");
  // Initialization fucntions and setup the initial position for robot.
  Braccio.begin();
  Serial.println("\nRobot reset to safety position!");
}

void loop() {
  
  // Read the each Potentiometer as analog value
  base_ana_val = analogRead(BASE_POT);
  shoulder_ana_val = analogRead(SHOULDER_POT);
  elbow_ana_val = analogRead(ELBOW_POT);
  wrist_rot_ana_val = analogRead(WRIST_ROT_POT);
  wrist_ver_ana_val = analogRead(WRIST_VER_POT);
  gripper_ana_val = analogRead(GRIPPER_POT);

  // Convert the analog value into angle
  base_angle = map(base_ana_val, 0, 1023, 0, 180); // M1: base degrees. Allowed values from 0 to 180 degrees
  shoulder_angle = map(shoulder_ana_val, 0, 1023, 15, 165); // M2: shoulder degrees. Allowed values from 15 to 165 degrees
  elbow_angle = map(elbow_ana_val, 0, 1023, 0, 180); // M3: elbow degrees. Allowed values from 0 to 180 degrees
  wrist_rot_angle = map(wrist_rot_ana_val, 0, 1023, 0, 180); // M4: wrist vertical degrees. Allowed values from 0 to 180 degrees
  wrist_ver_angle = map(wrist_ver_ana_val, 0, 1023, 0, 180); // M5: wrist rotation degrees. Allowed values from 0 to 180 degrees
  gripper_angle = map(gripper_ana_val, 0, 1023, 10, 73); // M6: gripper degrees. Allowed values from 10 to 73 degrees. 10: the toungue is open, 73: the gripper is closed.

  // Show angle value in Serial Monitor/Serial Plotter
  Serial.println("\n===AngleValue===");
  Serial.print("BaseAngle:");
  Serial.print(base_angle);
  Serial.print(" ShoulderAngle:");
  Serial.print(shoulder_angle);
  Serial.print(" ElbowAngle:");
  Serial.print(elbow_angle);
  Serial.print(" WristRotationAngle:");
  Serial.print(wrist_rot_angle);
  Serial.print(" WristVerticalAngle:");
  Serial.print(wrist_ver_angle);
  Serial.print(" GripperAngle:");
  Serial.println(gripper_angle);

  // Control the each servo motor with angle (degree)
  //                    step_delay,base,shoulder,elbow,wrist vertical,wrist rotation,gripper
  Braccio.ServoMovement(10, base_angle, shoulder_angle, elbow_angle, wrist_rot_angle, wrist_ver_angle, gripper_angle);
}
