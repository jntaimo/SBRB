#include <Arduino.h>
#include "encoders.h"

void setup() {
  //Configure motor pins as outputs
  encoderSetup();
}



void loop() {
  encoderLoop();
}
