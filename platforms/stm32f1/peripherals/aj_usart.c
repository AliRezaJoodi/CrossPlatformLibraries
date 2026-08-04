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

//*******************************************************************************
#if defined(USART_CR1_OVER8_Msk)
void AJ_USART_ConfigOverSampling(USART_TypeDef *USARTx, aj_usart_oversampling_t oversampling){
  if (oversampling == AJ_USART_OVERSAMPLING_16){
    AJ_BitReg_ClearBit_Mask(&(USARTx->CR1), USART_CR1_OVER8_Msk);
  }
  else{
    AJ_BitReg_SetBit_Mask(&(USARTx->CR1), USART_CR1_OVER8_Msk);
  }
}

aj_usart_oversampling_t AJ_USART_ReadOverSampling(const USART_TypeDef *USARTx){
  if (AJ_BitReg_IsBitSet_Mask(&(USARTx->CR1), USART_CR1_OVER8_Msk) == 0U){
    return AJ_USART_OVERSAMPLING_16;
  }

  return AJ_USART_OVERSAMPLING_8;
}
#endif

void AJ_USART_CalculateDivider_8x(USART_TypeDef *USARTx){
}

void AJ_USART_CalculateDivider_16x(USART_TypeDef *USARTx){
}
