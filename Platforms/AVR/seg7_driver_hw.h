#ifndef SEG7_DRIVER_HW_INCLUDED
#define SEG7_DRIVER_HW_INCLUDED

#include "compiler_port.h"

/** @brief Include user-overridable hardware macros. */
//#include "hardware.h"
#include "seg7_driver_config.h"

#ifndef SEG7_DRIVER_HARDWARE
#define SEG7_DRIVER_HARDWARE

#if SEG7_DIGITS_COUNT > 0
    #define SEG7_DIGIT0_DDR          DDRB
    #define SEG7_DIGIT0_PORT         PORTB
    #define SEG7_DIGIT0_BIT          0
#endif

#if SEG7_DIGITS_COUNT > 1
    #define SEG7_DIGIT1_DDR          DDRB
    #define SEG7_DIGIT1_PORT         PORTB
    #define SEG7_DIGIT1_BIT          1
#endif

#if SEG7_DIGITS_COUNT > 2
    #define SEG7_DIGIT2_DDR          DDRB
    #define SEG7_DIGIT2_PORT         PORTB
    #define SEG7_DIGIT2_BIT          2
#endif

#if SEG7_DIGITS_COUNT > 3
    #define SEG7_DIGIT3_DDR          DDRB
    #define SEG7_DIGIT3_PORT         PORTB
    #define SEG7_DIGIT3_BIT          3
#endif

#if SEG7_DIGITS_COUNT > 4
    #define SEG7_DIGIT4_DDR          DDRB
    #define SEG7_DIGIT4_PORT         PORTB
    #define SEG7_DIGIT4_BIT          4
#endif

#if SEG7_DIGITS_COUNT > 5
    #define SEG7_DIGIT5_DDR          DDRB
    #define SEG7_DIGIT5_PORT         PORTB
    #define SEG7_DIGIT5_BIT          5
#endif

#if SEG7_DIGITS_COUNT > 6
    #define SEG7_DIGIT6_DDR          DDRB
    #define SEG7_DIGIT6_PORT         PORTB
    #define SEG7_DIGIT6_BIT          6
#endif

#if SEG7_DIGITS_COUNT > 7
    #define SEG7_DIGIT7_DDR          DDRB
    #define SEG7_DIGIT7_PORT         PORTB
    #define SEG7_DIGIT7_BIT          7
#endif

    #define SEG7_A_DDR               DDRD
    #define SEG7_A_PORT              PORTD
    #define SEG7_A_BIT               0

    #define SEG7_B_DDR               DDRD
    #define SEG7_B_PORT              PORTD
    #define SEG7_B_BIT               1

    #define SEG7_C_DDR               DDRD
    #define SEG7_C_PORT              PORTD
    #define SEG7_C_BIT               2

    #define SEG7_D_DDR               DDRD
    #define SEG7_D_PORT              PORTD
    #define SEG7_D_BIT               3

    #define SEG7_E_DDR               DDRD
    #define SEG7_E_PORT              PORTD
    #define SEG7_E_BIT               4

    #define SEG7_F_DDR               DDRD
    #define SEG7_F_PORT              PORTD
    #define SEG7_F_BIT               5

    #define SEG7_G_DDR               DDRD
    #define SEG7_G_PORT              PORTD
    #define SEG7_G_BIT               6

    #define SEG7_DP_DDR              DDRD
    #define SEG7_DP_PORT             PORTD
    #define SEG7_DP_BIT              7

    #warning "SEG7_DRIVER_HARDWARE is not defined; default hardware will be used."
#endif

#endif
