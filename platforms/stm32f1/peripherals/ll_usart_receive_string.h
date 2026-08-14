/**
 * @brief   Receive string management for STM32 USART using interrupts and the LL APIs.
 *
 * This library provides interrupt-driven helper APIs to receive a whole string
 * over an STM32 USART peripheral until the receive buffer is full.
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: Compilation & Linkage
 * -----------------------------------------------------------------------------
 * The following source files must be compiled and linked in the project:
 * - `ll_usart_receive_string.c`
 *
 * @author  AliRezaJoodi
 * @see     https://github.com/AliRezaJoodi
 */

// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef LL_USART_RECEIVER_STRING_INCLUDED
#define LL_USART_RECEIVER_STRING_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include <stm32f1xx.h>

typedef struct{
    char *rx_buf_p;
    char *rx_pos_p;
    uint16_t rx_remaining;
    volatile uint8_t rx_busy;
    volatile uint8_t rx_done;
} LL_USART_ReceiveString_TypeDef;

void LL_USART_ReceiveString_IT(USART_TypeDef *USARTx, LL_USART_ReceiveString_TypeDef *handle, char *str, uint16_t size);
void LL_USART_ReceiveString_IT_Handler(USART_TypeDef *USARTx, LL_USART_ReceiveString_TypeDef *handle);
void LL_USART_StopReceivingString_IT(USART_TypeDef *USARTx, LL_USART_ReceiveString_TypeDef *handle);
uint8_t LL_USART_IsReceivingStringBusy(LL_USART_ReceiveString_TypeDef *handle);
uint8_t LL_USART_IsReceivingStringDone(LL_USART_ReceiveString_TypeDef *handle);


#ifdef __cplusplus
}
#endif

#endif	