# Arduino Projects 
Personal Arduino Projects, Coded in JetBrains CLion w/ Arduino Plugin

## Contents
* Random Color:
    * Uses a **RGB LED** and the random() function to randomly generate colors in a 1s interval.
* Frequency Decreaser
    * Uses a pushbutton to decrease the frequency of sound made by the **buzzer**.
* Passive Buzzer
    * Produces musical notes with **the passive buzzer**, along with two leds to indicate progress
* Ultrasonic Distance Indicator
    * Uses a **ultrasonic sensor** to drive 3 LEDs that indicate distances as close, medium and far
* Humidity & Temperature w/ LCD
    * Uses a **DHT11 Humidity Sensor** and a **LCD Display** read the humidity/temperature of the surrounding environment & print them to the LCD.
* Obstacle Detector with LED
    * Makes use of an **IR Sensor** to show whether an obstacle is present.
* Turn-on / off LED with HC-08 Bluetooth Module
    * Makes use of an **HC-08 Bluetooth Module** to turn LEDs on/off.

## Getting the HC08 Bluetooth Moule Working
* Make sure HC08 TX -> Arduino RX & HC08 RX -> Arduino TX.
* Make sure the power src supplies enough voltage (A power supply module may not supply enough voltage)
* Use separate pins for RX and TX, do not use pin 0 and 1 on the Arduino.