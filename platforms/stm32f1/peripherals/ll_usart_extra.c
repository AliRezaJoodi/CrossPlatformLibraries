// GitHub Account: GitHub.com/AliRezaJoodi

#include "ll_usart_extra.h"
#include <stddef.h>

static const char *p_tx_data = NULL;
static volatile uint8_t is_sending = 0;

//********************************
void LL_USART_TransmitString_IT(USART_TypeDef *USARTx, const char *str) {
    if (is_sending || str == NULL || *str == '\0'){
			return;
		}

    p_tx_data = str;
    is_sending = 1;

    LL_USART_EnableIT_TXE(USARTx);
}

//********************************
uint8_t LL_USART_IsSending(USART_TypeDef *USARTx) {
    return is_sending;
}

//********************************
void LL_USART_Transmit_IRQHandler(USART_TypeDef *USARTx) {
    if (LL_USART_IsEnabledIT_TXE(USARTx) && LL_USART_IsActiveFlag_TXE(USARTx)) {
        if (*p_tx_data != '\0') {
            LL_USART_TransmitData8(USARTx, *p_tx_data++);
        } else {
            LL_USART_DisableIT_TXE(USARTx);
            LL_USART_EnableIT_TC(USARTx);
        }
    }

    if (LL_USART_IsEnabledIT_TC(USARTx) && LL_USART_IsActiveFlag_TC(USARTx)) {
        LL_USART_ClearFlag_TC(USARTx);
        LL_USART_DisableIT_TC(USARTx);
        is_sending = 0; 
    }
}

//********************************
void LL_USART_PutChar(USART_TypeDef *USARTx, char data){
	while(LL_USART_IsActiveFlag_TXE(USARTx) != 1){}		// Transmit Data Register Empty 
	LL_USART_TransmitData8(USARTx,data);
//	while(LL_USART_IsActiveFlag_TC(USARTx) != 1){}		// Transmission Complete 
}

//********************************
void LL_USART_TransmitString(USART_TypeDef *USARTx, const char *str){
  while(*str != 0){
		LL_USART_PutChar(USARTx,*str);
    str++;
  }
	LL_USART_PutChar(USARTx, '\r');		// 0x0D
	LL_USART_PutChar(USARTx, '\n');		// 0x0A
}