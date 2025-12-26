#include <ESP32Servo.h>

Servo myServo;
const int servoPin = 21;

void setup() {
  Serial.begin(115200);
  myServo.attach(servoPin, 500, 2400);
  Serial.println("SERVO READY");
}

void loop() {
  myServo.write(0);
  delay(300);

  myServo.write(90);
  delay(300);

  myServo.write(180);
  delay(300);
}
