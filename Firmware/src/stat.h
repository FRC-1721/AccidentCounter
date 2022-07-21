/**
 * @file stat.h
 * @author Joe
 * @brief Simple methods for the stat LED
 *
 */

#include <Arduino.h>

enum BlinkState
{
    START,
    RUN,
    ERR
};
BlinkState curState = START;

void blink(uint8_t statLED, uint8_t numBlips)
{
    for (uint8_t i = 0; i < numBlips; i++)
    {
        digitalWrite(STAT_LED, HIGH);
        delay(25);
        digitalWrite(STAT_LED, LOW);

        if (numBlips == 1)
        {
            break;
        }
        else
        {
            delay(150);
        }
    }
}

void statBlink()
{
    switch (curState)
    {
    case START:
        blink(STAT_LED, 2);
        break;
    case RUN:
        blink(STAT_LED, 1);
        break;
    case ERR:
        blink(STAT_LED, 5);
        break;

    default:
        break;
    }
}
