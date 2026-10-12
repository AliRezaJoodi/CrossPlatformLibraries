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
	AJ_SWJ_SWD_JTAG_NJTRST 	= 0x0U,			/**< SW-DP enabled, 	JTAG-DP enabled with NJTRST */
	AJ_SWJ_SWD_JTAG 				= 0x1U, 		/**< SW-DP enabled, 	JTAG-DP enabled without NJTRST */
	AJ_SWJ_SWD           		= 0x2U, 		/**< SW-DP enabled, 	JTAG-DP disabled */
	AJ_SWJ_DISABLED    			= 0x4U   		/**< SW-DP disabled, 	JTAG-DP disabled */
} aj_afio_swj_t;


#ifdef __cplusplus
}
#endif

#endif	/* AJ_AFIO_TYPE_INCLUDED */