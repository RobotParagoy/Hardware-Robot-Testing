#include <Arduino.h>

/* ===== MX1919 DRIVER 1 ===== */

#define M1_IN1 16 //FR
#define M1_IN2 17
#define M1_IN3 18 //FL
#define M1_IN4 19

/* ===== MX1919 DRIVER 2 ===== */
#define M2_IN1 10 // BR
#define M2_IN2 11
#define M2_IN3 12 // BL
#define M2_IN4 13

void setup() {
  Serial.begin(115200);

  pinMode(M1_IN1, OUTPUT);
  pinMode(M1_IN2, OUTPUT);
  pinMode(M1_IN3, OUTPUT);
  pinMode(M1_IN4, OUTPUT);

  pinMode(M2_IN1, OUTPUT);
  pinMode(M2_IN2, OUTPUT);
  pinMode(M2_IN3, OUTPUT);
  pinMode(M2_IN4, OUTPUT);

  Serial.println("MX1919 DUAL DRIVER READY");
}

void loop() {
  // ===== MAJU (SEMUA MOTOR) =====
  digitalWrite(M1_IN1, HIGH);
  digitalWrite(M1_IN2, LOW);
  digitalWrite(M1_IN3, HIGH);
  digitalWrite(M1_IN4, LOW);

  digitalWrite(M2_IN1, HIGH);
  digitalWrite(M2_IN2, LOW);
  digitalWrite(M2_IN3, HIGH);
  digitalWrite(M2_IN4, LOW);

  Serial.println("FORWARD");
  delay(2000);

  // ===== STOP =====
  digitalWrite(M1_IN1, LOW);
  digitalWrite(M1_IN2, LOW);
  digitalWrite(M1_IN3, LOW);
  digitalWrite(M1_IN4, LOW);

  digitalWrite(M2_IN1, LOW);
  digitalWrite(M2_IN2, LOW);
  digitalWrite(M2_IN3, LOW);
  digitalWrite(M2_IN4, LOW);

  Serial.println("STOP");
  delay(1000);

  // ===== MUNDUR =====
  digitalWrite(M1_IN1, LOW);
  digitalWrite(M1_IN2, HIGH);
  digitalWrite(M1_IN3, LOW);
  digitalWrite(M1_IN4, HIGH);

  digitalWrite(M2_IN1, LOW);
  digitalWrite(M2_IN2, HIGH);
  digitalWrite(M2_IN3, LOW);
  digitalWrite(M2_IN4, HIGH);

  Serial.println("REVERSE");
  delay(2000);
}
