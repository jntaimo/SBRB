#include <RF24.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE 7
#define CSN 8

RF24 radio(CE, CSN);

const byte address[6] = "00001";

void receiverSetup() {
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void receiverLoop() {
    if (radio.available()){
        char text[32] = "";
        radio.read(&text, sizeof(text));
        Serial.println(text);
    }
}