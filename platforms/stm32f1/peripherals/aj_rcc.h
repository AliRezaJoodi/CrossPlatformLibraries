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


#ifdef __cplusplus
}
#endif

#endif  /* AJ_RCC_INCLUDED */