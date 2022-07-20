/**
 * @file display.cpp
 * @author Joe
 * @brief Prototypes and structures for the shift register based segment display.
 */

#include <Arduino.h>
#include "display.h"

Display::Display(uint8_t _NUM_SEGMENTS, uint8_t _LATCH_PIN, uint8_t _CLOCK_PIN, uint8_t _DATA_PIN) : NUM_SEGMENTS(_NUM_SEGMENTS), latchPin(_LATCH_PIN), clockPin(_CLOCK_PIN), dataPin(_DATA_PIN)
{
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
};

void Display::setNum(uint16_t num)
{
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, segChars[num]);
    digitalWrite(latchPin, HIGH);
};
