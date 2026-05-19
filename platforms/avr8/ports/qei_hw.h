#ifndef QEI_HW_INCLUDED
#define QEI_HW_INCLUDED

#ifndef QEI_HARDWARE
#define QEI_HARDWARE
    #define QEI_A_DDR               DDRD
    #define QEI_A_PIN               PIND
    #define QEI_A_PORT              PORTD
    #define QEI_A_BIT               2U
    #define QEI_A_MASK              (1U << QEI_A_BIT)

    #define QEI_B_DDR               DDRD
    #define QEI_B_PIN               PIND
    #define QEI_B_PORT              PORTD
    #define QEI_B_BIT               3U
    #define QEI_B_MASK              (1U << QEI_B_BIT)
#endif

#endif
