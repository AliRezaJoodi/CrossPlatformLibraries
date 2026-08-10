// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef AJ_USART_TYPE_INCLUDED
#define AJ_USART_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stm32f1xx.h>

typedef enum{
	AJ_USART_FLAG_CTS   = USART_SR_CTS_Msk,
	AJ_USART_FLAG_LBD   = USART_SR_LBD_Msk,
	AJ_USART_FLAG_TXE   = USART_SR_TXE_Msk,
	AJ_USART_FLAG_TC    = USART_SR_TC_Msk,
	AJ_USART_FLAG_RXNE  = USART_SR_RXNE_Msk,
	AJ_USART_FLAG_IDLE  = USART_SR_IDLE_Msk,
	AJ_USART_FLAG_ORE   = USART_SR_ORE_Msk,
	AJ_USART_FLAG_NE    = USART_SR_NE_Msk,
	AJ_USART_FLAG_FE    = USART_SR_FE_Msk,
	AJ_USART_FLAG_PE    = USART_SR_PE_Msk
} aj_usart_sr_flag_t;

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

typedef enum{
	AJ_USART_DIRECTION_NONE = 0U,
	AJ_USART_DIRECTION_RX   = USART_CR1_RE_Msk,
	AJ_USART_DIRECTION_TX   = USART_CR1_TE_Msk,
	AJ_USART_DIRECTION_TX_RX = (USART_CR1_TE_Msk | USART_CR1_RE_Msk)
} aj_usart_direction_t;

#if defined(USART_CR1_OVER8_Msk)
typedef enum{
	AJ_USART_OVERSAMPLING_16 = 0U,
	AJ_USART_OVERSAMPLING_8  = USART_CR1_OVER8_Msk
} aj_usart_oversampling_t;
#endif

typedef enum{
	AJ_USART_STOPBITS_1     = 0U,
	AJ_USART_STOPBITS_0_5   = USART_CR2_STOP_0,
	AJ_USART_STOPBITS_2     = USART_CR2_STOP_1,
	AJ_USART_STOPBITS_1_5   = (USART_CR2_STOP_0 | USART_CR2_STOP_1)
} aj_usart_stopbits_t;

typedef enum{
	AJ_USART_CLOCK_POLARITY_LOW  = 0U,
	AJ_USART_CLOCK_POLARITY_HIGH = USART_CR2_CPOL_Msk
} aj_usart_clock_polarity_t;

typedef enum{
	AJ_USART_CLOCK_PHASE_1EDGE = 0U,
	AJ_USART_CLOCK_PHASE_2EDGE = USART_CR2_CPHA_Msk
} aj_usart_clock_phase_t;

typedef enum{
	AJ_USART_LIN_BREAK_DETECT_10B = 0U,
	AJ_USART_LIN_BREAK_DETECT_11B = USART_CR2_LBDL_Msk
} aj_usart_lin_break_detection_t;


#ifdef __cplusplus
}
#endif

#endif	/* AJ_USART_TYPE_INCLUDED */