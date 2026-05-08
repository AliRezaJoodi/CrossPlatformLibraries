#ifndef GPIO_INCLUDED
#define GPIO_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @brief Hardware configuration for a gpio.
 *
 * This structure holds the hardware registers and pin index
 * for a gpio. It is used inside the GPIO_t structure.
 */
typedef struct {
    volatile uint8_t    *ddr;      /**< Data Direction Register */
    volatile uint8_t    *port;     /**< Port register */
    volatile uint8_t    *pin;      /**< Pin register */
    const uint8_t       index;    /**< Pin index number */
    const uint8_t       mask;
} GPIO_t;

/**
 * @example
 * Example: initializing a structure
 *
 * @code
 * #define KEY_DDR     DDRA
 * #define KEY_PORT    PORTA
 * #define KEY_PIN     PINA
 * #define KEY_BIT     0U
 * #define KEY_MASK    (1U << KEY_BIT)
 *
 *     static const GPIO_t key = {
 *         .ddr   = &KEY_DDR,
 *         .port  = &KEY_PORT,
 *         .pin   = &KEY_PIN,
 *         .index = KEY_BIT,
 *         .mask  = KEY_MASK
 *     };
 * @endcode
 */

//*****************************************************************
static inline void GPIO_ConfigOutputPinMask(const GPIO_t *gpio) {
    *(gpio->ddr) = (uint8_t)(*(gpio->ddr) | gpio->mask);
}

static inline void GPIO_ConfigOutputPin(const GPIO_t *gpio) {
    *(gpio->ddr) = (uint8_t)(*(gpio->ddr) | (0x01U << gpio->index));
}

static inline void GPIO_ConfigOutputPort(const GPIO_t *gpio) {
    *(gpio->ddr) = 0xFFU;
}

//*****************************************************************
static inline void GPIO_ConfigInputPinMask(const GPIO_t *gpio) {
    *(gpio->ddr) = (uint8_t)(*(gpio->ddr) & (~gpio->mask));
}

static inline void GPIO_ConfigInputPin(const GPIO_t *gpio) {
    *(gpio->ddr) = (uint8_t)(*(gpio->ddr) & ~(0x01U << gpio->index));
}

static inline void GPIO_ConfigInputPort(const GPIO_t *gpio) {
    *(gpio->ddr) = 0x00U;
}

//*****************************************************************
static inline void GPIO_ConfigPullNonePinMask(const GPIO_t *gpio) {
    *(gpio->port) = (uint8_t)(*(gpio->port) & (~gpio->mask));
}

static inline void GPIO_ConfigPullNonePin(const GPIO_t *gpio) {
    *(gpio->port) = (uint8_t)(*(gpio->port) & ~(0x01U << gpio->index));
}

static inline void GPIO_ConfigPullNonePort(const GPIO_t *gpio) {
    *(gpio->port) = 0x00U;
}

//*****************************************************************
static inline void GPIO_ConfigPullUpPinMask(const GPIO_t *gpio) {
    *(gpio->port) = (uint8_t)(*(gpio->port) | gpio->mask);
}

static inline void GPIO_ConfigPullUpPin(const GPIO_t *gpio) {
    *(gpio->port) = (uint8_t)(*(gpio->port) | (0x01U << gpio->index));
}

static inline void GPIO_ConfigPullUpPort(const GPIO_t *gpio) {
    *(gpio->port) = 0xFFU;
}

//*****************************************************************
static inline void GPIO_WritePinMask(const GPIO_t *gpio, uint8_t value){
    *(gpio->port) = (uint8_t)(
        (*(gpio->port) & ~(gpio->mask)) |
        ((value << gpio->index) & gpio->mask)
    );
}

static inline void GPIO_WritePin(const GPIO_t *gpio, uint8_t status) {
    *(gpio->port) = (uint8_t)(
        (*(gpio->port) & ~(0x01U << gpio->index)) |
        ((status & 0x01U) << gpio->index)
    );
}

static inline void GPIO_WritePort(const GPIO_t *gpio, uint8_t value) {
    *(gpio->port) = value;
}

//*****************************************************************
static inline void GPIO_SetPinMask(const GPIO_t *gpio) {
    *(gpio->port) = (uint8_t)(*(gpio->port) | gpio->mask);
}

static inline void GPIO_SetPin(const GPIO_t *gpio) {
    *(gpio->port) = (uint8_t)(*(gpio->port) | (0x01U << gpio->index));
}

//static inline void GPIO_SetPort(const GPIO_t *gpio) {
//    *(gpio->port) = 0xFFU;
//}


//*****************************************************************
static inline void GPIO_ClearPinMask(const GPIO_t *gpio) {
    *(gpio->port) = (uint8_t)(*(gpio->port) & ~(gpio->mask));
}

static inline void GPIO_ClearPin(const GPIO_t *gpio) {
    *(gpio->port) = (uint8_t)(*(gpio->port) & ~(0x01U << gpio->index));
}

//static inline void GPIO_ClearPort(const GPIO_t *gpio) {
//    *(gpio->port) = 0x00U;
//}

//*****************************************************************
static inline void GPIO_TogglePinMask(const GPIO_t *gpio) {
    *(gpio->port) = (uint8_t)(*(gpio->port) ^ gpio->mask);
}

static inline void GPIO_TogglePin(const GPIO_t *gpio) {
    *(gpio->port) = (uint8_t)(*(gpio->port) ^ (0x01U << gpio->index));
}

static inline void GPIO_TogglePort(const GPIO_t *gpio) {
    *(gpio->port) = (uint8_t)(*(gpio->port) ^ 0xFFU);
}

//*****************************************************************
static inline uint8_t GPIO_ReadPinMask(const GPIO_t *gpio) {
    return (uint8_t)((*(gpio->pin) & gpio->mask) >> gpio->index);
}

static inline uint8_t GPIO_ReadPinMask_Boolean(const GPIO_t *gpio) {
    return (uint8_t)(((*(gpio->pin)) & gpio->mask) != 0U);
}

static inline uint8_t GPIO_ReadPin(const GPIO_t *gpio) {
    return (uint8_t)((*(gpio->pin) >> gpio->index) & 0x01U);
}

static inline uint8_t GPIO_ReadPort(const GPIO_t *gpio) {
    return *(gpio->pin);
}

#ifdef __cplusplus
}
#endif

#endif
