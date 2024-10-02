/*
Author      : Teeraphat Kullanankanjana
Version     : 1.0
Date        : 02/10/2567
Description : Template file for TinkerKit Braccio Robot
Copyright (C) 2024 Teeraphat Kullanankanjana. All rights reserved.
*/

// Include the Braccio and Servo library
#include <Braccio.h>
#include <Servo.h>

Servo base; // M1
Servo shoulder; // M2
Servo elbow; // M3
Servo wrist_ver; // M4
Servo wrist_rot; // M5
Servo gripper; // M6

void setup() {
  /*
  Initialization fucntions and setup the initial position for robot.
  All servo motors will be positioned in the "safety" position:
  M1=90,M2=45,M3=180,M4=180,M5=180,M6=10
  */
  Braccio.begin();  
}

void loop() {
 
}
