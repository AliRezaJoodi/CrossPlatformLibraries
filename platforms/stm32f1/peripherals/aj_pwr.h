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
 * @brief  Enables or disables write access to the backup domain
 *         (RTC and backup registers) by driving the DBP bit.
 * @param  state  DBP configuration:
 *                - AJ_ENABLE: allow writes to the backup domain
 *                - AJ_DISABLE: protect the backup domain
 * @note   If the HSE divided by 128 is used as the RTC clock, this bit must
 *         remain set to 1.
 */
static inline void AJ_PWR_ConfigureBackupDomainWriteAccess(aj_operation_state_t state){
	AJ_BitReg_WriteBit_Position(&(PWR->CR), PWR_CR_DBP_Pos, state);
}

/**
 * @brief  Reports whether write access to the backup domain
 *         (RTC and backup registers) is enabled.
 * @return DBP bit state:
 *         - 1: writes to the backup domain are allowed
 *         - 0: writes to the backup domain are protected
 */
static inline uint8_t AJ_PWR_IsBackupDomainWriteAccessEnabled(void){
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
 * @param  state  PVD configuration:
 *                - AJ_ENABLE: enable the PVD
 *                - AJ_DISABLE: disable the PVD
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


#ifdef __cplusplus
}
#endif

#endif	/* AJ_PWR_INCLUDED */
