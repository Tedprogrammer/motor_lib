#ifndef SIMPLESERVO_H
#define SIMPLESERVO_H

#include <Arduino.h>
#include <Servo.h>

class SimpleServo {
  private:
    Servo _servo;
    int _pin;
    int _minAngle;
    int _maxAngle;
    int _currentAngle;

  public:
    SimpleServo(int pin);
    void begin();
    void setLimits(int minAngle, int maxAngle);
    void setAngle(int angle);
    int getCurrentAngle();
};
#endif
