const int pumpPin = 9;
unsigned long startTime = 0;
bool pumpRunning = false;

void setup() {
  pinMode(pumpPin, OUTPUT);
}

void loop() {
  if (!pumpRunning) {
    turnOnPump();
    startTime = millis();
    pumpRunning = true;
  } else {
    unsigned long currentTime = millis();
    if (currentTime - startTime >= 5000) {
      turnOffPump();
      pumpRunning = false;
      delay(5000); // Delay before starting the pump again
    }
  }
}

void turnOnPump() {
  digitalWrite(pumpPin, HIGH); // Turn on the pump
}

void turnOffPump() {
  digitalWrite(pumpPin, LOW); // Turn off the pump
}
