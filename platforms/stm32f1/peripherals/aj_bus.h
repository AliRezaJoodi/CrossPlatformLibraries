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
#include "bit_register32.h"
#include "aj_bus_type.h"

/**
 * @brief  Enable the clock of the specified AHB peripheral(s).
 * @param  periphs  Bit mask of AHB peripherals in RCC->AHBENR.
 * @note   A read-back is performed after enabling to ensure the write is applied
 *         before further peripheral access.
 */
static inline void AJ_BUS_AHB_EnableClock(AJ_BUS_AHB_PeriphMask_t periphs){
	volatile uint32_t tmpreg;

	SetBitMask_Reg32(&(RCC->AHBENR), periphs);

	tmpreg = READ_BIT(RCC->AHBENR, periphs);
	(void)tmpreg;
}

/**
 * @brief  Disable the clock of the specified AHB peripheral(s).
 * @param  periphs  Bit mask of AHB peripherals in RCC->AHBENR.
 */
static inline void AJ_BUS_AHB_DisableClock(AJ_BUS_AHB_PeriphMask_t periphs){
	ClearBitMask_Reg32(&(RCC->AHBENR), periphs);
}

/**
 * @brief  Check whether the specified AHB peripheral clock(s) are enabled.
 * @param  periphs  Bit mask of AHB peripherals in RCC->AHBENR.
 * @retval Clock enable status.
 */
static inline AJ_BUS_ClockEnableStatus_t AJ_BUS_AHB_IsClockEnabled(AJ_BUS_AHB_PeriphMask_t periphs){
	return IsBitMaskSet_Reg32(&(RCC->AHBENR), periphs);
}

#if defined(RCC_AHBRSTR_SUPPORT)
/**
 * @brief  Force reset of the specified AHB peripheral(s).
 * @param  periphs  Bit mask of AHB peripherals in RCC->AHBRSTR.
 */
static inline void AJ_BUS_AHB_ForceReset(AJ_BUS_AHB_PeriphMask_t periphs){
	SetBitMask_Reg32(&(RCC->AHBRSTR), periphs);
}

/**
 * @brief  Release reset of the specified AHB peripheral(s).
 * @param  periphs  Bit mask of AHB peripherals in RCC->AHBRSTR.
 * @note   After a force/release reset sequence, the peripheral registers return
 *         to their reset values. The peripheral must be reconfigured before reuse.
 */
static inline void AJ_BUS_AHB_ReleaseReset(AJ_BUS_AHB_PeriphMask_t periphs){
	ClearBitMask_Reg32(&(RCC->AHBRSTR), periphs);
}
#endif /* RCC_AHBRSTR_SUPPORT */

/**
 * @brief  Enable the clock of the specified APB1 peripheral(s).
 * @param  periphs  Bit mask of APB1 peripherals in RCC->APB1ENR.
 * @note   A read-back is performed after enabling to ensure the write is applied
 *         before further peripheral access.
 */
static inline void AJ_BUS_APB1_EnableClock(AJ_BUS_APB1_PeriphMask_t periphs){
	volatile uint32_t tmpreg;

	SetBitMask_Reg32(&(RCC->APB1ENR), periphs);

	tmpreg = READ_BIT(RCC->APB1ENR, periphs);
	(void)tmpreg;
}

/**
 * @brief  Disable the clock of the specified APB1 peripheral(s).
 * @param  periphs  Bit mask of APB1 peripherals in RCC->APB1ENR.
 */
static inline void AJ_BUS_APB1_DisableClock(AJ_BUS_APB1_PeriphMask_t periphs){
	ClearBitMask_Reg32(&(RCC->APB1ENR), periphs);
}

/**
 * @brief  Check whether the specified APB1 peripheral clock(s) are enabled.
 * @param  periphs  Bit mask of APB1 peripherals in RCC->APB1ENR.
 * @retval Clock enable status.
 */
static inline AJ_BUS_ClockEnableStatus_t AJ_BUS_APB1_IsClockEnabled(AJ_BUS_APB1_PeriphMask_t periphs){
	return IsBitMaskSet_Reg32(&(RCC->APB1ENR), periphs);
}

/**
 * @brief  Force reset of the specified APB1 peripheral(s).
 * @param  periphs  Bit mask of APB1 peripherals in RCC->APB1RSTR.
 */
static inline void AJ_BUS_APB1_ForceReset(AJ_BUS_APB1_PeriphMask_t periphs){
	SetBitMask_Reg32(&(RCC->APB1RSTR), periphs);
}

/**
 * @brief  Release reset of the specified APB1 peripheral(s).
 * @param  periphs  Bit mask of APB1 peripherals in RCC->APB1RSTR.
 * @note   After a force/release reset sequence, the peripheral registers return
 *         to their reset values. The peripheral must be reconfigured before reuse.
 */
static inline void AJ_BUS_APB1_ReleaseReset(AJ_BUS_APB1_PeriphMask_t periphs){
	ClearBitMask_Reg32(&(RCC->APB1RSTR), periphs);
}

/**
 * @brief  Enable the clock of the specified APB2 peripheral(s).
 * @param  periphs  Bit mask of APB2 peripherals in RCC->APB2ENR.
 * @note   A read-back is performed after enabling to ensure the write is applied
 *         before further peripheral access.
 */
static inline void AJ_BUS_APB2_EnableClock(AJ_BUS_APB2_PeriphMask_t periphs){
	volatile uint32_t tmpreg;

	SetBitMask_Reg32(&(RCC->APB2ENR), periphs);
	
	tmpreg = READ_BIT(RCC->APB2ENR, periphs);
	(void)tmpreg;
}

/**
 * @brief  Disable the clock of the specified APB2 peripheral(s).
 * @param  periphs  Bit mask of APB2 peripherals in RCC->APB2ENR.
 */
static inline void AJ_BUS_APB2_DisableClock(AJ_BUS_APB2_PeriphMask_t periphs){
	ClearBitMask_Reg32(&(RCC->APB2ENR), periphs);
}

/**
 * @brief  Check whether the specified APB2 peripheral clock(s) are enabled.
 * @param  periphs  Bit mask of APB2 peripherals in RCC->APB2ENR.
 * @retval Clock enable status.
 */
static inline AJ_BUS_ClockEnableStatus_t  AJ_BUS_APB2_IsClockEnabled(AJ_BUS_APB2_PeriphMask_t periphs){
	return IsBitMaskSet_Reg32(&(RCC->APB2ENR), periphs);
}

/**
 * @brief  Force reset of the specified APB2 peripheral(s).
 * @param  periphs  Bit mask of APB2 peripherals in RCC->APB2RSTR.
 */
static inline void AJ_BUS_APB2_ForceReset(AJ_BUS_APB2_PeriphMask_t periphs){
	SetBitMask_Reg32(&(RCC->APB2RSTR), periphs);
}

/**
 * @brief  Release reset of the specified APB2 peripheral(s).
 * @param  periphs  Bit mask of APB2 peripherals in RCC->APB2RSTR.
 * @note   After a force/release reset sequence, the peripheral registers return
 *         to their reset values. The peripheral must be reconfigured before reuse.
 */
static inline void AJ_BUS_APB2_ReleaseReset(AJ_BUS_APB2_PeriphMask_t periphs){
	ClearBitMask_Reg32(&(RCC->APB2RSTR), periphs);
}

#ifdef __cplusplus
}
#endif

#endif  /* AJ_BUS_INCLUDED */
	
	