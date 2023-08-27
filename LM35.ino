const int lm35Pin = A0; // Analog pin A0 for LM35 sensor
const int pumpPin = 9;   // Digital pin 9 for controlling the fan relay
const float thresholdTemp = 30.0; // Temperature threshold to activate the pump (adjust as needed)
const unsigned long pumpOnDuration = 300000; // 5 minutes in milliseconds

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(pumpPin, OUTPUT); // Set pumpPin as OUTPUT
  digitalWrite(pumpPin, LOW); // Turn off the pump initially
}

void loop() {
  int sensorValue = analogRead(lm35Pin); // Read analog value from LM35 sensor
  float voltage = (sensorValue / 1023.0) * 5.0; // Convert sensor value to voltage (assuming 5V Arduino board)
  float temperatureCelsius = (voltage - 0.5) * 100.0; // Calculate temperature in Celsius

  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(", Voltage: ");
  Serial.print(voltage);
  Serial.print("V, Temperature: ");
  Serial.print(temperatureCelsius);
  Serial.println(" °C");

  // Check if the temperature exceeds the threshold
  if (temperatureCelsius > thresholdTemp) {
    Serial.println("Temperature exceeds threshold. Fan ON.");
    digitalWrite(pumpPin, HIGH); // Turn ON the pump
    delay(pumpOnDuration); // Keep the pump ON for the specified duration (5 minutes)
    digitalWrite(pumpPin, LOW); // Turn OFF the pump
    Serial.println("pump OFF.");
  }

  delay(1000); // Delay for one second before taking the next reading
}
