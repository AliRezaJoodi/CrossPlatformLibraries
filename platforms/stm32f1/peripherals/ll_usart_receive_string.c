// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <stddef.h>
#include "stm32f1xx_ll_usart.h"
#include "ll_usart_receive_string.h"

void LL_USART_ReceiveString_IT(LL_USART_ReceiveString_TypeDef *handle, USART_TypeDef *USARTx, char *str, uint16_t size){
    if ((handle == 0) || (str == 0) || (size == 0) || handle->rx_busy) {
        return;
    }

    handle->rx_buf_p = str;
    handle->rx_pos_p = str;
    handle->rx_remaining = size - 1;   // reserve space for '\0'
    handle->rx_busy = 1;
    handle->rx_done = 0;

    LL_USART_EnableIT_RXNE(USARTx);
}

void LL_USART_ReceiveString_IT_Handler(LL_USART_ReceiveString_TypeDef *handle, USART_TypeDef *USARTx){
    if (handle == 0) {
        return;
    }

    char data;

    if (LL_USART_IsActiveFlag_RXNE(USARTx) && LL_USART_IsEnabledIT_RXNE(USARTx)) {
        data = LL_USART_ReceiveData8(USARTx);

        // optional echo, non-blocking
//        if (LL_USART_IsActiveFlag_TXE(USARTx)) {
//            LL_USART_TransmitData8(USARTx, data);
//        }

        if ((data >= 32) && (data < 127)) {
            if (handle->rx_remaining > 0) {
                *handle->rx_pos_p = data;
                handle->rx_pos_p++;
                handle->rx_remaining--;
            }
        }
        else if (data == '\r') {
            *handle->rx_pos_p = '\0';
            handle->rx_busy = 0;
            handle->rx_done = 1;
            LL_USART_DisableIT_RXNE(USARTx);
        }
    }
}

void LL_USART_StopReceivingString_IT(LL_USART_ReceiveString_TypeDef *handle, USART_TypeDef *USARTx){
    LL_USART_DisableIT_RXNE(USARTx);
    handle->rx_busy = 0;
    handle->rx_done = 0;
}

uint8_t LL_USART_IsReceivingStringBusy(LL_USART_ReceiveString_TypeDef *handle){
    return handle->rx_busy;
}

uint8_t LL_USART_IsReceivingStringDone(LL_USART_ReceiveString_TypeDef *handle){
    return handle->rx_done;
}

