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

typedef enum {
	AJ_GPIO_MODE_INPUT			= 0x00U,		/* Input (reset state) */
	AJ_GPIO_MODE_OUTPUT 		= 0x01U,		/* General purpose output mode */
	AJ_GPIO_MODE_ALTERNATE	= 0x02U,		/* Alternate function mode */
	AJ_GPIO_MODE_ANALOG 		= 0x03U			/* Analog mode */
} AJ_GPIO_Direction_t;

typedef enum {
	AJ_GPIO_OUTPUT_PUSHPULL   = 0U,	/**< Output push-pull (reset state) */
	AJ_GPIO_OUTPUT_OPENDRAIN  = 1U, 	/**< Output open-drain */
} AJ_GPIO_OutputType_t;

typedef enum {
	AJ_GPIO_SPEED_2MHZ		= 0x00U,		/* 2 MHz Low speed */
	AJ_GPIO_SPEED_25MHZ 	= 0x01U,		/* 25 MHz Medium speed */
	AJ_GPIO_SPEED_50MHZ		= 0x02U,		/* 50 MHz Fast speed */
	AJ_GPIO_SPEED_100MHZ	= 0x03U			/* 100 MHz High speed on 30 pF (80 MHz Output max speed on 15 pF) */
} AJ_GPIO_OutputSpeed_t;

typedef enum {
	AJ_GPIO_PULL_NONE = 0x00U,		/* No pull-up, pull-down */
	AJ_GPIO_PULL_UP   = 0x01U,		/* Pull-up */
	AJ_GPIO_PULL_DOWN = 0x02U		/* Pull-down */
} AJ_GPIO_Pull_t;


#ifdef __cplusplus
}
#endif

#endif	/* AJ_GPIO_TYPE_INCLUDED */