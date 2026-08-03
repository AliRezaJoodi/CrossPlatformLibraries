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


#ifdef __cplusplus
}
#endif

#endif	/* AJ_USART_TYPE_INCLUDED */