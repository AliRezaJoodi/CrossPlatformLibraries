// GitHub Account: GitHub.com/AliRezaJoodi

#include <seg7_encoder.h>

// Double Dabble (8-bit to 2 digits)
/****************************************************/
uint8_t Seg7_Encode2Digits(uint8_t number, uint8_t *seg){
    uint8_t i = 0;
    uint8_t carry = 0;
    uint8_t bcd[2] = {0};

    if (number > 99){
        *(seg + 0) = 0U;
        *(seg + 1) = 0U;
        return 1;
    }

    for (i = 0; i < 8; ++i){
        if (bcd[0] >= 5) { bcd[0] += 3; }
        if (bcd[1] >= 5) { bcd[1] += 3; }

        WRITE_BIT(carry, 0, GET_BIT(bcd[1], 3));   // carry0
        WRITE_BIT(carry, 1, GET_BIT(number, 7));   // carry1

        bcd[0] = ((bcd[0] << 1) & 0x0F) | GET_BIT(carry, 0);
        bcd[1] = ((bcd[1] << 1) & 0x0F) | GET_BIT(carry, 1);

        number <<= 1;
    }

    /* Convert BCD digits to 7-segment font */
    for (i = 0; i < 2; i++){
        *(seg + i) = seg7_font_digit[bcd[1 - i] & 0x0F];
    }

    return 0;
}

// Double Dabble (16-bit to 3 digits)
/****************************************************/
uint8_t Seg7_Encode3Digits(uint16_t number, uint8_t *seg){
    uint8_t i = 0;
    uint8_t carry = 0;
    uint8_t bcd[3] = {0};

    if (number > 999){
        *(seg + 0) = 0U;
        *(seg + 1) = 0U;
        *(seg + 2) = 0U;
        return 1;
    }

    for (i = 0; i < 16; ++i){
        if (bcd[0] >= 5) { bcd[0] += 3; }
        if (bcd[1] >= 5) { bcd[1] += 3; }
        if (bcd[2] >= 5) { bcd[2] += 3; }

        WRITE_BIT(carry, 0, GET_BIT(bcd[1], 3));   // carry0
        WRITE_BIT(carry, 1, GET_BIT(bcd[2], 3));   // carry1
        WRITE_BIT(carry, 2, GET_BIT(number, 15));  // carry2

        bcd[0] = ((bcd[0] << 1) & 0x0F) | GET_BIT(carry, 0);
        bcd[1] = ((bcd[1] << 1) & 0x0F) | GET_BIT(carry, 1);
        bcd[2] = ((bcd[2] << 1) & 0x0F) | GET_BIT(carry, 2);

        number <<= 1;
    }

    /* Convert BCD digits to 7-segment font */
    for (i = 0; i < 3; i++){
        *(seg + i) = seg7_font_digit[bcd[2 - i] & 0x0F];
    }

    return 0;
}

// Double Dabble
/****************************************************/
uint8_t Seg7_Encode4Digits(uint16_t number, uint8_t *seg){
    uint8_t i = 0;
    uint8_t carry = 0;
    uint8_t bcd[4] = {0};

    if (number > 9999){
        *(seg + 0) = 0U;
        *(seg + 1) = 0U;
        *(seg + 2) = 0U;
        *(seg + 3) = 0U;
        return 1;
    }

    for (i = 0; i < 16; ++i){
        if (bcd[0] >= 5) { bcd[0] += 3; }
        if (bcd[1] >= 5) { bcd[1] += 3; }
        if (bcd[2] >= 5) { bcd[2] += 3; }
        if (bcd[3] >= 5) { bcd[3] += 3; }

        WRITE_BIT(carry, 0, GET_BIT(bcd[1], 3));    // carry0
        WRITE_BIT(carry, 1, GET_BIT(bcd[2], 3));    // carry1
        WRITE_BIT(carry, 2, GET_BIT(bcd[3], 3));    // carry2
        WRITE_BIT(carry, 3, GET_BIT(number, 15));   // carry3

        bcd[0] = ((bcd[0] << 1) & 0x0F) | GET_BIT(carry, 0);
        bcd[1] = ((bcd[1] << 1) & 0x0F) | GET_BIT(carry, 1);
        bcd[2] = ((bcd[2] << 1) & 0x0F) | GET_BIT(carry, 2);
        bcd[3] = ((bcd[3] << 1) & 0x0F) | GET_BIT(carry, 3);

        number <<= 1;
    }

    /* Convert BCD digits to 7-segment font */
    for (i = 0; i < 4; i++){
        *(seg + i) = seg7_font_digit[bcd[3 - i] & 0x0F];
    }

    return 0;
}

/* Reverse the order of 4-byte segment array (MSB <-> LSB) */
/****************************************************/
void Seg7_Reverse4Bytes(uint8_t *seg){
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

