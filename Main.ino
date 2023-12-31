/*
Created by Evan St-Pierre
Nov 2023
Utilizes a servo through a potentiometer.
*/

#include <Servo.h>

Servo mainServo;

void setup() {
  Serial.begin(9600);
  mainServo.attach(8); // Pin number
  mainServo.write(0);
  delay(1000);
 
}
void loop() {
  
  const double diffValue = 1023 / 180; // Max rotation value of potentiometer / Max rotation of servo degree             
  int sensorValue = analogRead(A0);
  int angle = sensorValue / diffValue; // Lets servo know what degree to rotate to based on potentiometer position.
 
  Serial.print(sensorValue);
  Serial.print(":");
  Serial.println(angle);
 
  mainServo.write(angle);
  
  delay(1);
}