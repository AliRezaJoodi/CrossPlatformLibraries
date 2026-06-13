// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef AJ_SEG7_FONT_INCLUDED
#define AJ_SEG7_FONT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define AJ_SEG7_FONT_DIGIT_SIZE    10U
#define AJ_SEG7_FONT_ALPHA_SIZE    11U
#define AJ_SEG7_FONT_SYMBOL_SIZE   3U

extern const uint8_t aj_seg7_font_digit[AJ_SEG7_FONT_DIGIT_SIZE];
extern const uint8_t aj_seg7_font_alpha[AJ_SEG7_FONT_ALPHA_SIZE];
extern const uint8_t aj_seg7_font_symbol[AJ_SEG7_FONT_SYMBOL_SIZE];

#ifdef __cplusplus
}
#endif

#endif
