int stepPin[] = {2, 3};
int dirPin[] ={5, 6};
int enablePin[] ={8, 9};
unsigned long intervalClockwise[] = {200, 300};
unsigned long intervalCounterClockwise[] = {400, 300};

int State1[] = {LOW, LOW};
int State2[] = {LOW, LOW};
unsigned long previousMillis1[] = {0, 0};
unsigned long previousMillis2[] = {0, 0};

void setup() {
  for (int N = 0; N < 2; N++)
  {
    pinMode(stepPin[N], OUTPUT);
    pinMode(dirPin[N], OUTPUT);
    pinMode(enablePin[N], OUTPUT);
  }
}

void loop() {
  for (int N = 0; N < 2; N++)
  {
    digitalWrite(enablePin[N], LOW);
    digitalWrite(dirPin[N], HIGH);
    unsigned long currentMillis1 = micros();
    unsigned long currentMillis2 = micros();
    if (currentMillis1 - previousMillis1[N] >= intervalClockwise[N]) {
      previousMillis1[N] = currentMillis1;

      if (State1[N] == LOW) {
        State1[N] = HIGH;
      } 
      else {
        State1[N] = LOW;
      }
       digitalWrite(stepPin[N], State1[N]);
       delayMicroseconds(25);
    }

    digitalWrite(dirPin[N], LOW);
    if (currentMillis2 - previousMillis2[N] >= intervalCounterClockwise[N]) {
      previousMillis2[N] = currentMillis2;

      if (State2[N] == LOW) {
        State2[N] = HIGH;
      } 
      else {
        State2[N] = LOW;
      }
       digitalWrite(stepPin[N], State2[N]);
       delayMicroseconds(1000);
    }
    digitalWrite(enablePin[N], HIGH);
  }
}
