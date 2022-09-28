#include <RF24.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE 9
#define CSN 10
#define VRX 3
#define VRY 4
struct Orientation
{
  float pitch;
  float yaw; 
};

struct Desired_Orientation
{
  float pitch;
  float yaw; 
};

RF24 radio(CE, CSN);

const byte address[6] = "00001";

void controllerSetup() {
    Serial.println("Starting Transmitter!");
    pinMode(VRX, INPUT);
    pinMode(VRY, INPUT);
    radio.begin();
    radio.openWritingPipe(address);
    radio.setPALevel(RF24_PA_MIN);
    radio.stopListening();
}

void controllerLoop() {
    Desired_Orientation msg= {0.0, 0.0};
    msg.pitch = analogRead(VRX);
    msg.yaw = analogRead(VRY);
    Serial.println("-----");
    Serial.println(msg.pitch);
    Serial.println(msg.yaw);
    
    radio.write(&msg, sizeof(msg));
    delay(500);
}