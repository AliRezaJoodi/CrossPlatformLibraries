// GitHub Account: GitHub.com/AliRezaJoodi

#include "ll_usart_extra.h"
#include <stddef.h>

static const char *tx_data_p = NULL;
static volatile uint8_t sending = 0;

//********************************
void LL_USART_TransmitString_IT(USART_TypeDef *USARTx, const char *str) {
    if (sending == 1 || str == NULL || *str == '\0'){
			return;
		}

    tx_data_p = str;
    sending = 1;

    LL_USART_EnableIT_TXE(USARTx);
}

//********************************
uint8_t LL_USART_IsTransmitBusy(USART_TypeDef *USARTx) {
    return sending;
}

//********************************
void LL_USART_Transmit_Handler(USART_TypeDef *USARTx) {
    if (LL_USART_IsEnabledIT_TXE(USARTx) && LL_USART_IsActiveFlag_TXE(USARTx)) {
        if (*tx_data_p != '\0') {
            LL_USART_TransmitData8(USARTx, *tx_data_p++);
        } else {
            LL_USART_DisableIT_TXE(USARTx);
            LL_USART_EnableIT_TC(USARTx);
        }
    }

    if (LL_USART_IsEnabledIT_TC(USARTx) && LL_USART_IsActiveFlag_TC(USARTx)) {
        LL_USART_ClearFlag_TC(USARTx);
        LL_USART_DisableIT_TC(USARTx);
        sending = 0; 
    }
}

//********************************
void LL_USART_TransmitChar(USART_TypeDef *USARTx, char data){
	while(LL_USART_IsActiveFlag_TXE(USARTx) != 1){}		// Transmit Data Register Empty 
	LL_USART_TransmitData8(USARTx,data);
//	while(LL_USART_IsActiveFlag_TC(USARTx) != 1){}		// Transmission Complete 
}

//********************************
void LL_USART_TransmitString(USART_TypeDef *USARTx, const char *str){
  while(*str != 0){
		LL_USART_TransmitChar(USARTx,*str);
    str++;
  }
//	LL_USART_TransmitChar(USARTx, '\r');		// 0x0D
//	LL_USART_TransmitChar(USARTx, '\n');		// 0x0A
}