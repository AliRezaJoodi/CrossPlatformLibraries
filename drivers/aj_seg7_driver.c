
#include "aj_seg7_driver_config.h"
#include "aj_seg7_driver_port.h"
#include "aj_seg7_driver.h"

static uint8_t *seg7_buffer = 0;    /* Pointer to external display buffer */
static uint8_t seg7_index = 0;      /* Current digit index for multiplex scanning */

/*********************************/
void AJ_Seg7_Init(void){
    AJ_Seg7_Digits_ConfigAsOutput();
    AJ_Seg7_Segments_ConfigAsOutput();
    AJ_Seg7_Segments_Write(0x00U);
}

/*********************************/
void AJ_Seg7_SetBuffer(uint8_t *buffer){
    if (buffer != 0){
        seg7_buffer = buffer;
    }
}

/*********************************/
void AJ_Seg7_Refresh(void){
    /* Deactivate the selected digit line */
    //Seg7_Digit_Write(seg7_index, !AJ_SEG7_DIGITS_ACTIVATE);
    #if AJ_SEG7_DIGITS_ACTIVATE == 0U
        AJ_Seg7_Digit_Set(seg7_index);
    #else
        AJ_Seg7_Digit_Clear(seg7_index);
    #endif

    seg7_index++;
    if (seg7_index >= AJ_SEG7_DIGITS_COUNT){
        seg7_index = 0;
    }

    AJ_Seg7_Segments_Write(*(seg7_buffer + seg7_index));

    /* Activate the selected digit line */
    //Seg7_Digit_Write(seg7_index, AJ_SEG7_DIGITS_ACTIVATE);
    #if AJ_SEG7_DIGITS_ACTIVATE == 0U
        AJ_Seg7_Digit_Clear(seg7_index);
    #else
        AJ_Seg7_Digit_Set(seg7_index);
    #endif
}