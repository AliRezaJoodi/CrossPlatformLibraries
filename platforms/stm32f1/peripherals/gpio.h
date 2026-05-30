#ifndef GPIO_INCLUDED
#define GPIO_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stm32f1xx.h>	
#include "bit_register32.h"
#include "gpio_type.h"	

static inline void GPIO_ConfigDirection(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pin, GPIO_Direction_t mode){
	if(pin <= 7){
		Write2Bit_Reg32(&(GPIOx->CRL), pin * 4, mode);
	}
	else{
		Write2Bit_Reg32(&(GPIOx->CRH), (pin - 8) * 4, mode);
	}	
}

static inline void GPIO_ConfigInputType(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pin, GPIO_InputType_t mode){
	if(pin <= 7){
		Write2Bit_Reg32(&(GPIOx->CRL), (pin * 4) + 2, mode);
	}
	else{
		Write2Bit_Reg32(&(GPIOx->CRH), ((pin - 8) * 4) + 2, mode);
	}
}

static inline void GPIO_ConfigOutputType(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pin, GPIO_OutputType_t mode){
	if(pin <= 7){
		Write2Bit_Reg32(&GPIOx->CRL, (pin*4)+2, mode);
	}
	else{
		Write2Bit_Reg32(&GPIOx->CRH, ((pin-8)*4)+2, mode);
	}
}

static inline void GPIO_ConfigPull(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pin, GPIO_Pull_t mode){
	WriteBit_Reg32(&GPIOx->ODR, pin, mode);
}

static inline void GPIO_WritePinField(GPIO_TypeDef *GPIOx, uint32_t mask, uint32_t value){
  WriteBitField_Reg32(&GPIOx->ODR, mask, value);
}

static inline void GPIO_WritePin(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pin, uint32_t status){
	WriteBit_Reg32(&GPIOx->ODR, pin, status);
}

static inline void GPIO_Write2Pin(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pos, uint32_t value){
	Write2Bit_Reg32(&GPIOx->ODR, pos, value);
}

static inline void GPIO_Write3Pin(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pos, uint32_t value){
	Write3Bit_Reg32(&GPIOx->ODR, pos, value);
}

static inline void GPIO_Write4Pin(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pos, uint32_t value){
	Write4Bit_Reg32(&GPIOx->ODR, pos, value);
}

static inline void GPIO_WritePort(GPIO_TypeDef *GPIOx, uint32_t value){
	GPIOx->ODR = (value & 0xFFFFU);
}

static inline void GPIO_TogglePinMask(GPIO_TypeDef *GPIOx, uint32_t mask){
	ToggleBitMask_Reg32(&GPIOx->ODR, mask);
}

static inline void GPIO_TogglePin(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pin){
	ToggleBit_Reg32(&GPIOx->ODR, pin);
}

static inline void GPIO_SetPinMask(GPIO_TypeDef *GPIOx, uint32_t mask){
	GPIOx->BSRR = mask & 0xFFFFUL;
}

static inline void GPIO_SetPin(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pin){
	GPIOx->BSRR = (1UL << pin);
}

static inline void GPIO_ClearPinMask(GPIO_TypeDef *GPIOx, uint32_t mask){
	GPIOx->BRR = mask;
}

static inline void GPIO_ClearPin(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pin){
	GPIOx->BRR = (1UL << pin);
}

static inline uint32_t GPIO_ReadPinField(GPIO_TypeDef *GPIOx, uint32_t mask){
	return GetBitField_Reg32(&GPIOx->IDR, mask);
}

static inline uint8_t GPIO_ReadPin(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pos){
	return GetBit_Reg32(&GPIOx->IDR, pos);
}

static inline uint8_t GPIO_Read2Pin(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pos){
	return Get2Bit_Reg32(&GPIOx->IDR, pos);
}

static inline uint8_t GPIO_Read3Pin(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pos){
	return Get3Bit_Reg32(&GPIOx->IDR, pos);
}

static inline uint8_t GPIO_Read4Pin(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pos){
	return Get4Bit_Reg32(&GPIOx->IDR, pos);
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

static inline uint8_t GPIO_ReadPinLockStatus(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pin){
	uint32_t lckr = GPIOx->LCKR;

	return (uint8_t)(
									((lckr >> GPIO_LCKR_LCKK_Pos) & 1U) &&	// LCKK
									((lckr >> pin) & 1U)       							// LCKy
									);
}

//static inline uint8_t GPIO_ReadLockKeyBit(GPIO_TypeDef *GPIOx){
//	return GetBit_Reg32(&GPIOx->LCKR, GPIO_LCKR_LCKK_Pos);
//}

//static inline uint8_t GPIO_ReadLockPin(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pin){
//    return (uint8_t)((GPIOx->LCKR >> pin) & 0x01UL);
//}

#ifdef __cplusplus
}
#endif

#endif	/* GPIO_INCLUDED */
