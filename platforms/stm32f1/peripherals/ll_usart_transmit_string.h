// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef LL_USART_TRANSMIT_STRING_INCLUDED
#define LL_USART_TRANSMIT_STRING_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stm32f1xx.h>
#include <stm32f1xx_ll_usart.h>
	
void LL_USART_TransmitChar(USART_TypeDef *USARTx, char data);
void LL_USART_TransmitString(USART_TypeDef *USARTx, const char *str);

void LL_USART_TransmitString_IT(USART_TypeDef *USARTx, const char *str);
void LL_USART_TransmitString_IT_Handler(USART_TypeDef *USARTx);
uint8_t LL_USART_IsTransmittingStringBusy(USART_TypeDef *USARTx);


#ifdef __cplusplus
}
#endif

#endif		// LL_USART_TRANSMIT_STRING_INCLUDED