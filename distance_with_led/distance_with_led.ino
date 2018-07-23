#include <Arduino.h>
#include "SR04.h"

#define TRIG_PIN 12
#define ECHO_PIN 11
#define REDLED 5
#define YELOWLED 6
#define GREENLED 7

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);

long a;

void setup() {
    Serial.begin(9600);
    delay(1000);
    pinMode(REDLED,OUTPUT);
    pinMode(YELOWLED,OUTPUT);
    pinMode(GREENLED,OUTPUT);
}

void loop() {
    a = sr04.Distance();
    Serial.print(a);
    Serial.println("cm");

    long low = 20;
    long med = 50;

    if (a < low) {
        digitalWrite(REDLED, HIGH);
        digitalWrite(YELOWLED, LOW);
        digitalWrite(GREENLED, LOW);
        Serial.println("red");
    } else if (a < med){
        digitalWrite(REDLED, LOW);
        digitalWrite(YELOWLED, HIGH);
        digitalWrite(GREENLED, LOW);
        Serial.println("yellow");
    } else {
        digitalWrite(REDLED, LOW);
        digitalWrite(YELOWLED, LOW);
        digitalWrite(GREENLED, HIGH);
        Serial.println("green");
    }

    delay(500);
}
