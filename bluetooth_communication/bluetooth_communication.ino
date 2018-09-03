#include <Arduino.h>
#include <SoftwareSerial.h>

#define ledpin 5
#define txPin 1
#define rxPin 0

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
  //    if (Serial.available()) {
  //        state = Serial.read();
  //        Serial.println(state);
  //        toggle();
  //    }

  // Feed all data from termial to bluetooth
  if (Serial.available())
    mySerial.println(Serial.read());

  // Feed any data from bluetooth to Terminal.
  if (mySerial.available()) {
    int data = mySerial.read();
    Serial.print(data);
    if (data > 0) {
      Serial.println(" data is read");
    }
  }
  delay(1000);
  toggle();
}

void toggle() {
  // set the LED pin using the pinState variable:
  digitalWrite(ledpin, state);
  // if pinState = 0, set it to 1, and vice versa:
  state = !state;
}
