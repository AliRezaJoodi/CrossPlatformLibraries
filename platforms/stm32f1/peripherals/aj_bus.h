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
static inline void AJ_Bus_AHB_EnableClock(aj_bus_ahb_clock_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->AHBENR), periphs);

	// Synchronize RCC write: read back to ensure clock is enabled.
	volatile uint32_t dummy = RCC->AHBENR;
	(void)dummy;
}

static inline aj_bus_clock_state_t AJ_Bus_AHB_IsClockEnabled(aj_bus_ahb_clock_mask_t periphs){
	return AJ_BitReg_IsBitSet_Mask(&(RCC->AHBENR), periphs);
}

static inline void AJ_Bus_AHB_DisableClock(aj_bus_ahb_clock_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->AHBENR), periphs);
}


#if defined(AJ_BUS_AHBRSTR_SUPPORT)
//********************************************************
static inline void AJ_Bus_AHB_ForceReset(aj_bus_ahb_reset_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->AHBRSTR), periphs);
}

static inline void AJ_Bus_AHB_ReleaseReset(aj_bus_ahb_reset_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->AHBRSTR), periphs);
}
#endif /* AJ_BUS_AHBRSTR_SUPPORT */


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


//********************************************************
static inline void AJ_Bus_APB2_EnableClock(aj_bus_apb2_clock_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->APB2ENR), periphs);

	// Synchronize RCC write: read back to ensure clock is enabled.
	volatile uint32_t dummy = RCC->APB2ENR;
	(void)dummy;
}

static inline aj_bus_clock_state_t  AJ_Bus_APB2_IsClockEnabled(aj_bus_apb2_clock_mask_t periphs){
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

#ifdef __cplusplus
}
#endif

#endif  /* AJ_BUS_INCLUDED */
	
	