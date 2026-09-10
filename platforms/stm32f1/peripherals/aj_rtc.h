/**
 * @brief   Real-time clock (RTC) interface for STM32 peripherals.
 *
 * This file provides helper APIs for managing RTC control, status and
 * data registers, including:
 * - RTC->CRL
 * - RTC->CRH
 * - RTC->CNTH + RTC->CNTL
 * - RTC->ALRH + RTC->ALRL
 * - RTC->PRLH + RTC->PRLL
 * - RTC->DIVH + RTC->DIVL
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: Compilation & Linkage
 * -----------------------------------------------------------------------------
 * The following source files must be compiled and linked in the project:
 * - `aj_rtc.c`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 2: BUS Configuration
 * -----------------------------------------------------------------------------
 * This library does not enable any peripheral clock.
 * The application must enable the required clock buses before using this driver.
 * - The clock bus of the RTC peripheral (backup domain, etc.)
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_RTC_INCLUDED
#define AJ_RTC_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include <stm32f1xx.h>
#include "aj_bit_reg.h"
#include "aj_type.h"
#include "aj_rtc_type.h"

/******************************************************************************/
/* Control register high (RTC_CRH): interrupt enables                         */
/******************************************************************************/
static inline void AJ_RTC_ConfigOverflowInterrupt(aj_state_enable_t state){
	AJ_BitReg_WriteBit_Position(&(RTC->CRH), RTC_CRH_OWIE_Pos, state);
}

static inline uint8_t AJ_RTC_IsOverflowInterruptEnabled(void){
	return AJ_BitReg_IsBitSet_Mask(&(RTC->CRH), RTC_CRH_OWIE_Msk);
}

static inline void AJ_RTC_ConfigAlarmInterrupt(aj_state_enable_t state){
	AJ_BitReg_WriteBit_Position(&(RTC->CRH), RTC_CRH_ALRIE_Pos, state);
}

static inline uint8_t AJ_RTC_IsAlarmInterruptEnabled(void){
	return AJ_BitReg_IsBitSet_Mask(&(RTC->CRH), RTC_CRH_ALRIE_Msk);
}

static inline void AJ_RTC_ConfigSecondInterrupt(aj_state_enable_t state){
	AJ_BitReg_WriteBit_Position(&(RTC->CRH), RTC_CRH_SECIE_Pos, state);
}

static inline uint8_t AJ_RTC_IsSecondInterruptEnabled(void){
	return AJ_BitReg_IsBitSet_Mask(&(RTC->CRH), RTC_CRH_SECIE_Msk);
}

/******************************************************************************/
/* Time counter registers (RTC_CNTL + RTC_CNTH)                               */
/******************************************************************************/
uint32_t AJ_RTC_ReadCounter(void);

void AJ_RTC_WriteCounter(uint32_t value);

/******************************************************************************/
/* Alarm registers (RTC_ALRL + RTC_ALRH)                                      */
/******************************************************************************/
uint32_t AJ_RTC_ReadAlarm(void);

void AJ_RTC_WriteAlarm(uint32_t value);

/******************************************************************************/
/* Prescaler load registers (RTC_PRLL + RTC_PRLH)                             */
/******************************************************************************/
void AJ_RTC_WritePrescaler(uint32_t value);


#ifdef __cplusplus
}
#endif

#endif	/* AJ_RTC_INCLUDED */