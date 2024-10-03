/*
Author      : Teeraphat Kullanankanjana
Version     : 1.0
Date        : 03/10/2567
Description : Control TinkerKit Braccio Robot with Web Server
Copyright (C) 2024 Teeraphat Kullanankanjana. All rights reserved.
*/

// Include the Braccio and Servo library
#include <Braccio.h>
#include <Servo.h>

// Set Servo Instance
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
}
