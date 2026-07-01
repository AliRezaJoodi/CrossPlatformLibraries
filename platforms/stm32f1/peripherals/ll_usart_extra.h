// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef LL_USART_EXTRA_INCLUDED
#define LL_USART_EXTRA_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stm32f1xx.h>
#include <stm32f1xx_ll_usart.h>
	
void LL_USART_PutChar(USART_TypeDef *USARTx, char data);
void LL_USART_PutString(USART_TypeDef *USARTx, const char *str);

#ifdef __cplusplus
}
#endif

#endif		// LL_USART_EXTRA_INCLUDED