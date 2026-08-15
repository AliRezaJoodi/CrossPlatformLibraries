/**
 * @brief GPIO utility library for STM32F4xx microcontrollers.
 *
 * Provides inline functions for GPIO configuration, read/write operations,
 * and GPIO lock management.
 *
 * @section usage_constraints Usage Constraints
 * - STM32F1xx only (CRL/CRH GPIO architecture).
 * - Pin positions are 0-indexed and must be in the range 0..15.
 * - GPIO masks are interpreted as 16-bit masks.
 * - Functions operating on bit-fields require the mask to describe exactly
 *   one contiguous bit-field.
 * - Additional mask constraints may apply through `aj_bit_reg.h`.
 * - GPIO peripheral clock must be enabled before use.
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT: Configuration Override
 * -----------------------------------------------------------------------------
 * The default macros are declared in the following headers:
 * - `aj_target.h`
 *
 * To customize these configurations, override them inside the central project
 * hardware configuration file:
 * - `hardware.h`
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_GPIO_INCLUDED
#define AJ_GPIO_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stm32f4xx.h>	
#include "aj_bit_reg.h"
#include "aj_gpio_type.h"

//******************************************************
static inline void AJ_GPIO_ConfigDirection(GPIO_TypeDef *GPIOx, aj_gpio_pin_pos_t pin, aj_gpio_direction_t mode){
	AJ_BitReg_Write2Bit_Position(&(GPIOx->MODER), pin * 2U, mode);
}

static inline void AJ_GPIO_ConfigOutputType(GPIO_TypeDef *GPIOx, aj_gpio_pin_pos_t pin, aj_gpio_output_t mode){
	AJ_BitReg_WriteBit_Position(&(GPIOx->OTYPER), pin, mode);
}

static inline void AJ_GPIO_ConfigOutputSpeed(GPIO_TypeDef *GPIOx, aj_gpio_pin_pos_t pin, aj_gpio_speed_t mode){
	AJ_BitReg_Write2Bit_Position(&(GPIOx->OSPEEDR), pin * 2U, mode);
}

static inline void AJ_GPIO_ConfigPull(GPIO_TypeDef *GPIOx, aj_gpio_pin_pos_t pin, aj_gpio_pull_t mode){
	AJ_BitReg_Write2Bit_Position(&(GPIOx->PUPDR), pin * 2U, mode);
}

//******************************************************
static inline void AJ_GPIO_SetPin_Mask(GPIO_TypeDef *GPIOx, uint32_t mask){
	GPIOx->BSRR = (mask & 0xFFFFUL);
}

static inline void AJ_GPIO_SetPin_Position(GPIO_TypeDef *GPIOx, aj_gpio_pin_pos_t pos){
	GPIOx->BSRR = (1UL << pos);
}

//******************************************************
static inline void AJ_GPIO_ClearPin_Mask(GPIO_TypeDef *GPIOx, uint32_t mask){
	GPIOx->BSRR = (mask << 16U);
}

static inline void AJ_GPIO_ClearPin_Position(GPIO_TypeDef *GPIOx, aj_gpio_pin_pos_t pos){
	GPIOx->BSRR = (1U << (pos + 16U));
}

//******************************************************
static inline void AJ_GPIO_TogglePin_Mask(GPIO_TypeDef *GPIOx, uint32_t mask){
	AJ_BitReg_ToggleBit_Mask(&(GPIOx->ODR), mask);
}

static inline void AJ_GPIO_TogglePin_Position(GPIO_TypeDef *GPIOx, aj_gpio_pin_pos_t pos){
	AJ_BitReg_ToggleBit_Position(&(GPIOx->ODR), pos);
}

//******************************************************
//static inline void AJ_GPIO_WriteField_Mask(GPIO_TypeDef *GPIOx, uint32_t mask, uint32_t field){
//  AJ_BitReg_WriteField_Mask(&(GPIOx->ODR), mask, field);
//}

static inline void AJ_GPIO_WritePin_Position(GPIO_TypeDef *GPIOx, aj_gpio_pin_pos_t pos, uint32_t state){
	AJ_BitReg_WriteBit_Position(&(GPIOx->ODR), pos, state);
}

static inline void AJ_GPIO_Write2Pin_Position(GPIO_TypeDef *GPIOx, aj_gpio_pin_pos_t pos, uint32_t value){
	AJ_BitReg_Write2Bit_Position(&(GPIOx->ODR), pos, value);
}

static inline void AJ_GPIO_Write3Pin_Position(GPIO_TypeDef *GPIOx, aj_gpio_pin_pos_t pos, uint32_t value){
	AJ_BitReg_Write3Bit_Position(&(GPIOx->ODR), pos, value);
}

static inline void AJ_GPIO_Write4Pin_Position(GPIO_TypeDef *GPIOx, aj_gpio_pin_pos_t pos, uint32_t value){
	AJ_BitReg_Write4Bit_Position(&(GPIOx->ODR), pos, value);
}

static inline void AJ_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint32_t value){
	GPIOx->ODR = (value & 0xFFFFU);
}

//******************************************************
//static inline uint32_t AJ_GPIO_ReadField_Mask(GPIO_TypeDef *GPIOx, uint32_t field){
//	return AJ_BitReg_GetField_Mask(&(GPIOx->IDR), field);
//}

static inline uint8_t AJ_GPIO_IsPinSet_Mask(GPIO_TypeDef *GPIOx, uint32_t mask){
	return AJ_BitReg_IsBitSet_Mask(&(GPIOx->IDR), mask);
}

static inline uint8_t AJ_GPIO_IsPinSet_Position(GPIO_TypeDef *GPIOx, aj_gpio_pin_pos_t pos){
	return AJ_BitReg_IsBitSet_Position(&(GPIOx->IDR), pos);
}

static inline uint8_t AJ_GPIO_ReadPin_Position(GPIO_TypeDef *GPIOx, aj_gpio_pin_pos_t pos){
	return AJ_BitReg_GetBit_Position(&(GPIOx->IDR), pos);
}

static inline uint8_t AJ_GPIO_Read2Pin_Position(GPIO_TypeDef *GPIOx, aj_gpio_pin_pos_t pos){
	return AJ_BitReg_Get2Bit_Position(&(GPIOx->IDR), pos);
}

static inline uint8_t AJ_GPIO_Read3Pin_Position(GPIO_TypeDef *GPIOx, aj_gpio_pin_pos_t pos){
	return AJ_BitReg_Get3Bit_Position(&(GPIOx->IDR), pos);
}

static inline uint8_t AJ_GPIO_Read4Pin_Position(GPIO_TypeDef *GPIOx, aj_gpio_pin_pos_t pos){
	return AJ_BitReg_Get4Bit_Position(&(GPIOx->IDR), pos);
}

static inline uint16_t AJ_GPIO_ReadPort(GPIO_TypeDef *GPIOx){
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
static inline uint8_t AJ_GPIO_LockPin_Mask(GPIO_TypeDef *GPIOx, uint32_t mask){
	uint32_t lock_value = (1UL << GPIO_LCKR_LCKK_Pos) | (mask & 0xFFFFUL);

	GPIOx->LCKR = lock_value;					/**< Write 1 */
	GPIOx->LCKR = (mask & 0xFFFFUL);	/**< Write 0 */
	GPIOx->LCKR = lock_value;					/**< Write 1 */

	(void)GPIOx->LCKR;								/**< Read 0 */
	
	return AJ_BitReg_IsBitSet_Position(&(GPIOx->LCKR), GPIO_LCKR_LCKK_Pos);
}

/**
 * @brief  Checks whether all GPIO pins specified in the mask are locked.
 * @note   The function returns true only if:
 *         - The Port Lock Key (LCKK) bit is set.
 *         - Every pin selected in the mask has its corresponding LCKy bit set.
 *         If any selected pin is not locked, the function returns false.
 * @param  GPIOx  Pointer to the GPIO peripheral (e.g., GPIOA, GPIOB).
 * @param  mask   16-bit mask specifying the pins to check.
 * @return 1 if all selected pins are locked, 0 otherwise.
 */
static inline uint8_t AJ_GPIO_IsPinLocked_Mask(GPIO_TypeDef *GPIOx, uint32_t mask){
	uint32_t lckr = GPIOx->LCKR;
	mask &= 0xFFFFUL;

	return (uint8_t)(
									((lckr & GPIO_LCKR_LCKK_Msk) != 0U) &&
									((lckr & mask) == mask)
									);
}

/**
 * @brief  Checks if a specific GPIO pin configuration is locked.
 * @param  GPIOx  Pointer to the GPIO peripheral (e.g., GPIOA, GPIOB).
 * @param  pin    GPIO pin number (e.g., GPIO_PIN_0, GPIO_PIN_1, etc.).
 * @return 1 if both the Port Lock Key is active AND the specific pin is locked, 0 otherwise.
 */
static inline uint8_t AJ_GPIO_IsPinLocked_Position(GPIO_TypeDef *GPIOx, aj_gpio_pin_pos_t pos){
	uint32_t lckr = GPIOx->LCKR;

	return (uint8_t)(
									((lckr >> GPIO_LCKR_LCKK_Pos) & 1U) &&	// LCKK
									((lckr >> pos) & 1U)       							// LCKy
									);
}

#ifdef __cplusplus
}
#endif

#endif	/* AJ_GPIO_INCLUDED */