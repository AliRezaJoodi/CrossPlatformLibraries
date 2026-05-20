#ifndef GPIO_INCLUDED
#define GPIO_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stm32f4xx.h>	
#include "bit.h"

typedef enum{
	GPIO_PIN_0  = 0U,
	GPIO_PIN_1  = 1U,
	GPIO_PIN_2  = 2U,
	GPIO_PIN_3  = 3U,
	GPIO_PIN_4  = 4U,
	GPIO_PIN_5  = 5U,
	GPIO_PIN_6  = 6U,
	GPIO_PIN_7  = 7U,
	GPIO_PIN_8  = 8U,
	GPIO_PIN_9  = 9U,
	GPIO_PIN_10 = 10U,
	GPIO_PIN_11 = 11U,
	GPIO_PIN_12 = 12U,
	GPIO_PIN_13 = 13U,
	GPIO_PIN_14 = 14U,
	GPIO_PIN_15 = 15U
} GPIO_Pin_t;

typedef enum{
	GPIO_PINMASK_0  = (1UL << 0),
	GPIO_PINMASK_1  = (1UL << 1),
	GPIO_PINMASK_2  = (1UL << 2),
	GPIO_PINMASK_3  = (1UL << 3),
	GPIO_PINMASK_4  = (1UL << 4),
	GPIO_PINMASK_5  = (1UL << 5),
	GPIO_PINMASK_6  = (1UL << 6),
	GPIO_PINMASK_7  = (1UL << 7),
	GPIO_PINMASK_8  = (1UL << 8),
	GPIO_PINMASK_9  = (1UL << 9),
	GPIO_PINMASK_10 = (1UL << 10),
	GPIO_PINMASK_11 = (1UL << 11),
	GPIO_PINMASK_12 = (1UL << 12),
	GPIO_PINMASK_13 = (1UL << 13),
	GPIO_PINMASK_14 = (1UL << 14),
	GPIO_PINMASK_15 = (1UL << 15)
} GPIO_PinMask_t;

/*
 * GPIO port mode register
 * GPIOx_MODER, Bits 2y:2y+1
 * MODEy[1:0]: Port x configuration bits (y = 0..15)
 *
 * 						These bits are written by software to configure the I/O direction mode.
 * 						00: Input (reset state)
 * 						01: General purpose output mode
 * 						10: Alternate function mode
 * 						11: Analog mode
 */

typedef enum {
	GPIO_MODE_INPUT			= 0x00U,
	GPIO_MODE_OUTPUT 		= 0x01U,
	GPIO_MODE_ALTERNATE	= 0x02U,
	GPIO_MODE_ANALOG 		= 0x03U
} GPIO_Direction_t;

static inline void GPIO_ConfigDirection(GPIO_TypeDef *GPIOx, GPIO_Pin_t pin, GPIO_Direction_t mode){
	Write2Bit_Reg32(&GPIOx->MODER, pin * 2U, mode);
}

/*
 * GPIO port output type register
 * GPIOx_OTYPER, Bits 15:0
 * OTy[1:0]: Port x configuration bits (y = 0..15)
 * 
 * 						These bits are written by software to configure the output type of the I/O port.					
 * 						0: Output push-pull (reset state)
 * 						1: Output open-drain
 */

typedef enum {
	GPIO_OUTPUT_PUSHPULL   = 0U,	/**< Output push-pull */
	GPIO_OUTPUT_OPENDRAIN  = 1U, 	/**< Output open-drain */
} GPIO_OutputType_t;

static inline void GPIO_ConfigOutputType(GPIO_TypeDef *GPIOx, GPIO_Pin_t pin, GPIO_OutputType_t mode){
	WriteBit_Reg32(&GPIOx->OTYPER, pin, mode);
}

/*
 * GPIO port output speed register
 * GPIOx_OSPEEDR, Bits 2y:2y+1
 * OSPEEDRy[1:0]: Port x configuration bits (y = 0..15)
 *
 * 						These bits are written by software to configure the I/O output speed.
 * 						00: 2 MHz Low speed
 * 						01: 25 MHz Medium speed
 * 						10: 50 MHz Fast speed
 * 						11: 100 MHz High speed on 30 pF (80 MHz Output max speed on 15 pF)
 */

typedef enum {
	GPIO_SPEED_2MHZ		= 0x00U,
	GPIO_SPEED_25MHZ 	= 0x01U,
	GPIO_SPEED_50MHZ	= 0x02U,
	GPIO_SPEED_100MHZ	= 0x03U
} GPIO_OutputSpeed_t;

static inline void GPIO_ConfigOutputSpeed(GPIO_TypeDef *GPIOx, GPIO_Pin_t pin, GPIO_OutputSpeed_t mode){
	Write2Bit_Reg32(&GPIOx->OSPEEDR, pin * 2U, mode);
}

/*
 * GPIO port pull-up/pull-down register
 * GPIOx_PUPDR, Bits 2y:2y+1
 * PUPDRy[1:0]: Port x configuration bits (y = 0..15)
 * 						These bits are written by software to configure the I/O pull-up or pull-down
 * 						00: No pull-up, pull-down
 * 						01: Pull-up
 * 						10: Pull-down
 * 						11: Reserved
 */

typedef enum {
	GPIO_PULL_NONE = 0x00U,
	GPIO_PULL_UP   = 0x01U,
	GPIO_PULL_DOWN = 0x02U
} GPIO_Pull_t;

static inline void GPIO_ConfigPull(GPIO_TypeDef *GPIOx, GPIO_Pin_t pin, GPIO_Pull_t mode){
	Write2Bit_Reg32(&GPIOx->PUPDR, pin * 2U, mode);
}

#ifdef __cplusplus
}
#endif

#endif