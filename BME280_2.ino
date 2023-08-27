#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define BME280_I2C_ADDR1 0x76 // I2C address of the first BME280 sensor
#define BME280_I2C_ADDR2 0x77 // I2C address of the second BME280 sensor

Adafruit_BME280 bme1;
Adafruit_BME280 bme2;

void setup() {
  Wire.begin();
  Serial.begin(9600);

  // Initialize the first BME280 sensor
  if (!bme1.begin(BME280_I2C_ADDR1)) {
    Serial.println("Could not find a valid BME280 sensor at address 0x76");
    while (1);
  }

  // Initialize the second BME280 sensor
  if (!bme2.begin(BME280_I2C_ADDR2)) {
    Serial.println("Could not find a valid BME280 sensor at address 0x77");
    while (1);
  }
}

void loop() {
  // Read data from the first BME280 sensor
  float temp1 = bme1.readTemperature();
  float press1 = bme1.readPressure() / 100.0;
  float hum1 = bme1.readHumidity();

  // Read data from the second BME280 sensor
  float temp2 = bme2.readTemperature();
  float press2 = bme2.readPressure() / 100.0;
  float hum2 = bme2.readHumidity();

  // Print the sensor values
  Serial.print("Sensor 1 - ");
  Serial.print("Temperature: ");
  Serial.print(temp1);
  Serial.print(" °C, Pressure: ");
  Serial.print(press1);
  Serial.print(" hPa, Humidity: ");
  Serial.print(hum1);
  Serial.println(" %");

  Serial.print("Sensor 2 - ");
  Serial.print("Temperature: ");
  Serial.print(temp2);
  Serial.print(" °C, Pressure: ");
  Serial.print(press2);
  Serial.print(" hPa, Humidity: ");
  Serial.print(hum2);
  Serial.println(" %");

  delay(2000); // Delay between readings
}
