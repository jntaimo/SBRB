#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>
#include "encoders.h"

//Encoder pulses per revolution for 312 RPM Bilda motor
#define PPR 751.8
//Pinouts for wiring
#define encLPinA 20
#define encLPinB 21
#define encRPinA 22
#define encRPinB 23

//Left Encoder Variables
long currentLPos = 0;
long prevLPos = 0;
long currentLTime = 0;
long prevLTime = 0;
float radL = 0;

//Right Encoder Variables
long currentRPos = 0;
long prevRPos = 0;
long currentRTime = 0;
long prevRTime = 0;
float radR = 0;

//Smoothing constant for filtering
//alpha closer to 0 is closer to raw data, very fast
//alpha closer to 1 is more smooth, but more sluggish
float alpha = 0.1;
float filtRadL = 0;
float filtRadR = 0;

Encoder encL(encLPinA, encLPinB);
Encoder encR(encRPinA, encRPinB);

long prevTime = 0;
long delayTime = 25;


void encoderSetup() {
  Serial.begin(115200);
}


void encoderLoop() {
  readEncoders();

  //Only print data if the current time is more than 25 ms greater than the last time it was printed
  if(millis() > prevTime + delayTime){
    //Print the current rotation speed
     prevTime = millis();
    // Serial.print(radL);
    // Serial.print("\t");
    // Serial.print(filtRadL);
    // Serial.print("\t");
    // Serial.print(radR);
    // Serial.print("\t");
    // Serial.println(filtRadR);
    //Print the current position
    Serial.print(currentLPos);
    Serial.print("\t");
    Serial.println(currentRPos);
  }

}

void readEncoders(){
  //update left encoder
  currentLPos = encL.read();
  currentLTime = micros();
  radL = float(currentLPos-prevLPos)*2*PI/(PPR*(currentLTime - prevLTime))*1e6;
  prevLPos = currentLPos; 
  prevLTime = currentLTime; 

  //update right encoder
  currentRPos = encR.read();
  currentRTime = micros();
  radR = float(currentRPos-prevRPos)*2*PI/(PPR*(currentRTime - prevRTime))*1e6;
  prevRPos = currentRPos; 
  prevRTime = currentRTime;  

  //filter values to smooth noise
  filtRadL = alpha*radL + (1-alpha)*filtRadL;
  filtRadR = alpha*radR + (1-alpha)*filtRadR;  

}