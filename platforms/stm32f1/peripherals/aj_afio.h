/**
 * @brief   Alternate function I/O (AFIO) interface for STM32 peripherals.
 *
 * This file provides helper APIs for managing AFIO control registers,
 * including:
 * - AFIO->MAPR
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: Application Setup (BUS Configuration)
 * -----------------------------------------------------------------------------
 * This library does not enable any peripheral clock.
 * The application must enable the required clock buses before using this driver.
 * The following clock bus must be enabled:
 * - The APB2 clock of the AFIO peripheral
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
 * -----------------------------------------------------------------------------
 * EXAMPLE PROJECT
 * -----------------------------------------------------------------------------
 * @see    STM32F103 training exercise link:
 *         https://github.com/AliRezaJoodi/STM32_Exercises/tree/main/AFIO_F103/BareMetal
 *     
 * -----------------------------------------------------------------------------
 * Source
 * -----------------------------------------------------------------------------
 * @author  AliRezaJoodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_AFIO_INCLUDED
#define AJ_AFIO_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include <stm32f1xx.h>
#include "aj_bit_reg.h"

typedef enum{
	AJ_SWJ_SWD_JTAG_NJTRST 	= 0x0U,			/**< SW-DP enabled, 	JTAG-DP enabled with NJTRST */
	AJ_SWJ_SWD_JTAG 				= 0x1U, 		/**< SW-DP enabled, 	JTAG-DP enabled without NJTRST */
	AJ_SWJ_SWD           		= 0x2U, 		/**< SW-DP enabled, 	JTAG-DP disabled */
	AJ_SWJ_DISABLED    			= 0x4U   		/**< SW-DP disabled, 	JTAG-DP disabled */
} aj_afio_swj_t;

static inline void AJ_AFIO_ConfigSWJ(aj_afio_swj_t mode){
	AJ_BitReg_Write3Bit_Position(&AFIO->MAPR, AFIO_MAPR_SWJ_CFG_Pos, mode);
}


#ifdef __cplusplus
}
#endif

#endif	/* AJ_AFIO_INCLUDED */