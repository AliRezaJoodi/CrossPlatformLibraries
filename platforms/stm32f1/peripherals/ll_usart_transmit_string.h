// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef LL_USART_TRANSMIT_STRING_INCLUDED
#define LL_USART_TRANSMIT_STRING_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include <stm32f1xx.h>
#include <stm32f1xx_ll_usart.h>

typedef struct{
    const char *tx_str_p;
    volatile uint8_t tx_busy;
} LL_USART_TransmitString_TypeDef;

void LL_USART_TransmitChar(USART_TypeDef *USARTx, char data);
void LL_USART_TransmitString(USART_TypeDef *USARTx, const char *str);

void LL_USART_TransmitString_IT(LL_USART_TransmitString_TypeDef *handle, USART_TypeDef *USARTx, const char *str);
void LL_USART_TransmitString_IT_Handler(LL_USART_TransmitString_TypeDef *handle, USART_TypeDef *USARTx);
uint8_t LL_USART_IsTransmittingStringBusy(LL_USART_TransmitString_TypeDef *handle);


#ifdef __cplusplus
}
#endif

#endif		// LL_USART_TRANSMIT_STRING_INCLUDED