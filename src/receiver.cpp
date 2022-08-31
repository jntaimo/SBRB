#include <RF24.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE 9
#define CSN 10

RF24 radio1(CE, CSN);

const byte address[6] = "00001";

void receiverSetup() {
  radio1.begin();
  radio1.openReadingPipe(0, address);
  radio1.setPALevel(RF24_PA_MIN);
  radio1.startListening();
}

void receiverLoop() {
    //Serial.println("Supposed to be receiving something!");
    if (radio1.available()){
        char text[32] = "";
        radio1.read(&text, sizeof(text));
        Serial.println(text);
    }
}