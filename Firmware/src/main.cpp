/**
 * @file main.cpp
 * @author Joe
 * @brief Source code for Tidal Force's "Days Worked Without Incident" counter.
 */

// Libs
#include <Arduino.h>
#include <Wire.h>
#include <RTClib.h>

// Headers
#include "boardPins.h"

// Libs
#include "display.h"

// Objects
Display display(3, LATCH_PIN, CLOCK_PIN, DATA_PIN);
RTC_DS1307 rtc;

// Global Vars
uint16_t currentDay = 0;

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

    // Setup RTC
    rtc.begin();
}

void loop()
{
    digitalWrite(STAT_LED, HIGH);
    delay(500);
    digitalWrite(STAT_LED, LOW);
    delay(500);

    display.setNum(currentDay);

    DateTime now = rtc.now();

    Serial.println(now.unixtime());
}

void serialEvent()
{
    while (Serial.available())
    {
        currentDay = Serial.parseInt();
        rtc.adjust(DateTime(SECONDS_PER_DAY * currentDay));
    }
}
