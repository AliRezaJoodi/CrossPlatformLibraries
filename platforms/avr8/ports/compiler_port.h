// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef COMPILER_PORT_INCLUDED
#define COMPILER_PORT_INCLUDED

#if defined(__GNUC__)
    #ifndef F_CPU
        #error "F_CPU must be defined."
    #endif

    #include <avr/io.h>
    #include <util/delay.h>

    #define DELAY_MS(ms)                    _delay_ms(ms)
    #define DELAY_US(us)                    _delay_us(us)
    #define NOP()                           __asm__ __volatile__("nop")
    #define INT_GLOBAL_SAVE(sreg_save)      sreg_save = SREG;
    #define INT_GLOBAL_DISABLE()            cli()
    #define INT_GLOBAL_ENABLE()             sei()
    #define INT_GLOBAL_RESTORE(sreg_save)   SREG = sreg_save

#elif defined(__CODEVISIONAVR__)
    #include <io.h>
    #include <delay.h>

    #define DELAY_MS(ms)                    delay_ms(ms)
    #define DELAY_US(us)                    delay_us(us)
    #define NOP()                           #asm("nop")
    #define INT_GLOBAL_SAVE(sreg_save)      sreg_save = SREG;
    #define INT_GLOBAL_DISABLE()            #asm("cli")
    #define INT_GLOBAL_ENABLE()             #asm("sei")
    #define INT_GLOBAL_RESTORE(sreg_save)   SREG = sreg_save

#elif defined(__ICCAVR__)
    #ifndef F_CPU
    #error "F_CPU must be defined."
    #endif

    #include <ioavr.h>

    #define DELAY_MS(ms)                    __delay_cycles((F_CPU/1000UL)*(ms))
    #define DELAY_US(us)                    __delay_cycles((F_CPU/1000000UL)*(us))
    #define NOP()                           __no_operation()  // or asm("nop")
    #define INT_GLOBAL_SAVE(sreg_save)      (sreg_save) = __get_interrupt_state()
    #define INT_GLOBAL_DISABLE()            __disable_interrupt()
    #define INT_GLOBAL_ENABLE()             __enable_interrupt()
    #define INT_GLOBAL_RESTORE(sreg_save)   __set_interrupt_state(sreg_save)

#else
    #error "Unsupported Compiler"

#endif

#endif  /* COMPILER_PORT_INCLUDED */
