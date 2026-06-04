#ifndef AJ_AFIO_INCLUDED
#define AJ_AFIO_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stm32f1xx.h>	
#include "aj_bit_reg.h"

/*
 * AFIO_MAPR, Bits 26:24
 * SWJ_CFG[2:0]: Serial wire JTAG configuration
 * 							These bits are write-only (when read, the value is undefined).
 * 							They are used to configure the SWJ and trace alternate function I/Os.
 * 							The SWJ (Serial Wire JTAG) supports JTAG or SWD access to the Cortex® debug port.
 * 							The default state after reset is SWJ ON without trace.
 * 							This allows JTAG or SW mode to be enabled by sending a specific sequence on the JTMS/JTCK pin.
 * 							000: Full SWJ (JTAG-DP + SW-DP): Reset State
 * 							001: Full SWJ (JTAG-DP + SW-DP) but without NJTRST
 * 							010: JTAG-DP Disabled and SW-DP Enabled
 * 							100: JTAG-DP Disabled and SW-DP Disabled
 * 							
 * 							Note: Other combinations: no effect
 */

typedef enum{
    AJ_SWJ_SWD_JTAG_NJTRST 	= 0x0U,			/**< SW-DP enabled, 	JTAG-DP enabled with NJTRST */
    AJ_SWJ_SWD_JTAG 				= 0x1U, 		/**< SW-DP enabled, 	JTAG-DP enabled without NJTRST */
    AJ_SWJ_SWD           		= 0x2U, 		/**< SW-DP enabled, 	JTAG-DP disabled */
    AJ_SWJ_DISABLED    			= 0x4U   		/**< SW-DP disabled, 	JTAG-DP disabled */
} AJ_AFIO_SWJ_t;

static inline void AJ_AFIO_ConfigSWJ(AJ_AFIO_SWJ_t mode){
	AJ_BitReg_Write3Bits_Position(&AFIO->MAPR, AFIO_MAPR_SWJ_CFG_Pos, mode);
}

#ifdef __cplusplus
}
#endif

#endif	/* AJ_AFIO_INCLUDED */