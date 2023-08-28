void setup() {
  Serial.begin(9600); //เปลี่ยนได้
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(1000); //เขียนต่อ
}
n("Could not find a valid BNO08x sensor, check wiring!");
    while (1);
  }
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  imu.update();

  if (imu.accelAvailable()) {
    float accelX = imu.getAccelX();
    float accelY = imu.getAccelY();
    float accelZ = imu.getAccelZ();

    Serial.print("Accelerometer: ");
    Serial.print("X: "); Serial.print(accelX); Serial.print("\t");
    Serial.print("Y: "); Serial.print(accelY); Serial.print("\t");
    Serial.print("Z: "); Serial.println(accelZ);
  }

  delay(100);  // Delay between readings
}
