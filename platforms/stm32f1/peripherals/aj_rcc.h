/**
 * @brief Reset and clock control (RCC) utility library for STM32F1xx microcontrollers.
 *
 * This file provides helper APIs for the following RCC registers:
 * - RCC->CR    (8.3.1 Clock control register)
 * - RCC->CFGR  (8.3.2 Clock configuration register)
 * - RCC->CIR   (8.3.3 Clock interrupt register)
 * - RCC->BDCR  (Backup domain control register)
 * - RCC->CSR   (Clock control/status register)
 *
 * Abbreviations:
 * - RCC_CR:   Clock control register
 * - HSE:      High-Speed External Clock Signal
 * - HSI:      High-Speed Internal Clock Signal
 * - LSI:      Low-Speed Internal Clock Signal
 * - LSE:      Low-Speed External Clock Signal
 * - EXTCLK:   External Clock Source
 *
 * @note    This header is under editing and will be completed gradually.
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: Default Configuration
 * -----------------------------------------------------------------------------
 * The default macros are declared in the following headers:
 * - `aj_target.h`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 2: User Configuration Override
 * -----------------------------------------------------------------------------
 * This library's default configuration can be customized via the central
 * project hardware configuration file, which MUST be present alongside your
 * project source files. Override the macros inside it:
 * - `hardware.h`
 *
 * -----------------------------------------------------------------------------
 * EXAMPLE PROJECT
 * -----------------------------------------------------------------------------
 * @see    STM32F103 training exercise link:
 *         https://github.com/AliRezaJoodi/STM32_Exercises
 *
 * -----------------------------------------------------------------------------
 * Source
 * -----------------------------------------------------------------------------
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_RCC_INCLUDED
#define AJ_RCC_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include <stm32f1xx.h>
#include "aj_bit_reg.h"
#include "aj_type.h"
#include "aj_rcc_type.h"

/******************************************************************************/
/* RCC->CR                                                                    */
/******************************************************************************/
/**
 * @brief  Enables or disables the clock security system (CSS).
 * @param  state  Clock security system (CSS) configuration:
 *                - AJ_ENABLE: Clock detector ON (if HSE oscillator is ready)
 *                - AJ_DISABLE: Clock detector OFF
 * @note   When CSSON is set, the clock detector is enabled by hardware once the
 *         HSE oscillator is ready, and disabled by hardware if an HSE clock
 *         failure is detected.
 */
static inline void AJ_RCC_HSE_ConfigureClockSecuritySystem(aj_enable_state_t state){
	AJ_BitReg_WriteBit_Position(&(RCC->CR), RCC_CR_CSSON_Pos, state);
}

/**
 * @brief  Reports whether the clock security system (CSS) is enabled.
 * @return Clock security system (CSS) state:
 *         - 1: Clock detector ON
 *         - 0: Clock detector OFF
 */
static inline uint8_t AJ_RCC_HSE_IsClockSecuritySystemEnabled(void){
	return AJ_BitReg_IsBitSet_Mask(&(RCC->CR), RCC_CR_CSSON_Msk);
}

/**
 * @brief  Selects the HSE clock source.
 * @param  source  HSE clock source:
 *                 - AJ_RCC_HSE_CLKSOURCE_XTAL: external oscillator (two-pin crystal)
 *                 - AJ_RCC_HSE_CLKSOURCE_EXTCLK: external clock applied to OSC_IN
 * @note   HSEBYP can only be written when the HSE oscillator is disabled.
 *         The external clock must be enabled with the HSEON bit set to be used.
 */
static inline void AJ_RCC_HSE_ConfigureClockSource(aj_hse_clksource_t source){
	AJ_BitReg_WriteBit_Position(&(RCC->CR), RCC_CR_HSEBYP_Pos, source);
}

/**
 * @brief  Reads the HSE clock source.
 * @return HSE clock source:
 *         - AJ_RCC_HSE_CLKSOURCE_XTAL: external oscillator (two-pin crystal)
 *         - AJ_RCC_HSE_CLKSOURCE_EXTCLK: external clock applied to OSC_IN
 */
static inline aj_hse_clksource_t AJ_RCC_HSE_GetClockSource(void){
	return (aj_hse_clksource_t)AJ_BitReg_GetBit_Position(&(RCC->CR), RCC_CR_HSEBYP_Pos);
}


#ifdef __cplusplus
}
#endif

#endif  /* AJ_RCC_INCLUDED */