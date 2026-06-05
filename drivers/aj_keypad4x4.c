// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "aj_keypad4x4_port.h"
#include "aj_keypad4x4.h"

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
uint8_t AJ_Keypad4x4_GetKey(void){
    uint8_t number = 0xFFU;
    uint8_t rows = 0U, cols = 0U;

    AJ_Keypad4x4_R1_ConfigAsOutput();
    AJ_Keypad4x4_R1_Clear();

    AJ_Keypad4X4_R2_ConfigAsOutput();
    AJ_Keypad4X4_R2_Clear();

    AJ_Keypad4X4_R3_ConfigAsOutput();
    AJ_Keypad4X4_R3_Clear();

    AJ_Keypad4x4_R4_ConfigAsOutput();
    AJ_Keypad4x4_R4_Clear();

    cols |= (!AJ_Keypad4x4_C1_Read());
    cols |= (!AJ_Keypad4x4_C2_Read()) << 1;
    cols |= (!AJ_Keypad4x4_C3_Read()) << 2;
    cols |= (!AJ_Keypad4x4_C4_Read()) << 3;

    cols = table_ctz4[cols & 0x0F];

    AJ_Keypad4x4_R1_ConfigAsInput();
    AJ_Keypad4x4_R1_ConfigAsPullUp();

    AJ_Keypad4X4_R2_ConfigAsInput();
    AJ_Keypad4X4_R2_ConfigAsPullUp();

    AJ_Keypad4X4_R3_ConfigAsInput();
    AJ_Keypad4X4_R3_ConfigAsPullUp();

    AJ_Keypad4x4_R4_ConfigAsInput();
    AJ_Keypad4x4_R4_ConfigAsPullUp();

    AJ_Keypad4x4_C1_ConfigAsOutput();
    AJ_Keypad4x4_C1_Clear();

    AJ_Keypad4x4_C2_ConfigAsOutput();
    AJ_Keypad4x4_C2_Clear();

    AJ_Keypad4x4_C3_ConfigAsOutput();
    AJ_Keypad4x4_C3_Clear();

    AJ_Keypad4x4_C4_ConfigAsOutput();
    AJ_Keypad4x4_C4_Clear();

    rows |= (!AJ_Keypad4x4_R1_Read());
    rows |= (!AJ_Keypad4X4_R2_Read()) << 1;
    rows |= (!AJ_Keypad4X4_R3_Read()) << 2;
    rows |= (!AJ_Keypad4x4_R4_Read()) << 3;

    rows = table_ctz4[rows & 0x0F];

    AJ_Keypad4x4_C1_ConfigAsInput();
    AJ_Keypad4x4_C1_ConfigAsPullUp();

    AJ_Keypad4x4_C2_ConfigAsInput();
    AJ_Keypad4x4_C2_ConfigAsPullUp();

    AJ_Keypad4x4_C3_ConfigAsInput();
    AJ_Keypad4x4_C3_ConfigAsPullUp();

    AJ_Keypad4x4_C4_ConfigAsInput();
    AJ_Keypad4x4_C4_ConfigAsPullUp();

    return (cols << 2) | rows;
}

