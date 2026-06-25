/**
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

//****************************************************************************
static inline void AJ_BUS_AHB1_EnableClock(aj_bus_ahb1_clock_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->AHB1ENR), periphs);

	volatile uint32_t dummy = RCC->AHB1ENR;
	(void)dummy;
}

static inline aj_bus_clock_state_t AJ_BUS_AHB1_IsClockEnabled(aj_bus_ahb1_clock_mask_t periphs){
	return AJ_BitReg_IsBitSet_Mask(&(RCC->AHB1ENR), periphs);
}

static inline void AJ_BUS_AHB1_DisableClock(aj_bus_ahb1_clock_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->AHB1ENR), periphs);
}

static inline void AJ_BUS_AHB1_ForceReset(aj_bus_ahb1_reset_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->AHB1RSTR), periphs);
}

static inline void AJ_BUS_AHB1_ReleaseReset(aj_bus_ahb1_reset_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->AHB1RSTR), periphs);
}

static inline void AJ_BUS_AHB1_EnableClockInLowPower(aj_bus_ahb1_clock_lp_mask_t periphs){
	AJ_BitReg_SetBit_Mask(&(RCC->AHB1LPENR), periphs);

	volatile uint32_t dummy = RCC->AHB1LPENR;
	(void)dummy;
}

static inline void AJ_BUS_AHB1_DisableClockInLowPower(aj_bus_ahb1_clock_lp_mask_t periphs){
	AJ_BitReg_ClearBit_Mask(&(RCC->AHB1LPENR), periphs);
}


#ifdef __cplusplus
}
#endif

#endif  /* AJ_BUS_INCLUDED */
