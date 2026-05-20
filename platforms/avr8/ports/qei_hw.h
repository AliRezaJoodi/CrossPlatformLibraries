#ifndef QEI_HW_INCLUDED
#define QEI_HW_INCLUDED

#ifndef QEI_HARDWARE
#define QEI_HARDWARE
    #define QEI_PULL_UP             0U  /**< Internal pull-up resistor (0: disabled, 1: enabled) */
    #define QEI_AB_CLOSED           0U  /**< Channels A and B are on adjacent bits of the same port (0: disabled, 1: enabled) */
    #define QEI_Z                   0U

    #warning "QEI_HARDWARE is not defined; default configuration will be used."
#endif

#ifndef QEI_HARDWARE_EXTRA
#define QEI_HARDWARE_EXTRA
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

#ifndef QEI_HARDWARE_EXTRA2
#define QEI_HARDWARE_EXTRA2
    #define QEI_Z_DDR               DDRB
    #define QEI_Z_PIN               PINB
    #define QEI_Z_PORT              PORTB
    #define QEI_Z_BIT               2U
    #define QEI_Z_MASK              (1U << QEI_Z_BIT)
#endif

#endif
