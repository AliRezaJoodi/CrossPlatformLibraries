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
#include "aj_afio_type.h"

static inline void AJ_AFIO_ConfigureSWJ(aj_afio_swj_t mode){
	AJ_BitReg_Write3Bit_Position(&(AFIO->MAPR), AFIO_MAPR_SWJ_CFG_Pos, mode);
}

/**
 * @brief  Selects the port that feeds an EXTI line.
 * @param  line  Line index (0 to 15).
 * @param  port  Port connected to the line.
 * @note   Each EXTI line accepts exactly one source port.
 *         A later call for the same line overwrites the previous port selection.
 */
static inline void AJ_AFIO_ConfigureEXTISource(aj_afio_exti_line_t line, aj_afio_exti_port_t port){
	uint32_t idx = (uint32_t)(line) / 4U;
	uint32_t pos = (uint32_t)(((uint32_t)(line) % 4U) * 4U);

	AJ_BitReg_Write4Bit_Position(&(AFIO->EXTICR[idx]), pos, (uint32_t)port);
}

/**
 * @brief  Reads the port currently feeding an EXTI line.
 * @param  line  Line index (0 to 15).
 * @return Port connected to the line.
 */
static inline aj_afio_exti_port_t AJ_AFIO_GetEXTISource(aj_afio_exti_line_t line){
	uint32_t idx = (uint32_t)(line) / 4U;
	uint32_t pos = (uint32_t)(((uint32_t)(line) % 4U) * 4U);

	return (aj_afio_exti_port_t)AJ_BitReg_Get4Bit_Position(&(AFIO->EXTICR[idx]), pos);
}


#ifdef __cplusplus
}
#endif

#endif	/* AJ_AFIO_INCLUDED */