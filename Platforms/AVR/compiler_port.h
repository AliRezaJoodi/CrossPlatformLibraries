
#ifndef COMPILER_PORT_INCLUDED
#define COMPILER_PORT_INCLUDED

#if defined(__GNUC__)
    #define COMPILER_GCC 1

    #ifndef F_CPU
        #error "F_CPU must be defined before including this library"
    #endif

    #include <avr/io.h>
    #include <util/delay.h> // F_CPU must be defined before including this header for accurate delay calculations

    #define DELAY_MS(ms) _delay_ms(ms)  /* Macro for delay in milliseconds */
    #define DELAY_US(us) _delay_us(us)  /* Macro for delay in microseconds */

#elif defined(__CODEVISIONAVR__)
    #define COMPILER_CODEVISIONAVR 1

    #include <io.h>
    #include <delay.h>

    #define DELAY_MS(ms) delay_ms(ms)   /* Macro for delay in milliseconds */
    #define DELAY_US(us) delay_us(us)   /* Macro for delay in microseconds */

#elif defined(__ICCAVR__)
    #define COMPILER_IAR 1

    #ifndef F_CPU
    #error "F_CPU must be defined before including this library"
    #endif

    #include <ioavr.h>

    #define DELAY_MS(ms) __delay_cycles((F_CPU/1000UL)*(ms))
    #define DELAY_US(us) __delay_cycles((F_CPU/1000000UL)*(us))

#else
    #error "Unsupported Compiler"
#endif

#endif
