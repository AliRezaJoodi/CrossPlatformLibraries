
#include "hardware.h"			    /* Project-level overrides */
#include "seg7_driver_port.h"
#include "drivers/seg7_driver.h"

static uint8_t *seg7_buffer = 0;    /* Pointer to external display buffer */
static uint8_t seg7_index = 0;      /* Current digit index for multiplex scanning */

/*********************************/
void Seg7_Init(void){
    Seg7_Digits_SetOutput();
    Seg7_Segments_SetOutput();
    Seg7_Segments_Write(0x00U);
}

/*********************************/
void Seg7_SetBuffer(uint8_t *buffer){
    if (buffer != 0){
        seg7_buffer = buffer;
    }
}

/*********************************/
void Seg7_Refresh(void){
    /* Deactivate the selected digit line */
    //Seg7_Digit_Write(seg7_index, !SEG7_DIGITS_ACTIVATE);
    #if SEG7_DIGITS_ACTIVATE == 0U
        Seg7_Digits_WriteHigh(seg7_index);
    #else
        Seg7_Digits_WriteLow(seg7_index);
    #endif

    seg7_index++;
    if (seg7_index >= SEG7_DIGITS_COUNT){
        seg7_index = 0;
    }

    Seg7_Segments_Write(*(seg7_buffer + seg7_index));

    /* Activate the selected digit line */
    //Seg7_Digit_Write(seg7_index, SEG7_DIGITS_ACTIVATE);
    #if SEG7_DIGITS_ACTIVATE == 0U
        Seg7_Digits_WriteLow(seg7_index);
    #else
        Seg7_Digits_WriteHigh(seg7_index);
    #endif
}