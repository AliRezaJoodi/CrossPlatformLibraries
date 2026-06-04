// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef AJ_GPIO_TYPE_INCLUDED
#define AJ_GPIO_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    AJ_GPIO_DIR_INPUT  = 0U,
    AJ_GPIO_DIR_OUTPUT = 1U
} AJ_GPIO_Direction_t;

typedef enum {
	AJ_GPIO_PULL_NONE = 0U,
	AJ_GPIO_PULL_UP   = 1U
} AJ_GPIO_Pull_t;

typedef enum{
    AJ_GPIO_PIN_0_POS  = 0U,
    AJ_GPIO_PIN_1_POS  = 1U,
    AJ_GPIO_PIN_2_POS  = 2U,
    AJ_GPIO_PIN_3_POS  = 3U,
    AJ_GPIO_PIN_4_POS  = 4U,
    AJ_GPIO_PIN_5_POS  = 5U,
    AJ_GPIO_PIN_6_POS  = 6U,
    AJ_GPIO_PIN_7_POS  = 7U,
    AJ_GPIO_PIN_8_POS  = 8U,
    AJ_GPIO_PIN_9_POS  = 9U,
    AJ_GPIO_PIN_10_POS = 10U,
    AJ_GPIO_PIN_11_POS = 11U,
    AJ_GPIO_PIN_12_POS = 12U,
    AJ_GPIO_PIN_13_POS = 13U,
    AJ_GPIO_PIN_14_POS = 14U,
    AJ_GPIO_PIN_15_POS = 15U
} AJ_GPIO_PinPos_t;

typedef enum{
	AJ_GPIO_PIN_0_MASK  = (1UL << AJ_GPIO_PIN_0_POS),
	AJ_GPIO_PIN_1_MASK  = (1UL << AJ_GPIO_PIN_1_POS),
	AJ_GPIO_PIN_2_MASK  = (1UL << AJ_GPIO_PIN_2_POS),
	AJ_GPIO_PIN_3_MASK  = (1UL << AJ_GPIO_PIN_3_POS),
	AJ_GPIO_PIN_4_MASK  = (1UL << AJ_GPIO_PIN_4_POS),
	AJ_GPIO_PIN_5_MASK  = (1UL << AJ_GPIO_PIN_5_POS),
	AJ_GPIO_PIN_6_MASK  = (1UL << AJ_GPIO_PIN_6_POS),
	AJ_GPIO_PIN_7_MASK  = (1UL << AJ_GPIO_PIN_7_POS),
	AJ_GPIO_PIN_8_MASK  = (1UL << AJ_GPIO_PIN_8_POS),
	AJ_GPIO_PIN_9_MASK  = (1UL << AJ_GPIO_PIN_9_POS),
	AJ_GPIO_PIN_10_MASK = (1UL << AJ_GPIO_PIN_10_POS),
	AJ_GPIO_PIN_11_MASK = (1UL << AJ_GPIO_PIN_11_POS),
	AJ_GPIO_PIN_12_MASK = (1UL << AJ_GPIO_PIN_12_POS),
	AJ_GPIO_PIN_13_MASK = (1UL << AJ_GPIO_PIN_13_POS),
	AJ_GPIO_PIN_14_MASK = (1UL << AJ_GPIO_PIN_14_POS),
	AJ_GPIO_PIN_15_MASK = (1UL << AJ_GPIO_PIN_15_POS)
} AJ_GPIO_PinMask_t;

typedef struct {
    volatile uint8_t    *pin;      /**< Pin register */
    volatile uint8_t    *ddr;      /**< Data Direction Register */
    volatile uint8_t    *port;     /**< Port register */
} AJ_GPIO_PortReg_t;

#ifdef __cplusplus
}
#endif

#endif  /* AJ_GPIO_TYPE_INCLUDED */
