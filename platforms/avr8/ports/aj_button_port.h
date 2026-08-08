/**
 * @file    button_port.h
 * @brief   GPIO and hardware support for button handling.
 *
 * This header provides structures and inline functions for
 * configuring and reading buttons, including:
 *  - Button hardware configuration (Button_HW_t)
 *  - Button object (Button_t)
 *  - Pin configuration functions
 *
 * Inline functions are provided for fast access in AVR MCUs.
 * The header is portable and can be adapted to other microcontrollers.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_BUTTON_PORT_INCLUDED
#define AJ_BUTTON_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_compiler.h"
#include "aj_bit_reg.h"
#include "aj_button_config.h"
#include "aj_button_config_platform.h"
#include "aj_button_type.h"

#define AJ_BUTTON_DELAY_US(VALUE)      AJ_DELAY_US(VALUE)

static inline void AJ_Button_Pin_ConfigAsInput(aj_button_t *btn){
    AJ_BitReg_ClearBit_Mask(btn->hw.ddr, btn->hw.mask);
}

static inline void AJ_Button_Pin_ConfigAsPullNone(aj_button_t *btn){
    AJ_BitReg_ClearBit_Mask(btn->hw.port, btn->hw.mask);
}

static inline void AJ_Button_Pin_ConfigAsPullUp(aj_button_t *btn){
    AJ_BitReg_SetBit_Mask(btn->hw.port, btn->hw.mask);
}

/* Not supported on AVR - same as floating */
static inline void AJ_Button_Pin_ConfigAsPullDown(aj_button_t *btn){
    AJ_BitReg_ClearBit_Mask(btn->hw.port, btn->hw.mask);
}

static inline uint8_t AJ_Button_Pin_Read(aj_button_t *btn){
    return AJ_BitReg_IsBitSet_Mask(btn->hw.pin, btn->hw.mask);
}


#ifdef __cplusplus
}
#endif

#endif  /* AJ_BUTTON_PORT_INCLUDED */
