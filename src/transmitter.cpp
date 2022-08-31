#include <RF24.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE 9
#define CSN 10

RF24 radio(CE, CSN);

const byte address[6] = "00001";

void transmitterSetup() {
    Serial.println("Starting Transmitter!");
    radio.begin();
    radio.openWritingPipe(address);
    radio.setPALevel(RF24_PA_MIN);
    radio.stopListening();
}

void transmitterLoop() {
    const char text[] = "Hello World!";
    radio.write(&text, sizeof(text));
    Serial.println("Sending message");
    delay(1000);
}