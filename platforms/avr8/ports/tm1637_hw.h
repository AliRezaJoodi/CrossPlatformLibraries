#ifndef TM1637_HW_INCLUDED
#define TM1637_HW_INCLUDED

#include "hardware.h"

#ifndef TM1637_HARDWARE_EXTRA
#define TM1637_HARDWARE_EXTRA
    #define TM1637_CLK_DDR         DDRC
    #define TM1637_CLK_PORT        PORTC
    #define TM1637_CLK_PIN         PINC
    #define TM1637_CLK_BIT         0U
    #define TM1637_CLK_MASK        (1U << TM1637_CLK_BIT)

    #define TM1637_DIO_DDR         DDRC
    #define TM1637_DIO_PORT        PORTC
    #define TM1637_DIO_PIN         PINC
    #define TM1637_DIO_BIT         1U
    #define TM1637_DIO_MASK        (1U << TM1637_DIO_BIT)

#endif

#endif
