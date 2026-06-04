#ifndef GPIO_INCLUDED
#define GPIO_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stm32f1xx.h>
#include "aj_bit_reg.h"
#include "aj_gpio_type.h"	

static inline void AJ_GPIO_ConfigDirection(GPIO_TypeDef *GPIOx, AJ_GPIO_PinPos_t pos, AJ_GPIO_Direction_t mode){
	if(pos <= 7){
		AJ_BitReg_Write2Bits_Position(&(GPIOx->CRL), pos * 4, mode);
	}
	else{
		AJ_BitReg_Write2Bits_Position(&(GPIOx->CRH), (pos - 8) * 4, mode);
	}	
}

static inline void AJ_GPIO_ConfigInputType(GPIO_TypeDef *GPIOx, AJ_GPIO_PinPos_t pos, AJ_GPIO_InputType_t mode){
	if(pos <= 7){
		AJ_BitReg_Write2Bits_Position(&(GPIOx->CRL), (pos * 4) + 2, mode);
	}
	else{
		AJ_BitReg_Write2Bits_Position(&(GPIOx->CRH), ((pos - 8) * 4) + 2, mode);
	}
}

static inline void AJ_GPIO_ConfigOutputType(GPIO_TypeDef *GPIOx, AJ_GPIO_PinPos_t pos, AJ_GPIO_OutputType_t mode){
	if(pos <= 7){
		AJ_BitReg_Write2Bits_Position(&GPIOx->CRL, (pos*4)+2, mode);
	}
	else{
		AJ_BitReg_Write2Bits_Position(&GPIOx->CRH, ((pos-8)*4)+2, mode);
	}
}

static inline void AJ_GPIO_ConfigPull(GPIO_TypeDef *GPIOx, AJ_GPIO_PinPos_t pos, AJ_GPIO_Pull_t mode){
	AJ_BitReg_WriteBit_Position(&GPIOx->ODR, pos, mode);
}

static inline void AJ_GPIO_SetPins_Mask(GPIO_TypeDef *GPIOx, uint32_t mask){
	GPIOx->BSRR = mask & 0xFFFFUL;
}

static inline void AJ_GPIO_SetPin_Position(GPIO_TypeDef *GPIOx, AJ_GPIO_PinPos_t pos){
	GPIOx->BSRR = (1UL << pos);
}

static inline void AJ_GPIO_ClearPins_Mask(GPIO_TypeDef *GPIOx, uint32_t mask){
	GPIOx->BRR = mask;
}

static inline void AJ_GPIO_ClearPin_Position(GPIO_TypeDef *GPIOx, AJ_GPIO_PinPos_t pos){
	GPIOx->BRR = (1UL << pos);
}

static inline void AJ_GPIO_TogglePins_Mask(GPIO_TypeDef *GPIOx, uint32_t mask){
	AJ_BitReg_ToggleBits_Mask(&GPIOx->ODR, mask);
}

static inline void AJ_GPIO_TogglePin_Position(GPIO_TypeDef *GPIOx, AJ_GPIO_PinPos_t pos){
	AJ_BitReg_ToggleBit_Position(&GPIOx->ODR, pos);
}

static inline void AJ_GPIO_WriteField_Mask(GPIO_TypeDef *GPIOx, uint32_t mask, uint32_t value){
  AJ_BitReg_WriteField_Mask(&GPIOx->ODR, mask, value);
}

static inline void AJ_GPIO_WritePin_Position(GPIO_TypeDef *GPIOx, AJ_GPIO_PinPos_t pos, uint32_t status){
	AJ_BitReg_WriteBit_Position(&GPIOx->ODR, pos, status);
}

static inline void AJ_GPIO_Write2Pins_Position(GPIO_TypeDef *GPIOx, AJ_GPIO_PinPos_t pos, uint32_t value){
	AJ_BitReg_Write2Bits_Position(&GPIOx->ODR, pos, value);
}

static inline void AJ_GPIO_Write3Pins_Position(GPIO_TypeDef *GPIOx, AJ_GPIO_PinPos_t pos, uint32_t value){
	AJ_BitReg_Write3Bits_Position(&GPIOx->ODR, pos, value);
}

static inline void AJ_GPIO_Write4Pins_Position(GPIO_TypeDef *GPIOx, AJ_GPIO_PinPos_t pos, uint32_t value){
	AJ_BitReg_Write4Bits_Position(&GPIOx->ODR, pos, value);
}

static inline void GPIO_WritePort(GPIO_TypeDef *GPIOx, uint32_t value){
	GPIOx->ODR = (value & 0xFFFFU);
}

static inline uint32_t AJ_GPIO_ReadField_Mask(GPIO_TypeDef *GPIOx, uint32_t mask){
	return AJ_BitReg_GetField_Mask(&GPIOx->IDR, mask);
}

static inline uint32_t AJ_GPIO_ArePinsSet_Mask(GPIO_TypeDef *GPIOx, uint32_t mask){
	return AJ_BitReg_AreBitsSet_Mask(&GPIOx->IDR, mask);
}

static inline uint32_t AJ_GPIO_IsAnyPinSet_Mask(GPIO_TypeDef *GPIOx, uint32_t mask){
	return AJ_BitReg_IsAnyBitSet_Mask(&GPIOx->IDR, mask);
}

static inline uint8_t AJ_GPIO_IsPinSet_Position(GPIO_TypeDef *GPIOx, AJ_GPIO_PinPos_t pos){
	return AJ_BitReg_IsBitSet_Position(&GPIOx->IDR, pos);
}

static inline uint8_t AJ_GPIO_ReadPin_Position(GPIO_TypeDef *GPIOx, AJ_GPIO_PinPos_t pos){
	return AJ_BitReg_GetBit_Position(&GPIOx->IDR, pos);
}

static inline uint8_t AJ_GPIO_Read2Pins_Position(GPIO_TypeDef *GPIOx, AJ_GPIO_PinPos_t pos){
	return AJ_BitReg_Get2Bits_Position(&GPIOx->IDR, pos);
}

static inline uint8_t AJ_GPIO_Read3Pins_Position(GPIO_TypeDef *GPIOx, AJ_GPIO_PinPos_t pos){
	return AJ_BitReg_Get3Bits_Position(&GPIOx->IDR, pos);
}

static inline uint8_t AJ_GPIO_Read4Pins_Position(GPIO_TypeDef *GPIOx, AJ_GPIO_PinPos_t pos){
	return AJ_BitReg_Get4Bits_Position(&GPIOx->IDR, pos);
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

static inline uint8_t GPIO_LockPins_Mask(GPIO_TypeDef *GPIOx, uint32_t mask){
	uint32_t lock_value = (1UL << GPIO_LCKR_LCKK_Pos) | (mask & 0xFFFFUL);

	GPIOx->LCKR = lock_value;	/**< Write 1 */
	GPIOx->LCKR = (mask & 0xFFFFUL);	/**< Write 0 */
	GPIOx->LCKR = lock_value;	/**< Write 1 */

	(void)GPIOx->LCKR;	/**< Read 0 */
	
	return AJ_BitReg_GetBit_Position(&GPIOx->LCKR, GPIO_LCKR_LCKK_Pos);
}

static inline uint8_t AJ_GPIO_IsPinLocked_Position(GPIO_TypeDef *GPIOx, AJ_GPIO_PinPos_t pos){
	uint32_t lckr = GPIOx->LCKR;

	return (uint8_t)(
									((lckr >> GPIO_LCKR_LCKK_Pos) & 1U) &&	// LCKK
									((lckr >> pos) & 1U)       							// LCKy
									);
}

//static inline uint8_t GPIO_ReadLockKeyBit(GPIO_TypeDef *GPIOx){
//	return GetBit_Reg32(&GPIOx->LCKR, GPIO_LCKR_LCKK_Pos);
//}

//static inline uint8_t GPIO_ReadLockPin(GPIO_TypeDef *GPIOx, AJ_GPIO_PinPos_t pin){
//    return (uint8_t)((GPIOx->LCKR >> pin) & 0x01UL);
//}

#ifdef __cplusplus
}
#endif

#endif	/* GPIO_INCLUDED */
