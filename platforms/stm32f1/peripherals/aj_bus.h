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
 * @brief  Enable or disable the clock of an AHB peripheral.
 * @param  Periph	AHB peripheral bit position in RCC->AHBENR.
 * @param  mode  	Clock enable state.
 * @note   A read-back is performed after enabling to ensure the write is applied
 *         before further peripheral access.
 */
static inline void AJ_BUS_AHB_ConfigClockEnableStatus(AJ_BUS_AHB_Periph_t Periph, AJ_BUS_ClockEnableStatus_t mode){
	WriteBit_Reg32(&(RCC->AHBENR), Periph, mode);
	
	if(mode == AJ_BUS_ENABLE){
		volatile uint32_t tmpreg = READ_BIT(RCC->AHBENR, (1UL << (uint32_t)Periph));
		(void)tmpreg;
	}
}

/**
 * @brief  Get AHB peripheral clock enable state.
 * @param  Periph	AHB peripheral bit position in RCC->AHBENR.
 * @retval Clock 	enable state.
 */
static inline AJ_BUS_ClockEnableStatus_t AJ_BUS_AHB_GetClockEnableStatus(AJ_BUS_AHB_Periph_t Periph){
	return GetBit_Reg32(&(RCC->AHBENR), Periph);
}

#if defined(RCC_AHBRSTR_SUPPORT)
/**
 * @brief  Force or release reset of an AHB peripheral.
 * @param  Periph AHB peripheral bit position in RCC->AHBRSTR.
 * @param  mode   Reset state.
 * @note   After a reset force/release sequence, the peripheral registers return
 *         to their reset values. The peripheral must be reconfigured before reuse.
 */
static inline void AJ_BUS_AHB_ConfigResetStatus(AJ_BUS_AHB_Periph_t Periph, AJ_BUS_ResetStatus_t mode){
	WriteBit_Reg32(&(RCC->AHBRSTR), Periph, mode);
}
#endif /* RCC_AHBRSTR_SUPPORT */

/**
 * @brief  Enable or disable the clock of an APB1 peripheral.
 * @param  Periph	APB1 peripheral bit position in RCC->APB1ENR.
 * @param  mode  	Clock enable state.
 * @note   A read-back is performed after enabling to ensure the write is applied
 *         before further peripheral access.
 */
static inline void AJ_BUS_APB1_ConfigClockEnableStatus(AJ_BUS_APB1_Periph_t Periph, AJ_BUS_ClockEnableStatus_t mode){
	WriteBit_Reg32(&(RCC->APB1ENR), Periph, mode);
	
	if(mode == AJ_BUS_ENABLE){
		volatile uint32_t tmpreg = READ_BIT(RCC->APB1ENR, (1UL << (uint32_t)Periph));
		(void)tmpreg;
	}
}

/**
 * @brief  Get APB1 peripheral clock enable state.
 * @param  Periph	APB1 peripheral bit position in RCC->APB1ENR.
 * @retval Clock 	enable state.
 */
static inline AJ_BUS_ClockEnableStatus_t AJ_BUS_APB1_GetClockEnableStatus(AJ_BUS_APB1_Periph_t Periph){
	return GetBit_Reg32(&(RCC->APB1ENR), Periph);
}

/**
 * @brief  Force or release reset of an APB1 peripheral.
 * @param  Periph APB1 peripheral bit position in RCC->APB1RSTR.
 * @param  mode   Reset state.
 * @note   After a reset force/release sequence, the peripheral registers return
 *         to their reset values. The peripheral must be reconfigured before reuse.
 */
static inline void AJ_BUS_APB1_ConfigResetStatus(AJ_BUS_APB1_Periph_t Periph, AJ_BUS_ResetStatus_t mode){
	WriteBit_Reg32(&(RCC->APB1RSTR), Periph, mode);
}

/**
 * @brief  Enable or disable the clock of an APB2 peripheral.
 * @param  Periph	APB2 peripheral bit position in RCC->APB2ENR.
 * @param  mode  	Clock enable state.
 * @note   A read-back is performed after enabling to ensure the write is applied
 *         before further peripheral access.
 */
static inline void AJ_BUS_APB2_ConfigClockEnableStatus(AJ_BUS_APB2_Periph_t Periph, AJ_BUS_ClockEnableStatus_t mode){
	WriteBit_Reg32(&(RCC->APB2ENR), Periph, mode);
	
	if(mode == AJ_BUS_ENABLE){
		volatile uint32_t tmpreg = READ_BIT(RCC->APB2ENR, (1UL << (uint32_t)Periph));
		(void)tmpreg;
	}
}

/**
 * @brief  Get APB2 peripheral clock enable state.
 * @param  Periph	APB2 peripheral bit position in RCC->APB2ENR.
 * @retval Clock 	enable state.
 */
static inline AJ_BUS_ClockEnableStatus_t  AJ_BUS_APB2_GetClockEnableStatus(AJ_BUS_APB2_Periph_t Periph){
	return GetBit_Reg32(&(RCC->APB2ENR), Periph);
}

/**
 * @brief  Force or release reset of an APB2 peripheral.
 * @param  Periph APB2 peripheral bit position in RCC->APB2RSTR.
 * @param  mode   Reset state.
 * @note   After a reset force/release sequence, the peripheral registers return
 *         to their reset values. The peripheral must be reconfigured before reuse.
 */
static inline void AJ_BUS_APB2_ConfigResetStatus(AJ_BUS_APB2_Periph_t Periph, AJ_BUS_ResetStatus_t mode){
	WriteBit_Reg32(&(RCC->APB2RSTR), Periph, mode);
}

#ifdef __cplusplus
}
#endif

#endif  /* AJ_BUS_INCLUDED */
	
	