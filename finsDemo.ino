#include <Servo.h>
#include <math.h>

Servo finLeft;
Servo finRight;
Servo finTop;
Servo finBottom;

const float frequency = 0.5;  // Adjust frequency for spin rate
const float amplitude = 20.0; // Angle for fin deflection
const int centerAngle = 90;   // Neutral position for fins

void setup() {
  finLeft.attach(3);
  finRight.attach(5);
  finTop.attach(6);
  finBottom.attach(9);
}

void loop() {
  float time = millis() / 1000.0;

  // Calculate fin deflections for circular or figure-8 pattern
  int left_angle = centerAngle + amplitude * sin(2 * PI * frequency * time);
  int right_angle = centerAngle - amplitude * sin(2 * PI * frequency * time);
  int top_angle = centerAngle + amplitude * cos(2 * PI * frequency * time);
  int bottom_angle = centerAngle - amplitude * cos(2 * PI * frequency * time);

  // Set fin angles
  finLeft.write(left_angle);
  finRight.write(right_angle);
  finTop.write(top_angle);
  finBottom.write(bottom_angle);

  delay(20); // Small delay for smooth motion
}