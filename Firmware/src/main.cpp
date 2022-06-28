/**
 * @file main.cpp
 * @author Joe
 * @brief Todo!
 * @date 2022-06-28
 *
 * @copyright Copyright (c) 2022
 *
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
