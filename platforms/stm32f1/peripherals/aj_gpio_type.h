#ifndef AJ_GPIO_TYPE_INCLUDED
#define AJ_GPIO_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


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
} aj_gpio_pin_pos_t;

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
} aj_gpio_pin_mask_t;

typedef enum {
	AJ_GPIO_MODE_INPUT        = 0x00U,
	AJ_GPIO_MODE_OUTPUT_10MHz = 0x01U,
	AJ_GPIO_MODE_OUTPUT_2MHz  = 0x02U,
	AJ_GPIO_MODE_OUTPUT_50MHz = 0x03U
} aj_gpio_direction_t;

typedef enum {
	AJ_GPIO_INPUT_ANALOG   = 0x00U,
	AJ_GPIO_INPUT_FLOATING = 0x01U,
	AJ_GPIO_INPUT_PULL     = 0x02U
} aj_gpio_input_t;

typedef enum {
	AJ_GPIO_OUTPUT_GP_PUSHPULL   = 0x00U,		/**< General purpose, output push-pull */
	AJ_GPIO_OUTPUT_GP_OPENDRAIN  = 0x01U, 	/**< General purpose, output open-drain */
	AJ_GPIO_OUTPUT_AF_PUSHPULL   = 0x02U, 	/**< Alternate function, output push-pull */
	AJ_GPIO_OUTPUT_AF_OPENDRAIN	 = 0x03U  		/**< Alternate function, output open-drain */
} aj_gpio_output_t;

typedef enum {
	AJ_GPIO_PULL_DOWN = 0U,
	AJ_GPIO_PULL_UP   = 1U
} aj_gpio_pull_t;


#ifdef __cplusplus
}
#endif

#endif	/* AJ_GPIO_TYPE_INCLUDED */