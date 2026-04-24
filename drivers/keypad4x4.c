// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "hardware.h"
#include "utils/bit.h"
#include "utils/bit_value.h"
#include "keypad4x4_port.h"
#include "drivers/keypad4x4.h"

typedef enum{
    KEYPAD_PIN_INPUT = 0,
    KEYPAD_PIN_OUTPUT = 1
} Keypad_PinDirection_t;

#define KEYPAD4X4_NO_INDEX  0xFFU

static const uint8_t table_ctz4[16] = {
    KEYPAD4X4_NO_INDEX, // 0000
    0U,                 // 0001
    1U,                 // 0010
    KEYPAD4X4_NO_INDEX, // 0011
    2U,                 // 0100
    KEYPAD4X4_NO_INDEX, // 0101
    KEYPAD4X4_NO_INDEX, // 0110
    KEYPAD4X4_NO_INDEX, // 0111
    3U,                 // 1000
    KEYPAD4X4_NO_INDEX, // 1001
    KEYPAD4X4_NO_INDEX, // 1010
    KEYPAD4X4_NO_INDEX, // 1011
    KEYPAD4X4_NO_INDEX, // 1100
    KEYPAD4X4_NO_INDEX, // 1101
    KEYPAD4X4_NO_INDEX, // 1110
    KEYPAD4X4_NO_INDEX  // 1111
};

//********************************************************
uint8_t Keypad4x4_GetNumber(void){
    uint8_t number = 0xFFU;
    uint8_t rows = 0U, cols = 0U;

    Keypad4x4_R1_SetInput();
    Keypad4x4_R1_SetPullUp();

    Keypad4x4_R2_SetInput();
    Keypad4x4_R2_SetPullUp();

    Keypad4x4_R3_SetInput();
    Keypad4x4_R3_SetPullUp();

    Keypad4x4_R4_SetInput();
    Keypad4x4_R4_SetPullUp();

    Keypad4x4_C1_SetOutput();
    Keypad4x4_C1_WriteLow();

    Keypad4x4_C2_SetOutput();
    Keypad4x4_C2_WriteLow();

    Keypad4x4_C3_SetOutput();
    Keypad4x4_C3_WriteLow();

    Keypad4x4_C4_SetOutput();
    Keypad4x4_C4_WriteLow();

    //Keypad4x4_InitPins_Mode1();
//    number = WriteBit_u8(number, 0, Keypad4x4_R1_Read());
//    number = WriteBit_u8(number, 1, Keypad4x4_R2_Read());
//    number = WriteBit_u8(number, 2, Keypad4x4_R3_Read());
//    number = WriteBit_u8(number, 3, Keypad4x4_R4_Read());
    //number = Keypad4x4_GetPins_Mode1();

    rows |= (!Keypad4x4_R1_Read());
    rows |= (!Keypad4x4_R2_Read()) << 1;
    rows |= (!Keypad4x4_R3_Read()) << 2;
    rows |= (!Keypad4x4_R4_Read()) << 3;

    rows = table_ctz4[rows & 0x0F];

    Keypad4x4_R1_SetOutput();
    Keypad4x4_R1_WriteLow();

    Keypad4x4_R2_SetOutput();
    Keypad4x4_R2_WriteLow();

    Keypad4x4_R3_SetOutput();
    Keypad4x4_R3_WriteLow();

    Keypad4x4_R4_SetOutput();
    Keypad4x4_R4_WriteLow();

    Keypad4x4_C1_SetInput();
    Keypad4x4_C1_SetPullUp();

    Keypad4x4_C2_SetInput();
    Keypad4x4_C2_SetPullUp();

    Keypad4x4_C3_SetInput();
    Keypad4x4_C3_SetPullUp();

    Keypad4x4_C4_SetInput();
    Keypad4x4_C4_SetPullUp();

    //Keypad4x4_InitPins_Mode2();

//    number = WriteBit_u8(number, 4, Keypad4x4_C1_Read());
//    number = WriteBit_u8(number, 5, Keypad4x4_C2_Read());
//    number = WriteBit_u8(number, 6, Keypad4x4_C3_Read());
//    number = WriteBit_u8(number, 7, Keypad4x4_C4_Read());
    //number |= Keypad4x4_GetPins_Mode2();

    cols |= (!Keypad4x4_C1_Read());
    cols |= (!Keypad4x4_C2_Read()) << 1;
    cols |= (!Keypad4x4_C3_Read()) << 2;
    cols |= (!Keypad4x4_C4_Read()) << 3;

    cols = table_ctz4[cols & 0x0F];

//    switch (number){
//        case KEYPAD4X4_N00:
//            return 0; break;
//        case KEYPAD4X4_N01:
//            return 1; break;
//        case KEYPAD4X4_N02:
//            return 2; break;
//        case KEYPAD4X4_N03:
//            return 3; break;
//        case KEYPAD4X4_N04:
//            return 4; break;
//        case KEYPAD4X4_N05:
//            return 5; break;
//        case KEYPAD4X4_N06:
//            return 6; break;
//        case KEYPAD4X4_N07:
//            return 7; break;
//        case KEYPAD4X4_N08:
//            return 8; break;
//        case KEYPAD4X4_N09:
//            return 9; break;
//        case KEYPAD4X4_N10:
//            return 10; break;
//        case KEYPAD4X4_N11:
//            return 11; break;
//        case KEYPAD4X4_N12:
//            return 12; break;
//        case KEYPAD4X4_N13:
//            return 13; break;
//        case KEYPAD4X4_N14:
//            return 14; break;
//        case KEYPAD4X4_N15:
//            return 15; break;
//        default:
//            return 16;
//    }

    return (cols << 2) | rows;
}

