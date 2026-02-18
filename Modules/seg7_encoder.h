// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef SEG7_ENCODER_INCLOUDED
#define SEG7_ENCODER_INCLOUDED

#include <stdint.h>

#include "utility_bit.h"
#include "seg7_font.h"

void Seg7_Encode4Digits_U16(uint16_t number, uint8_t *seg);
void Seg7_Encode3Digits_U16(uint16_t number, uint8_t *seg);
void Seg7_Encode2Digits_U8(uint8_t number, uint8_t *seg);
void Seg7_Reverse4Bytes(uint8_t *seg);

#endif
