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

static inline uint8_t AJ_USART_IsPeripheralEnabled(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->CR1), USART_CR1_UE_Msk);
}

static inline void AJ_USART_ConfigWordLength(USART_TypeDef *USARTx, aj_usart_wordlength_t length){
  AJ_BitReg_ModifyBit_Mask(&(USARTx->CR1), USART_CR1_M_Msk, length);
}

static inline aj_usart_wordlength_t AJ_USART_ReadWordLength(const USART_TypeDef *USARTx){
  return (aj_usart_wordlength_t)AJ_BitReg_GetBit_Mask(&(USARTx->CR1), USART_CR1_M_Msk);
}

static inline void AJ_USART_ConfigWakeupMethod(USART_TypeDef *USARTx, aj_usart_wakeup_t wakeup){
  AJ_BitReg_ModifyBit_Mask(&(USARTx->CR1), USART_CR1_WAKE_Msk, wakeup);
}

static inline aj_usart_wakeup_t AJ_USART_ReadWakeupMethod(const USART_TypeDef *USARTx){
  return (aj_usart_wakeup_t)AJ_BitReg_GetBit_Mask(&(USARTx->CR1), USART_CR1_WAKE_Msk);
}

static inline void AJ_USART_ConfigParity(USART_TypeDef *USARTx, aj_usart_parity_t parity){
  AJ_BitReg_ModifyBit_Mask(&(USARTx->CR1), (USART_CR1_PCE_Msk | USART_CR1_PS_Msk), parity);
}

static inline aj_usart_parity_t AJ_USART_ReadParity(const USART_TypeDef *USARTx){
  return (aj_usart_parity_t)AJ_BitReg_GetBit_Mask(&(USARTx->CR1), (USART_CR1_PCE_Msk | USART_CR1_PS_Msk));
}

static inline void AJ_USART_EnableInterrupt_ParityError(USART_TypeDef *USARTx){
  AJ_BitReg_SetBit_Mask(&(USARTx->CR1), USART_CR1_PEIE_Msk);
}

static inline void AJ_USART_DisableInterrupt_ParityError(USART_TypeDef *USARTx){
  AJ_BitReg_ClearBit_Mask(&(USARTx->CR1), USART_CR1_PEIE_Msk);
}

static inline uint8_t AJ_USART_IsInterruptEnabled_ParityError(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->CR1), USART_CR1_PEIE_Msk);
}

static inline void AJ_USART_EnableInterrupt_TxEmpty(USART_TypeDef *USARTx){
  AJ_BitReg_SetBit_Mask(&(USARTx->CR1), USART_CR1_TXEIE_Msk);
}

static inline void AJ_USART_DisableInterrupt_TxEmpty(USART_TypeDef *USARTx){
  AJ_BitReg_ClearBit_Mask(&(USARTx->CR1), USART_CR1_TXEIE_Msk);
}

static inline uint8_t AJ_USART_IsInterruptEnabled_TxEmpty(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->CR1), USART_CR1_TXEIE_Msk);
}

static inline void AJ_USART_EnableInterrupt_TransmissionComplete(USART_TypeDef *USARTx){
  AJ_BitReg_SetBit_Mask(&(USARTx->CR1), USART_CR1_TCIE_Msk);
}

static inline void AJ_USART_DisableInterrupt_TransmissionComplete(USART_TypeDef *USARTx){
  AJ_BitReg_ClearBit_Mask(&(USARTx->CR1), USART_CR1_TCIE_Msk);
}

static inline uint8_t AJ_USART_IsInterruptEnabled_TransmissionComplete(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->CR1), USART_CR1_TCIE_Msk);
}

static inline void AJ_USART_EnableInterrupt_RxNotEmpty(USART_TypeDef *USARTx){
  AJ_BitReg_SetBit_Mask(&(USARTx->CR1), USART_CR1_RXNEIE_Msk);
}

static inline void AJ_USART_DisableInterrupt_RxNotEmpty(USART_TypeDef *USARTx){
  AJ_BitReg_ClearBit_Mask(&(USARTx->CR1), USART_CR1_RXNEIE_Msk);
}

static inline uint8_t AJ_USART_IsInterruptEnabled_RxNotEmpty(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->CR1), USART_CR1_RXNEIE_Msk);
}

static inline void AJ_USART_EnableInterrupt_IdleLine(USART_TypeDef *USARTx){
  AJ_BitReg_SetBit_Mask(&(USARTx->CR1), USART_CR1_IDLEIE_Msk);
}

static inline void AJ_USART_DisableInterrupt_IdleLine(USART_TypeDef *USARTx){
  AJ_BitReg_ClearBit_Mask(&(USARTx->CR1), USART_CR1_IDLEIE_Msk);
}

static inline uint8_t AJ_USART_IsInterruptEnabled_IdleLine(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->CR1), USART_CR1_IDLEIE_Msk);
}

static inline void AJ_USART_ConfigDirection(USART_TypeDef *USARTx, aj_usart_direction_t direction){
  AJ_BitReg_ModifyBit_Mask(&(USARTx->CR1), (USART_CR1_TE_Msk | USART_CR1_RE_Msk), direction);
}

static inline aj_usart_direction_t AJ_USART_ReadDirection(const USART_TypeDef *USARTx){
  return (aj_usart_direction_t)AJ_BitReg_GetBit_Mask(&(USARTx->CR1), (USART_CR1_TE_Msk | USART_CR1_RE_Msk));
}

static inline void AJ_USART_RequestEnterMuteMode(USART_TypeDef *USARTx){
  AJ_BitReg_SetBit_Mask(&(USARTx->CR1), USART_CR1_RWU_Msk);
}

static inline void AJ_USART_RequestExitMuteMode(USART_TypeDef *USARTx){
  AJ_BitReg_ClearBit_Mask(&(USARTx->CR1), USART_CR1_RWU_Msk);
}

static inline uint8_t AJ_USART_IsMuteModeActive(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->CR1), USART_CR1_RWU_Msk);
}

static inline void AJ_USART_RequestBreakSending(USART_TypeDef *USARTx){
  AJ_BitReg_SetBit_Mask(&(USARTx->CR1), USART_CR1_SBK_Msk);
}

/******************************************************************************/
/* Control register 2 (USART_CR2)                                             */
/******************************************************************************/

static inline void AJ_USART_EnableLIN(USART_TypeDef *USARTx){
  AJ_BitReg_SetBit_Mask(&(USARTx->CR2), USART_CR2_LINEN_Msk);
}

static inline void AJ_USART_DisableLIN(USART_TypeDef *USARTx){
  AJ_BitReg_ClearBit_Mask(&(USARTx->CR2), USART_CR2_LINEN_Msk);
}

static inline uint8_t AJ_USART_IsLINEnabled(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->CR2), USART_CR2_LINEN_Msk);
}

static inline void AJ_USART_ConfigStopBitsLength(USART_TypeDef *USARTx, aj_usart_stopbits_t stopbits){
  AJ_BitReg_ModifyBit_Mask(&(USARTx->CR2), USART_CR2_STOP_Msk, stopbits);
}

static inline aj_usart_stopbits_t AJ_USART_ReadStopBitsLength(const USART_TypeDef *USARTx){
  return (aj_usart_stopbits_t)AJ_BitReg_GetBit_Mask(&(USARTx->CR2), USART_CR2_STOP_Msk);
}

static inline void AJ_USART_EnableClockOutput(USART_TypeDef *USARTx){
  AJ_BitReg_SetBit_Mask(&(USARTx->CR2), USART_CR2_CLKEN_Msk);
}

static inline void AJ_USART_DisableClockOutput(USART_TypeDef *USARTx){
  AJ_BitReg_ClearBit_Mask(&(USARTx->CR2), USART_CR2_CLKEN_Msk);
}

static inline uint8_t AJ_USART_IsClockOutputEnabled(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->CR2), USART_CR2_CLKEN_Msk);
}

static inline void AJ_USART_ConfigClockSignal(USART_TypeDef *USARTx, aj_usart_clock_phase_t phase, aj_usart_clock_polarity_t polarity, uint8_t lastbitclkpulse){
  AJ_BitReg_ModifyBit_Mask(&(USARTx->CR2), (USART_CR2_CPHA_Msk | USART_CR2_CPOL_Msk | USART_CR2_LBCL_Msk), (phase | polarity | lastbitclkpulse));
}

static inline void AJ_USART_ConfigClockPolarity(USART_TypeDef *USARTx, aj_usart_clock_polarity_t polarity){
  AJ_BitReg_ModifyBit_Mask(&(USARTx->CR2), USART_CR2_CPOL_Msk, polarity);
}

static inline aj_usart_clock_polarity_t AJ_USART_ReadClockPolarity(const USART_TypeDef *USARTx){
  return (aj_usart_clock_polarity_t)AJ_BitReg_GetBit_Mask(&(USARTx->CR2), USART_CR2_CPOL_Msk);
}

static inline void AJ_USART_ConfigClockPhase(USART_TypeDef *USARTx, aj_usart_clock_phase_t phase){
  AJ_BitReg_ModifyBit_Mask(&(USARTx->CR2), USART_CR2_CPHA_Msk, phase);
}

static inline aj_usart_clock_phase_t AJ_USART_ReadClockPhase(const USART_TypeDef *USARTx){
  return (aj_usart_clock_phase_t)AJ_BitReg_GetBit_Mask(&(USARTx->CR2), USART_CR2_CPHA_Msk);
}

static inline void AJ_USART_EnableLastBitClockPulse(USART_TypeDef *USARTx){
  AJ_BitReg_SetBit_Mask(&(USARTx->CR2), USART_CR2_LBCL_Msk);
}

static inline void AJ_USART_DisableLastBitClockPulse(USART_TypeDef *USARTx){
  AJ_BitReg_ClearBit_Mask(&(USARTx->CR2), USART_CR2_LBCL_Msk);
}

static inline void AJ_USART_EnableInterrupt_LINBreakDetection(USART_TypeDef *USARTx){
  AJ_BitReg_SetBit_Mask(&(USARTx->CR2), USART_CR2_LBDIE_Msk);
}

static inline void AJ_USART_DisableInterrupt_LINBreakDetection(USART_TypeDef *USARTx){
  AJ_BitReg_ClearBit_Mask(&(USARTx->CR2), USART_CR2_LBDIE_Msk);
}

static inline uint8_t AJ_USART_IsInterruptEnabled_LINBreakDetection(const USART_TypeDef *USARTx){
  return AJ_BitReg_IsBitSet_Mask(&(USARTx->CR2), USART_CR2_LBDIE_Msk);
}

static inline void AJ_USART_ConfigLINBreakDetectLength(USART_TypeDef *USARTx, aj_usart_lin_break_detection_t length){
  AJ_BitReg_ModifyBit_Mask(&(USARTx->CR2), USART_CR2_LBDL_Msk, length);
}

static inline aj_usart_lin_break_detection_t AJ_USART_ReadLINBreakDetectLength(const USART_TypeDef *USARTx){
  return (aj_usart_lin_break_detection_t)AJ_BitReg_GetBit_Mask(&(USARTx->CR2), USART_CR2_LBDL_Msk);
}

static inline void AJ_USART_ConfigNodeAddress(USART_TypeDef *USARTx, uint32_t address){
  AJ_BitReg_ModifyBit_Mask(&(USARTx->CR2), USART_CR2_ADD_Msk, (address & USART_CR2_ADD_Msk));
}

static inline uint32_t AJ_USART_ReadNodeAddress(const USART_TypeDef *USARTx){
  return (uint32_t)AJ_BitReg_GetBit_Mask(&(USARTx->CR2), USART_CR2_ADD_Msk);
}


#ifdef __cplusplus
}
#endif

#endif	/* AJ_USART_INCLUDED */