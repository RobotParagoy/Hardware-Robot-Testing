const int s1 = 4;
const int s2 = 5;
const int s3 = 6;
const int s4 = 7;
const int s5 = 15;

void setup() {
  Serial.begin(115200);

  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);

  Serial.println("LINE SENSOR READY");
}

void loop() {
  Serial.print(digitalRead(s1)); Serial.print(" ");
  Serial.print(digitalRead(s2)); Serial.print(" ");
  Serial.print(digitalRead(s3)); Serial.print(" ");
  Serial.print(digitalRead(s4)); Serial.print(" ");
  Serial.println(digitalRead(s5));

  delay(100);
}
