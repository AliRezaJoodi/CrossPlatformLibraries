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

#ifndef BUTTON_PORT_INCLUDED
#define BUTTON_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "compiler_port.h"
#include "aj_bit_reg.h"
#include "button_hw.h"
#include "button_type.h"

#define BUTTON_DELAY_US(VALUE)      DELAY_US(VALUE)

static inline void Button_Pin_ConfigAsInput(const Button_t *btn){
    AJ_BitReg_ClearBits_Mask(btn->hw.ddr, btn->hw.mask);
}

static inline void Button_Pin_ConfigAsPullNone(const Button_t *btn){
    AJ_BitReg_ClearBits_Mask(btn->hw.port, btn->hw.mask);
}

static inline void Button_Pin_ConfigAsPullUp(const Button_t *btn){
    AJ_BitReg_SetBits_Mask(btn->hw.port, btn->hw.mask);
}

/* Not supported on AVR - same as floating */
static inline void Button_Pin_ConfigAsPullDown(const Button_t *btn){
    AJ_BitReg_ClearBits_Mask(btn->hw.port, btn->hw.mask);
}

static inline uint8_t Button_Pin_Read(const Button_t *btn){
    return AJ_BitReg_AreBitsSet_Mask(btn->hw.pin, btn->hw.mask);
}

#ifdef __cplusplus
}
#endif

#endif
