
#ifndef COMPILER_DETECTOR_INCLUDED
#define COMPILER_DETECTOR_INCLUDED

#if defined(__GNUC__)
    #define COMPILER_GCC 1

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

    #include <ioavr.h>

#else
    #error "Unsupported Compiler"
#endif

#endif
