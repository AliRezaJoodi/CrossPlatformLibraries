/**
 * @brief Flash memory utility library for STM32F1xx microcontrollers.
 *
 * This file provides helper APIs for:
 * - FLASH->ACR
 *
 * @note    This header is under editing and will be completed gradually.
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: Application Setup (BUS Configuration)
 * -----------------------------------------------------------------------------
 * This library does not enable the Flash peripheral clock.
 * The application must enable the required clock buses before using this driver.
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 2: Default Configuration
 * -----------------------------------------------------------------------------
 * The default macros are declared in the following headers:
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
 * -----------------------------------------------------------------------------
 * EXAMPLE PROJECT
 * -----------------------------------------------------------------------------
 * @see    STM32F103 training exercise link:
 *         
 * 
 * -----------------------------------------------------------------------------
 * Source
 * -----------------------------------------------------------------------------
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_FLASH_INCLUDED
#define AJ_FLASH_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include <stm32f1xx.h>
#include "aj_bit_reg.h"
#include "aj_flash_type.h"

/******************************************************************************/
/* Flash access control register (FLASH_ACR)                                  */
/******************************************************************************/

/* 
 * TODO: Implement FLASH_ACR functions 
 */


#ifdef __cplusplus
}
#endif

#endif /* AJ_FLASH_INCLUDED */
