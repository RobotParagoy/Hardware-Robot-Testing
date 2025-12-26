#include <Arduino.h>
#include <Wire.h>
#include <MPU6050_tockn.h>
#include <ESP32Servo.h>

/* ========= MPU ========= */
MPU6050 mpu(Wire);

/* ========= SERVO ========= */
Servo myServo;
const int servoPin = 21;

/* ========= LINE FOLLOWER ========= */
const int s1 = 4;
const int s2 = 5;
const int s3 = 6;
const int s4 = 7;
const int s5 = 15;

/* ========= MOTOR DRIVER MX1919 ========= */
/* Driver 1 */
#define M1_IN1 16
#define M1_IN2 17
#define M1_IN3 18
#define M1_IN4 19

/* Driver 2 */
#define M2_IN1 10
#define M2_IN2 11
#define M2_IN3 12
#define M2_IN4 13

/* ========= QR SENSOR ========= */
#define QR_RX_PIN 38
#define QR_TX_PIN 39

/* ========= TIMING ========= */
unsigned long lastPrint = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);

  /* ===== MPU (ASLI, TIDAK DIUBAH) ===== */
  Wire.begin(8, 9);
  Serial.println("Initializing MPU6050...");
  mpu.begin();
  delay(1000);
  Serial.println("Calibrating gyro (DO NOT MOVE)...");
  mpu.calcGyroOffsets(true);
  Serial.println("MPU6050 READY");

  /* ===== SERVO ===== */
  myServo.attach(servoPin, 500, 2400);

  /* ===== LINE FOLLOWER ===== */
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);

  /* ===== MOTOR DRIVER ===== */
  pinMode(M1_IN1, OUTPUT);
  pinMode(M1_IN2, OUTPUT);
  pinMode(M1_IN3, OUTPUT);
  pinMode(M1_IN4, OUTPUT);

  pinMode(M2_IN1, OUTPUT);
  pinMode(M2_IN2, OUTPUT);
  pinMode(M2_IN3, OUTPUT);
  pinMode(M2_IN4, OUTPUT);

  /* ===== QR SENSOR ===== */
  Serial2.begin(9600, SERIAL_8N1, QR_RX_PIN, QR_TX_PIN);

  Serial.println("ALL SYSTEM READY");
  Serial.println("--------------------------------");
}

void loop() {
  /* ===== 1. MPU ===== */
  mpu.update();
  float gyroZ  = mpu.getGyroZ();
  float angleZ = mpu.getAngleZ();

  /* ===== 2. SERVO (LOGIKA ASLI) ===== */
  myServo.write(0);
  delay(300);
  myServo.write(90);
  delay(300);
  myServo.write(180);
  delay(300);

  /* ===== 3. LINE FOLLOWER ===== */
  int v1 = digitalRead(s1);
  int v2 = digitalRead(s2);
  int v3 = digitalRead(s3);
  int v4 = digitalRead(s4);
  int v5 = digitalRead(s5);

  /* ===== 4. MOTOR TEST ===== */
  // MAJU
  digitalWrite(M1_IN1, HIGH); digitalWrite(M1_IN2, LOW);
  digitalWrite(M1_IN3, HIGH); digitalWrite(M1_IN4, LOW);

  digitalWrite(M2_IN1, HIGH); digitalWrite(M2_IN2, LOW);
  digitalWrite(M2_IN3, HIGH); digitalWrite(M2_IN4, LOW);

  /* ===== 5. QR SENSOR ===== */
  String qrData = "";
  if (Serial2.available()) {
    qrData = Serial2.readStringUntil('\n');
  }

  /* ===== 6. SERIAL OUTPUT ===== */
  if (millis() - lastPrint > 200) {
    lastPrint = millis();

    Serial.print("GyroZ: ");
    Serial.print(gyroZ);
    Serial.print(" | AngleZ: ");
    Serial.print(angleZ);

    Serial.print(" | Line: ");
    Serial.print(v1); Serial.print(" ");
    Serial.print(v2); Serial.print(" ");
    Serial.print(v3); Serial.print(" ");
    Serial.print(v4); Serial.print(" ");
    Serial.print(v5);

    if (qrData.length() > 0) {
      Serial.print(" | QR: ");
      Serial.print(qrData);
    }

    Serial.println();
  }
}
