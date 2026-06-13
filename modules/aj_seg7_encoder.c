// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "aj_bit_u8.h"
#include "aj_seg7_encoder.h"

// Double Dabble (8-bit to 2 digits)
/****************************************************/
uint8_t AJ_Seg7_EncodeNumber_2Digits(uint8_t *seg, uint8_t number){
    uint8_t i = 0;
    uint8_t carry = 0;
    uint8_t bcd[2] = {0};

    if (number > 99){
        seg[0] = AJ_SEG7_ENCODER_INVALID;
        seg[1] = AJ_SEG7_ENCODER_INVALID;
        return AJ_SEG7_ENCODER_ERROR;
    }

    for (i = 0; i < 8; ++i){
        if (bcd[0] >= 5) { bcd[0] += 3; }
        if (bcd[1] >= 5) { bcd[1] += 3; }

        AJ_BitU8_WriteBit_Position(carry, 0, AJ_BitU8_GetBit_Position(bcd[1], 3));   // carry0
        AJ_BitU8_WriteBit_Position(carry, 1, AJ_BitU8_GetBit_Position(number, 7));   // carry1

        bcd[0] = ((bcd[0] << 1) & 0x0F) | AJ_BitU8_GetBit_Position(carry, 0);
        bcd[1] = ((bcd[1] << 1) & 0x0F) | AJ_BitU8_GetBit_Position(carry, 1);

        number <<= 1;
    }

    /* Convert BCD digits to 7-segment font */
    for (i = 0; i < 2; i++){
        seg[i] = aj_seg7_font_digit[bcd[1 - i] & 0x0F];
    }

    return AJ_SEG7_ENCODER_OK;
}

/****************************************************/
uint8_t AJ_Seg7_SetDecimalPoint_2Digits(uint8_t *seg, uint8_t position){
    if (position > 1U) {
        return AJ_SEG7_ENCODER_ERROR;   /* Invalid position */
    }

    seg[position] |= AJ_SEG7_ENCODER_DP;
    return AJ_SEG7_ENCODER_OK;       /* Success */
}

/* Reverse the order of 2-byte segment array (MSB <-> LSB) */
/****************************************************/
void AJ_Seg7_Reverse2Bytes(uint8_t *seg){
    uint8_t temp = 0;

    /* Swap seg[0] and seg[1] */
    temp = seg[0];
    seg[0] = seg[1];
    seg[1] = temp;
}

// Double Dabble (16-bit to 3 digits)
/****************************************************/
uint8_t AJ_Seg7_EncodeNumber_3Digits(uint8_t *seg, uint16_t number){
    uint8_t i = 0;
    uint8_t carry = 0;
    uint8_t bcd[3] = {0};

    if (number > 999){
        seg[0] = AJ_SEG7_ENCODER_INVALID;
        seg[1] = AJ_SEG7_ENCODER_INVALID;
        seg[2] = AJ_SEG7_ENCODER_INVALID;
        return AJ_SEG7_ENCODER_ERROR;
    }

    for (i = 0; i < 16; ++i){
        if (bcd[0] >= 5) { bcd[0] += 3; }
        if (bcd[1] >= 5) { bcd[1] += 3; }
        if (bcd[2] >= 5) { bcd[2] += 3; }

        AJ_BitU8_WriteBit_Position(carry, 0, AJ_BitU8_GetBit_Position(bcd[1], 3));   // carry0
        AJ_BitU8_WriteBit_Position(carry, 1, AJ_BitU8_GetBit_Position(bcd[2], 3));   // carry1
        AJ_BitU8_WriteBit_Position(carry, 2, AJ_BitU8_GetBit_Position(number, 15));  // carry2

        bcd[0] = ((bcd[0] << 1) & 0x0F) | AJ_BitU8_GetBit_Position(carry, 0);
        bcd[1] = ((bcd[1] << 1) & 0x0F) | AJ_BitU8_GetBit_Position(carry, 1);
        bcd[2] = ((bcd[2] << 1) & 0x0F) | AJ_BitU8_GetBit_Position(carry, 2);

        number <<= 1;
    }

    /* Convert BCD digits to 7-segment font */
    for (i = 0; i < 3; i++){
        seg[i] = aj_seg7_font_digit[bcd[2 - i] & 0x0F];
    }

    return AJ_SEG7_ENCODER_OK;
}

/****************************************************/
uint8_t AJ_Seg7_SetDecimalPoint_3Digits(uint8_t *seg, uint8_t position){
    if (position > 2U) {
        return AJ_SEG7_ENCODER_ERROR;   /* Invalid position */
    }

    seg[position] |= AJ_SEG7_ENCODER_DP;
    return AJ_SEG7_ENCODER_OK;       /* Success */
}

/* Reverse the order of 3-byte segment array (MSB <-> LSB) */
/****************************************************/
void AJ_Seg7_Reverse3Bytes(uint8_t *seg){
    uint8_t temp = 0;

    /* Swap seg[0] and seg[2] */
    temp = seg[0];
    seg[0] = seg[2];
    seg[2] = temp;

    /* seg[1] is in the middle, no need to swap */
}

// Double Dabble
/****************************************************/
uint8_t AJ_Seg7_EncodeNumber_4Digits(uint8_t *seg, uint16_t number){
    uint8_t i = 0;
    uint8_t carry = 0;
    uint8_t bcd[4] = {0};

    if (number > 9999){
        seg[0] = AJ_SEG7_ENCODER_INVALID;
        seg[1] = AJ_SEG7_ENCODER_INVALID;
        seg[2] = AJ_SEG7_ENCODER_INVALID;
        seg[3] = AJ_SEG7_ENCODER_INVALID;
        return AJ_SEG7_ENCODER_ERROR;
    }

    for (i = 0; i < 16; ++i){
        if (bcd[0] >= 5) { bcd[0] += 3; }
        if (bcd[1] >= 5) { bcd[1] += 3; }
        if (bcd[2] >= 5) { bcd[2] += 3; }
        if (bcd[3] >= 5) { bcd[3] += 3; }

        AJ_BitU8_WriteBit_Position(carry, 0, AJ_BitU8_GetBit_Position(bcd[1], 3));    // carry0
        AJ_BitU8_WriteBit_Position(carry, 1, AJ_BitU8_GetBit_Position(bcd[2], 3));    // carry1
        AJ_BitU8_WriteBit_Position(carry, 2, AJ_BitU8_GetBit_Position(bcd[3], 3));    // carry2
        AJ_BitU8_WriteBit_Position(carry, 3, AJ_BitU8_GetBit_Position(number, 15));   // carry3

        bcd[0] = ((bcd[0] << 1) & 0x0F) | AJ_BitU8_GetBit_Position(carry, 0);
        bcd[1] = ((bcd[1] << 1) & 0x0F) | AJ_BitU8_GetBit_Position(carry, 1);
        bcd[2] = ((bcd[2] << 1) & 0x0F) | AJ_BitU8_GetBit_Position(carry, 2);
        bcd[3] = ((bcd[3] << 1) & 0x0F) | AJ_BitU8_GetBit_Position(carry, 3);

        number <<= 1;
    }

    /* Convert BCD digits to 7-segment font */
    for (i = 0; i < 4; i++){
        seg[i] = aj_seg7_font_digit[bcd[3 - i] & 0x0F];
    }

    return AJ_SEG7_ENCODER_OK;
}

/****************************************************/
uint8_t AJ_Seg7_SetDecimalPoint_4Digits(uint8_t *seg, uint8_t position){
    if (position > 3U) {
        return AJ_SEG7_ENCODER_ERROR;   /* Invalid position */
    }

    seg[position] |= AJ_SEG7_ENCODER_DP;
    return AJ_SEG7_ENCODER_OK;       /* Success */
}

/* Reverse the order of 4-byte segment array (MSB <-> LSB) */
/****************************************************/
void AJ_Seg7_Reverse4Bytes(uint8_t *seg){
    uint8_t temp = 0;

    /* Swap seg[0] and seg[3] */
    temp = seg[0];
    seg[0] = seg[3];
    seg[3] = temp;

    /* Swap seg[1] and seg[2] */
    temp = seg[1];
    seg[1] = seg[2];
    seg[2] = temp;
}

