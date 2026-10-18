/**
 * @brief   Power control (PWR) interface for STM32 peripherals.
 *
 * This file provides helper APIs for managing PWR control and status
 * registers, including:
 * - PWR->CR
 * - PWR->CSR
 *
 * @note    This header is under editing and will be completed gradually.
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: Source Files to Build
 * -----------------------------------------------------------------------------
 * The following source files must be compiled and linked in the project:
 * - `aj_pwr.c`
 *
 * -----------------------------------------------------------------------------
 * Source
 * -----------------------------------------------------------------------------
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_PWR_INCLUDED
#define AJ_PWR_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include <stm32f1xx.h>
#include "aj_bit_reg.h"
#include "aj_type.h"
#include "aj_pwr_type.h"

/******************************************************************************/
/* PWR->CR                                                                    */
/******************************************************************************/
/**
 * @brief  Enables or disables access to the backup domain
 *         (RTC and backup registers) by driving the DBP bit.
 * @param  Enable/Disable State
 * @note   If the HSE divided by 128 is used as the RTC clock, this bit must
 *         remain set to 1.
 */
static inline void AJ_PWR_ConfigureBackupDomainAccess(aj_operation_state_t state){
	AJ_BitReg_WriteBit_Position(&(PWR->CR), PWR_CR_DBP_Pos, state);
}

/**
 * @brief  Reports whether access to the backup domain
 *         (RTC and backup registers) is enabled.
 * @return DBP bit state:
 *         - 1: access to the backup domain is allowed
 *         - 0: access to the backup domain is protected
 */
static inline uint8_t AJ_PWR_IsBackupDomainAccessEnabled(void){
	return AJ_BitReg_IsBitSet_Mask(&(PWR->CR), PWR_CR_DBP_Msk);
}

/**
 * @brief  Selects the PVD voltage threshold by driving the PLS[2:0] bits.
 * @param  level PVD voltage threshold to select.
 * @note   The PVD must be enabled separately via the PVDE bit to be active.
 */
static inline void AJ_PWR_ConfigurePVDLevel(aj_pwr_pvd_level_t level){
	AJ_BitReg_Write3Bit_Position(&(PWR->CR), PWR_CR_PLS_Pos, level);
}

/**
 * @brief  Reads the selected PVD voltage threshold.
 * @return PVD voltage threshold.
 */
static inline aj_pwr_pvd_level_t AJ_PWR_GetPVDLevel(void){
	return (aj_pwr_pvd_level_t)AJ_BitReg_Get3Bit_Position(&(PWR->CR), PWR_CR_PLS_Pos);
}

/**
 * @brief  Enables or disables the programmable voltage detector (PVD).
 * @param  Enable/Disable State
 */
static inline void AJ_PWR_ConfigurePVDEnable(aj_operation_state_t state){
	AJ_BitReg_WriteBit_Position(&(PWR->CR), PWR_CR_PVDE_Pos, state);
}

/**
 * @brief  Reports whether the programmable voltage detector (PVD) is enabled.
 * @return PVD state:
 *         - 1: PVD enabled
 *         - 0: PVD disabled
 */
static inline uint8_t AJ_PWR_IsPVDEnabled(void){
	return AJ_BitReg_IsBitSet_Mask(&(PWR->CR), PWR_CR_PVDE_Msk);
}

/**
 * @brief  Clears one or more PWR flags.
 * @param  flag Flag(s) to clear; combine with the bitwise OR operator.
 */
static inline void AJ_PWR_ClearFlag(aj_pwr_flag_clear_t flag){
	AJ_BitReg_SetBit_Mask(&(PWR->CR), flag);
}

/**
 * @brief  Selects the power mode entered when the CPU enters deepsleep.
 * @param  mode Power mode entered on deepsleep.
 */
static inline void AJ_PWR_ConfigureDeepSleepMode(aj_pwr_deepsleep_t mode){
	AJ_BitReg_Write2Bit_Position(&(PWR->CR), PWR_CR_LPDS_Pos, mode);
}

/**
 * @brief  Reads the power mode entered when the CPU enters deepsleep.
 * @return Power mode entered on deepsleep.
 */
static inline aj_pwr_deepsleep_t AJ_PWR_GetDeepSleepMode(void){
	return (aj_pwr_deepsleep_t)AJ_BitReg_Get2Bit_Position(&(PWR->CR), PWR_CR_LPDS_Pos);
}

/******************************************************************************/
/* PWR->CSR                                                                   */
/******************************************************************************/
/**
 * @brief  Enables or disables the wakeup (WKUP) pin function.
 * @param  state  WKUP pin configuration:
 *                - AJ_ENABLE: pin wakes up the device from Standby mode
 *                - AJ_DISABLE: pin used as general purpose I/O
 * @note   Reset by a system reset.
 */
static inline void AJ_PWR_ConfigureWakeUpPin(aj_operation_state_t state){
	AJ_BitReg_WriteBit_Position(&(PWR->CSR), PWR_CSR_EWUP_Pos, state);
}

/**
 * @brief  Reports whether the wakeup (WKUP) pin function is enabled.
 * @return WKUP pin state:
 *         - 1: pin wakes up the device from Standby mode
 *         - 0: pin used as general purpose I/O
 */
static inline uint8_t AJ_PWR_IsWakeUpPinEnabled(void){
	return AJ_BitReg_IsBitSet_Mask(&(PWR->CSR), PWR_CSR_EWUP_Msk);
}

/**
 * @brief  Checks whether one or more PWR status flags are active.
 * @param  flag Flag(s) to check; combine with the bitwise OR operator.
 * @return - 1: at least one selected flag is active
 *         - 0: no selected flag is active
 */
static inline uint8_t AJ_PWR_IsFlagActive(aj_pwr_flag_status_t flag){
	return AJ_BitReg_IsBitSet_Mask(&(PWR->CSR), flag);
}

/******************************************************************************/
/* De-initialization                                                          */
/******************************************************************************/
/**
 * @brief  Resets the PWR control and status registers to their default values.
 * @note   The PWR_CSR flags (WUF, SBF, PVDO) are read-only and are not cleared
 *         by this function; use AJ_PWR_ClearFlag() to clear WUF/SBF.
 */
void AJ_PWR_DeInit(void);


#ifdef __cplusplus
}
#endif

#endif	/* AJ_PWR_INCLUDED */
