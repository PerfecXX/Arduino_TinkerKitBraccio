/*
Author      : Teeraphat Kullanankanjana
Version     : 1.0
Date        : 03/10/2567
Description : Control TinkerKit Braccio Robot with Arduino Cloud 
Copyright (C) 2024 Teeraphat Kullanankanjana. All rights reserved.
*/

// Include the Braccio and Servo library
#include <Braccio.h>
#include <Servo.h>
// Include all setting from thingProperties header file
#include "thingProperties.h"

// Define Servo Port
Servo base;       // M1
Servo shoulder;   // M2
Servo elbow;      // M3
Servo wrist_ver;  // M4
Servo wrist_rot;  // M5
Servo gripper;    // M6

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  Serial.println("\nRobot Begin...");
  // Initialization fucntions and setup the initial position for robot.
  Braccio.begin();
  Serial.println("\nRobot reset to safety position!");
  
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information youâll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  // Update and sync the value between the variable and the cloud variable. 
  ArduinoCloud.update();

  // if the reset_state is True, Reset the robot to safe position
  if (reset_state)
  {
    // Reset the robot to safe postion
    Braccio.ServoMovement(step_delay,90,45,180,180,180,10);
  }
  // If the reset is false, Move the robot according to the cloud variable value from Arduino Cloud. 
  else
  {
    // Move the robot by using cloud variable value (Can be set with the Dashboard widget)
    Braccio.ServoMovement(step_delay,base_angle,shoulder_angle,elbow_angle,wrist_rot_angle,wrist_ver_angle,gripper_angle);
  }
  
}

/*
Since all cloud variable permission is READ_WRITE variable, this follwing function is
executed every time a new value is received from IoT Cloud:

- onBaseAngleChange()
- onShoulderAngleChange()
- onElbowAngleChange()
- onWristRotAngleChange()
- onWristVerAngleChange()
- onGripperAngleChange()
- onStepDelayChange()
- onResetStateChange()

DO NOT ATTEMPT TO REMOVE IT; KEEP IT TO YOUR FILE.
*/

void onBaseAngleChange(){}
void onShoulderAngleChange(){}
void onElbowAngleChange(){}
void onWristRotAngleChange(){}
void onWristVerAngleChange(){}
void onGripperAngleChange(){}
void onResetStateChange(){}
void onStepDelayChange(){}
