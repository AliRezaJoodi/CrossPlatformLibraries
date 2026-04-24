// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "hardware.h"
#include "keypad4x4_port.h"
#include "drivers/keypad4x4.h"

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
uint8_t Keypad4x4_GetKey(void){
    uint8_t number = 0xFFU;
    uint8_t rows = 0U, cols = 0U;

    Keypad4x4_R1_SetOutput();
    Keypad4x4_R1_WriteLow();

    Keypad4x4_R2_SetOutput();
    Keypad4x4_R2_WriteLow();

    Keypad4x4_R3_SetOutput();
    Keypad4x4_R3_WriteLow();

    Keypad4x4_R4_SetOutput();
    Keypad4x4_R4_WriteLow();

    cols |= (!Keypad4x4_C1_Read());
    cols |= (!Keypad4x4_C2_Read()) << 1;
    cols |= (!Keypad4x4_C3_Read()) << 2;
    cols |= (!Keypad4x4_C4_Read()) << 3;

    cols = table_ctz4[cols & 0x0F];

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

    rows |= (!Keypad4x4_R1_Read());
    rows |= (!Keypad4x4_R2_Read()) << 1;
    rows |= (!Keypad4x4_R3_Read()) << 2;
    rows |= (!Keypad4x4_R4_Read()) << 3;

    rows = table_ctz4[rows & 0x0F];

    Keypad4x4_C1_SetInput();
    Keypad4x4_C1_SetPullUp();

    Keypad4x4_C2_SetInput();
    Keypad4x4_C2_SetPullUp();

    Keypad4x4_C3_SetInput();
    Keypad4x4_C3_SetPullUp();

    Keypad4x4_C4_SetInput();
    Keypad4x4_C4_SetPullUp();

    return (cols << 2) | rows;
}

