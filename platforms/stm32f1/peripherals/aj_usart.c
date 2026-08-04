// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <stm32f1xx.h>
#include "aj_bit_reg.h"
#include "aj_usart_type.h"
#include "aj_usart.h"

//*******************************************************************************
void AJ_USART_ConfigOperatingMode(USART_TypeDef *USARTx, aj_usart_mode_t mode){
  AJ_BitReg_ClearBit_Mask(&(USARTx->CR2), (USART_CR2_CLKEN_Msk | USART_CR2_LINEN_Msk));
  AJ_BitReg_ClearBit_Mask(&(USARTx->CR3), (USART_CR3_SCEN_Msk | USART_CR3_IREN_Msk | USART_CR3_HDSEL_Msk));

  switch (mode){
		case AJ_USART_MODE_ASYNC:
      break;
    case AJ_USART_MODE_SYNC:
      AJ_BitReg_SetBit_Mask(&(USARTx->CR2), USART_CR2_CLKEN_Msk);
      break;
    case AJ_USART_MODE_LIN:
      AJ_BitReg_SetBit_Mask(&(USARTx->CR2), USART_CR2_LINEN_Msk);
      break;
    case AJ_USART_MODE_SMARTCARD:
      AJ_BitReg_SetBit_Mask(&(USARTx->CR3), USART_CR3_SCEN_Msk);
      break;
    case AJ_USART_MODE_IRDA:
      AJ_BitReg_SetBit_Mask(&(USARTx->CR3), USART_CR3_IREN_Msk);
      break;
    case AJ_USART_MODE_HALF_DUPLEX:
      AJ_BitReg_SetBit_Mask(&(USARTx->CR3), USART_CR3_HDSEL_Msk);
      break;
    default:
      break;
  }
}