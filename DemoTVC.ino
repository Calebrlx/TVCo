#include <Servo.h>
#include <math.h>

Servo servoX;
Servo servoY;

const float frequency = 0.5;
const float amplitude = 20.0;
const int centerX = 90;
const int centerY = 90;

void setup() {
  servoX.attach(9);
  servoY.attach(10);
}

void loop() {
  float time = millis() / 1000.0;

  // Calculate servo positions for a circular motion
  int pitch_angle = centerX + amplitude * sin(2 * PI * frequency * time);
  int yaw_angle = centerY + amplitude * cos(2 * PI * frequency * time);

  // Send angles to servos
  servoX.write(pitch_angle);
  servoY.write(yaw_angle);

  delay(20);
}