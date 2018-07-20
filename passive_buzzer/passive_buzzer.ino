#include <Arduino.h>
#include "pitches.h"

#define buzzer 13
#define led 7
#define led2 6

unsigned int melody[] = { NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};
unsigned int duration = 500;
unsigned int wait = 1000;

void setup() {
    Serial.begin(9600);
    pinMode(led,OUTPUT);
    pinMode(led2,OUTPUT);
}

int status = 1;

void loop() {
    for (int note = 0; note < 8; ++note) {
        tone(buzzer ,melody[note],duration);
        Serial.print(note);
        delay(wait);

        if (status){
            status = 0;
            digitalWrite(led,LOW);
            digitalWrite(led2,HIGH);
        } else {
            status = 1;
            digitalWrite(led,HIGH);
            digitalWrite(led2,LOW);
        }
    }
}