/**
 * @brief   Transmit string management for STM32 USART using interrupts and the LL APIs.
 *
 * This library provides blocking and interrupt-driven helper APIs to transmit
 * a single character or a whole string over an STM32 USART peripheral.
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: Compilation & Linkage
 * -----------------------------------------------------------------------------
 * The following source files must be compiled and linked in the project:
 * - `ll_usart_transmit_string.c`
 *
 * @author  AliRezaJoodi
 * @see     https://github.com/AliRezaJoodi
 */

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

void LL_USART_TransmitString_IT(USART_TypeDef *USARTx, LL_USART_TransmitString_TypeDef *handle, const char *str);
void LL_USART_TransmitString_IT_Handler(USART_TypeDef *USARTx, LL_USART_TransmitString_TypeDef *handle);
uint8_t LL_USART_IsTransmittingStringBusy(LL_USART_TransmitString_TypeDef *handle);


#ifdef __cplusplus
}
#endif

#endif		// LL_USART_TRANSMIT_STRING_INCLUDED
