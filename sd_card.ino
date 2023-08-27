#include <SD.h>

const int chipSelect = 10; 

File dataFile;

void setup() {
  Serial.begin(9600);
  if (!SD.begin(chipSelect)) {
    Serial.println("SD card initialization failed!");
    return;
  }
  Serial.println("SD card initialized successfully!");

  dataFile = SD.open("data.txt", FILE_WRITE);

  if (dataFile) {
    Serial.println("Data file opened successfully!");
    dataFile.println("Hello, this is a sample text.");
    dataFile.close();
    Serial.println("โหลดข้อมูลแล้วฮ้าฟฟู่ว");
  } else {
    Serial.println("เปิดไม่ได้ ฮ้าฟฟู่ว");
  }
}

void loop() {
}
