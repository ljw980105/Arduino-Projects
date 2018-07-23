#include <Arduino.h>

#define led 6
#define ballSwitch 7

void setup() {
    pinMode(ballSwitch, INPUT);
    pinMode(led, OUTPUT);
    digitalWrite(led, HIGH);
}

void loop() {
    int readValue = digitalRead(ballSwitch);
    if (readValue == HIGH){
        digitalWrite(led,LOW);
    } else {
        digitalWrite(led,HIGH);
    }
}