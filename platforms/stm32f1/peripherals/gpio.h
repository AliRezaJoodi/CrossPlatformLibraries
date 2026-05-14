#ifndef GPIO_INCLUDED
#define GPIO_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stm32f1xx.h>	
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
 * GPIOx_CRL, Bits 29:28, 25:24, 21:20, 17:16, 13:12, 9:8, 5:4, 1:0
 * MODEy[1:0]: Port x mode bits (y= 0 .. 7)
 * 
 * GPIOx_CRH, Bits 29:28, 25:24, 21:20, 17:16, 13:12, 9:8, 5:4, 1:0
 * MODEy[1:0]: Port x mode bits (y= 8 .. 15)
 *
 * 						These bits are written by software to configure the corresponding I/O port.
 * 						00: Input mode (reset state)
 * 						01: Output mode, max speed 10 MHz.
 * 						10: Output mode, max speed 2 MHz.
 * 						11: Output mode, max speed 50 MHz.
 */
 
typedef enum {
	GPIO_MODE_INPUT        = 0x00U,
	GPIO_MODE_OUTPUT_10MHz = 0x01U,
	GPIO_MODE_OUTPUT_2MHz  = 0x02U,
	GPIO_MODE_OUTPUT_50MHz = 0x03U
} GPIO_Direction_t;

static inline void GPIO_ConfigDirection(GPIO_TypeDef *GPIOx, GPIO_Pin_t pin, GPIO_Direction_t mode){
	if(pin <= 7){
		Write2Bit_Reg32(&GPIOx->CRL, pin*4, mode);
	}
	else{
		Write2Bit_Reg32(&GPIOx->CRH, (pin-8)*4, mode);
	}	
}

/*
 * GPIOx_CRL, Bits 31:30, 27:26, 23:22, 19:18, 15:14, 11:10, 7:6, 3:2
 * CNFy[1:0]: 	Port x configuration bits (y= 0 .. 7)
 * 
 * GPIOx_CRH, Bits 31:30, 27:26, 23:22, 19:18, 15:14, 11:10, 7:6, 3:2
 * CNFy[1:0]: 	Port x configuration bits (y= 8 .. 15)
 * 
 * 						These bits are written by software to configure the corresponding I/O port.						
 * 						00: Analog mode
 * 						01: Floating input (reset state)
 * 						10: Input with pull-up / pull-down
 * 						11: Reserved
 */

typedef enum {
	GPIO_INPUT_ANALOG   = 0x00U,
	GPIO_INPUT_FLOATING = 0x01U,
	GPIO_INPUT_PULL     = 0x02U
} GPIO_InputType_t;

static inline void GPIO_ConfigInputType(GPIO_TypeDef *GPIOx, GPIO_Pin_t pin, GPIO_InputType_t mode){
	if(pin <= 7){
		Write2Bit_Reg32(&GPIOx->CRL, (pin*4)+2, mode);
	}
	else{
		Write2Bit_Reg32(&GPIOx->CRH, ((pin-8)*4)+2, mode);
	}
}

/*
 * GPIOx_CRL, Bits 31:30, 27:26, 23:22, 19:18, 15:14, 11:10, 7:6, 3:2
 * CNFy[1:0]: 	Port x configuration bits (y= 0 .. 7)
 * 
 * GPIOx_CRH, Bits 31:30, 27:26, 23:22, 19:18, 15:14, 11:10, 7:6, 3:2
 * CNFy[1:0]: 	Port x configuration bits (y= 8 .. 15)
 * 
 * 						These bits are written by software to configure the corresponding I/O port.						
 * 						00: General purpose output push-pull
 * 						01: General purpose output Open-drain
 * 						10: Alternate function output Push-pull
 * 						11: Alternate function output Open-drain
 */

typedef enum {
	GPIO_OUTPUT_GP_PUSHPULL   = 0x00U,	/**< General purpose output push-pull */
	GPIO_OUTPUT_GP_OPENDRAIN  = 0x01U, 	/**< General purpose output open-drain */
	GPIO_OUTPUT_AF_PUSHPULL   = 0x02U, 	/**< Alternate function output push-pull */
	GPIO_OUTPUT_AF_OPENDRAIN	= 0x03U  	/**< Alternate function output open-drain */
} GPIO_OutputType_t;

static inline void GPIO_ConfigOutputType(GPIO_TypeDef *GPIOx, GPIO_Pin_t pin, GPIO_OutputType_t mode){
	if(pin <= 7){
		Write2Bit_Reg32(&GPIOx->CRL, (pin*4)+2, mode);
	}
	else{
		Write2Bit_Reg32(&GPIOx->CRH, ((pin-8)*4)+2, mode);
	}
}

/*
 * GPIOx_ODR, Bits 15:0
 * ODRy: Port output data (y= 0 .. 15)
 * 						These bits can be read and written by software and can be accessed in Word mode only.
 */

typedef enum {
	GPIO_PULL_DOWN = 0U,
	GPIO_PULL_UP   = 1U
} GPIO_Pull_t;

static inline void GPIO_ConfigPull(GPIO_TypeDef *GPIOx, GPIO_Pin_t pin, GPIO_Pull_t mode){
	WriteBit_Reg32(&GPIOx->ODR, pin, mode);
}

static inline void GPIO_WritePinField(GPIO_TypeDef *GPIOx, uint32_t mask, uint32_t value){
  WriteBitField_Reg32(&GPIOx->ODR, mask, value);
}

static inline void GPIO_WritePin(GPIO_TypeDef *GPIOx, GPIO_Pin_t pin, uint32_t status){
	WriteBit_Reg32(&GPIOx->ODR, pin, status);
}

static inline void GPIO_Write2Pin(GPIO_TypeDef *GPIOx, GPIO_Pin_t pin, uint32_t value){
	Write2Bit_Reg32(&GPIOx->ODR, pin, value);
}

static inline void GPIO_Write3Pin(GPIO_TypeDef *GPIOx, GPIO_Pin_t pin, uint32_t value){
	Write3Bit_Reg32(&GPIOx->ODR, pin, value);
}

static inline void GPIO_Write4Pin(GPIO_TypeDef *GPIOx, GPIO_Pin_t pin, uint32_t value){
	Write4Bit_Reg32(&GPIOx->ODR, pin, value);
}

static inline void GPIO_WritePort(GPIO_TypeDef *GPIOx, uint32_t value){
	GPIOx->ODR = (value & 0xFFFFU);
}

static inline void GPIO_TogglePinMask(GPIO_TypeDef *GPIOx, uint32_t mask){
	ToggleBitMask_Reg32(&GPIOx->ODR, mask);
}

static inline void GPIO_TogglePin(GPIO_TypeDef *GPIOx, GPIO_Pin_t pin){
	ToggleBit_Reg32(&GPIOx->ODR, pin);
}

/*
 * GPIOx_BSRR, Bits 15:0
 * BSy: 	Port x Set bit y (y= 0 .. 15)
 * 			These bits are write-only and can be accessed in Word mode only.
 * 			0: No action on the corresponding ODRx bit
 * 			1: Set the corresponding ODRx bit
 */

static inline void GPIO_SetPinMask(GPIO_TypeDef *GPIOx, uint32_t mask){
	GPIOx->BSRR = mask & 0xFFFFUL;
}

static inline void GPIO_SetPin(GPIO_TypeDef *GPIOx, GPIO_Pin_t pin){
	GPIOx->BSRR = (1UL << pin);
}

/*
 * GPIOx_BRR, Bits 15:0
 * BRy: Port x Reset bit y (y= 0 .. 15)
 * 			These bits are write-only and can be accessed in Word mode only.
 * 			0: No action on the corresponding ODRx bit
 * 			1: Reset the corresponding ODRx bit
 */

static inline void GPIO_ResetPinMask(GPIO_TypeDef *GPIOx, uint32_t mask){
	GPIOx->BRR = mask;
}

static inline void GPIO_ResetPin(GPIO_TypeDef *GPIOx, GPIO_Pin_t pin){
	GPIOx->BRR = (1UL << pin);
}

/*
GPIOx_IDR, Bits 15:0
IDRy:	Port input data (y= 0 .. 15)
			These bits are read only and can be accessed in Word mode only.
			They contain the input value of the corresponding I/O port.
*/

static inline uint32_t GPIO_ReadPinField(GPIO_TypeDef *GPIOx, uint32_t mask){
	return GetBitField_Reg32(&GPIOx->IDR, mask);
}

static inline uint8_t GPIO_ReadPin(GPIO_TypeDef *GPIOx, GPIO_Pin_t pin){
	return GetBit_Reg32(&GPIOx->IDR, pin);
}

static inline uint8_t GPIO_Read2Pin(GPIO_TypeDef *GPIOx, GPIO_Pin_t pin){
	return Get2Bit_Reg32(&GPIOx->IDR, pin);
}

static inline uint8_t GPIO_Read3Pin(GPIO_TypeDef *GPIOx, GPIO_Pin_t pin){
	return Get3Bit_Reg32(&GPIOx->IDR, pin);
}

static inline uint8_t GPIO_Read4Pin(GPIO_TypeDef *GPIOx, GPIO_Pin_t pin){
	return Get4Bit_Reg32(&GPIOx->IDR, pin);
}

static inline uint16_t GPIO_ReadPort(GPIO_TypeDef *GPIOx){
	return (uint16_t)((GPIOx->IDR) & 0xFFFFU);
}

/*
 * GPIOx_LCKR, Bit 16
 * LCKK[16]: Lock key
 * 					This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
 * 					0: Port configuration lock key not active
 * 					1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
 * 					
 * 					LOCK key writing sequence:
 * 					Write 1
 * 					Write 0
 * 					Write 1
 * 					Read 0
 * 					Read 1 (this read is optional but confirms that the lock is active)
 * 					
 * 					Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
 * 					Any error in the lock sequence will abort the lock.
 * 
 * GPIOx_LCKR, Bits 15:0
 * LCKy:	Port x Lock bit y (y= 0 .. 15)
 * 				These bits are read write but can only be written when the LCKK bit is 0.
 * 				0: Port configuration not locked.
 * 				1: Port configuration locked.
 */

static inline uint8_t GPIO_LockPinMask(GPIO_TypeDef *GPIOx, uint32_t mask){
	uint32_t lock_value = (1UL << GPIO_LCKR_LCKK_Pos) | (mask & 0xFFFFUL);

	GPIOx->LCKR = lock_value;	/**< Write 1 */
	GPIOx->LCKR = (mask & 0xFFFFUL);	/**< Write 0 */
	GPIOx->LCKR = lock_value;	/**< Write 1 */

	(void)GPIOx->LCKR;	/**< Read 0 */
	
	return GetBit_Reg32(&GPIOx->LCKR, GPIO_LCKR_LCKK_Pos);
}

static inline uint8_t GPIO_ReadPinLockStatus(GPIO_TypeDef *GPIOx, GPIO_Pin_t pin){
	uint32_t lckr = GPIOx->LCKR;

	return (uint8_t)(
									((lckr >> GPIO_LCKR_LCKK_Pos) & 1U) &&	// LCKK
									((lckr >> pin) & 1U)       							// LCKy
									);
}

//static inline uint8_t GPIO_ReadLockKeyBit(GPIO_TypeDef *GPIOx){
//	return GetBit_Reg32(&GPIOx->LCKR, GPIO_LCKR_LCKK_Pos);
//}

//static inline uint8_t GPIO_ReadLockPin(GPIO_TypeDef *GPIOx, GPIO_Pin_t pin){
//    return (uint8_t)((GPIOx->LCKR >> pin) & 0x01UL);
//}

#ifdef __cplusplus
}
#endif

#endif
