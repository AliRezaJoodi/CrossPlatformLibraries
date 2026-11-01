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
#include "aj_type.h"

/******************************************************************************/
/* Flash access control register (FLASH_ACR)                                  */
/******************************************************************************/
static inline void AJ_Flash_ConfigureLatency(aj_flash_latency_t latency){
	AJ_BitReg_Write3Bit_Position(&(FLASH->ACR), FLASH_ACR_LATENCY_Pos, (uint32_t)latency);
}

static inline aj_flash_latency_t AJ_Flash_GetLatency(void){
	return (aj_flash_latency_t)AJ_BitReg_Get3Bit_Position(&(FLASH->ACR), FLASH_ACR_LATENCY_Pos);
}

static inline void AJ_Flash_ConfigureHalfCycleAccess(aj_enable_state_t state){
	AJ_BitReg_WriteBit_Position(&(FLASH->ACR), FLASH_ACR_HLFCYA_Pos, state);
}

static inline uint32_t AJ_Flash_IsHalfCycleAccessEnabled(void){
	return AJ_BitReg_IsBitSet_Position(&(FLASH->ACR), FLASH_ACR_HLFCYA_Pos);
}

static inline void AJ_Flash_ConfigurePrefetchBuffer(aj_enable_state_t state){
	AJ_BitReg_WriteBit_Position(&(FLASH->ACR), FLASH_ACR_PRFTBE_Pos, state);
}

static inline uint32_t AJ_Flash_IsPrefetchBufferEnabled(void){
	return AJ_BitReg_IsBitSet_Position(&(FLASH->ACR), FLASH_ACR_PRFTBE_Pos);
}


#ifdef __cplusplus
}
#endif

#endif /* AJ_FLASH_INCLUDED */
