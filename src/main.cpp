#include <Arduino.h>
#include "encoders.h"
#include "drippyimu.h"
#include "transmitter.h"
//#include "receiver.h"
//Delay in milliseconds
long loopDelay = 20;
long prevLoopTime = 0;
float yaw, pitch, roll;

//motor controller pins
#define DIR1 2
#define PWM1 3
#define DIR2 4
#define PWM2 5 

void setup() {
  //Configure motor pins as outputs
  // pinMode(DIR1, OUTPUT);
  // pinMode(DIR2, OUTPUT);
  // pinMode(PWM1, OUTPUT);
  // pinMode(PWM2, OUTPUT);
  Serial.println("starting");
  encoderSetup();
  imuSetup();
  transmitterSetup();
  //receiverSetup();
}



void loop() {
  //encoderLoop();
  transmitterLoop();
  //receiverLoop();
  // readGyro(yaw, pitch, roll);
  // if (millis() > prevLoopTime + loopDelay){
  //   prevLoopTime = millis();
  //   Serial.printf("Yaw: %.5f, Pitch: %.5f, Roll: %.5f\n", yaw, pitch, roll);
  // }
  // digitalWrite(DIR1, HIGH);
  // digitalWrite(DIR2, HIGH);
  // analogWrite(PWM1, 100);
  // analogWrite(PWM2, 100);

  // delay(500);

  // digitalWrite(DIR1, LOW);
  // digitalWrite(DIR2, LOW);
  // analogWrite(PWM1, 230);
  // analogWrite(PWM2, 230);  

  // delay(500);

}
