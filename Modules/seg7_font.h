// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef SEG7_FONT_INCLUDED
#define SEG7_FONT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define SEG7_FONT_DIGIT_SIZE    10
#define SEG7_FONT_ALPHA_SIZE    11
#define SEG7_FONT_SYMBOL_SIZE   2

extern const uint8_t seg7_font_digit[SEG7_FONT_DIGIT_SIZE];
extern const uint8_t seg7_font_alpha[SEG7_FONT_ALPHA_SIZE];
extern const uint8_t seg7_font_symbol[SEG7_FONT_SYMBOL_SIZE];

#ifdef __cplusplus
}
#endif

#endif
