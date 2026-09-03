/**
 * @brief SysTick utility library for STM32F1xx microcontrollers.
 *
 * This file provides helper APIs for managing SysTick control and status
 * registers, including:
 * - SysTick->CTRL
 * - SysTick->LOAD
 * - SysTick->VAL
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: Compilation & Linkage
 * -----------------------------------------------------------------------------
 * The following source files must be compiled and linked in the project:
 * - `aj_systick.c`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 2: Default Configuration
 * -----------------------------------------------------------------------------
 * The default driver macros are declared in the following headers:
 * - `aj_target.h`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 3: User Configuration Override
 * -----------------------------------------------------------------------------
 * This library's default configuration can be customized via the central
 * project hardware configuration file, which MUST be present alongside your
 * project source files. Override the macros inside it:
 * - `hardware.h`
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
#include "aj_type.h"
#include "aj_systick_type.h"

/******************************************************************************/
/* SysTick->CTRL                                                              */
/******************************************************************************/
static inline void AJ_SysTick_ConfigEnableState(aj_state_enable_t state){
	AJ_BitReg_WriteBit_Position(&(SysTick->CTRL), SysTick_CTRL_ENABLE_Pos, state);
}

static inline uint8_t AJ_SysTick_IsEnabled(void){
	return AJ_BitReg_IsBitSet_Mask(&(SysTick->CTRL), SysTick_CTRL_ENABLE_Msk);
}

static inline void AJ_SysTick_ConfigInterruptState(aj_state_enable_t state){
	AJ_BitReg_WriteBit_Position(&(SysTick->CTRL), SysTick_CTRL_TICKINT_Pos, state);
}

static inline uint8_t AJ_SysTick_IsInterruptEnabled(void){
	return AJ_BitReg_IsBitSet_Mask(&(SysTick->CTRL), SysTick_CTRL_TICKINT_Msk);
}

static inline void AJ_SysTick_ConfigClockSource(aj_systick_clksource_t source){
	AJ_BitReg_WriteBit_Position(&(SysTick->CTRL), SysTick_CTRL_CLKSOURCE_Pos, source);
}

static inline aj_systick_clksource_t AJ_SysTick_GetClockSource(void){
	return (aj_systick_clksource_t)AJ_BitReg_GetBit_Position(&(SysTick->CTRL), SysTick_CTRL_CLKSOURCE_Pos);
}

static inline uint8_t AJ_SysTick_IsFlagActive(void){
	return AJ_BitReg_IsBitSet_Mask(&(SysTick->CTRL), SysTick_CTRL_COUNTFLAG_Msk);
}

static inline void AJ_SysTick_ClearFlag(void){
	volatile uint32_t tmp = SysTick->CTRL;
	((void)tmp);
}

/******************************************************************************/
/* SysTick->LOAD                                                              */
/******************************************************************************/
static inline void AJ_SysTick_WriteLoad(uint32_t load){
	SysTick->LOAD = load & SysTick_LOAD_RELOAD_Msk;
}

static inline uint32_t AJ_SysTick_ReadLoad(void){
	return SysTick->LOAD & SysTick_LOAD_RELOAD_Msk;
}

/******************************************************************************/
/* SysTick->VAL                                                               */
/******************************************************************************/
static inline uint32_t AJ_SysTick_ReadValue(void){
	return SysTick->VAL & SysTick_VAL_CURRENT_Msk;
}

static inline void AJ_SysTick_ClearValue(void){
	SysTick->VAL = 0U;
}

/******************************************************************************/
/* Init                                                                       */
/******************************************************************************/
/**
 * @brief  Initializes the SysTick timer to generate a 1 ms time base.
 *
 * Performs the following steps in order:
 * - Stops the SysTick counter if it is already running.
 * - Disables the SysTick interrupt.
 * - Selects the processor clock (HCLK) as the clock source.
 * - Writes the reload value calculated from `clk_hz` to produce a 1 ms period.
 * - Clears the current counter value so the new period starts immediately.
 * - Starts the SysTick counter.
 *
 * @note   The interrupt is left disabled by design; enable it explicitly with
 *         AJ_SysTick_ConfigInterruptState() if required.
 * @param  clk_hz  Core clock frequency in Hz (e.g. 8000000U for 8 MHz).
 */
void AJ_SysTick_Init_1ms(uint32_t clk_hz);


#ifdef __cplusplus
}
#endif

#endif	/* AJ_SYSTICK_INCLUDED */
