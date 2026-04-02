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

// What this sketch is doing read the potentiometer map its value into 0 to 180 send that angle to the servo print debug info
