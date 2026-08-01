// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef LL_USART_RECEIVER_STRING_INCLUDED
#define LL_USART_RECEIVER_STRING_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include <stm32f1xx.h>

typedef struct{
    char *p_rx_buf;
    char *p_rx_pos;
    uint16_t rx_remaining;
    volatile uint8_t rx_busy;
    volatile uint8_t rx_done;
} LL_USART_ReceiveString_TypeDef;

void LL_USART_ReceiveString_IT(LL_USART_ReceiveString_TypeDef *handle, USART_TypeDef *USARTx, char *str, uint16_t size);
void LL_USART_ReceiveString_IT_Handler(LL_USART_ReceiveString_TypeDef *handle, USART_TypeDef *USARTx);
void LL_USART_StopReceivingString_IT(LL_USART_ReceiveString_TypeDef *handle, USART_TypeDef *USARTx);
uint8_t LL_USART_IsReceivingStringBusy(LL_USART_ReceiveString_TypeDef *handle);
uint8_t LL_USART_IsReceivingStringDone(LL_USART_ReceiveString_TypeDef *handle);


#ifdef __cplusplus
}
#endif

#endif	