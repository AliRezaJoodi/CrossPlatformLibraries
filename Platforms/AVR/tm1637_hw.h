#ifndef TM1637_HW_INCLUDED
#define TM1637_HW_INCLUDED

#include "compiler_port.h"

#ifndef TM1637_HARDWARE_EXTRA
#define TM1637_HARDWARE_EXTRA
    #define TM1637_CLK_DDR         DDRC
    #define TM1637_CLK_PORT        PORTC
    #define TM1637_CLK_PIN         PINC
    #define TM1637_CLK_BIT         0

    #define TM1637_DIO_DDR         DDRC
    #define TM1637_DIO_PORT        PORTC
    #define TM1637_DIO_PIN         PINC
    #define TM1637_DIO_BIT         1

    //#warning "TM1637_HARDWARE_EXTRA is not defined; default configuration will be used."
#endif

#endif
