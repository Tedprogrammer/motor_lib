#include "SimpleServo.h"

SimpleServo::SimpleServo(int pin) {
  _pin = pin;
  _minAngle = 0;
  _maxAngle = 180;
  _currentAngle = 90;
}

void SimpleServo::begin() {
  _servo.attach(_pin);
  _servo.write(_currentAngle);
}

void SimpleServo::setLimits(int minAngle, int maxAngle) {
  _minAngle = minAngle;
  _maxAngle = maxAngle;
}

void SimpleServo::setAngle(int angle) {
  _currentAngle = constrain(angle, _minAngle, _maxAngle);
  _servo.write(_currentAngle);
}

int SimpleServo::getCurrentAngle() {
  return _currentAngle;
}
