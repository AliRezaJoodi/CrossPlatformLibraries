/**
 * @brief   Transmit string management for STM32 USART using interrupts and raw registers.
 *
 * This library provides blocking and interrupt-driven helper APIs to transmit
 * a single character or a whole string over an STM32 USART peripheral.
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: Compilation & Linkage
 * -----------------------------------------------------------------------------
 * The following source files must be compiled and linked in the project:
 * - `aj_usart_transmit_string.c`
 *
 * @author  AliRezaJoodi
 * @see     https://github.com/AliRezaJoodi
 */

// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef AJ_USART_TRANSMIT_STRING_INCLUDED
#define AJ_USART_TRANSMIT_STRING_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include <stm32f1xx.h>

typedef struct{
    const char *tx_str_p;
    volatile uint8_t tx_busy;
} aj_usart_tx_string_t;

void AJ_USART_TransmitChar(USART_TypeDef *USARTx, char data);
void AJ_USART_TransmitString(USART_TypeDef *USARTx, const char *str);

void AJ_USART_TransmitString_Interrupt(USART_TypeDef *USARTx, aj_usart_tx_string_t *handle, const char *str);
void AJ_USART_TransmitString_Interrupt_Handler(USART_TypeDef *USARTx, aj_usart_tx_string_t *handle);
uint8_t AJ_USART_IsTransmittingStringBusy(aj_usart_tx_string_t *handle);


#ifdef __cplusplus
}
#endif

#endif		// AJ_USART_TRANSMIT_STRING_INCLUDED
