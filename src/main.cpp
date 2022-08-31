#include <Arduino.h>
#include "encoders.h"
#include "drippyimu.h"
//Delay in milliseconds
long loopDelay = 20;
long prevLoopTime = 0;

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
  if (millis() > prevLoopTime + loopDelay){
    prevLoopTime = millis();
    Serial.printf("X: %f, Y: %f, Z: %f\n", x, y, z);
  }
  
}
