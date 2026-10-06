/**
 * @brief   External interrupt/Event controller (EXTI) interface for STM32 peripherals.
 *
 * This file provides helper APIs for managing EXTI control and status
 * registers, including:
 * - EXTI->IMR
 * - EXTI->EMR
 * - EXTI->RTSR
 * - EXTI->FTSR
 * - EXTI->SWIER
 * - EXTI->PR
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: Source Files to Build
 * -----------------------------------------------------------------------------
 * The following source files must be compiled and linked in the project:
 * - `aj_exti.c`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 2: Application Setup (BUS Configuration)
 * -----------------------------------------------------------------------------
 * This library does not enable any peripheral clock.
 * The application must enable the required clock buses before using this driver.
 * The following clock bus must be enabled:
 * - The APB2 clock of the AFIO peripheral (required to select the EXTI source port)
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 3: Default Configuration
 * -----------------------------------------------------------------------------
 * The default driver macros are declared in the following headers:
 * - `aj_target.h`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 4: User Configuration Override
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
 *         https://github.com/AliRezaJoodi/STM32_Exercises/tree/main/EXTI_F103/BareMetal
 *     
 * -----------------------------------------------------------------------------
 * Source
 * -----------------------------------------------------------------------------
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_EXTI_INCLUDED
#define AJ_EXTI_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include <stm32f1xx.h>
#include "aj_bit_reg.h"
#include "aj_type.h"
#include "aj_exti_type.h"

/******************************************************************************/
/* Interrupt mask register (EXTI_IMR): interrupt lines                        */
/******************************************************************************/
/**
 * @brief  Enables the interrupt request on the selected line(s).
 * @param  line Mask of the line(s) to enable. Must not be `AJ_EXTI_LINE_NONE`.
 */
static inline void AJ_EXTI_EnableInterrupt(aj_exti_line_mask_t line){
	AJ_BitReg_SetBit_Mask(&(EXTI->IMR), line);
}

/**
 * @brief  Disables the interrupt request on the selected line(s).
 * @param  line Mask of the line(s) to disable. Must not be `AJ_EXTI_LINE_NONE`.
 */
static inline void AJ_EXTI_DisableInterrupt(aj_exti_line_mask_t line){
	AJ_BitReg_ClearBit_Mask(&(EXTI->IMR), line);
}

/**
 * @brief  Checks whether every line of the mask is enabled in EXTI_IMR.
 * @param  line Mask of the line(s) to test. Must not be `AJ_EXTI_LINE_NONE`.
 * @retval uint8_t:
 *         - 1: All the selected lines are enabled.
 *         - 0: At least one of the selected lines is disabled.
 */
static inline uint8_t AJ_EXTI_IsInterruptEnabled(aj_exti_line_mask_t line){
	return AJ_BitReg_IsBitSet_Mask(&(EXTI->IMR), line);
}

/******************************************************************************/
/* Event mask register (EXTI_EMR): event lines                                */
/******************************************************************************/
/**
 * @brief  Enables the event on the selected line(s).
 * @param  line Mask of the line(s) to enable. Must not be `AJ_EXTI_LINE_NONE`.
 */
static inline void AJ_EXTI_EnableEvent(aj_exti_line_mask_t line){
	AJ_BitReg_SetBit_Mask(&(EXTI->EMR), line);
}

/**
 * @brief  Disables the event on the selected line(s).
 * @param  line Mask of the line(s) to disable. Must not be `AJ_EXTI_LINE_NONE`.
 */
static inline void AJ_EXTI_DisableEvent(aj_exti_line_mask_t line){
	AJ_BitReg_ClearBit_Mask(&(EXTI->EMR), line);
}

/**
 * @brief  Checks whether every line of the mask is enabled in EXTI_EMR.
 * @param  line Mask of the line(s) to test. Must not be `AJ_EXTI_LINE_NONE`.
 * @retval uint8_t:
 *         - 1: All the selected lines are enabled.
 *         - 0: At least one of the selected lines is disabled.
 */
static inline uint8_t AJ_EXTI_IsEventEnabled(aj_exti_line_mask_t line){
	return AJ_BitReg_IsBitSet_Mask(&(EXTI->EMR), line);
}


#ifdef __cplusplus
}
#endif

#endif	/* AJ_EXTI_INCLUDED */