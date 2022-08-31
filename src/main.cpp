#include <Arduino.h>
#include "encoders.h"
#include "drippyimu.h"

void setup() {
  //Configure motor pins as outputs
  encoderSetup();
}



void loop() {
  encoderLoop();
}
