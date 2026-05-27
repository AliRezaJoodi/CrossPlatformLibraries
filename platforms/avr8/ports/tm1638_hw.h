#ifndef TM1638_HW_INCLUDED
#define TM1638_HW_INCLUDED

#include "hardware.h"   /**< Project-level overrides */

#ifndef TM1638_HARDWARE
#define TM1638_HARDWARE
    #define TM1638_CLK_DDR          DDRC
    #define TM1638_CLK_PIN          PINC
    #define TM1638_CLK_PORT         PORTC
    #define TM1638_CLK_BIT          7U
    #define TM1638_CLK_MASK         (1U << TM1638_CLK_BIT)

    #define TM1638_DIO_DDR          DDRC
    #define TM1638_DIO_PIN          PINC
    #define TM1638_DIO_PORT         PORTC
    #define TM1638_DIO_BIT          6U
    #define TM1638_DIO_MASK         (1U << TM1638_DIO_BIT)

    #warning "TM1638_HARDWARE is not defined; default configuration will be used."
#endif

#ifndef TM1638_HARDWARE_EXTRA
#define TM1638_HARDWARE_EXTRA
    #define TM1638_STB_DDR          DDRA
    #define TM1638_STB_PORT         PORTA
    #define TM1638_STB_BIT          7U
    #define TM1638_STB_MASK         (1U << TM1638_STB_BIT)
#endif

#endif
