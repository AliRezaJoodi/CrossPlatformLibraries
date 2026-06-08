// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef AJ_GPIO_TYPE_INCLUDED
#define AJ_GPIO_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    AJ_GPIO_DIR_INPUT  = 0U,
    AJ_GPIO_DIR_OUTPUT = 1U
} aj_gpio_direction_t;

typedef enum {
	AJ_GPIO_PULL_NONE = 0U,
	AJ_GPIO_PULL_UP   = 1U
} aj_gpio_pull_t;

typedef enum{
    AJ_GPIO_PIN_0_POS  = 0U,
    AJ_GPIO_PIN_1_POS  = 1U,
    AJ_GPIO_PIN_2_POS  = 2U,
    AJ_GPIO_PIN_3_POS  = 3U,
    AJ_GPIO_PIN_4_POS  = 4U,
    AJ_GPIO_PIN_5_POS  = 5U,
    AJ_GPIO_PIN_6_POS  = 6U,
    AJ_GPIO_PIN_7_POS  = 7U
} aj_gpio_pin_pos_t;

typedef enum{
	AJ_GPIO_PIN_0_MASK  = (1U << AJ_GPIO_PIN_0_POS),
	AJ_GPIO_PIN_1_MASK  = (1U << AJ_GPIO_PIN_1_POS),
	AJ_GPIO_PIN_2_MASK  = (1U << AJ_GPIO_PIN_2_POS),
	AJ_GPIO_PIN_3_MASK  = (1U << AJ_GPIO_PIN_3_POS),
	AJ_GPIO_PIN_4_MASK  = (1U << AJ_GPIO_PIN_4_POS),
	AJ_GPIO_PIN_5_MASK  = (1U << AJ_GPIO_PIN_5_POS),
	AJ_GPIO_PIN_6_MASK  = (1U << AJ_GPIO_PIN_6_POS),
	AJ_GPIO_PIN_7_MASK  = (1U << AJ_GPIO_PIN_7_POS)
} aj_gpio_pin_mask_t;

typedef struct {
    volatile uint8_t    *pin;      /**< Pin register */
    volatile uint8_t    *ddr;      /**< Data Direction Register */
    volatile uint8_t    *port;     /**< Port register */
} aj_gpio_reg_t;

#ifdef __cplusplus
}
#endif

#endif  /* AJ_GPIO_TYPE_INCLUDED */
