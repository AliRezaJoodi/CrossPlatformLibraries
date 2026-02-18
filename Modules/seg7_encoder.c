// GitHub Account: GitHub.com/AliRezaJoodi

#include <seg7_encoder.h>

/* Reverse the order of 4-byte segment array (MSB <-> LSB) */
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

void Seg7_Encode4Digits_U16(uint16_t number, uint8_t *seg){
    uint8_t i = 0, carry = 0;

    for (i = 0; i < 4; ++i){
        *(seg + i) = 0;
    }
//    *(seg + 0) = 0;
//    *(seg + 1) = 0;
//    *(seg + 2) = 0;
//    *(seg + 3) = 0;

    for (i = 0; i < 16; ++i){
        if(*(seg + 0) >= 5) { *(seg + 0) += 3; }
        if(*(seg + 1) >= 5) { *(seg + 1) += 3; }
        if(*(seg + 2) >= 5) { *(seg + 2) += 3; }
        if(*(seg + 3) >= 5) { *(seg + 3) += 3; }

        WRITE_BIT(carry, 0, GET_BIT(*(seg + 1), 3)); // carry0
        WRITE_BIT(carry, 1, GET_BIT(*(seg + 2), 3)); // carry1
        WRITE_BIT(carry, 2, GET_BIT(*(seg + 3), 3)); // carry2
        WRITE_BIT(carry, 3, GET_BIT(number, 15));    // carry3

        *(seg + 0) = ((*(seg + 0) << 1) & 0x0F) | GET_BIT(carry, 0);
        *(seg + 1) = ((*(seg + 1) << 1) & 0x0F) | GET_BIT(carry, 1);
        *(seg + 2) = ((*(seg + 2) << 1) & 0x0F) | GET_BIT(carry, 2);
        *(seg + 3) = ((*(seg + 3) << 1) & 0x0F) | GET_BIT(carry, 3);

        number <<= 1;
    }

    for (i = 0; i < 4; i++){
        *(seg + i) = seg7_font_digit[*(seg + i) & 0x0F];
    }
}

//void Seg7_Encode4Digits_U16_2(uint16_t number, uint8_t *seg){
//    uint8_t i, j;
//    uint8_t carry0, carry1, carry2, carry3;
//
//    for(i = 0; i < 4; i++) { *(seg + i) = 0; }
//
//    for(i = 0; i < 16; i++){
//        for(j = 0; j < 4; j++){
//            if(*(seg + j) >= 5) { *(seg + j) += 3; }
//        }
//
//        carry0 = (*(seg + 1) & 0x08) >> 3;
//        carry1 = (*(seg + 2) & 0x08) >> 3;
//        carry2 = (*(seg + 3) & 0x08) >> 3;
//        //carry3 = ((number & 0x8000) != 0) ? 1 : 0;
//        carry3 = GET_BIT(number, 15);
//
//        *(seg + 0) = ((*(seg + 0) << 1) & 0x0F) | carry0;
//        *(seg + 1) = ((*(seg + 1) << 1) & 0x0F) | carry1;
//        *(seg + 2) = ((*(seg + 2) << 1) & 0x0F) | carry2;
//        *(seg + 3) = ((*(seg + 3) << 1) & 0x0F) | carry3;
//
//        number <<= 1;
//    }
//
//    for(i = 0; i < 4; i++) { *(seg + i) = seg7_font_digit[*(seg + i) & 0x0F]; }
//}

//void Seg7_Encode4Digits_U16_1(uint16_t number, uint8_t *seg){
//    uint8_t bcd[4] = {0, 0, 0, 0};
//    uint8_t i, j;
//
//    uint8_t carry0;
//    uint8_t carry1;
//    uint8_t carry2;
//    uint8_t carry3;
//
//    for (i = 0; i < 16; i++){
//        /* Add-3 step */
//        for (j = 0; j < 4; j++){
//            if (bcd[j] >= 5){
//                bcd[j] += 3;
//            }
//        }
//
//        /* Capture carries before shifting */
//        carry0 = (bcd[1] & 0x8) >> 3;
//        carry1 = (bcd[2] & 0x8) >> 3;
//        carry2 = (bcd[3] & 0x8) >> 3;
//        carry3 = (number & 0x8000) ? 1 : 0;
//
//        /* Shift left BCD nibbles */
//        bcd[0] = ((bcd[0] << 1) & 0x0F) | carry0;
//        bcd[1] = ((bcd[1] << 1) & 0x0F) | carry1;
//        bcd[2] = ((bcd[2] << 1) & 0x0F) | carry2;
//        bcd[3] = ((bcd[3] << 1) & 0x0F) | carry3;
//
//        number <<= 1;
//    }
//
//    *(seg + 0) = seg7_font_digit[bcd[0]];
//    *(seg + 1) = seg7_font_digit[bcd[1]];
//    *(seg + 2) = seg7_font_digit[bcd[2]];
//    *(seg + 3) = seg7_font_digit[bcd[3]];
//}

//void Seg7_Encode4Digits_U16(uint16_t number, uint8_t *seg){
//    *(seg + 0) = seg7_font_digit[1];
//    *(seg + 1) = seg7_font_digit[2];
//    *(seg + 2) = seg7_font_digit[3];
//    *(seg + 3) = seg7_font_digit[4];
//}


