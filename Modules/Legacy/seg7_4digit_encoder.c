// GitHub Account: GitHub.com/AliRezaJoodi

#include <seg7_4digit_encoder.h>

//*************************************************
void Seg7_4Digit_ToggleSegments(uint8_t *seg){
 uint8_t i = 0;

 for(i=0; i<4; ++i){
    *(seg + i) = ~(*(seg + i));
 }
}

//*************************************************
static uint8_t Seg7_4Digit_CheckFloatForInvalid(float value){
    if ((value < 0) || (10000 <= value)){
        return 1;   //Error
    }

    return 0;
}

//*************************************************
void Seg7_4Digit_EncodeFloat_2DP(float value, uint8_t *seg){
    uint16_t value_u16 = 0;
    uint8_t digit = 0;
    uint8_t dp = 2;

    if( Seg7_4Digit_CheckFloatForInvalid(value) ){
        for (digit=0; digit<4; ++digit){
            *(seg + digit) = 0b01000000;
        }
        return;
    }

    if (value < 0.01){
        *(seg + 0) = 0U;
        *(seg + 1) = 0U;
        *(seg + 2) = 0U;
        *(seg + 3) = 0b00111111;
        return;
    }
    else if (value<100.0f){
        value_u16 = value * 100.0f;
        dp = 2U;
    }
    else if (value<1000.0f) {
        value_u16 = value * 10.0f;
        dp = 1U;
    }
    else if (value<10000.0f) {
        value_u16 = value;
        dp = 0U;
    }

    digit = value_u16 % 10;
    //Seg7_1Digit_EncodeDigit_ByRef(digit, (seg+3));
    *(seg + 3) = seg7_font_digit[digit];

    value_u16 /= 10;
    digit = value_u16 % 10;
    //Seg7_1Digit_EncodeDigit_ByRef(digit, (seg+2));
    *(seg + 2) = seg7_font_digit[digit];
    if(dp == 1){
        *(seg+2) = (*(seg+2)) | 0b10000000;
    }

    value_u16 /= 10;
    digit = value_u16 % 10;
    //Seg7_1Digit_EncodeDigit_ByRef(digit, (seg+1));
    *(seg + 1) = seg7_font_digit[digit];
    if(dp == 2){
        *(seg+1) = (*(seg+1)) | 0b10000000;
    }

    value_u16 /= 10;
    digit = value_u16 % 10;
//    Seg7_1Digit_EncodeDigit_ByRef(digit, (seg+0));
    *(seg + 0) = seg7_font_digit[digit];

    if(*(seg+0) == 0b00111111){
        *(seg+0) = 0b00000000;
    }
}

//*************************************************
uint8_t Seg7_4Digit_EncodeFloat_1DP(float value, uint8_t *seg){
    uint16_t value_u16 = 0;
    uint8_t digit = 0;
    uint8_t dp = 1;

    if( Seg7_4Digit_CheckFloatForInvalid(value) ){
        for (digit=0; digit<4; ++digit){
            *(seg + digit) = 0b01000000;
        }
        return 1;
    }

    if (value<1000) {
        value_u16 = value*10;
        dp = 1;
    }
    else if (value<10000) {
        value_u16 = value;
        dp = 0;
    }

    digit=value_u16%10;
    //Seg7_1Digit_EncodeDigit_ByRef(digit, (seg+3));
    *(seg + 3) = seg7_font_digit[digit];

    value_u16=value_u16/10;
    digit=value_u16%10;
    //Seg7_1Digit_EncodeDigit_ByRef(digit, (seg+2));
    *(seg + 2) = seg7_font_digit[digit];
    if(dp==1){
        *(seg+2) = (*(seg+2)) | 0b10000000;
    }

    value_u16=value_u16/10;
    digit=value_u16%10;
    //Seg7_1Digit_EncodeDigit_ByRef(digit, (seg+1));
    *(seg + 1) = seg7_font_digit[digit];

    value_u16=value_u16/10;
    digit=value_u16%10;
    //Seg7_1Digit_EncodeDigit_ByRef(digit, (seg+0));
    *(seg + 0) = seg7_font_digit[digit];

    if(*(seg+0) == 0b00111111){
        *(seg+0) = 0b00000000;

        if(*(seg+1) == 0b00111111){
            *(seg+1) = 0b00000000;
        }
    }

    return 0;
}
