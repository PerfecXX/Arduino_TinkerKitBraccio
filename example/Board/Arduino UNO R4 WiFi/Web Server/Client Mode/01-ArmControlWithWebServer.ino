/*
Author      : Teeraphat Kullanankanjana
Version     : 1.0
Date        : 03/10/2567
Description : Control TinkerKit Braccio Robot with Web Server (Client Mode)
Copyright (C) 2024 Teeraphat Kullanankanjana. All rights reserved.
*/

#include <WiFi.h>           // Include WiFi library
#include <Braccio.h>        // Include Braccio library
#include <Servo.h>          // Include Servo library
#include "home_page.h"       // Include the homepage HTML

// Network credentials
const char *ssid = "iMakeEDU";          // Replace with your Wi-Fi network name
const char *password = "imake1234";  // Replace with your Wi-Fi network password

// Create WiFiServer on port 80
WiFiServer server(80);

// Servo objects for Braccio robot
Servo base;      
Servo shoulder;  
Servo elbow;     
Servo wrist_ver; 
Servo wrist_rot; 
Servo gripper;   

// Initialize variables for servo positions
int basePos = 90, shoulderPos = 90, elbowPos = 90, wristVerPos = 90, wristRotPos = 90, gripperPos = 40;
int step_delay=20;

void setup() {
  // Start Serial communication
  Serial.begin(9600);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println();
  Serial.println("Connected to Wi-Fi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Initialize Braccio robot
  Braccio.begin();
  
  // Start the WiFi server
  server.begin();
  Serial.println("Web server started");
}

void loop() {
  // Listen for incoming clients
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New client connected");

    String currentLine = "";
    String request = "";
    
    // Read HTTP request
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        request += c;
        Serial.write(c);
        
        if (c == '\n') {
          // Empty line indicates end of headers
          if (currentLine.length() == 0) {
            // Serve HTML homepage if root page is requested
            if (request.indexOf("GET / ") >= 0) {
              client.println("HTTP/1.1 200 OK");
              client.println("Content-type:text/html");
              client.println();
              client.print(index_html);
            }
            
            // Handle servo setting requests (e.g., GET /setServo?...)
            else if (request.indexOf("GET /setServo") >= 0) {
              handleSetServo(request, client);
            }
            
            // Break out of loop to close connection
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }
    
    // Close the connection
    client.stop();
    Serial.println("Client disconnected");
  }
}

// Function to parse GET request and set servo positions
void handleSetServo(String request, WiFiClient &client) {
  // Parse slider values from the request
  basePos = getParam(request, "base");
  shoulderPos = getParam(request, "shoulder");
  elbowPos = getParam(request, "elbow");
  wristVerPos = getParam(request, "wristVer");
  wristRotPos = getParam(request, "wristRot");
  gripperPos = getParam(request, "gripper");
  step_delay = getParam(request, "stepDelay");

  // Move the servos to the new positions
  Braccio.ServoMovement(step_delay, basePos, shoulderPos, elbowPos, wristVerPos, wristRotPos, gripperPos);

  // Send response back to client
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/plain");
  client.println();
  client.print("Servo positions updated");
}

// Helper function to extract parameter from GET request
int getParam(String request, String param) {
  int startIdx = request.indexOf(param + "=");
  if (startIdx == -1) return -1;
  startIdx += param.length() + 1;  // Skip "param="
  
  int endIdx = request.indexOf('&', startIdx);  // Find the next "&" or end of line
  if (endIdx == -1) endIdx = request.indexOf(' ', startIdx);  // End of GET request

  return request.substring(startIdx, endIdx).toInt();  // Convert to int and return
}

