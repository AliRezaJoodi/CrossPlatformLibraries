// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "seg7_font.h"

const uint8_t seg7_font_digit[SEG7_FONT_DIGIT_SIZE]={
    0x3FU,      // 0
    0x06U,      // 1
    0x5BU,      // 2
    0x4FU,      // 3
    0x66U,      // 4
    0x6DU,      // 5
    0x7DU,      // 6
    0x07U,      // 7
    0x7FU,      // 8
    0x6FU       // 9
 };

const uint8_t seg7_font_alpha[SEG7_FONT_ALPHA_SIZE]={
    0x77U,      // 0,   A
    0x7CU,      // 1,   b
    0x39U,      // 2,   C
    0x5EU,      // 3,   d
    0x79U,      // 4,   E
    0x71U,      // 5,   F
    0x76U,      // 6,   H
    0x38U,      // 7,   L
    0x50U,      // 8,   r
    0x78U,      // 9,   t
    0x3EU       // 10,  U
};

const uint8_t seg7_font_symbol[SEG7_FONT_SYMBOL_SIZE] = {
    0x00U,      // 0,   NULL
    0x40U,      // 1,   -
    0x80U       // .,   dp
};

