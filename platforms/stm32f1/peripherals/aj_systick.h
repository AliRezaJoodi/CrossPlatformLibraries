/**
 * @brief SysTick utility library for STM32F1xx microcontrollers.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_SYSTICK_INCLUDED
#define AJ_SYSTICK_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include <stm32f1xx.h>
#include "aj_bit_reg.h"
#include "aj_systick_type.h"

/******************************************************************************/
/* Count Flag                                                                 */
/******************************************************************************/
static inline uint8_t AJ_SysTick_IsFlagActive(void){
	return AJ_BitReg_IsBitSet_Mask(&(SysTick->CTRL), SysTick_CTRL_COUNTFLAG_Msk);
}

static inline void AJ_SysTick_ClearFlag(void){
	volatile uint32_t tmp = SysTick->CTRL;
	((void)tmp);
}


#ifdef __cplusplus
}
#endif

#endif	/* AJ_SYSTICK_INCLUDED */
