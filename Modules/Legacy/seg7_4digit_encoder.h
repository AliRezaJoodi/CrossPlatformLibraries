// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef SEG7_4DIGIT_ENCODER_INCLOUDED
#define SEG7_4DIGIT_ENCODER_INCLOUDED

#include <stdint.h>

#include "seg7_font.h"

void Seg7_4Digit_EncodeFloat_2DP(float value, uint8_t *seg);
uint8_t Seg7_4Digit_EncodeFloat_1DP(float value, uint8_t *seg);
void    Seg7_4Digit_ToggleSegments(uint8_t *seg);

#endif
