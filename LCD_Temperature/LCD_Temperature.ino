#include <Arduino.h>
#include <LiquidCrystal.h>
#include <SimpleDHT.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int pinDHT11 = 2;
SimpleDHT11 dht11;

void setup() {
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("Hello, World!");
    Serial.begin(9600);
}

void loop() {
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 0);
    lcd.clear();

    byte temperature = 0;
    byte humidity = 0;
    byte data[40] = {0};
    if (dht11.read(pinDHT11, &temperature, &humidity, data)) {
        lcd.print("Read DHT11 failed");
        return;
    }

    lcd.print("Temp: " + String((int)temperature) + "*C");
    lcd.setCursor(0, 1);
    lcd.print("Hum: " + String((int)humidity) + "%");

    // DHT11 sampling rate is 1HZ.
    delay(1000);
}
