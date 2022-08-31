#include <Arduino.h>
#include "encoders.h"
#include "drippyimu.h"

void setup() {
  //Configure motor pins as outputs
  Serial.begin(115200);
  Serial.println("starting");
  encoderSetup();
  imuSetup();
}



void loop() {
  //encoderLoop();
  float x, y, z;
  readGyro(x, y, z);
  Serial.printf("X: %f, Y: %f, Z: %f", x, y, z);
}
