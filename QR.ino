#include <Arduino.h>

// UART pins for QR sensor
#define QR_RX_PIN 38
#define QR_TX_PIN 39

void setup() {
  Serial.begin(115200);
  delay(500); // Wait for serial to initialize
  Serial.println("QR Sensor initialized on pins 38 (TX) and 39 (RX)");
  Serial2.begin(9600, SERIAL_8N1, QR_RX_PIN, QR_TX_PIN); // Adjust baud rate based on your QR sensor specs
}

void loop() {
  // Read data from QR sensor
  if (Serial2.available()) {
    String qrData = Serial2.readStringUntil('\n');
    Serial.print("QR Code Read: ");
    Serial.println(qrData);
  }
  
  delay(100);
}