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

//*******************************************************************************
#if defined(USART_CR1_OVER8_Msk)
static uint16_t AJ_USART_CalculateDivider_8x(uint32_t periphclk, uint32_t baudrate){
  uint32_t div_x100;
  uint32_t mantissa;
  uint32_t fraction;

  div_x100 = (periphclk * 25U) / (2U * baudrate);
  mantissa = div_x100 / 100U;
  fraction = (((div_x100 - (mantissa * 100U)) * 8U) + 50U) / 100U;

  if (fraction >= 8U){
    fraction = 0U;
    mantissa += 1U;
  }

  return (uint16_t)((mantissa << 4U) | fraction);
}
#endif

static uint16_t AJ_USART_CalculateDivider_16x(uint32_t periphclk, uint32_t baudrate){
  uint32_t div_x100;
  uint32_t mantissa;
  uint32_t fraction;

  div_x100 = (periphclk * 25U) / (4U * baudrate);
  mantissa = div_x100 / 100U;
  fraction = (((div_x100 - (mantissa * 100U)) * 16U) + 50U) / 100U;

  if (fraction >= 16U){
    fraction = 0U;
    mantissa += 1U;
  }

  return (uint16_t)((mantissa << 4U) | fraction);
}

//*******************************************************************************
#if defined(USART_CR1_OVER8_Msk)
void AJ_USART_ConfigBaudRate_8x(USART_TypeDef *USARTx, uint32_t periphclk, uint32_t baudrate){
  USARTx->BRR = AJ_USART_CalculateDivider_8x(periphclk, baudrate);
}
#endif

void AJ_USART_ConfigBaudRate_16x(USART_TypeDef *USARTx, uint32_t periphclk, uint32_t baudrate){
  USARTx->BRR = AJ_USART_CalculateDivider_16x(periphclk, baudrate);
}
