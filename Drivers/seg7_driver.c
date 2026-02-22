
#include "seg7_driver.h"

static uint8_t *seg7_buffer = 0;
static uint8_t seg7_index = 0;

/*********************************/
void Seg7_Init(void){
    Seg7_Digits_InitAllPins();
    Seg7_Digits_DisableAllPins();

    Seg7_Segments_InitAllPins();
    Seg7_Segments_WriteAllPins(0x00U);
}

/*********************************/
void Seg7_SetBuffer(uint8_t *buffer){
    seg7_buffer = buffer;
}

/*********************************/
void Seg7_Refresh(void){
    Seg7_Digits_DisableAllPins();
    Seg7_Segments_WriteAllPins( *(seg7_buffer + seg7_index) );
    Seg7_Digit_EnablePin(seg7_index);

    seg7_index++;
    if (seg7_index > 1){
        seg7_index = 0;
    }
}
