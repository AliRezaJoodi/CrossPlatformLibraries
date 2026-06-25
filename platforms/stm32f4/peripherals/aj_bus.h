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
static inline void AJ_Bus_AHB1_EnableClock(aj_bus_ahb1_clock_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->AHB1ENR), periphs);
	
	// Synchronize RCC write: read back to ensure clock is enabled.
	volatile uint32_t dummy = RCC->AHB1ENR;
	(void)dummy;
}

static inline aj_bus_clock_state_t AJ_Bus_AHB1_IsClockEnabled(aj_bus_ahb1_clock_mask_t periphs){
	return AJ_BitReg_IsBitSet_Mask(&(RCC->AHB1ENR), periphs);
}

static inline void AJ_Bus_AHB1_DisableClock(aj_bus_ahb1_clock_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->AHB1ENR), periphs);
}

static inline void AJ_Bus_AHB1_ForceReset(aj_bus_ahb1_reset_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->AHB1RSTR), periphs);
}

static inline void AJ_Bus_AHB1_ReleaseReset(aj_bus_ahb1_reset_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->AHB1RSTR), periphs);
}

static inline void AJ_Bus_AHB1_EnableClockInLowPower(aj_bus_ahb1_clock_lp_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->AHB1LPENR), periphs);

	volatile uint32_t dummy = RCC->AHB1LPENR;
	(void)dummy;
}

static inline void AJ_Bus_AHB1_DisableClockInLowPower(aj_bus_ahb1_clock_lp_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->AHB1LPENR), periphs);
}


#if defined(RCC_AHB2_SUPPORT)
//********************************************************
static inline void AJ_Bus_AHB2_EnableClock(aj_bus_ahb2_clock_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->AHB2ENR), periphs);

	// Synchronize RCC write: read back to ensure clock is enabled.
	volatile uint32_t dummy = RCC->AHB2ENR;
	(void)dummy;
}

static inline aj_bus_clock_state_t AJ_Bus_AHB2_IsClockEnabled(aj_bus_ahb2_clock_mask_t periphs){
	return AJ_BitReg_IsBitSet_Mask(&(RCC->AHB2ENR), periphs);
}

static inline void AJ_Bus_AHB2_DisableClock(aj_bus_ahb2_clock_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->AHB2ENR), periphs);
}

static inline void AJ_Bus_AHB2_ForceReset(aj_bus_ahb2_reset_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->AHB2RSTR), periphs);
}

static inline void AJ_Bus_AHB2_ReleaseReset(aj_bus_ahb2_reset_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->AHB2RSTR), periphs);
}

static inline void AJ_Bus_AHB2_EnableClockInLowPower(aj_bus_ahb2_clock_lp_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->AHB2LPENR), periphs);

	volatile uint32_t dummy = RCC->AHB2LPENR;
	(void)dummy;
}

static inline void AJ_Bus_AHB2_DisableClockInLowPower(aj_bus_ahb2_clock_lp_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->AHB2LPENR), periphs);
}
#endif  /* RCC_AHB2_SUPPORT */


#if defined(RCC_AHB3_SUPPORT)
//********************************************************
static inline void AJ_Bus_AHB3_EnableClock(aj_bus_ahb3_clock_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->AHB3ENR), periphs);

	// Synchronize RCC write: read back to ensure clock is enabled.
	volatile uint32_t dummy = RCC->AHB3ENR;
	(void)dummy;
}

static inline aj_bus_clock_state_t AJ_Bus_AHB3_IsClockEnabled(aj_bus_ahb3_clock_mask_t periphs){
	return AJ_BitReg_IsBitSet_Mask(&(RCC->AHB3ENR), periphs);
}

static inline void AJ_Bus_AHB3_DisableClock(aj_bus_ahb3_clock_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->AHB3ENR), periphs);
}

static inline void AJ_Bus_AHB3_ForceReset(aj_bus_ahb3_reset_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->AHB3RSTR), periphs);
}

static inline void AJ_Bus_AHB3_ReleaseReset(aj_bus_ahb3_reset_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->AHB3RSTR), periphs);
}

static inline void AJ_Bus_AHB3_EnableClockInLowPower(aj_bus_ahb3_clock_lp_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->AHB3LPENR), periphs);

	volatile uint32_t dummy = RCC->AHB3LPENR;
	(void)dummy;
}

static inline void AJ_Bus_AHB3_DisableClockInLowPower(aj_bus_ahb3_clock_lp_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->AHB3LPENR), periphs);
}
#endif  /* RCC_AHB3_SUPPORT */


//********************************************************
static inline void AJ_Bus_APB1_EnableClock(aj_bus_apb1_clock_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->APB1ENR), periphs);

	// Synchronize RCC write: read back to ensure clock is enabled.
	volatile uint32_t dummy = RCC->APB1ENR;
	(void)dummy;
}

static inline aj_bus_clock_state_t AJ_Bus_APB1_IsClockEnabled(aj_bus_apb1_clock_mask_t periphs){
	return AJ_BitReg_IsBitSet_Mask(&(RCC->APB1ENR), periphs);
}

static inline void AJ_Bus_APB1_DisableClock(aj_bus_apb1_clock_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->APB1ENR), periphs);
}

static inline void AJ_Bus_APB1_ForceReset(aj_bus_apb1_reset_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->APB1RSTR), periphs);
}

static inline void AJ_Bus_APB1_ReleaseReset(aj_bus_apb1_reset_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->APB1RSTR), periphs);
}

static inline void AJ_Bus_APB1_EnableClockInLowPower(aj_bus_apb1_clock_lp_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->APB1LPENR), periphs);

	volatile uint32_t dummy = RCC->APB1LPENR;
	(void)dummy;
}

static inline void AJ_Bus_APB1_DisableClockInLowPower(aj_bus_apb1_clock_lp_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->APB1LPENR), periphs);
}


//********************************************************
static inline void AJ_Bus_APB2_EnableClock(aj_bus_apb2_clock_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->APB2ENR), periphs);

	// Synchronize RCC write: read back to ensure clock is enabled.
	volatile uint32_t dummy = RCC->APB2ENR;
	(void)dummy;
}

static inline aj_bus_clock_state_t AJ_Bus_APB2_IsClockEnabled(aj_bus_apb2_clock_mask_t periphs){
	return AJ_BitReg_IsBitSet_Mask(&(RCC->APB2ENR), periphs);
}

static inline void AJ_Bus_APB2_DisableClock(aj_bus_apb2_clock_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->APB2ENR), periphs);
}

static inline void AJ_Bus_APB2_ForceReset(aj_bus_apb2_reset_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->APB2RSTR), periphs);
}

static inline void AJ_Bus_APB2_ReleaseReset(aj_bus_apb2_reset_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->APB2RSTR), periphs);
}

static inline void AJ_Bus_APB2_EnableClockInLowPower(aj_bus_apb2_clock_lp_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->APB2LPENR), periphs);

	// Synchronize RCC write: read back to ensure clock is enabled.
	volatile uint32_t dummy = RCC->APB2LPENR;
	(void)dummy;
}

static inline void AJ_Bus_APB2_DisableClockInLowPower(aj_bus_apb2_clock_lp_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->APB2LPENR), periphs);
}


#ifdef __cplusplus
}
#endif

#endif  /* AJ_BUS_INCLUDED */
