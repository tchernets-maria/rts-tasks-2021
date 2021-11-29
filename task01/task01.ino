int ledMas[] = {3, 6, 9, 10, 11};
unsigned long intervalMas[] = {100, 755, 30, 4500, 50};

int ledState[] = {LOW, LOW, LOW, LOW, LOW};
unsigned long previousMillis[] = {0, 0, 0, 0, 0};

void setup() {
  for (int ledN = 0; ledN < 5; ledN++)
  {
    pinMode(ledMas[ledN], OUTPUT);
  }
}

void loop() {
  for (int ledN = 0; ledN < 5; ledN++)
  {
    unsigned long currentMillis = micros();
    if (currentMillis - previousMillis[ledN] >= intervalMas[ledN]) {
      previousMillis[ledN] = currentMillis;

      if (ledState[ledN] == LOW) {
        ledState[ledN] = HIGH;
      } 
      else {
        ledState[ledN] = LOW;
      }
       digitalWrite(ledMas[ledN], ledState[ledN]);
    }
  }
}
