#include <Servo.h>

// Initializing servo motor limits
Servo horizontalServo; // Horizontal servo
int horizontalAngle = 90;
const int horizontalLimitHigh = 240;
const int horizontalLimitLow = 2;

Servo verticalServo; // Vertical servo
int verticalAngle = 180;
const int verticalLimitHigh = 240;
const int verticalLimitLow = 2;

// LDR pin connections
const int ldrTopLeft = A0;    // LDR top left - BOTTOM LEFT
const int ldrTopRight = A3;   // LDR top right - BOTTOM RIGHT
const int ldrBottomLeft = A1; // LDR down left - TOP LEFT
const int ldrBottomRight = A2; // LDR down right - TOP RIGHT

void setup() {
    // Attach horizontal and vertical servo motors to pins 9 and 10 of the Arduino board
    horizontalServo.attach(9);
    verticalServo.attach(10);
    
    // Set the initial position of the horizontal and vertical servo motors
    horizontalServo.write(horizontalAngle);
    verticalServo.write(verticalAngle);
    
    // Delay to allow servos to reach initial positions
    delay(2500);
}

void loop() {
    // Read analog values from the LDRs
    int topLeft = analogRead(ldrTopLeft);
    int topRight = analogRead(ldrTopRight);
    int bottomLeft = analogRead(ldrBottomLeft);
    int bottomRight = analogRead(ldrBottomRight);

    const int delayTime = 50;
    const int tolerance = 20;

    // Calculate average values
    int averageTop = (topLeft + topRight) / 2;
    int averageBottom = (bottomLeft + bottomRight) / 2;
    int averageLeft = (topLeft + bottomLeft) / 2;
    int averageRight = (topRight + bottomRight) / 2;

    // Calculate differences in light intensity
    int differenceVertical = averageTop - averageBottom;
    int differenceHorizontal = averageLeft - averageRight;

    // Adjust vertical angle based on light intensity difference
    if (abs(differenceVertical) > tolerance) {
        if (averageTop > averageBottom) {
            verticalAngle = min(verticalAngle + 1, verticalLimitHigh);
        } else {
            verticalAngle = max(verticalAngle - 1, verticalLimitLow);
        }
        verticalServo.write(verticalAngle);
    }

    // Adjust horizontal angle based on light intensity difference
    if (abs(differenceHorizontal) > tolerance) {
        if (averageLeft > averageRight) {
            horizontalAngle = max(horizontalAngle - 1, horizontalLimitLow);
        } else {
            horizontalAngle = min(horizontalAngle + 1, horizontalLimitHigh);
        }
        horizontalServo.write(horizontalAngle);
    } else if (averageLeft == averageRight) {
        delay(5000);
    }

    // Short delay before the next loop iteration
    delay(delayTime);
}
