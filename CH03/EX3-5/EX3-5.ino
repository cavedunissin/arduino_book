#include <Stepper.h>
#define STEPS 2048
Stepper stepper(STEPS, 8, 9, 10, 11);

void setup() {
  stepper.setSpeed(5);
}

void loop() {
  stepper.step(2048);
  delay(100);
  stepper.step(-2048);
  delay(100);
}

