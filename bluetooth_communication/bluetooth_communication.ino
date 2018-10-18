#include <Arduino.h>
#include <SoftwareSerial.h>

#define ledpin 5
#define txPin 11
#define rxPin 10

int state = 1;

SoftwareSerial mySerial(rxPin, txPin);

void toggle();
void sendCommand();

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
  Serial.println("begun");
  mySerial.begin(9600);
  digitalWrite(ledpin, state);

  sendCommand("AT");
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
    Serial.print("Blutooth -> terminal ");
    Serial.println(data);
    toggle();
    if (data > 0) {
      Serial.println(" data is read");
    }
    if (data == 'F') {
      Serial.print("Received Data F");
    }
  }
}

void sendCommand(const char * command) {
    Serial.print("Command send :");
    Serial.println(command);
    mySerial.println(command);

    delay(100);
    char reply[100];
    int i = 0;
    while(mySerial.available()) {
        reply[i] = mySerial.read();
        i += 1;
    }

    reply[i] = '\0';
    Serial.println(reply);
    Serial.println("Reply ended");
}

void toggle() {
  // set the LED pin using the pinState variable:
  digitalWrite(ledpin, state);
  // if pinState = 0, set it to 1, and vice versa:
  state = !state;
}
