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
 * REQUIREMENT 1: Source Files to Build
 * -----------------------------------------------------------------------------
 * The following source files must be compiled and linked in the project:
 * - `aj_rtc.c`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 2: Application Setup (BUS Configuration)
 * -----------------------------------------------------------------------------
 * This library does not enable any peripheral clock.
 * The application must enable the required clock buses before using this driver.
 * - The clock bus of the RTC peripheral (backup domain, etc.)
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
 * @see    STM32 training and RTC usage example:
 *         https://github.com/AliRezaJoodi/STM32_Exercises/tree/main/RTC_F103/BareMetal
 *
 * -----------------------------------------------------------------------------
 * Source
 * -----------------------------------------------------------------------------
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
/* Status register (RTC_CRL): flags                                           */
/******************************************************************************/
static inline uint8_t AJ_RTC_IsFlagActive(aj_rtc_flag_r_t flag){
	return AJ_BitReg_IsBitSet_Mask(&(RTC->CRL), flag);
}

static inline void AJ_RTC_ClearFlag(aj_rtc_flag_w0_t flag){
	AJ_BitReg_ClearBit_Mask(&(RTC->CRL), flag);
}

/******************************************************************************/
/* Config mode (RTC_CRL_CNF)                                                  */
/******************************************************************************/
/**
 * @brief  Enters the RTC configuration mode.
 *         This function must be called before any write operation on
 *         the RTC data registers.
 * @retval aj_result_state_t:
 *         - AJ_SUCCESS: RTC is in configuration mode.
 *         - AJ_FAILURE: Timeout while waiting for the current write operation.
 */
aj_result_state_t AJ_RTC_EnterConfigMode(void);

/**
 * @brief  Exits the RTC configuration mode.
 *         This function must be called after finishing the write operations
 *         on the RTC data registers.
 * @retval aj_result_state_t:
 *         - AJ_SUCCESS: RTC is out of configuration mode.
 *         - AJ_FAILURE: Timeout while waiting for the write sequence to finish.
 */
aj_result_state_t AJ_RTC_ExitConfigMode(void);

/**
 * @brief  Synchronizes the RTC registers with the APB1 bus.
 *         This function must be called once after waking up from a
 *         low-power mode (STOP/STANDBY) or after any change to the
 *         APB1 clock configuration.
 * @retval aj_result_state_t:
 *         - AJ_SUCCESS: Registers are synchronized.
 *         - AJ_FAILURE: Timeout while waiting for synchronization.
 */
aj_result_state_t AJ_RTC_Synchronize(void);

/******************************************************************************/
/* Control register high (RTC_CRH): interrupt enables                         */
/******************************************************************************/
static inline void AJ_RTC_ConfigOverflowInterrupt(aj_operation_state_t state){
	AJ_BitReg_WriteBit_Position(&(RTC->CRH), RTC_CRH_OWIE_Pos, state);
}

static inline uint8_t AJ_RTC_IsOverflowInterruptEnabled(void){
	return AJ_BitReg_IsBitSet_Mask(&(RTC->CRH), RTC_CRH_OWIE_Msk);
}

static inline void AJ_RTC_ConfigAlarmInterrupt(aj_operation_state_t state){
	AJ_BitReg_WriteBit_Position(&(RTC->CRH), RTC_CRH_ALRIE_Pos, state);
}

static inline uint8_t AJ_RTC_IsAlarmInterruptEnabled(void){
	return AJ_BitReg_IsBitSet_Mask(&(RTC->CRH), RTC_CRH_ALRIE_Msk);
}

static inline void AJ_RTC_ConfigSecondInterrupt(aj_operation_state_t state){
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
uint32_t AJ_RTC_ReadPrescaler(void);

void AJ_RTC_WritePrescaler(uint32_t value);

/******************************************************************************/
/* Divider register (RTC_DIVL + RTC_DIVH)                                     */
/******************************************************************************/
uint32_t AJ_RTC_ReadDivider(void);


#ifdef __cplusplus
}
#endif

#endif	/* AJ_RTC_INCLUDED */