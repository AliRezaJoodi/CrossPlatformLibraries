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

/******************************************************************************/
/* Baud rate register (USART_BRR)                                             */
/******************************************************************************/
#if defined(USART_CR1_OVER8_Msk)
void AJ_USART_ConfigBaudRate_8x(USART_TypeDef *USARTx, uint32_t periphclk, uint32_t baudrate);
#endif

void AJ_USART_ConfigBaudRate_16x(USART_TypeDef *USARTx, uint32_t periphclk, uint32_t baudrate);

/******************************************************************************/
/* Data register (USART_DR)                                                   */
/******************************************************************************/
static inline uint8_t AJ_USART_Receive8Bit(const USART_TypeDef *USARTx){
  return (uint8_t)(USARTx->DR & 0x00FFU);
}

static inline uint16_t AJ_USART_Receive9Bit(const USART_TypeDef *USARTx){
  return (uint16_t)(USARTx->DR & 0x01FFU);
}

static inline void AJ_USART_Transmit8Bit(USART_TypeDef *USARTx, uint8_t value){
  USARTx->DR = (uint32_t)value;
}

static inline void AJ_USART_Transmit9Bit(USART_TypeDef *USARTx, uint16_t value){
  USARTx->DR = (uint32_t)(value & 0x1FFU);
}

/******************************************************************************/
/* Status register (USART_SR)                                                 */
/******************************************************************************/
static inline uint8_t AJ_USART_IsFlagActive_CTS(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->SR), USART_SR_CTS_Msk);
}

static inline void AJ_USART_ClearFlag_CTS(USART_TypeDef *USARTx){
  USARTx->SR = ~(USART_SR_CTS_Msk);
}

static inline uint8_t AJ_USART_IsFlagActive_LinBreakDetection(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->SR), USART_SR_LBD_Msk);
}

static inline void AJ_USART_ClearFlag_LinBreakDetection(USART_TypeDef *USARTx){
  USARTx->SR = ~(USART_SR_LBD_Msk);
}

static inline uint8_t AJ_USART_IsFlagActive_TransmitDataEmpty(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->SR), USART_SR_TXE_Msk);
}

static inline uint8_t AJ_USART_IsFlagActive_TransmissionComplete(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->SR), USART_SR_TC_Msk);
}

static inline void AJ_USART_ClearFlag_TransmissionComplete(USART_TypeDef *USARTx){
  USARTx->SR = ~(USART_SR_TC_Msk);
}

static inline uint8_t AJ_USART_IsFlagActive_ReceiveDataNotEmpty(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->SR), USART_SR_RXNE_Msk);
}

static inline void AJ_USART_ClearFlag_ReceiveDataNotEmpty(USART_TypeDef *USARTx){
  USARTx->SR = ~(USART_SR_RXNE_Msk);
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

/******************************************************************************/
/* Data register (USART_CR1)                                                  */
/******************************************************************************/
#if defined(USART_CR1_OVER8_Msk)
void AJ_USART_ConfigOverSampling(USART_TypeDef *USARTx, aj_usart_oversampling_t oversampling

aj_usart_oversampling_t AJ_USART_ReadOverSampling(const USART_TypeDef *USARTx);
#endif

static inline void AJ_USART_EnablePeripheral(USART_TypeDef *USARTx){
  AJ_BitReg_SetBit_Mask(&(USARTx->CR1), USART_CR1_UE_Msk);
}

static inline void AJ_USART_DisablePeripheral(USART_TypeDef *USARTx){
  AJ_BitReg_ClearBit_Mask(&(USARTx->CR1), USART_CR1_UE_Msk);
}

static inline uint8_t AJ_USART_IsPeripheralEnable(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->CR1), USART_CR1_UE_Msk);
}

static inline void AJ_USART_ConfigWordLength(USART_TypeDef *USARTx, aj_usart_wordlength_t length){
  AJ_BitReg_WriteBit_Position(&(USARTx->CR1), USART_CR1_M_Pos, length);
}

static inline aj_usart_wordlength_t AJ_USART_ReadWordLength(const USART_TypeDef *USARTx){
  return (aj_usart_wordlength_t)AJ_BitReg_GetBit_Position(&(USARTx->CR1), USART_CR1_M_Pos);
}

static inline void AJ_USART_ConfigWakeupMethod(USART_TypeDef *USARTx, aj_usart_wakeup_t wakeup){
  AJ_BitReg_WriteBit_Position(&(USARTx->CR1), USART_CR1_WAKE_Pos, wakeup);
}

static inline aj_usart_wakeup_t AJ_USART_ReadWakeupMethod(const USART_TypeDef *USARTx){
  return (aj_usart_wakeup_t)AJ_BitReg_GetBit_Position(&(USARTx->CR1), USART_CR1_WAKE_Pos);
}

static inline void AJ_USART_ConfigParity(USART_TypeDef *USARTx, aj_usart_parity_t parity){
  AJ_BitReg_ClearBit_Mask(&(USARTx->CR1), (USART_CR1_PCE_Msk | USART_CR1_PS_Msk));
  AJ_BitReg_SetBit_Mask(&(USARTx->CR1), parity);
}

static inline aj_usart_parity_t AJ_USART_ReadParity(const USART_TypeDef *USARTx){
  return (aj_usart_parity_t)AJ_BitReg_GetBit_Mask(&(USARTx->CR1), (USART_CR1_PCE_Msk | USART_CR1_PS_Msk));
}


#ifdef __cplusplus
}
#endif

#endif	/* AJ_USART_INCLUDED */