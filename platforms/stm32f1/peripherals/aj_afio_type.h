// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef AJ_AFIO_TYPE_INCLUDED
#define AJ_AFIO_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


/******************************************************************************/
/* SWJ configuration                                                          */
/******************************************************************************/
/**
 * @brief SWJ (Serial Wire JTAG) mode selection in the AFIO_MAPR register.
 */
typedef enum{
	AJ_AFIO_SWJ_SWD_JTAG_NJTRST = 0x0U,		/**< SW-DP enabled, JTAG-DP enabled with NJTRST */
	AJ_AFIO_SWJ_SWD_JTAG        = 0x1U,		/**< SW-DP enabled, JTAG-DP enabled without NJTRST */
	AJ_AFIO_SWJ_SWD             = 0x2U,		/**< SW-DP enabled, JTAG-DP disabled */
	AJ_AFIO_SWJ_DISABLED        = 0x4U		/**< SW-DP disabled, JTAG-DP disabled */
} aj_afio_swj_t;

/******************************************************************************/
/* EXTI source line                                                           */
/******************************************************************************/
/**
 * @brief EXTI line index (0 to 15) whose source port is selected
 *        in the AFIO_EXTICR1..4 registers.
 */
typedef enum{
	AJ_AFIO_EXTI_LINE0  = 0U,
	AJ_AFIO_EXTI_LINE1  = 1U,
	AJ_AFIO_EXTI_LINE2  = 2U,
	AJ_AFIO_EXTI_LINE3  = 3U,
	AJ_AFIO_EXTI_LINE4  = 4U,
	AJ_AFIO_EXTI_LINE5  = 5U,
	AJ_AFIO_EXTI_LINE6  = 6U,
	AJ_AFIO_EXTI_LINE7  = 7U,
	AJ_AFIO_EXTI_LINE8  = 8U,
	AJ_AFIO_EXTI_LINE9  = 9U,
	AJ_AFIO_EXTI_LINE10 = 10U,
	AJ_AFIO_EXTI_LINE11 = 11U,
	AJ_AFIO_EXTI_LINE12 = 12U,
	AJ_AFIO_EXTI_LINE13 = 13U,
	AJ_AFIO_EXTI_LINE14 = 14U,
	AJ_AFIO_EXTI_LINE15 = 15U
} aj_afio_exti_line_t;

/******************************************************************************/
/* EXTI source port                                                           */
/******************************************************************************/
/**
 * @brief Port selected as the source of an EXTI line in the AFIO_EXTICR1..4
 *        registers. Port codes match the hardware field values.
 */
typedef enum{
	AJ_AFIO_EXTI_PORTA = 0U,
	AJ_AFIO_EXTI_PORTB = 1U,
	AJ_AFIO_EXTI_PORTC = 2U,
	AJ_AFIO_EXTI_PORTD = 3U,
	AJ_AFIO_EXTI_PORTE = 4U,
	AJ_AFIO_EXTI_PORTF = 5U,
	AJ_AFIO_EXTI_PORTG = 6U
} aj_afio_exti_port_t;


#ifdef __cplusplus
}
#endif

#endif	/* AJ_AFIO_TYPE_INCLUDED */