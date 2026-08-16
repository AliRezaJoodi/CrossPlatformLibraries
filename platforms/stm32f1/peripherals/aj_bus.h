/**
 * @brief   Bus clock and reset control interface for STM32 peripherals.
 *
 * This file provides helper APIs for managing peripheral bus control registers, including:
 * - RCC->AHBENR
 * - RCC->APB1ENR
 * - RCC->APB2ENR
 * - RCC->AHBRSTR
 * - RCC->APB1RSTR
 * - RCC->APB2RSTR
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_BUS_INCLUDED
#define AJ_BUS_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include <stm32f1xx.h>
#include "aj_bit_reg.h"
#include "aj_bus_type.h"

#if defined(RCC_AHBRSTR_OTGFSRST_Msk) || defined(RCC_AHBRSTR_ETHMACRST_Msk)
	#define AJ_BUS_AHBRSTR_SUPPORT
#endif

//********************************************************
static inline void AJ_Bus_EnableClock_AHB(aj_bus_clock_ahb_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->AHBENR), periphs);

	// Synchronize RCC write: read back to ensure clock is enabled.
	volatile uint32_t dummy = RCC->AHBENR;
	(void)dummy;
}

static inline uint8_t AJ_Bus_IsClockEnabled_AHB(aj_bus_clock_ahb_mask_t periphs){
	return AJ_BitReg_IsBitSet_Mask(&(RCC->AHBENR), periphs);
}

static inline void AJ_Bus_DisableClock_AHB(aj_bus_clock_ahb_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->AHBENR), periphs);
}


#if defined(AJ_BUS_AHBRSTR_SUPPORT)
//********************************************************
static inline void AJ_Bus_ForceReset_AHB(aj_bus_reset_ahb_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->AHBRSTR), periphs);
}

static inline void AJ_Bus_ReleaseReset_AHB(aj_bus_reset_ahb_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->AHBRSTR), periphs);
}
#endif /* AJ_BUS_AHBRSTR_SUPPORT */


//********************************************************
static inline void AJ_Bus_EnableClock_APB1(aj_bus_clock_apb1_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->APB1ENR), periphs);

	// Synchronize RCC write: read back to ensure clock is enabled.
	volatile uint32_t dummy = RCC->APB1ENR;
	(void)dummy;
}

static inline uint8_t AJ_Bus_IsClockEnabled_APB1(aj_bus_clock_apb1_mask_t periphs){
	return AJ_BitReg_IsBitSet_Mask(&(RCC->APB1ENR), periphs);
}

static inline void AJ_Bus_DisableClock_APB1(aj_bus_clock_apb1_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->APB1ENR), periphs);
}

static inline void AJ_Bus_ForceReset_APB1(aj_bus_reset_apb1_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->APB1RSTR), periphs);
}

static inline void AJ_Bus_ReleaseReset_APB1(aj_bus_reset_apb1_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->APB1RSTR), periphs);
}


//********************************************************
static inline void AJ_Bus_EnableClock_APB2(aj_bus_clock_apb2_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->APB2ENR), periphs);

	// Synchronize RCC write: read back to ensure clock is enabled.
	volatile uint32_t dummy = RCC->APB2ENR;
	(void)dummy;
}

static inline uint8_t  AJ_Bus_IsClockEnabled_APB2(aj_bus_clock_apb2_mask_t periphs){
	return AJ_BitReg_IsBitSet_Mask(&(RCC->APB2ENR), periphs);
}

static inline void AJ_Bus_DisableClock_APB2(aj_bus_clock_apb2_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->APB2ENR), periphs);
}

static inline void AJ_Bus_ForceReset_APB2(aj_bus_reset_apb2_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->APB2RSTR), periphs);
}

static inline void AJ_Bus_ReleaseReset_APB2(aj_bus_reset_apb2_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->APB2RSTR), periphs);
}

#ifdef __cplusplus
}
#endif

#endif  /* AJ_BUS_INCLUDED */
	
	