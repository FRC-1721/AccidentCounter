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
    const uint8_t segChars[37] = {
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
        0b1110111, // A
        0b0011111, // b
        0b1001110, // C
        0b0111101, // d
        0b1001111, // E
        0b1000111, // F
        0b1011110, // G
        0b0010111, // h
        0b0000110, // i
        0b0111100, // j
        0b1010111, // k
        0b0001110, // L
        0b1010100, // M
        0b1110110, // N
        0b1111110, // O
        0b1100111, // p
        0b1110011, // q
        0b0000101, // r
        0b1011011, // s
        0b0001111, // t
        0b0111110, // U
        0b0111010, // V
        0b0101010, // W
        0b0110111, // X
        0b0111011, // Y
        0b1101001, // Z
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
