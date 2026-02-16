// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef SEG7_1DIGIT_ENCODER_INCLOUDED
#define SEG7_1DIGIT_ENCODER_INCLOUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

uint8_t Seg7_1Digit_EncodeDigit(uint8_t digit);
void    Seg7_1Digit_EncodeDigit_ByRef(uint8_t digit,  uint8_t *seg);

uint8_t Seg7_1Digit_EncodeAlpha(uint8_t index);
void    Seg7_1Digit_EncodeAlpha_ByRef(uint8_t index,  uint8_t *seg);

uint8_t Seg7_1Digit_EncodeSymbol(uint8_t index);
void    Seg7_1Digit_EncodeSymbol_ByRef(uint8_t index,  uint8_t *seg);

uint8_t Seg7_1Digit_ToggleSegments(uint8_t seg);
void    Seg7_1Digit_ToggleSegments_ByRef(uint8_t *seg);

#ifdef __cplusplus
}
#endif

#endif
