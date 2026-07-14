#ifndef AJ_TM1637_CONFIG_PLATFORM_INCLUDED
#define AJ_TM1637_CONFIG_PLATFORM_INCLUDED


#include "hardware.h"

#ifndef AJ_TM1637_CONFIG_PLATFORM_EXTRA
#define AJ_TM1637_CONFIG_PLATFORM_EXTRA
    #define AJ_TM1637_CLK_DDR         DDRC
    #define AJ_TM1637_CLK_PORT        PORTC
    #define AJ_TM1637_CLK_PIN         PINC
    #define AJ_TM1637_CLK_POS         0U
    #define AJ_TM1637_CLK_MASK        (1U << AJ_TM1637_CLK_POS)

    #define AJ_TM1637_DIO_DDR         DDRC
    #define AJ_TM1637_DIO_PORT        PORTC
    #define AJ_TM1637_DIO_PIN         PINC
    #define AJ_TM1637_DIO_POS         1U
    #define AJ_TM1637_DIO_MASK        (1U << AJ_TM1637_DIO_POS)
#endif


#endif
