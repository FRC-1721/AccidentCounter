/**
 * @file main.cpp
 * @author Joe
 * @brief Source code for Tidal Force's "Days Worked Without Incident" counter.
 */

#include "Arduino.h"

void setup()
{
    // Setup serial
    delay(200);
    Serial.begin(115200);
    Serial.println(MOTD);
}

void loop()
{
    ;
}
