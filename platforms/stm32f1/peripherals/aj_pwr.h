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


#ifdef __cplusplus
}
#endif

#endif	/* AJ_PWR_INCLUDED */
