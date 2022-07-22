/**
 * @file display.h
 * @author Joe
 * @brief Prototypes and structures for the shift register based segment display.
 */

#include <Arduino.h>

class Display
{
private:
    // Pins
    uint8_t latchPin;
    uint8_t clockPin;
    uint8_t dataPin;

    // Settings
    uint8_t numSegments;

    /** 0b1000000, // G
     *  0b0100000, // F
     *  0b0010000, // E
     *  0b0001000, // D
     *  0b0000100, // C
     *  0b0000010, // B
     *  0b0000001, // A
     */

    // Characters
    const uint8_t segChars[13] = {
        0b0111111, // 0
        0b0000110, // 1
        0b1011011, // 2
        0b1001111, // 3
        0b1100110, // 4
        0b1101101, // 5
        0b1111101, // 6
        0b0000111, // 7
        0b1111111, // 8
        0b1101111, // 9
        0b0000000, // null
        0b1111001, // E
        0b1010000, // r
    };

    /**
     * @brief Returns the n'th digit of a base 10 number
     *
     * @param val A base 10 value
     * @param n What power to extract, eg 0 for `1` in `1234`. and 2 for `3` in `1234`
     * @return uint16_t
     */
    int16_t Display::nth_digit(int16_t val, int16_t n);
    uint32_t pow[5] = {1, 10, 100, 1000, 10000};

public:
    /**
     * @brief Construct a new display object
     *
     * @param _NUM_SEGMENTS  Number of segments in the chain
     * @param _LATCH_PIN     Latch pin
     * @param _CLOCK_PIN     Clock pin
     * @param _DATA_PIN      Data pin
     */
    Display(uint8_t _NUM_SEGMENTS, uint8_t _LATCH_PIN, uint8_t _CLOCK_PIN, uint8_t _DATA_PIN);

    /**
     * @brief Displays an err message on the screen
     *
     */
    void setErr();

    /**
     * @brief Set the number being displayed
     *
     * @param num A number with no more digits than numSegments
     */
    void setNum(uint16_t num);

    /**
     * @brief Clears the screen
     *
     */
    void clear();
};
