/**
 * @brief   Receive string management for STM32 USART using interrupts and raw registers.
 *
 * This library provides interrupt-driven helper APIs to receive a whole string
 * over an STM32 USART peripheral until the receive buffer is full.
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: Compilation & Linkage
 * -----------------------------------------------------------------------------
 * The following source files must be compiled and linked in the project:
 * - `aj_usart_receive_string.c`
 *
 * @author  AliRezaJoodi
 * @see     https://github.com/AliRezaJoodi
 */

// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef AJ_USART_RECEIVE_STRING_INCLUDED
#define AJ_USART_RECEIVE_STRING_INCLUDED

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
} aj_usart_rx_string_t;

void AJ_USART_ReceiveString_Interrupt(USART_TypeDef *USARTx, aj_usart_rx_string_t *handle, char *str, uint16_t size);
void AJ_USART_ReceiveString_Interrupt_Handler(USART_TypeDef *USARTx, aj_usart_rx_string_t *handle);
void AJ_USART_StopReceivingString_Interrupt(USART_TypeDef *USARTx, aj_usart_rx_string_t *handle);
uint8_t AJ_USART_IsReceivingStringBusy(aj_usart_rx_string_t *handle);
uint8_t AJ_USART_IsReceivingStringDone(aj_usart_rx_string_t *handle);


#ifdef __cplusplus
}
#endif

#endif	
