#ifndef GPIO_TYPE_INCLUDED
#define GPIO_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


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

typedef enum {
	GPIO_MODE_INPUT        = 0x00U,
	GPIO_MODE_OUTPUT_10MHz = 0x01U,
	GPIO_MODE_OUTPUT_2MHz  = 0x02U,
	GPIO_MODE_OUTPUT_50MHz = 0x03U
} GPIO_Direction_t;

typedef enum {
	GPIO_INPUT_ANALOG   = 0x00U,
	GPIO_INPUT_FLOATING = 0x01U,
	GPIO_INPUT_PULL     = 0x02U
} GPIO_InputType_t;

typedef enum {
	GPIO_OUTPUT_GP_PUSHPULL   = 0x00U,	/**< General purpose, output push-pull */
	GPIO_OUTPUT_GP_OPENDRAIN  = 0x01U, 	/**< General purpose, output open-drain */
	GPIO_OUTPUT_AF_PUSHPULL   = 0x02U, 	/**< Alternate function, output push-pull */
	GPIO_OUTPUT_AF_OPENDRAIN	= 0x03U  	/**< Alternate function, output open-drain */
} GPIO_OutputType_t;

typedef enum {
	GPIO_PULL_DOWN = 0U,
	GPIO_PULL_UP   = 1U
} GPIO_Pull_t;


#ifdef __cplusplus
}
#endif

#endif	/* GPIO_TYPE_INCLUDED */