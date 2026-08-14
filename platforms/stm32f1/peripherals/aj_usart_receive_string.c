// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <stddef.h>
#include <stm32f1xx.h>
#include "aj_usart.h"
#include "aj_usart_receive_string.h"

void AJ_USART_ReceiveString_Interrupt(USART_TypeDef *USARTx, aj_usart_rx_string_t *handle, char *str, uint16_t size){
    if ((handle == 0) || (str == 0) || (size == 0) || handle->rx_busy) {
        return;
    }

    handle->rx_buf_p = str;
    handle->rx_pos_p = str;
    handle->rx_remaining = size - 1;   // reserve space for '\0'
    handle->rx_busy = 1;
    handle->rx_done = 0;

    AJ_USART_CR1_EnableBit(USARTx, AJ_USART_CR1_RXNEIE);
}

void AJ_USART_ReceiveString_Interrupt_Handler(USART_TypeDef *USARTx, aj_usart_rx_string_t *handle){
    if (handle == 0) {
        return;
    }

    char data;

    if (AJ_USART_SR_IsFlagActive(USARTx, AJ_USART_SR_RXNE) && AJ_USART_CR1_IsBitEnabled(USARTx, AJ_USART_CR1_RXNEIE)) {
        data = (char)AJ_USART_ReceiveData_8Bit(USARTx);

        // optional echo, non-blocking
//        if (AJ_USART_SR_IsFlagActive(USARTx, AJ_USART_SR_TXE)) {
//            AJ_USART_TransmitData_8Bit(USARTx, (uint8_t)data);
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
            AJ_USART_CR1_DisableBit(USARTx, AJ_USART_CR1_RXNEIE);
        }
    }
}

void AJ_USART_StopReceivingString_Interrupt(USART_TypeDef *USARTx, aj_usart_rx_string_t *handle){
    AJ_USART_CR1_DisableBit(USARTx, AJ_USART_CR1_RXNEIE);
    handle->rx_busy = 0;
    handle->rx_done = 0;
}

uint8_t AJ_USART_IsReceivingStringBusy(aj_usart_rx_string_t *handle){
    return handle->rx_busy;
}

uint8_t AJ_USART_IsReceivingStringDone(aj_usart_rx_string_t *handle){
    return handle->rx_done;
}
