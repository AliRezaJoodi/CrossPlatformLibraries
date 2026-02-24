
#include "seg7_driver.h"

/* Pointer to external display buffer */
static uint8_t *seg7_buffer = 0;

/* Current digit index for multiplex scanning */
static uint8_t seg7_index = 0;

/*********************************/
void Seg7_Init(void){
    Seg7_InitDigits();
    Seg7_DisableAllDigits();

    Seg7_InitSegments();
    Seg7_WriteSegments(0x00U);
}

/*********************************/
void Seg7_SetBuffer(uint8_t *buffer){
    if (buffer != 0){
        seg7_buffer = buffer;
    }
}

/*********************************/
void Seg7_Refresh(void){
    Seg7_DisableAllDigits();
    Seg7_WriteSegments( *(seg7_buffer + seg7_index) );
    Seg7_EnableDigit(seg7_index);

    seg7_index++;
    if (seg7_index >= SEG7_DIGITS_COUNT){
        seg7_index = 0;
    }
}
