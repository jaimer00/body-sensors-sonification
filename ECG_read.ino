/******************************************************************************
Heart_Rate_Display.ino
Demo Program for AD8232 Heart Rate sensor.
Casey Kuhns @ SparkFun Electronics
6/27/2014
https://github.com/sparkfun/AD8232_Heart_Rate_Monitor
The AD8232 Heart Rate sensor is a low cost EKG/ECG sensor.  This example shows
how to create an ECG with real time display.  The display is using Processing.
This sketch is based heavily on the Graphing Tutorial provided in the Arduino
IDE. http://www.arduino.cc/en/Tutorial/Graph
Resources:
This program requires a Processing sketch to view the data in real time.
Development environment specifics:
  IDE: Arduino 1.0.5
  Hardware Platform: Arduino Pro 3.3V/8MHz
  AD8232 Heart Monitor Version: 1.0
This code is beerware. If you see me (or any other SparkFun employee) at the
local pub, and you've found our code helpful, please buy us a round!
Distributed as-is; no warranty is given.
******************************************************************************/

int SAMPLE_SIZE = 15;

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  pinMode(9, INPUT);   // Setup for leads off detection LO +
  pinMode(10, INPUT);  // Setup for leads off detection LO -
}

void loop() {
  int average = 0;
  int reading = 0;
  //if ((digitalRead (0) == 1) || (digitalRead (1) == 1)) {
  //Serial.println ('!');
  //}
  //else {
  // send the value of analog input 0:
  for (int i = 0; i < SAMPLE_SIZE; i++) {
    reading += analogRead(A0);
    delay(1);
  }
  average = reading / SAMPLE_SIZE;
  Serial.println(average);
  //}
  // Wait for a bit to keep serial data from saturating
}
