// this code needs to be compiled on Kiel Uvision & the hex file generated needs to burned on the 8051 microcontroller.
#include<reg51.h> 

// Define motor pins for controlling movement
sbit mot1 = P2^0;  // Motor 1 control pin
sbit mot2 = P2^1;  // Motor 2 control pin
sbit mot3 = P2^2;  // Motor 3 control pin
sbit mot4 = P2^3;  // Motor 4 control pin

// Define sensor pins for left and right IR sensors
sbit s_left = P2^6;  // Left sensor
sbit s_right = P2^7; // Right sensor

// Function declarations for robot movement
void forward(void);    // Move forward
void backward(void);   // Move backward
void left(void);       // Turn left
void right(void);      // Turn right
void stop(void);       // Stop movement

// Function to move the robot forward
void forward(void) {
  mot1 = 0;  // Motor 1 OFF
  mot2 = 1;  // Motor 2 ON
  mot3 = 1;  // Motor 3 ON
  mot4 = 0;  // Motor 4 OFF
}

// Function to move the robot backward
void backward(void) {
  mot1 = 0;  // Motor 1 OFF
  mot2 = 1;  // Motor 2 ON
  mot3 = 0;  // Motor 3 OFF
  mot4 = 1;  // Motor 4 ON
}

// Function to turn the robot left
void left(void) {
  mot1 = 0;  // Motor 1 OFF
  mot2 = 1;  // Motor 2 ON
  mot3 = 0;  // Motor 3 OFF
  mot4 = 0;  // Motor 4 OFF
}

// Function to turn the robot right
void right(void) {
  mot1 = 0;  // Motor 1 OFF
  mot2 = 0;  // Motor 2 OFF
  mot3 = 1;  // Motor 3 ON
  mot4 = 0;  // Motor 4 OFF
}

// Function to stop the robot
void stop(void) {
  mot1 = 0;  // Motor 1 OFF
  mot2 = 0;  // Motor 2 OFF
  mot3 = 0;  // Motor 3 OFF
  mot4 = 0;  // Motor 4 OFF
}

void main() {
  // Initialize sensors as active high
  s_left = 1;   // Left sensor ON
  s_right = 1;  // Right sensor ON

  while(1) {  // Infinite loop for continuous operation
    // Both sensors detect the line - move forward
    if (s_left == 0 && s_right == 0) {
      forward();
    }
    // Both sensors do not detect the line - stop
    else if (s_left == 1 && s_right == 1) {
      stop();
    }
    // Left sensor detects the line - turn left
    else if (s_left == 0 && s_right == 1) {
      left();
    }
    // Right sensor detects the line - turn right
    else if (s_left == 1 && s_right == 0) {
      right();
    }
  }
}
