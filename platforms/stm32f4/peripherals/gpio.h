#ifndef GPIO_INCLUDED
#define GPIO_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stm32f4xx.h>	
#include "bit_register32.h"
#include "gpio_type.h"

static inline void GPIO_ConfigDirection(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pin, GPIO_Direction_t mode){
	Write2Bit_Reg32(&GPIOx->MODER, pin * 2U, mode);
}

static inline void GPIO_ConfigOutputType(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pin, GPIO_OutputType_t mode){
	WriteBit_Reg32(&GPIOx->OTYPER, pin, mode);
}

static inline void GPIO_ConfigOutputSpeed(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pin, GPIO_OutputSpeed_t mode){
	Write2Bit_Reg32(&GPIOx->OSPEEDR, pin * 2U, mode);
}

static inline void GPIO_ConfigPull(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pin, GPIO_Pull_t mode){
	Write2Bit_Reg32(&GPIOx->PUPDR, pin * 2U, mode);
}

static inline void GPIO_WritePinField(GPIO_TypeDef *GPIOx, uint32_t mask, uint32_t value){
  WriteBitField_Reg32(&GPIOx->ODR, mask, value);
}

static inline void GPIO_WritePin(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pin, uint32_t status){
	WriteBit_Reg32(&GPIOx->ODR, pin, status);
}

static inline void GPIO_Write2Pin(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pin, uint32_t value){
	Write2Bit_Reg32(&GPIOx->ODR, pin, value);
}

static inline void GPIO_Write3Pin(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pin, uint32_t value){
	Write3Bit_Reg32(&GPIOx->ODR, pin, value);
}

static inline void GPIO_Write4Pin(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pin, uint32_t value){
	Write4Bit_Reg32(&GPIOx->ODR, pin, value);
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
	GPIOx->BSRR = (mask & 0xFFFFUL);
}

static inline void GPIO_SetPin(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pin){
	GPIOx->BSRR = (1UL << pin);
}

static inline void GPIO_ClearPinMask(GPIO_TypeDef *GPIOx, uint32_t mask){
	GPIOx->BSRR = (mask << 16U);
}

static inline void GPIO_ClearPin(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pin){
	GPIOx->BSRR = (1U << (pin + 16U));
}

static inline uint32_t GPIO_ReadPinField(GPIO_TypeDef *GPIOx, uint32_t mask){
	return GetBitField_Reg32(&GPIOx->IDR, mask);
}

static inline uint8_t GPIO_ReadPin(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pin){
	return GetBit_Reg32(&GPIOx->IDR, pin);
}

static inline uint8_t GPIO_Read2Pin(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pin){
	return Get2Bit_Reg32(&GPIOx->IDR, pin);
}

static inline uint8_t GPIO_Read3Pin(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pin){
	return Get3Bit_Reg32(&GPIOx->IDR, pin);
}

static inline uint8_t GPIO_Read4Pin(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pin){
	return Get4Bit_Reg32(&GPIOx->IDR, pin);
}

static inline uint16_t GPIO_ReadPort(GPIO_TypeDef *GPIOx){
	return (uint16_t)((GPIOx->IDR) & 0xFFFFU);
}

/**
 * @brief  Locks the configuration of specified GPIO pins.
 * @note   This function performs the mandatory lock key write sequence as defined 
 *         in the Reference Manual. Once a pin is locked, its configuration (MODER, 
 *         OTYPER, OSPEEDR, PUPDR, AFR) cannot be modified until the next MCU reset.
 * @param  GPIOx  Pointer to the GPIO peripheral (e.g., GPIOA, GPIOB).
 * @param  mask   16-bit mask specifying which pins to lock.
 * @return 1 if the port configuration is locked (LCKK bit set), 0 otherwise.
 */
static inline uint8_t GPIO_LockPinMask(GPIO_TypeDef *GPIOx, uint32_t mask){
	uint32_t lock_value = (1UL << GPIO_LCKR_LCKK_Pos) | (mask & 0xFFFFUL);

	GPIOx->LCKR = lock_value;					/**< Write 1 */
	GPIOx->LCKR = (mask & 0xFFFFUL);	/**< Write 0 */
	GPIOx->LCKR = lock_value;					/**< Write 1 */

	(void)GPIOx->LCKR;								/**< Read 0 */
	
	return GetBit_Reg32(&GPIOx->LCKR, GPIO_LCKR_LCKK_Pos);
}

/**
 * @brief  Checks if a specific GPIO pin configuration is locked.
 * @param  GPIOx  Pointer to the GPIO peripheral (e.g., GPIOA, GPIOB).
 * @param  pin    GPIO pin number (e.g., GPIO_PIN_0, GPIO_PIN_1, etc.).
 * @return 1 if both the Port Lock Key is active AND the specific pin is locked, 0 otherwise.
 */
static inline uint8_t GPIO_ReadPinLockStatus(GPIO_TypeDef *GPIOx, GPIO_PinPos_t pin){
	uint32_t lckr = GPIOx->LCKR;

	return (uint8_t)(
									((lckr >> GPIO_LCKR_LCKK_Pos) & 1U) &&	// LCKK
									((lckr >> pin) & 1U)       							// LCKy
									);
}

#ifdef __cplusplus
}
#endif

#endif