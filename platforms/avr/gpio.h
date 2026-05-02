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
 * #define LED_DDR     DDRB
 * #define LED_PORT    PORTB
 * #define LED_PIN     PINB
 * #define LED_BIT     0U
 * #define LED_MASK    (1U << LED_BIT)
 *
 *    static const GPIO_t led = {
 *        .ddr   = &LED_DDR,
 *        .port  = &LED_PORT,
 *        .pin   = &LED_PIN,
 *        .index = LED_BIT,
 *        .mask  = LED_MASK
 *    };
 * @endcode
 */

//*****************************************************************
static inline void GPIO_SetOutputPinMask(GPIO_t *gpio) {
    *(gpio->ddr) = (uint8_t)(*(gpio->ddr) | gpio->mask);
}

//*****************************************************************
static inline void GPIO_WritePinMask(const GPIO_t *gpio, uint8_t value){
    *(gpio->port) = (uint8_t)(
        (*(gpio->port) & ~(gpio->mask)) |
        ((value << gpio->index) & gpio->mask)
    );
}

static inline void GPIO_WritePin(GPIO_t *gpio, uint8_t status) {
    *(gpio->port) = (uint8_t)(
        (*(gpio->port) & ~(0x01U << gpio->index)) |
        ((status & 0x01U) << gpio->index)
    );
}

static inline void GPIO_WriteHighPinMask(GPIO_t *gpio) {
    *(gpio->port) = (uint8_t)(*(gpio->port) | gpio->mask);
}

static inline void GPIO_WriteHighPin(GPIO_t *gpio){
    *(gpio->port) = (uint8_t)(*(gpio->port) | (0x01U << gpio->index));
}

static inline void GPIO_WriteLowPinMask(GPIO_t *gpio) {
    *(gpio->port) = (uint8_t)(*(gpio->port) & ~(gpio->mask));
}

static inline void GPIO_WriteLowPin(GPIO_t *gpio) {
    *(gpio->port) = (uint8_t)(*(gpio->port) & ~(0x01U << gpio->index));
}

//*****************************************************************
static inline void GPIO_TogglePinMask(GPIO_t *gpio) {
    *(gpio->port) = (uint8_t)(*(gpio->port) ^ gpio->mask);
}

static inline void GPIO_TogglePin(GPIO_t *gpio) {
    *(gpio->port) = (uint8_t)(*(gpio->port) ^ (0x01U << gpio->index));
}

//*****************************************************************
static inline void GPIO_SetInputPinMask(GPIO_t *gpio) {
    *(gpio->ddr) = (uint8_t)(*(gpio->ddr) & (~gpio->mask));
}

//*****************************************************************
static inline void GPIO_SetPullNonePinMask(GPIO_t *gpio) {
    *(gpio->port) = (uint8_t)(*(gpio->port) & (~gpio->mask));
}

static inline void GPIO_SetPullUpPinMask(GPIO_t *gpio) {
    *(gpio->port) = (uint8_t)(*(gpio->port) | gpio->mask);
}

//*****************************************************************
static inline uint8_t GPIO_ReadPinMask_Shifted(const GPIO_t *gpio) {
    return (uint8_t)((*(gpio->pin) & gpio->mask) >> gpio->index);
}

static inline uint8_t GPIO_ReadPinMask_Boolean(const GPIO_t *gpio) {
    return (uint8_t)(((*(gpio->pin)) & gpio->mask) != 0U);
}

static inline uint8_t GPIO_ReadPin(const GPIO_t *gpio) {
    return (uint8_t)((*(gpio->pin) >> gpio->index) & 0x01U);
}

#ifdef __cplusplus
}
#endif

#endif
