#ifndef AJ_AFIO_INCLUDED
#define AJ_AFIO_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stm32f1xx.h>
#include "aj_bit_reg.h"

typedef enum{
	AJ_SWJ_SWD_JTAG_NJTRST 	= 0x0U,			/**< SW-DP enabled, 	JTAG-DP enabled with NJTRST */
	AJ_SWJ_SWD_JTAG 				= 0x1U, 		/**< SW-DP enabled, 	JTAG-DP enabled without NJTRST */
	AJ_SWJ_SWD           		= 0x2U, 		/**< SW-DP enabled, 	JTAG-DP disabled */
	AJ_SWJ_DISABLED    			= 0x4U   		/**< SW-DP disabled, 	JTAG-DP disabled */
} aj_afio_swj_t;

static inline void AJ_AFIO_ConfigSWJ(aj_afio_swj_t mode){
	AJ_BitReg_Write3Bit_Position(&AFIO->MAPR, AFIO_MAPR_SWJ_CFG_Pos, mode);
}

#ifdef __cplusplus
}
#endif

#endif	/* AJ_AFIO_INCLUDED */