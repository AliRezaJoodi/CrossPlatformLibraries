/**
 * @brief   Bus clock, reset, and low-power clock control interface for STM32F4 peripherals.
 *
 * This file provides helper APIs for managing peripheral bus control registers, including:
 * - RCC->AHB1ENR
 * - RCC->AHB2ENR
 * - RCC->AHB3ENR
 * - RCC->APB1ENR
 * - RCC->APB2ENR
 * - RCC->AHB1RSTR
 * - RCC->AHB2RSTR
 * - RCC->AHB3RSTR
 * - RCC->APB1RSTR
 * - RCC->APB2RSTR
 * - RCC->AHB1LPENR
 * - RCC->AHB2LPENR
 * - RCC->AHB3LPENR
 * - RCC->APB1LPENR
 * - RCC->APB2LPENR
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
#include <stm32f4xx.h>
#include "aj_bit_reg.h"
#include "aj_bus_type.h"

//********************************************************
static inline void AJ_Bus_EnableClock_AHB1(aj_bus_clock_ahb1_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->AHB1ENR), periphs);
	
	// Synchronize RCC write: read back to ensure clock is enabled.
	volatile uint32_t dummy = RCC->AHB1ENR;
	(void)dummy;
}

static inline aj_bus_clock_state_t AJ_Bus_IsClockEnabled_AHB1(aj_bus_clock_ahb1_mask_t periphs){
	return AJ_BitReg_IsBitSet_Mask(&(RCC->AHB1ENR), periphs);
}

static inline void AJ_Bus_DisableClock_AHB1(aj_bus_clock_ahb1_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->AHB1ENR), periphs);
}

static inline void AJ_Bus_ForceReset_AHB1(aj_bus_reset_ahb1_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->AHB1RSTR), periphs);
}

static inline void AJ_Bus_ReleaseReset_AHB1(aj_bus_reset_ahb1_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->AHB1RSTR), periphs);
}

static inline void AJ_Bus_EnableClockInLowPower_AHB1(aj_bus_clock_lp_ahb1_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->AHB1LPENR), periphs);

	volatile uint32_t dummy = RCC->AHB1LPENR;
	(void)dummy;
}

static inline void AJ_Bus_DisableClockInLowPower_AHB1(aj_bus_clock_lp_ahb1_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->AHB1LPENR), periphs);
}


#if defined(RCC_AHB2_SUPPORT)
//********************************************************
static inline void AJ_Bus_EnableClock_AHB2(aj_bus_clock_ahb2_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->AHB2ENR), periphs);

	// Synchronize RCC write: read back to ensure clock is enabled.
	volatile uint32_t dummy = RCC->AHB2ENR;
	(void)dummy;
}

static inline aj_bus_clock_state_t AJ_Bus_IsClockEnabled_AHB2(aj_bus_clock_ahb2_mask_t periphs){
	return AJ_BitReg_IsBitSet_Mask(&(RCC->AHB2ENR), periphs);
}

static inline void AJ_Bus_DisableClock_AHB2(aj_bus_clock_ahb2_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->AHB2ENR), periphs);
}

static inline void AJ_Bus_ForceReset_AHB2(aj_bus_reset_ahb2_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->AHB2RSTR), periphs);
}

static inline void AJ_Bus_ReleaseReset_AHB2(aj_bus_reset_ahb2_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->AHB2RSTR), periphs);
}

static inline void AJ_Bus_EnableClockInLowPower_AHB2(aj_bus_clock_lp_ahb2_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->AHB2LPENR), periphs);

	volatile uint32_t dummy = RCC->AHB2LPENR;
	(void)dummy;
}

static inline void AJ_Bus_DisableClockInLowPower_AHB2(aj_bus_clock_lp_ahb2_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->AHB2LPENR), periphs);
}
#endif  /* RCC_AHB2_SUPPORT */


#if defined(RCC_AHB3_SUPPORT)
//********************************************************
static inline void AJ_Bus_EnableClock_AHB3(aj_bus_clock_ahb3_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->AHB3ENR), periphs);

	// Synchronize RCC write: read back to ensure clock is enabled.
	volatile uint32_t dummy = RCC->AHB3ENR;
	(void)dummy;
}

static inline aj_bus_clock_state_t AJ_Bus_IsClockEnabled_AHB3(aj_bus_clock_ahb3_mask_t periphs){
	return AJ_BitReg_IsBitSet_Mask(&(RCC->AHB3ENR), periphs);
}

static inline void AJ_Bus_DisableClock_AHB3(aj_bus_clock_ahb3_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->AHB3ENR), periphs);
}

static inline void AJ_Bus_ForceReset_AHB3(aj_bus_reset_ahb3_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->AHB3RSTR), periphs);
}

static inline void AJ_Bus_ReleaseReset_AHB3(aj_bus_reset_ahb3_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->AHB3RSTR), periphs);
}

static inline void AJ_Bus_EnableClockInLowPower_AHB3(aj_bus_clock_lp_ahb3_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->AHB3LPENR), periphs);

	volatile uint32_t dummy = RCC->AHB3LPENR;
	(void)dummy;
}

static inline void AJ_Bus_DisableClockInLowPower_AHB3(aj_bus_clock_lp_ahb3_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->AHB3LPENR), periphs);
}
#endif  /* RCC_AHB3_SUPPORT */


//********************************************************
static inline void AJ_Bus_EnableClock_APB1(aj_bus_clock_apb1_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->APB1ENR), periphs);

	// Synchronize RCC write: read back to ensure clock is enabled.
	volatile uint32_t dummy = RCC->APB1ENR;
	(void)dummy;
}

static inline aj_bus_clock_state_t AJ_Bus_IsClockEnabled_APB1(aj_bus_clock_apb1_mask_t periphs){
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

static inline void AJ_Bus_EnableClockInLowPower_APB1(aj_bus_clock_lp_apb1_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->APB1LPENR), periphs);

	volatile uint32_t dummy = RCC->APB1LPENR;
	(void)dummy;
}

static inline void AJ_Bus_DisableClockInLowPower_APB1(aj_bus_clock_lp_apb1_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->APB1LPENR), periphs);
}


//********************************************************
static inline void AJ_Bus_EnableClock_APB2(aj_bus_clock_apb2_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->APB2ENR), periphs);

	// Synchronize RCC write: read back to ensure clock is enabled.
	volatile uint32_t dummy = RCC->APB2ENR;
	(void)dummy;
}

static inline aj_bus_clock_state_t AJ_Bus_IsClockEnabled_APB2(aj_bus_clock_apb2_mask_t periphs){
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

static inline void AJ_Bus_EnableClockInLowPower_APB2(aj_bus_clock_lp_apb2_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->APB2LPENR), periphs);

	// Synchronize RCC write: read back to ensure clock is enabled.
	volatile uint32_t dummy = RCC->APB2LPENR;
	(void)dummy;
}

static inline void AJ_Bus_DisableClockInLowPower_APB2(aj_bus_clock_lp_apb2_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->APB2LPENR), periphs);
}


#ifdef __cplusplus
}
#endif

#endif  /* AJ_BUS_INCLUDED */
