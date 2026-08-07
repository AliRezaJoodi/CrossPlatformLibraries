// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef AJ_USART_TYPE_INCLUDED
#define AJ_USART_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stm32f1xx.h>

typedef enum{
	AJ_USART_MODE_ASYNC = 0U,
	AJ_USART_MODE_SYNC,
	AJ_USART_MODE_LIN,
	AJ_USART_MODE_SMARTCARD,
	AJ_USART_MODE_IRDA,
	AJ_USART_MODE_HALF_DUPLEX
} aj_usart_mode_t;

typedef enum{
	AJ_USART_WORDLENGTH_8B = 0U,
	AJ_USART_WORDLENGTH_9B = USART_CR1_M_Msk
} aj_usart_wordlength_t;

typedef enum{
	AJ_USART_WAKEUP_IDLELINE = 0U,
	AJ_USART_WAKEUP_ADDRESSMARK = USART_CR1_WAKE_Msk
} aj_usart_wakeup_t;

typedef enum{
	AJ_USART_PARITY_NONE = 0U,
	AJ_USART_PARITY_EVEN = USART_CR1_PCE_Msk,
	AJ_USART_PARITY_ODD  = (USART_CR1_PCE_Msk | USART_CR1_PS_Msk)
} aj_usart_parity_t;

#if defined(USART_CR1_OVER8_Msk)
typedef enum{
	AJ_USART_OVERSAMPLING_16 = 0U,
	AJ_USART_OVERSAMPLING_8  = USART_CR1_OVER8_Msk
} aj_usart_oversampling_t;
#endif


#ifdef __cplusplus
}
#endif

#endif	/* AJ_USART_TYPE_INCLUDED */