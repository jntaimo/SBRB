#include <RF24.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE 9
#define CSN 10


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

RF24 radio1(CE, CSN);

const byte address[6] = "00001";

void robotReceiverSetup() {
  radio1.begin();
  radio1.openReadingPipe(0, address);
  radio1.setPALevel(RF24_PA_MIN);
  radio1.startListening();
}

void robotReceiverLoop() {
    //Serial.println("Supposed to be receiving something!");
    // If it doesn't sense any messages from remote in a certain time, then resets to 0 set point (stands upright)
    
    // If there are messages to be read, then 
    if (radio1.available()){
        //char text[32] = "";
        Desired_Orientation msg;
        radio1.read(&msg, sizeof(msg));
        Serial.println(msg.pitch);
        Serial.println(msg.yaw);
    }
}