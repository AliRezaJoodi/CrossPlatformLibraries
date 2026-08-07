// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef AJ_USART_TYPE_INCLUDED
#define AJ_USART_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


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
	AJ_USART_WORDLENGTH_9B = 1U
} aj_usart_wordlength_t;

typedef enum{
	AJ_USART_WAKEUP_IDLELINE = 0U,
	AJ_USART_WAKEUP_ADDRESSMARK = 1U
} aj_usart_wakeup_t;

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