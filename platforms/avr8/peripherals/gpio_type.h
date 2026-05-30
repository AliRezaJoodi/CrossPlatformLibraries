// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef GPIO_TYPE_INCLUDED
#define GPIO_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    GPIO_DIR_INPUT  = 0U,
    GPIO_DIR_OUTPUT = 1U
} GPIO_Direction_t;

typedef enum {
	GPIO_PULL_NONE = 0U,
	GPIO_PULL_UP   = 1U
} GPIO_Pull_t;

typedef enum{
    GPIO_PIN_0_POS  = 0U,
    GPIO_PIN_1_POS  = 1U,
    GPIO_PIN_2_POS  = 2U,
    GPIO_PIN_3_POS  = 3U,
    GPIO_PIN_4_POS  = 4U,
    GPIO_PIN_5_POS  = 5U,
    GPIO_PIN_6_POS  = 6U,
    GPIO_PIN_7_POS  = 7U,
    GPIO_PIN_8_POS  = 8U,
    GPIO_PIN_9_POS  = 9U,
    GPIO_PIN_10_POS = 10U,
    GPIO_PIN_11_POS = 11U,
    GPIO_PIN_12_POS = 12U,
    GPIO_PIN_13_POS = 13U,
    GPIO_PIN_14_POS = 14U,
    GPIO_PIN_15_POS = 15U
} GPIO_PinPos_t;

typedef enum{
	GPIO_PIN_0_MASK  = (1UL << GPIO_PIN_0_POS),
	GPIO_PIN_1_MASK  = (1UL << GPIO_PIN_1_POS),
	GPIO_PIN_2_MASK  = (1UL << GPIO_PIN_2_POS),
	GPIO_PIN_3_MASK  = (1UL << GPIO_PIN_3_POS),
	GPIO_PIN_4_MASK  = (1UL << GPIO_PIN_4_POS),
	GPIO_PIN_5_MASK  = (1UL << GPIO_PIN_5_POS),
	GPIO_PIN_6_MASK  = (1UL << GPIO_PIN_6_POS),
	GPIO_PIN_7_MASK  = (1UL << GPIO_PIN_7_POS),
	GPIO_PIN_8_MASK  = (1UL << GPIO_PIN_8_POS),
	GPIO_PIN_9_MASK  = (1UL << GPIO_PIN_9_POS),
	GPIO_PIN_10_MASK = (1UL << GPIO_PIN_10_POS),
	GPIO_PIN_11_MASK = (1UL << GPIO_PIN_11_POS),
	GPIO_PIN_12_MASK = (1UL << GPIO_PIN_12_POS),
	GPIO_PIN_13_MASK = (1UL << GPIO_PIN_13_POS),
	GPIO_PIN_14_MASK = (1UL << GPIO_PIN_14_POS),
	GPIO_PIN_15_MASK = (1UL << GPIO_PIN_15_POS)
} GPIO_PinMask_t;

typedef struct {
    volatile uint8_t    *pin;      /**< Pin register */
    volatile uint8_t    *ddr;      /**< Data Direction Register */
    volatile uint8_t    *port;     /**< Port register */
} GPIO_PortReg_t;

#ifdef __cplusplus
}
#endif

#endif  /* GPIO_TYPE_INCLUDED */
