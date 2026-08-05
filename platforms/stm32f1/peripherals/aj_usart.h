/**
 * @brief   Universal synchronous/asynchronous receiver transmitter (USART) interface for STM32 peripherals.
 *
 * This file provides helper APIs for managing USART control, status and data registers, including:
 * - USARTx->SR
 * - USARTx->DR
 * - USARTx->BRR
 * - USARTx->CR1
 * - USARTx->CR2
 * - USARTx->CR3
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_USART_INCLUDED
#define AJ_USART_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include <stm32f1xx.h>
#include "aj_bit_reg.h"
#include "aj_usart_type.h"

void AJ_USART_ConfigOperatingMode(USART_TypeDef *USARTx, aj_usart_mode_t mode);

#if defined(USART_CR1_OVER8_Msk)
void AJ_USART_ConfigOverSampling(USART_TypeDef *USARTx, aj_usart_oversampling_t oversampling);
aj_usart_oversampling_t AJ_USART_ReadOverSampling(const USART_TypeDef *USARTx);
#endif

/******************************************************************************/
/* Baud rate register (USART_BRR)                                             */
/******************************************************************************/
#if defined(USART_CR1_OVER8_Msk)
void AJ_USART_ConfigBaudRate_8x(USART_TypeDef *USARTx, uint32_t periphclk, uint32_t baudrate);
#endif

void AJ_USART_ConfigBaudRate_16x(USART_TypeDef *USARTx, uint32_t periphclk, uint32_t baudrate);

/******************************************************************************/
/* Status register (USART_SR)                                                 */
/******************************************************************************/
static inline uint8_t AJ_USART_IsFlagActive_ParityError(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->SR), USART_SR_PE_Msk);
}

static inline void AJ_USART_ClearFlag_ParityError(USART_TypeDef *USARTx){
  volatile uint32_t tmpreg;
  tmpreg = USARTx->SR;
  (void) tmpreg;
  tmpreg = USARTx->DR;
  (void) tmpreg;
}

static inline uint8_t AJ_USART_IsFlagActive_FramingError(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->SR), USART_SR_FE_Msk);
}

static inline void AJ_USART_ClearFlag_FramingError(USART_TypeDef *USARTx){
  volatile uint32_t tmpreg;
  tmpreg = USARTx->SR;
  (void) tmpreg;
  tmpreg = USARTx->DR;
  (void) tmpreg;
}

static inline uint8_t AJ_USART_IsFlagActive_NoiseError(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->SR), USART_SR_NE_Msk);
}

static inline void AJ_USART_ClearFlag_NoiseError(USART_TypeDef *USARTx){
  volatile uint32_t tmpreg;
  tmpreg = USARTx->SR;
  (void) tmpreg;
  tmpreg = USARTx->DR;
  (void) tmpreg;
}

static inline uint8_t AJ_USART_IsFlagActive_OverrunError(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->SR), USART_SR_ORE_Msk);
}

static inline void AJ_USART_ClearFlag_OverrunError(USART_TypeDef *USARTx){
  volatile uint32_t tmpreg;
  tmpreg = USARTx->SR;
  (void) tmpreg;
  tmpreg = USARTx->DR;
  (void) tmpreg;
}

static inline uint8_t AJ_USART_IsFlagActive_IdleLine(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->SR), USART_SR_IDLE_Msk);
}

static inline void AJ_USART_ClearFlag_IdleLine(USART_TypeDef *USARTx){
  volatile uint32_t tmpreg;
  tmpreg = USARTx->SR;
  (void) tmpreg;
  tmpreg = USARTx->DR;
  (void) tmpreg;
}

static inline uint8_t AJ_USART_IsFlagActive_ReceiveDataNotEmpty(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->SR), USART_SR_RXNE_Msk);
}

static inline void AJ_USART_ClearFlag_ReceiveDataNotEmpty(USART_TypeDef *USARTx){
  USARTx->SR = ~(USART_SR_RXNE_Msk);
}

static inline uint8_t AJ_USART_IsFlagActive_TransmissionComplete(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->SR), USART_SR_TC_Msk);
}

static inline void AJ_USART_ClearFlag_TransmissionComplete(USART_TypeDef *USARTx){
  USARTx->SR = ~(USART_SR_TC_Msk);
}

static inline uint8_t AJ_USART_IsFlagActive_TransmitDataEmpty(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->SR), USART_SR_TXE_Msk);
}

static inline uint8_t AJ_USART_IsFlagActive_LinBreakDetection(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->SR), USART_SR_LBD_Msk);
}

static inline void AJ_USART_ClearFlag_LinBreakDetection(USART_TypeDef *USARTx){
  USARTx->SR = ~(USART_SR_LBD_Msk);
}

static inline uint8_t AJ_USART_IsFlagActive_CTS(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->SR), USART_SR_CTS_Msk);
}

static inline void AJ_USART_ClearFlag_CTS(USART_TypeDef *USARTx){
  USARTx->SR = ~(USART_SR_CTS_Msk);
}


#ifdef __cplusplus
}
#endif

#endif	/* AJ_USART_INCLUDED */