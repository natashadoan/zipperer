//code for the stepper motor to be used with a slider (DPDT 3-position mech slider specifically)
#include <Stepper.h>

#define STEPS_PER_REV 2048
#define SWITCH_LEFT   2   // when in left pos, low
#define SWITCH_RIGHT  3   // when in right pos, low

// motor to pins 10, 8, 9, 7
Stepper stepper(STEPS_PER_REV, 10, 8, 9, 7);

const int STEP_SIZE = STEPS_PER_REV / 100;

void setup() {
  pinMode(SWITCH_LEFT, INPUT_PULLUP);
  pinMode(SWITCH_RIGHT, INPUT_PULLUP);

  stepper.setSpeed(15); // rpm
}

void loop() {
  bool isLeft  = digitalRead(SWITCH_LEFT)  == LOW;
  bool isRight = digitalRead(SWITCH_RIGHT) == LOW;

  if (isLeft && !isRight) {
    stepper.step(-STEP_SIZE); // ccw when left
  }
  else if (isRight && !isLeft) {
    stepper.step(STEP_SIZE);  // cw when right
  }
  else {
    delay(5); // mid nothing
  }
}

