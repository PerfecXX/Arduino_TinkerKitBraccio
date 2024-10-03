/*
Author      : Teeraphat Kullanankanjana
Version     : 1.0
Date        : 03/10/2567
Description : Simple Movement (Gripper Only)
Copyright (C) 2024 Teeraphat Kullanankanjana. All rights reserved.
*/

// Include the Braccio and Servo library
#include <Braccio.h>
#include <Servo.h>

Servo base;       // M1
Servo shoulder;   // M2
Servo elbow;      // M3
Servo wrist_ver;  // M4
Servo wrist_rot;  // M5
Servo gripper;    // M6

void setup() {
  Braccio.begin();
}

void loop() {
  /*
  Use Braccio.ServoMovement (Step Delay, M1, M2, M3, M4, M5, M6) to move the servo motor to a specific angle (degree).
  Step Delay: a millisecond delay between the movement of each servo. Allowed values from 10 to 30 msec.
  M1: base degrees. Allowed values from 0 to 180 degrees
  M2: shoulder degrees. Allowed values from 15 to 165 degrees
  M3: elbow degrees. Allowed values from 0 to 180 degrees
  M4: wrist vertical degrees. Allowed values from 0 to 180 degrees
  M5: wrist rotation degrees. Allowed values from 0 to 180 degrees
  M6: gripper degrees. Allowed values range from 10 to 73 degrees. 10: The tongue is open; 73: The gripper is closed.
  */

  // Gripper open
  Braccio.ServoMovement(30, 90, 45, 180, 180, 180, 10);
  // Wait 1 Second
  delay(1000);
  // Gripper close
  Braccio.ServoMovement(30, 90, 45, 180, 180, 180, 73);
  // Wait 1 Second
  delay(1000);
}
