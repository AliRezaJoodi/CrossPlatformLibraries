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


#ifdef __cplusplus
}
#endif

#endif	/* AJ_USART_INCLUDED */