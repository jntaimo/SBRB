#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>


#define DIR1 15
#define PWM1 2
#define DIR2 4
#define PWM2 5
#define PPR 751.8


//Encoder Variables
long currentLPos = 0;
long prevLPos = 0;
long currentLTime = 0;
long prevLTime = 0;
float radL = 0;

Encoder encL(40, 41);

void readEncoders();
void setup() {
  //Configure motor pins as outputs
  pinMode(DIR1, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(DIR2, OUTPUT);
  pinMode(PWM2, OUTPUT);
  
  Serial.begin(115200);
}



void loop() {
  //GO forward
  digitalWrite(DIR1, HIGH);
  digitalWrite(DIR2, LOW);
  analogWrite(PWM1, 255);
  analogWrite(PWM2, 0);
  readEncoders();
  Serial.println(radL);
  delay(2);
}

void readEncoders(){
  currentLPos = encL.read();
  currentLTime = micros();
  radL = float(currentLPos-prevLPos)*2*PI/(PPR*(currentLTime - prevLTime))*1e6;
  prevLPos = currentLPos; 
  prevLTime = currentLTime; 
}