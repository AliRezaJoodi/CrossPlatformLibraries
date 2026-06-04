/**
 * @brief GPIO utility library for AVR8 microcontrollers.
 *
 * Provides inline functions for GPIO configuration and digital I/O control
 * using AVR port registers (DDRx, PORTx, PINx).
 *
 * @section usage_constraints Usage Constraints
 * - AVR8 architecture only (e.g., ATmega series).
 * - GPIO is controlled via DDRx (direction), PORTx (output/pull-up),
 *   and PINx (input read/toggle behavior).
 * - Pin positions are 0-indexed and must be in the range 0..7.
 * - GPIO masks are interpreted as 8-bit masks. Bits above bit 7 are ignored.
 * - Functions operating on bit-fields require the mask to describe exactly
 *   one contiguous bit-field.
 * - No clock enable or peripheral initialization is required (direct port access).
 *
 * @note Read-modify-write operations on PORTx are not atomic and may be
 *       affected by interrupts if shared between contexts.
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
#include "aj_bit_reg.h"
#include "aj_gpio_config.h"
#include "aj_gpio_type.h"

#if (AJ_MCU_SUPPORT_PORTA == 1U)
    extern AJ_GPIO_PortReg_t GPIOA;
#endif

#if (AJ_MCU_SUPPORT_PORTB == 1U)
    extern AJ_GPIO_PortReg_t GPIOB;
#endif

#if (AJ_MCU_SUPPORT_PORTC == 1U)
    extern AJ_GPIO_PortReg_t GPIOC;
#endif

#if (AJ_MCU_SUPPORT_PORTD == 1U)
    extern AJ_GPIO_PortReg_t GPIOD;
#endif

#if (AJ_MCU_SUPPORT_PORTE == 1U)
    extern AJ_GPIO_PortReg_t GPIOE;
#endif

#if (AJ_MCU_SUPPORT_PORTF == 1U)
    extern AJ_GPIO_PortReg_t GPIOF;
#endif

//*****************************************************************
static inline void AJ_GPIO_ConfigDirection(const AJ_GPIO_PortReg_t *gpio, AJ_GPIO_PinPos_t pos, AJ_GPIO_Direction_t mode){
    AJ_BitReg_WriteBit_Position(gpio->ddr, pos, mode);
}

static inline void AJ_GPIO_ConfigPinsAsOutput_Mask(const AJ_GPIO_PortReg_t *gpio, uint8_t mask){
    AJ_BitReg_SetBits_Mask(gpio->ddr, mask);
}

static inline void AJ_GPIO_ConfigPinsAsInput_Mask(const AJ_GPIO_PortReg_t *gpio, uint8_t mask){
    AJ_BitReg_ClearBits_Mask(gpio->ddr, mask);
}

static inline void AJ_GPIO_ConfigPinAsOutput_Position(const AJ_GPIO_PortReg_t *gpio, AJ_GPIO_PinPos_t pos){
    AJ_BitReg_SetBit_Position(gpio->ddr, pos);
}

static inline void AJ_GPIO_ConfigPinAsInput_Position(const AJ_GPIO_PortReg_t *gpio, AJ_GPIO_PinPos_t pos){
    AJ_BitReg_ClearBit_Position(gpio->ddr, pos);
}

//*****************************************************************
static inline void AJ_GPIO_ConfigPull(const AJ_GPIO_PortReg_t *gpio, AJ_GPIO_PinPos_t pos, AJ_GPIO_Pull_t mode){
    AJ_BitReg_WriteBit_Position(gpio->port, pos, mode);
}

static inline void AJ_GPIO_EnablePullUp_Mask(const AJ_GPIO_PortReg_t *gpio, uint8_t mask){
    AJ_BitReg_SetBits_Mask(gpio->port, mask);
}

static inline void AJ_GPIO_DisablePullUp_Mask(const AJ_GPIO_PortReg_t *gpio, uint8_t mask){
    AJ_BitReg_ClearBits_Mask(gpio->port, mask);
}

static inline void AJ_GPIO_EnablePullUp_Position(const AJ_GPIO_PortReg_t *gpio, AJ_GPIO_PinPos_t pos){
    AJ_BitReg_SetBit_Position(gpio->port, pos);
}

static inline void AJ_GPIO_DisablePullUp_Position(const AJ_GPIO_PortReg_t *gpio, AJ_GPIO_PinPos_t pos){
    AJ_BitReg_ClearBit_Position(gpio->port, pos);
}

//*****************************************************************
static inline void AJ_GPIO_SetPins_Mask(const AJ_GPIO_PortReg_t *gpio, uint8_t mask){
    AJ_BitReg_SetBits_Mask(gpio->port, mask);
}

static inline void AJ_GPIO_SetPin_Position(const AJ_GPIO_PortReg_t *gpio, AJ_GPIO_PinPos_t pos){
    AJ_BitReg_SetBit_Position(gpio->port, pos);
}

//*****************************************************************
static inline void AJ_GPIO_ClearPins_Mask(const AJ_GPIO_PortReg_t *gpio, uint8_t mask){
    AJ_BitReg_ClearBits_Mask(gpio->port, mask);
}

static inline void AJ_GPIO_ClearPin_Position(const AJ_GPIO_PortReg_t *gpio, AJ_GPIO_PinPos_t pos){
    AJ_BitReg_ClearBit_Position(gpio->port, pos);
}

//*****************************************************************
static inline void AJ_GPIO_TogglePins_Mask(const AJ_GPIO_PortReg_t *gpio, uint8_t mask){
    AJ_BitReg_ToggleBits_Mask(gpio->port, mask);
}

static inline void AJ_GPIO_TogglePin_Position(const AJ_GPIO_PortReg_t *gpio, AJ_GPIO_PinPos_t pos){
    AJ_BitReg_ToggleBit_Position(gpio->port, pos);
}

static inline void AJ_GPIO_TogglePort(const AJ_GPIO_PortReg_t *gpio){
    *(gpio->port) = (uint8_t)(*(gpio->port) ^ 0xFFU);
}

//*****************************************************************
static inline void AJ_GPIO_WriteField_Mask(const AJ_GPIO_PortReg_t *gpio, uint8_t mask, uint8_t value){
    AJ_BitReg_WriteField_Mask(gpio->port, mask, value);
}

static inline void AJ_GPIO_WritePin_Position(const AJ_GPIO_PortReg_t *gpio, AJ_GPIO_PinPos_t pos, uint8_t status){
    AJ_BitReg_WriteBit_Position(gpio->port, pos, status);
}

static inline void AJ_GPIO_Write2Pins_Position(const AJ_GPIO_PortReg_t *gpio, AJ_GPIO_PinPos_t pos, uint8_t value){
    AJ_BitReg_Write2Bits_Position(gpio->port, pos, value);
}

static inline void AJ_GPIO_Write3Pins_Position(const AJ_GPIO_PortReg_t *gpio, AJ_GPIO_PinPos_t pos, uint8_t value){
    AJ_BitReg_Write3Bits_Position(gpio->port, pos, value);
}

static inline void AJ_GPIO_Write4Pins_Position(const AJ_GPIO_PortReg_t *gpio, AJ_GPIO_PinPos_t pos, uint8_t value){
    AJ_BitReg_Write4Bits_Position(gpio->port, pos, value);
}

static inline void AJ_GPIO_WritePort(const AJ_GPIO_PortReg_t *gpio, uint8_t value){
    *(gpio->port) = value;
}

//*****************************************************************
static inline uint8_t AJ_GPIO_ReadField_Mask(const AJ_GPIO_PortReg_t *gpio, uint8_t mask){
    return AJ_BitReg_GetField_Mask(gpio->pin, mask);
}

static inline uint8_t AJ_GPIO_ArePinsSet_Mask(const AJ_GPIO_PortReg_t *gpio, uint8_t mask){
    return AJ_BitReg_AreBitsSet_Mask(gpio->pin, mask);
}

static inline uint8_t AJ_GPIO_IsAnyPinSet_Mask(const AJ_GPIO_PortReg_t *gpio, uint8_t mask){
    return AJ_BitReg_IsAnyBitSet_Mask(gpio->pin, mask);
}

static inline uint8_t AJ_GPIO_IsPinSet_Position(const AJ_GPIO_PortReg_t *gpio, AJ_GPIO_PinPos_t pos){
    return AJ_BitReg_IsBitSet_Position(gpio->pin, pos);
}

static inline uint8_t AJ_GPIO_ReadPin_Position(const AJ_GPIO_PortReg_t *gpio, AJ_GPIO_PinPos_t pos){
    return AJ_BitReg_GetBit_Position(gpio->pin, pos);
}

static inline uint8_t AJ_GPIO_Read2Pins_Position(const AJ_GPIO_PortReg_t *gpio, AJ_GPIO_PinPos_t pos){
    return AJ_BitReg_Get2Bits_Position(gpio->pin, pos);
}

static inline uint8_t AJ_GPIO_Read3Pins_Position(const AJ_GPIO_PortReg_t *gpio, AJ_GPIO_PinPos_t pos){
    return AJ_BitReg_Get3Bits_Position(gpio->pin, pos);
}

static inline uint8_t AJ_GPIO_Read4Pins_Position(const AJ_GPIO_PortReg_t *gpio, AJ_GPIO_PinPos_t pos){
    return AJ_BitReg_Get4Bits_Position(gpio->pin, pos);
}

static inline uint8_t GPIO_ReadPort(const AJ_GPIO_PortReg_t *gpio){
    return *(gpio->pin);
}

#ifdef __cplusplus
}
#endif

#endif  /* AJ_GPIO_INCLUDED */
