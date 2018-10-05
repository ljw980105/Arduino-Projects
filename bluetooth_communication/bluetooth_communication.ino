#include <Arduino.h>
#include <SoftwareSerial.h>

#define ledpin 5
#define txPin 11
#define rxPin 10

int state = 1;

SoftwareSerial mySerial(rxPin, txPin);

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
  Serial.println("begun");
  mySerial.begin(9600);
  digitalWrite(ledpin, state);
}

void loop() {
  // Feed all data from termial to bluetooth
  if (Serial.available()) {
      Serial.println("serial is working");
      mySerial.println(Serial.read()); 
      toggle();
    }

  // Feed any data from bluetooth to Terminal.
  if (mySerial.available()) {
    char data = mySerial.read();
    Serial.println("Blutooth -> terminal" + data);
    toggle();
    if (data > 0) {
      Serial.println(" data is read");
    }
  }
}

void toggle() {
  // set the LED pin using the pinState variable:
  digitalWrite(ledpin, state);
  // if pinState = 0, set it to 1, and vice versa:
  state = !state;
}
