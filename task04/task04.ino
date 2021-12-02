#include <TaskManagerIO.h>

#define stepPin_1 (2)
#define stepPin_2 (3)
#define dirPin_1 (5)
#define dirPin_2 (6)
#define enablePin_1 (8)
#define enablePin_2 (9)

int State1_1 = LOW;
int State1_2 = LOW;
int State2_1 = LOW;
int State2_2 = LOW;

void setup() {
  pinMode(stepPin_1, OUTPUT);
  pinMode(dirPin_1, OUTPUT);
  pinMode(enablePin_1, OUTPUT);
  pinMode(stepPin_2, OUTPUT);
  pinMode(dirPin_2, OUTPUT);
  pinMode(enablePin_2, OUTPUT);

  taskManager.scheduleFixedRate(200, [] {
        StepperMotor(State1_1, State1_2, stepPin_1, dirPin_1, enablePin_1);
        });

  taskManager.scheduleFixedRate(400, [] {
        StepperMotor(State2_1, State2_2, stepPin_2, dirPin_2, enablePin_2);
        });
}

void loop() {
  taskManager.runLoop();
}

void StepperMotor(int State1, int State2, int stepPort, int dirPort, int enablePin)
{
  Rotate(enablePin, LOW);
  Rotate(dirPort, HIGH);
  if (State1 == LOW) {
    State1 = HIGH;
  } 
  else {
    State1 = LOW;
  }
  digitalWrite(stepPort, State1);
  delayMicroseconds(25);
  
  Rotate(dirPort, LOW);
  if (State2 == LOW) {
    State2 = HIGH;
  } 
  else {
    State2 = LOW;
  }
  digitalWrite(stepPort, State2);
  delayMicroseconds(1000);
  Rotate(enablePin, HIGH);
}

void Rotate(int State, int port)
{
  digitalWrite(port, State);
}
