// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "hardware.h"
#include "utils/bit.h"
#include "keypad4x4_port.h"
#include "drivers/keypad4x4.h"

//********************************************************
uint8_t Keypad4x4_GetNumber(void){
    uint8_t number = 0U;

    Keypad4x4_InitPins_Mode1();
    number = Keypad4x4_GetPins_Mode1();

    Keypad4x4_InitPins_Mode2();
    number |= Keypad4x4_GetPins_Mode2();

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

