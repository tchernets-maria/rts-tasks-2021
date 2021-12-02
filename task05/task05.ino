#include <AccelStepper.h>

#define stepPin_1 (2)
#define dirPin_1 (5)
          
#define stepPin_2 (3)
#define dirPin_2 (6)

AccelStepper stepper1(1, stepPin_1, dirPin_1);
AccelStepper stepper2(1, stepPin_2, dirPin_2);
 
void setup() {
  stepper1.setMaxSpeed(500.0);
  stepper1.setSpeed(25.0);
 
  stepper2.setMaxSpeed(400.0);
  stepper2.setSpeed(80.0);
}
 
void loop() {
  stepper1.runSpeed();
  stepper2.runSpeed();
}
