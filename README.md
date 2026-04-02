# SimpleServo

A beginner Arduino motor library for reusable servo control.

## Features

- Attach a servo to a selected pin
- Set safe minimum and maximum angle limits
- Command the servo to a target angle
- Read back the current commanded angle

## Folder structure

- `src/` contains the library source code
- `examples/KnobToServo/` contains an example sketch

## Hardware

- Arduino Uno
- Servo motor
- Potentiometer
- Breadboard
- Jumper wires
- External power for servo if needed

## Wiring

### Potentiometer
- One outer pin to 5V
- Other outer pin to GND
- Middle pin to A5

### Servo
- Signal pin to D9
- Power to 5V or external 5V supply
- Ground to GND

## Example

```cpp
#include <SimpleSensor.h>
#include <SimpleServo.h>

SimpleSensor sensor(A5);
SimpleServo motor(9);

void setup() {
  Serial.begin(9600);

  sensor.begin();
  sensor.setCalibration(0, 1023);

  motor.begin();
  motor.setLimits(10, 170);
}

void loop() {
  sensor.update();

  int angle = sensor.getMappedValue(0, 180);
  motor.setAngle(angle);

  Serial.print("Raw: ");
  Serial.print(sensor.getRaw());
  Serial.print("  Angle: ");
  Serial.println(motor.getCurrentAngle());

  delay(200);
}
