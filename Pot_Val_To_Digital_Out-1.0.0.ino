// Created By: Jmere36
// Purpose: To read and change the output of a digital pin through a potentiometer or other sensors 
// Has the feature of telling you what output is at and what specific value in the serial monitor
// Has been tested on an led (why the int is led) and seems very accurate
// This can add many functionalities to your build including: using a potentiometer to control the loudness of your speakers
// If there's any issues or questions please contact my email at: jmere36@icloud.com

// Pot (potentiometer) or other input is connected to pin A0
// Led or other output is connected to pin 9

// Change Log:
// Created 1.0.0 with improved serial monitor experiences

const int pot = A0;
const int led = 9;
  // Adds the input an output connected
int val = 0;
  // Adds the int val to measure the value of A0
void setup() {
pinMode(pot, INPUT);
pinMode(led, OUTPUT);
  // Adds both pins to the coresponding values
Serial.begin(9600);
  // Starts the serial communication between the arduino and your pc
}

void loop() {
val = analogRead(pot);
  // Makes val equal the value of the pot/sensor
val = val / 4;
  // Scales val by 4 so that the output can work correctley
analogWrite(led, val);
  // Sets the led/output to the value of val
Serial.print("Value: ");
Serial.print(val);
Serial.print("\t");
  //  Prints to the serial communication the exact value and leaves a space of 'tab' (\t) for future use
if (val == 255) {
  // If value equals 255 continue
  Serial.println("Output: Full");
    // Print to serial output is full
}
if (val > 204 && val != 255) {
  // If val is greater than 204 and not equal to 255 continue
  Serial.println("Output: Very High");
    // Print to serial output is very high
}
if (val <= 204 && val > 153) {
  // If value is less than or equal to 204 and is greater than 153 continue
  Serial.println("Output: High");
    // Print to serial output is high
}
if (val <= 153 && val > 102) {
  // If value is less than or equal to 153 and is greater than 102 continue
  Serial.println("Output: Medium");
    // Print to serial output is medium
}
if (val <= 102 && val > 51) {
  // If value is less than or equal to 102 and is greater than 51 continue
  Serial.println("Output: Low");
    // Print to serial output is low
}
if (val <= 51 && val > 0) {
  // If value is less than or equal to 51 and is greater than 0 continue
  Serial.println("Output: Very Low");
    // Print to serial output is very low
}
if (val == 0) {
  // If value equals 0 continue
  Serial.println("Output: Off");
    // Print to serial output is off
}
}

