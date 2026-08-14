// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <stddef.h>
#include <stm32f1xx.h>
#include "aj_usart.h"
#include "aj_usart_transmit_string.h"

//********************************
void AJ_USART_TransmitChar(USART_TypeDef *USARTx, char data){
	while(AJ_USART_SR_IsFlagActive(USARTx, AJ_USART_SR_TXE) != 1U){}		// Transmit Data Register Empty
	AJ_USART_TransmitData_8Bit(USARTx, (uint8_t)data);
//	while(AJ_USART_SR_IsFlagActive(USARTx, AJ_USART_SR_TC) != 1U){}		// Transmission Complete
}

//********************************
void AJ_USART_TransmitString(USART_TypeDef *USARTx, const char *str){
  while(*str != 0){
		AJ_USART_TransmitChar(USARTx,*str);
    str++;
  }
//	AJ_USART_TransmitChar(USARTx, '\r');		// 0x0D
//	AJ_USART_TransmitChar(USARTx, '\n');		// 0x0A
}

//********************************
void AJ_USART_TransmitString_Interrupt(USART_TypeDef *USARTx, aj_usart_tx_string_t *handle, const char *str) {
    if (handle == 0 || handle->tx_busy == 1 || str == NULL || *str == '\0'){
        return;
    }

    handle->tx_str_p = str;
    handle->tx_busy = 1;

    AJ_USART_CR1_EnableBit(USARTx, AJ_USART_CR1_TXEIE);
}

//********************************
void AJ_USART_TransmitString_Interrupt_Handler(USART_TypeDef *USARTx, aj_usart_tx_string_t *handle) {
    if (handle == 0) {
        return;
    }

    if (AJ_USART_CR1_IsBitEnabled(USARTx, AJ_USART_CR1_TXEIE) && AJ_USART_SR_IsFlagActive(USARTx, AJ_USART_SR_TXE)) {
        if (*handle->tx_str_p != '\0') {
            AJ_USART_TransmitData_8Bit(USARTx, (uint8_t)(*handle->tx_str_p++));
        } else {
            AJ_USART_CR1_DisableBit(USARTx, AJ_USART_CR1_TXEIE);
            AJ_USART_CR1_EnableBit(USARTx, AJ_USART_CR1_TCIE);
        }
    }

    if (AJ_USART_CR1_IsBitEnabled(USARTx, AJ_USART_CR1_TCIE) && AJ_USART_SR_IsFlagActive(USARTx, AJ_USART_SR_TC)) {
        AJ_USART_SR_ClearFlagByWriteZero(USARTx, AJ_USART_SR_W0_TC);
        AJ_USART_CR1_DisableBit(USARTx, AJ_USART_CR1_TCIE);
        handle->tx_busy = 0;
    }
}

//********************************
uint8_t AJ_USART_IsTransmittingStringBusy(aj_usart_tx_string_t *handle) {
    return handle->tx_busy;
}
