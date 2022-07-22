/**
 * @file stat.h
 * @author Joe
 * @brief Simple methods for the stat LED
 *
 */

#include <Arduino.h>

bool lastBlink = false;

void blink(uint8_t statLED)
{
    digitalWrite(STAT_LED, lastBlink);
    lastBlink = !lastBlink;
}
