// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef AJ_USART_TYPE_INCLUDED
#define AJ_USART_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stm32f1xx.h>

typedef enum{
	AJ_USART_SR_PE   = USART_SR_PE_Msk,   /*< Parity error flag */
	AJ_USART_SR_FE   = USART_SR_FE_Msk,   /*< Framing error flag */
	AJ_USART_SR_NE   = USART_SR_NE_Msk,   /*< Noise error flag */
	AJ_USART_SR_ORE  = USART_SR_ORE_Msk,  /*< Overrun error flag */
	AJ_USART_SR_IDLE = USART_SR_IDLE_Msk, /*< Idle line detected flag */
	AJ_USART_SR_RXNE = USART_SR_RXNE_Msk, /*< Read data register not empty flag */
	AJ_USART_SR_TC   = USART_SR_TC_Msk,   /*< Transmission complete flag */
	AJ_USART_SR_TXE  = USART_SR_TXE_Msk,  /*< Transmit data register empty flag */
	AJ_USART_SR_LBD  = USART_SR_LBD_Msk,  /*< LIN break detection flag */
	AJ_USART_SR_CTS  = USART_SR_CTS_Msk   /*< CTS (Clear to send) flag */
} aj_usart_sr_t;

/**
 * @brief Flags cleared by software (by writing them to 0).
 */
typedef enum{
	AJ_USART_SR_W0_RXNE = USART_SR_RXNE_Msk, /*< Read data register not empty flag */
	AJ_USART_SR_W0_TC   = USART_SR_TC_Msk,   /*< Transmission complete flag */
	AJ_USART_SR_W0_LBD  = USART_SR_LBD_Msk,  /*< LIN break detection flag */
	AJ_USART_SR_W0_CTS  = USART_SR_CTS_Msk   /*< CTS (Clear to send) flag */
} aj_usart_sr_w0_t;

/**
 * @brief Flags cleared by a software sequence (a read to the USART_SR register
 *        followed by a read to the USART_DR register).
 */
typedef enum{
	AJ_USART_SR_R_PE   = USART_SR_PE_Msk,   /*< Parity error flag */
	AJ_USART_SR_R_FE   = USART_SR_FE_Msk,   /*< Framing error flag */
	AJ_USART_SR_R_NE   = USART_SR_NE_Msk,   /*< Noise error flag */
	AJ_USART_SR_R_ORE  = USART_SR_ORE_Msk,  /*< Overrun error flag */
	AJ_USART_SR_R_IDLE = USART_SR_IDLE_Msk  /*< Idle line detected flag */
} aj_usart_sr_r_t;

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

typedef enum{
	AJ_USART_CR1_RE     = USART_CR1_RE_Msk,     /*< Receiver enable */
	AJ_USART_CR1_TE     = USART_CR1_TE_Msk,     /*< Transmitter enable */
	AJ_USART_CR1_IDLEIE = USART_CR1_IDLEIE_Msk, /*< IDLE interrupt enable */
	AJ_USART_CR1_RXNEIE = USART_CR1_RXNEIE_Msk, /*< RXNE interrupt enable */
	AJ_USART_CR1_TCIE   = USART_CR1_TCIE_Msk,   /*< TC interrupt enable */
	AJ_USART_CR1_TXEIE  = USART_CR1_TXEIE_Msk,  /*< TXE interrupt enable */
	AJ_USART_CR1_PEIE   = USART_CR1_PEIE_Msk,   /*< PE interrupt enable */
	AJ_USART_CR1_PCE    = USART_CR1_PCE_Msk,    /*< Parity control enable */
	AJ_USART_CR1_UE     = USART_CR1_UE_Msk      /*< USART enable */
} aj_usart_cr1_t;

typedef enum{
	AJ_USART_CR2_LBDIE  = USART_CR2_LBDIE_Msk,  /*< LIN break detection interrupt enable */
	AJ_USART_CR2_LBCL   = USART_CR2_LBCL_Msk,   /*< Last bit clock pulse */
	AJ_USART_CR2_CLKEN  = USART_CR2_CLKEN_Msk,  /*< Clock enable (CK pin) */
	AJ_USART_CR2_LINEN  = USART_CR2_LINEN_Msk   /*< LIN mode enable */
} aj_usart_cr2_t;

typedef enum{
	AJ_USART_CR3_EIE   = USART_CR3_EIE_Msk,   /*< Error interrupt enable */
	AJ_USART_CR3_IREN  = USART_CR3_IREN_Msk,  /*< IrDA mode enable */
	AJ_USART_CR3_IRLP  = USART_CR3_IRLP_Msk,  /*< IrDA low power */
	AJ_USART_CR3_HDSEL = USART_CR3_HDSEL_Msk, /*< Half-duplex selection */
	AJ_USART_CR3_NACK  = USART_CR3_NACK_Msk,  /*< Smartcard NACK enable */
	AJ_USART_CR3_SCEN  = USART_CR3_SCEN_Msk,  /*< Smartcard mode enable */
	AJ_USART_CR3_DMAR  = USART_CR3_DMAR_Msk,  /*< DMA enable receiver */
	AJ_USART_CR3_DMAT  = USART_CR3_DMAT_Msk,  /*< DMA enable transmitter */
	AJ_USART_CR3_RTSE  = USART_CR3_RTSE_Msk,  /*< RTS enable */
	AJ_USART_CR3_CTSE  = USART_CR3_CTSE_Msk,  /*< CTS enable */
	AJ_USART_CR3_CTSIE = USART_CR3_CTSIE_Msk  /*< CTS interrupt enable */
} aj_usart_cr3_t;


#ifdef __cplusplus
}
#endif

#endif	/* AJ_USART_TYPE_INCLUDED */