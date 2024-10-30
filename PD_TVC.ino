#include <Servo.h>
#include <Wire.h>
#include <MPU6050.h>

Servo servoX;
Servo servoY;
MPU6050 mpu;

float Kp = 0.5; // Proportional gain, tune as needed
float Kd = 0.1; // Derivative gain, tune as needed
float previous_error_x = 0, previous_error_y = 0;
float max_error = 10.0;

void setup() {
    servoX.attach(9);
    servoY.attach(10);
    Wire.begin();
    mpu.initialize();
}

void loop() {
    // Get accelerometer data
    int16_t ax, ay, az;
    mpu.getAcceleration(&ax, &ay, &az);

    // Calculate tilt angle (simplified for 2D)
    float error_x = ax; // use atan2 if needed for angle
    float error_y = ay;

    // PD control for each servo
    float control_x = Kp * error_x + Kd * (error_x - previous_error_x);
    float control_y = Kp * error_y + Kd * (error_y - previous_error_y);

    previous_error_x = error_x;
    previous_error_y = error_y;

    // Map control output to servo range (1-2 ms)
    int servoX_val = map(control_x, -max_error, max_error, 1000, 2000);
    int servoY_val = map(control_y, -max_error, max_error, 1000, 2000);

    servoX.writeMicroseconds(servoX_val);
    servoY.writeMicroseconds(servoY_val);

    delay(10); // Small delay for control stability
}
