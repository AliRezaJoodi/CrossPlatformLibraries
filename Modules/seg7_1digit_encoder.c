// GitHub Account: GitHub.com/AliRezaJoodi

#include <seg7_1digit_encoder.h>

const uint8_t seg7_font_digit[10]={
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

const uint8_t seg7_font_alpha[11]={
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

static const uint8_t seg7_font_symbol[2] = {
    0x00U,      // 0,   NULL
    0x40U       // 1,   -
};

//*****************************************
uint8_t Seg7_1Digit_EncodeDigit(uint8_t digit){
    if(digit <= 9){
         return seg7_font_digit[digit];
    }

    return 0x00U;
}

//*****************************************
void Seg7_1Digit_EncodeDigit_ByRef(uint8_t digit,  uint8_t *seg){
    *seg = Seg7_1Digit_EncodeDigit(digit);
}

//*****************************************
uint8_t Seg7_1Digit_EncodeAlpha(uint8_t index){
    if(index <= 10){
        return seg7_font_alpha[index];
    }

    return 0x00U;
}

//*****************************************
void Seg7_1Digit_EncodeAlpha_ByRef(uint8_t index,  uint8_t *seg){
    *seg = Seg7_1Digit_EncodeAlpha(index);
}

//*****************************************
uint8_t Seg7_1Digit_EncodeSymbol(uint8_t index){
    if(index <= 1){
        return seg7_font_symbol[index];
    }

    return 0x00U;
}

//*****************************************
void Seg7_1Digit_EncodeSymbol_ByRef(uint8_t index,  uint8_t *seg){
    *seg = Seg7_1Digit_EncodeSymbol(index);
}

//*****************************************
uint8_t Seg7_1Digit_ToggleSegments(uint8_t seg){
    return ~seg;
}

//*****************************************
void Seg7_1Digit_ToggleSegments_ByRef(uint8_t *seg){
    *seg = ~(*seg);
}
