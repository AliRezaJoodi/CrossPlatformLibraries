// GitHub Account: GitHub.com/AliRezaJoodi

#include "hardware.h"
#include "keypad4x4.h"

#define KEYPAD4X4_MODE_INPUT   0U
#define KEYPAD4X4_MODE_OUTPUT  1U
                                   //__0,__1,__2,__3,__4,__5,__6,__7,__8,__9,_10,_11,_12,_13,_14,_15
//flash unsigned char keypad_data[16]={215,235,219,187,237,221,189,238,222,190,126,125,123,119,183,231};
//flash unsigned char keypad_data[16]={N00,N01,N02,N03,N04,N05,N06,N07,N08,N09,N10,N11,N12,N13,N14,N15};

//********************************************************
uint8_t Keypad4x4_GetInitialNumber(void){
    uint8_t numer = 0;

//    Keypad4x4_ConfigPin(&KEYPAD_R1_DDR, &KEYPAD_R1_PORT, KEYPAD_R1_BIT, KEYPAD4X4_MODE_INPUT);

    Keypad4x4_R1_ConfigPin(KEYPAD4X4_MODE_INPUT);
    Keypad4x4_R2_ConfigPin(KEYPAD4X4_MODE_INPUT);
    Keypad4x4_R3_ConfigPin(KEYPAD4X4_MODE_INPUT);
    Keypad4x4_R4_ConfigPin(KEYPAD4X4_MODE_INPUT);
    Keypad4x4_C1_ConfigPin(KEYPAD4X4_MODE_OUTPUT);
    Keypad4x4_C2_ConfigPin(KEYPAD4X4_MODE_OUTPUT);
    Keypad4x4_C3_ConfigPin(KEYPAD4X4_MODE_OUTPUT);
    Keypad4x4_C4_ConfigPin(KEYPAD4X4_MODE_OUTPUT);

//    KEYPAD4x4_DDR=0b11110000; KEYPAD4x4_PORT=0b00001111; delay_us(2);
    numer = KEYPAD4x4_PIN;

    Keypad4x4_R1_ConfigPin(KEYPAD4X4_MODE_OUTPUT);
    Keypad4x4_R2_ConfigPin(KEYPAD4X4_MODE_OUTPUT);
    Keypad4x4_R3_ConfigPin(KEYPAD4X4_MODE_OUTPUT);
    Keypad4x4_R4_ConfigPin(KEYPAD4X4_MODE_OUTPUT);
    Keypad4x4_C1_ConfigPin(KEYPAD4X4_MODE_INPUT);
    Keypad4x4_C2_ConfigPin(KEYPAD4X4_MODE_INPUT);
    Keypad4x4_C3_ConfigPin(KEYPAD4X4_MODE_INPUT);
    Keypad4x4_C4_ConfigPin(KEYPAD4X4_MODE_INPUT);

    //KEYPAD4x4_DDR=0b00001111; KEYPAD4x4_PORT=0b11110000; delay_us(2);
    numer=numer|KEYPAD4x4_PIN;

    return numer;
}

////********************************************************
//unsigned char Keypad4x4_GetInitialNumber_(void){
//    unsigned char numer;
//    KEYPAD4x4_DDR=0b00001111; KEYPAD4x4_PORT=0b11110000; delay_us(2); numer=KEYPAD4x4_PIN;
//    KEYPAD4x4_DDR=0b11110000; KEYPAD4x4_PORT=0b00001111; delay_us(2); numer=numer|KEYPAD4x4_PIN;
//    return numer;
//}

//********************************************************
unsigned char Keypad4x4_ConvertNumber(unsigned char key){
    switch (key){
        case N00:
            return 0; break;
        case N01:
            return 1; break;
        case N02:
            return 2; break;
        case N03:
            return 3; break;
        case N04:
            return 4; break;
        case N05:
            return 5; break;
        case N06:
            return 6; break;
        case N07:
            return 7; break;
        case N08:
            return 8; break;
        case N09:
            return 9; break;
        case N10:
            return 10; break;
        case N11:
            return 11; break;
        case N12:
            return 12; break;
        case N13:
            return 13; break;
        case N14:
            return 14; break;
        case N15:
            return 15; break;
        default:
            return 16;
    }
}

////********************************************************
//unsigned char Keypad4x4_ConvertNumber_(unsigned char key){
//    unsigned char i=0;
//
//    if(key!=0xff){
//        for(i=0; i<16; ++i){
//  	        if(key==keypad_data[i]){return i;}
//  	    }
//    }
//
//    return 16;
//}

//********************************************************
unsigned char Keypad4x4_GetNumber(void){
    unsigned char numer_initial = 0;

    numer_initial = Keypad4x4_GetInitialNumber();
    return Keypad4x4_ConvertNumber(numer_initial);
}

