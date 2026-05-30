// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef GPIO_INCLUDED
#define GPIO_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "bit_register8.h"
#include "gpio_config.h"
#include "gpio_type.h"

#if (MCU_SUPPORT_PORTA == 1U)
    extern GPIO_PortReg_t GPIOA;
#endif

#if (MCU_SUPPORT_PORTB == 1U)
    extern GPIO_PortReg_t GPIOB;
#endif

#if (MCU_SUPPORT_PORTC == 1U)
    extern GPIO_PortReg_t GPIOC;
#endif

#if (MCU_SUPPORT_PORTD == 1U)
    extern GPIO_PortReg_t GPIOD;
#endif

#if (MCU_SUPPORT_PORTE == 1U)
    extern GPIO_PortReg_t GPIOE;
#endif

#if (MCU_SUPPORT_PORTF == 1U)
    extern GPIO_PortReg_t GPIOF;
#endif

//*****************************************************************
static inline void GPIO_ConfigDirection(const GPIO_PortReg_t *gpio, GPIO_Pin_t pin, GPIO_Direction_t mode) {
    WriteBit_Reg8(gpio->ddr, pin, mode);
}

//*****************************************************************
static inline void GPIO_ConfigPull(const GPIO_PortReg_t *gpio, GPIO_Pin_t pin, GPIO_Pull_t mode) {
    WriteBit_Reg8(gpio->port, pin, mode);
}

//*****************************************************************
static inline void GPIO_WritePinField(const GPIO_PortReg_t *gpio, uint8_t mask, uint8_t value){
    WriteBitField_Reg8(gpio->port, mask, value);
}

static inline void GPIO_WritePin(const GPIO_PortReg_t *gpio, GPIO_Pin_t pin, uint8_t status) {
    WriteBit_Reg8(gpio->port, pin, status);
}

static inline void GPIO_Write2Pin(const GPIO_PortReg_t *gpio, GPIO_Pin_t pos, uint8_t value) {
    Write2Bit_Reg8(gpio->port, pos, value);
}

static inline void GPIO_Write3Pin(const GPIO_PortReg_t *gpio, GPIO_Pin_t pos, uint8_t value) {
    Write3Bit_Reg8(gpio->port, pos, value);
}

static inline void GPIO_Write4Pin(const GPIO_PortReg_t *gpio, GPIO_Pin_t pos, uint8_t value) {
    Write4Bit_Reg8(gpio->port, pos, value);
}

static inline void GPIO_WritePort(const GPIO_PortReg_t *gpio, uint8_t value) {
    WritePort_Reg8(gpio->port, value);
}

//*****************************************************************
static inline void GPIO_SetPinMask(const GPIO_PortReg_t *gpio, uint8_t mask) {
    SetBitMask_Reg8(gpio->port, mask);
}

static inline void GPIO_SetPin(const GPIO_PortReg_t *gpio, GPIO_Pin_t pin) {
    SetBit_Reg8(gpio->port, pin);
}

//*****************************************************************
static inline void GPIO_ClearPinMask(const GPIO_PortReg_t *gpio, uint8_t mask) {
    ClearBitMask_Reg8(gpio->port, mask);
}

static inline void GPIO_ClearPin(const GPIO_PortReg_t *gpio, GPIO_Pin_t pin) {
    ClearBit_Reg8(gpio->port, pin);
}

//*****************************************************************
static inline void GPIO_TogglePinMask(const GPIO_PortReg_t *gpio, uint8_t mask) {
    ToggleBitMask_Reg8(gpio->port, mask);
}

static inline void GPIO_TogglePin(const GPIO_PortReg_t *gpio, GPIO_Pin_t pin) {
    ToggleBit_Reg8(gpio->port, pin);
}

static inline void GPIO_TogglePort(const GPIO_PortReg_t *gpio) {
    TogglePort_Reg8(gpio->port);
}

//*****************************************************************
static inline uint8_t GPIO_ReadField(const GPIO_PortReg_t *gpio, uint8_t mask) {
    return GetBitField_Reg8(gpio->pin, mask);
}

static inline uint8_t GPIO_IsPinMaskSet(const GPIO_PortReg_t *gpio, uint8_t mask) {
    return IsBitMaskSet_Reg8(gpio->pin, mask);
}

static inline uint8_t GPIO_ReadPin(const GPIO_PortReg_t *gpio, GPIO_Pin_t pos) {
    return GetBit_Reg8(gpio->pin, pos);
}

static inline uint8_t GPIO_Read2Pin(const GPIO_PortReg_t *gpio, GPIO_Pin_t pos) {
    return Get2Bit_Reg8(gpio->pin, pos);
}

static inline uint8_t GPIO_Read3Pin(const GPIO_PortReg_t *gpio, GPIO_Pin_t pos) {
    return Get3Bit_Reg8(gpio->pin, pos);
}

static inline uint8_t GPIO_Read4Pin(const GPIO_PortReg_t *gpio, GPIO_Pin_t pos) {
    return Get4Bit_Reg8(gpio->pin, pos);
}

static inline uint8_t GPIO_ReadPort(const GPIO_PortReg_t *gpio) {
    return *(gpio->pin);
}

#ifdef __cplusplus
}
#endif

#endif  /* GPIO_INCLUDED */
