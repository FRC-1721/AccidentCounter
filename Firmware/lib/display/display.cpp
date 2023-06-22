/**
 * @file display.cpp
 * @author Joe
 * @brief Prototypes and structures for the shift register based segment display.
 */

#include <Arduino.h>
#include "display.h"

Display::Display(uint8_t _NUM_SEGMENTS, uint8_t _LATCH_PIN, uint8_t _CLOCK_PIN, uint8_t _DATA_PIN) : numSegments(_NUM_SEGMENTS), latchPin(_LATCH_PIN), clockPin(_CLOCK_PIN), dataPin(_DATA_PIN)
{
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);

    // Clear display
    clear();
};

void Display::setNum(uint16_t num)
{
    digitalWrite(latchPin, LOW); // Set latch low (stop displaying digits)

    uint8_t segmentArray[numSegments]; // A temporary array to hold all our segment numbers before shifting them out

    // For every segment
    for (uint8_t i = 0; i < numSegments; i++)
    {
        segmentArray[numSegments - i - 1] = nth_digit(num, i); // Grab the current digit at some base 10 spot (1s, 10s, 100s etc) and store it
    }

    // Special cases!
    // ==============

    // If any other number except the first one is a 0, draw it as a blank
    for (uint8_t i = 0; i < numSegments - 1; i++)
    {
        if (segmentArray[i] == 0)
        {                         // Check if 0
            segmentArray[i] = 10; // Blank
        }
        else
        {
            break; // Stop when we find a real number!
        }
    }

    // ==============

    // For every segment
    for (uint8_t i = 0; i < numSegments; i++)
    {
        shiftOut(dataPin, clockPin, MSBFIRST, segChars[segmentArray[i]]); // Write every segment out
    }

    digitalWrite(latchPin, HIGH); // Display it
};

void Display::setErr()
{
    uint8_t errText[3] = {segChars[11], segChars[12], segChars[12]};

    digitalWrite(latchPin, LOW); // Set latch low (stop displaying digits)

    // For every segment
    for (uint8_t i = 0; (i < sizeof(errText) / sizeof(uint8_t)) && i < numSegments; i++)
    {
        shiftOut(dataPin, clockPin, MSBFIRST, errText[i]); // Write every segment out
    }

    digitalWrite(latchPin, HIGH); // Display it
};

int16_t Display::nth_digit(int16_t val, int16_t n)
{
    // A little messy
    return val / pow[n] % 10;
};

void Display::clear()
{
    for (uint8_t i = 0; i < numSegments; i++)
    {
        setNum(10);
    }
};
