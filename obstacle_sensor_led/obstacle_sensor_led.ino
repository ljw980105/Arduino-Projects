#include <Arduino.h>

#define ledPin 5
#define obstaclePin 8

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(obstaclePin, INPUT);
}

void loop() {
    if (digitalRead(obstaclePin) == LOW) {
        // light surface
        digitalWrite(ledPin, HIGH);
    } else {
        // dark surface
        digitalWrite(ledPin, LOW);
    }
}