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


//********************************************************
uint8_t Keypad4x4_GetNumber(void){
    uint8_t number = 0xFFU;

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
    number = WriteBit_u8(number, 0, Keypad4x4_R1_Read());
    number = WriteBit_u8(number, 1, Keypad4x4_R2_Read());
    number = WriteBit_u8(number, 2, Keypad4x4_R3_Read());
    number = WriteBit_u8(number, 3, Keypad4x4_R4_Read());
    //number = Keypad4x4_GetPins_Mode1();

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

    number = WriteBit_u8(number, 4, Keypad4x4_C1_Read());
    number = WriteBit_u8(number, 5, Keypad4x4_C2_Read());
    number = WriteBit_u8(number, 6, Keypad4x4_C3_Read());
    number = WriteBit_u8(number, 7, Keypad4x4_C4_Read());
    //number |= Keypad4x4_GetPins_Mode2();

    switch (number){
        case KEYPAD4X4_N00:
            return 0; break;
        case KEYPAD4X4_N01:
            return 1; break;
        case KEYPAD4X4_N02:
            return 2; break;
        case KEYPAD4X4_N03:
            return 3; break;
        case KEYPAD4X4_N04:
            return 4; break;
        case KEYPAD4X4_N05:
            return 5; break;
        case KEYPAD4X4_N06:
            return 6; break;
        case KEYPAD4X4_N07:
            return 7; break;
        case KEYPAD4X4_N08:
            return 8; break;
        case KEYPAD4X4_N09:
            return 9; break;
        case KEYPAD4X4_N10:
            return 10; break;
        case KEYPAD4X4_N11:
            return 11; break;
        case KEYPAD4X4_N12:
            return 12; break;
        case KEYPAD4X4_N13:
            return 13; break;
        case KEYPAD4X4_N14:
            return 14; break;
        case KEYPAD4X4_N15:
            return 15; break;
        default:
            return 16;
    }

    return number;
}

