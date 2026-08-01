// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <stddef.h>
#include "stm32f1xx_ll_usart.h"
#include "ll_usart_transmit_string.h"

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

//********************************
void LL_USART_TransmitString_IT(LL_USART_TransmitString_TypeDef *handle, USART_TypeDef *USARTx, const char *str) {
    if (handle == 0 || handle->tx_busy == 1 || str == NULL || *str == '\0'){
        return;
    }

    handle->tx_str_p = str;
    handle->tx_busy = 1;

    LL_USART_EnableIT_TXE(USARTx);
}

//********************************
void LL_USART_TransmitString_IT_Handler(LL_USART_TransmitString_TypeDef *handle, USART_TypeDef *USARTx) {
    if (handle == 0) {
        return;
    }

    if (LL_USART_IsEnabledIT_TXE(USARTx) && LL_USART_IsActiveFlag_TXE(USARTx)) {
        if (*handle->tx_str_p != '\0') {
            LL_USART_TransmitData8(USARTx, *handle->tx_str_p++);
        } else {
            LL_USART_DisableIT_TXE(USARTx);
            LL_USART_EnableIT_TC(USARTx);
        }
    }

    if (LL_USART_IsEnabledIT_TC(USARTx) && LL_USART_IsActiveFlag_TC(USARTx)) {
        LL_USART_ClearFlag_TC(USARTx);
        LL_USART_DisableIT_TC(USARTx);
        handle->tx_busy = 0;
    }
}

//********************************
uint8_t LL_USART_IsTransmittingStringBusy(LL_USART_TransmitString_TypeDef *handle) {
    return handle->tx_busy;
}