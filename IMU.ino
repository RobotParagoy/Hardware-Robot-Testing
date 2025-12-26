#include <Wire.h>
#include <MPU6050_tockn.h>

MPU6050 mpu(Wire);

unsigned long lastPrint = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);

  // I2C ESP32-S3
  Wire.begin(8, 9);

  Serial.println("Initializing MPU6050...");
  mpu.begin();

  delay(1000);
  Serial.println("Calibrating gyro, DO NOT MOVE MPU...");
  mpu.calcGyroOffsets(true);

  Serial.println("MPU6050 READY");
  Serial.println("Rotate MPU on Z axis (yaw)");
}

void loop() {
  // HARUS dipanggil terus
  mpu.update();

  // Ambil hanya sumbu Z
  float gyroZ = mpu.getGyroZ();   // deg/s
  float angleZ = mpu.getAngleZ(); // deg (yaw)

  // Print tiap 50 ms (stabil)
  if (millis() - lastPrint > 50) {
    lastPrint = millis();

    Serial.print("Gyro Z (deg/s): ");
    Serial.print(gyroZ);

    Serial.print("\tAngle Z (deg): ");
    Serial.println(angleZ);
  }
}
