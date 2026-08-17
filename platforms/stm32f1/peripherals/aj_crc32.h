/**
 * @brief   CRC-32 calculation interface for STM32F1 peripherals.
 *
 * This file provides helper APIs for using the CRC peripheral of STM32F1, including:
 * - CRC->CR
 * - CRC->DR
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: BUS Configuration
 * -----------------------------------------------------------------------------
 * This library does not enable any peripheral clock.
 * The application must enable the required clock buses before using this driver.
 * The following clock bus must be enabled:
 * - The AHB clock of the CRC peripheral
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_CRC32_INCLUDED
#define AJ_CRC32_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include <stm32f1xx.h>

/******************************************************************************/
/* Control register (CRC_CR)                                                  */
/******************************************************************************/
static inline void AJ_CRC32_Reset(void){
  CRC->CR |= CRC_CR_RESET_Msk;
}

/******************************************************************************/
/* Data register (CRC_DR)                                                     */
/******************************************************************************/
static inline void AJ_CRC32_Feed(uint32_t data){
  CRC->DR = data;
}

static inline uint32_t AJ_CRC32_Read(void){
  return CRC->DR;
}


#ifdef __cplusplus
}
#endif

#endif  /* AJ_CRC32_INCLUDED */