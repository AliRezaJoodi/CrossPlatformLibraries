// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef LL_USART_EXTRA_INCLUDED
#define LL_USART_EXTRA_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stm32f1xx.h>
#include <stm32f1xx_ll_usart.h>
	
void LL_USART_PutChar(USART_TypeDef *USARTx, char data);
void LL_USART_TransmitString(USART_TypeDef *USARTx, const char *str);

void LL_USART_TransmitString_IT(USART_TypeDef *USARTx, const char *str);
uint8_t LL_USART_IsSending(USART_TypeDef *USARTx);
void LL_USART_Transmit_IRQHandler(USART_TypeDef *USARTx);


#ifdef __cplusplus
}
#endif

#endif		// LL_USART_EXTRA_INCLUDED