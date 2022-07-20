/**
 * @file main.cpp
 * @author Joe
 * @brief Source code for Tidal Force's "Days Worked Without Incident" counter.
 */

// Libs
#include "Arduino.h"

// Headers
#include "boardPins.h"

// Libs
#include "display.h"

Display display(1, LATCH_PIN, CLOCK_PIN, DATA_PIN);

void setup()
{
    // Setup serial
    delay(200);
    Serial.begin(115200);
    Serial.println(MOTD);

    // Pins
    pinMode(STAT_LED, OUTPUT);
    pinMode(LATCH_PIN, OUTPUT);
    pinMode(CLOCK_PIN, OUTPUT);
    pinMode(DATA_PIN, OUTPUT);
}

byte num = 0;

void loop()
{
    digitalWrite(STAT_LED, HIGH);
    delay(500);
    digitalWrite(STAT_LED, LOW);
    delay(500);

    display.setNum(num);

    num++;
    if (num > 10)
    {
        num = 0;
    }
}
