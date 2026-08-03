// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "aj_usart_type.h"
#include "aj_usart.h"

//*******************************************************************************
void LL_USART_ConfigOperatingMode(USART_TypeDef *USARTx, aj_usart_mode_t mode){
	switch (mode){
		case AJ_USART_MODE_ASYNC:
				USARTx->CR2 &= ~(USART_CR2_CLKEN | USART_CR2_LINEN);
				USARTx->CR3 &= ~(USART_CR3_SCEN |
												 USART_CR3_IREN |
												 USART_CR3_HDSEL);
				break;
		case AJ_USART_MODE_SYNC:
				USARTx->CR2 &= ~USART_CR2_LINEN;
				USARTx->CR2 |= USART_CR2_CLKEN;
				USARTx->CR3 &= ~(USART_CR3_SCEN |
												 USART_CR3_IREN |
												 USART_CR3_HDSEL);
				break;
		case AJ_USART_MODE_LIN:
				USARTx->CR2 &= ~USART_CR2_CLKEN;
				USARTx->CR2 |= USART_CR2_LINEN;
				USARTx->CR3 &= ~(USART_CR3_SCEN |
												 USART_CR3_IREN |
												 USART_CR3_HDSEL);
				break;
		case AJ_USART_MODE_SMARTCARD:
				USARTx->CR2 &= ~(USART_CR2_CLKEN | USART_CR2_LINEN);
				USARTx->CR3 &= ~(USART_CR3_IREN |
												 USART_CR3_HDSEL);
				USARTx->CR3 |= USART_CR3_SCEN;
				break;
		case AJ_USART_MODE_IRDA:
				USARTx->CR2 &= ~(USART_CR2_CLKEN | USART_CR2_LINEN);
				USARTx->CR3 &= ~(USART_CR3_SCEN |
												 USART_CR3_HDSEL);
				USARTx->CR3 |= USART_CR3_IREN;
				break;
		case AJ_USART_MODE_HALF_DUPLEX:
				USARTx->CR2 &= ~(USART_CR2_CLKEN | USART_CR2_LINEN);
				USARTx->CR3 &= ~(USART_CR3_SCEN |
												 USART_CR3_IREN);
				USARTx->CR3 |= USART_CR3_HDSEL;
				break;
		default:
				break;
	}
}