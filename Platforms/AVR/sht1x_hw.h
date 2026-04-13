#ifndef SHT1X_HW_INCLUDED
#define SHT1X_HW_INCLUDED

#ifndef SHT1X_HARDWARE_EXTRA
#define SHT1X_HARDWARE_EXTRA
    #define SHT1X_SCK_DDR           DDRC
    #define SHT1X_SCK_PORT          PORTC
    #define SHT1X_SCK_PIN           PINC
    #define SHT1X_SCK_BIT           0

    #define SHT1X_DATA_DDR          DDRC
    #define SHT1X_DATA_PORT         PORTC
    #define SHT1X_DATA_PIN          PINC
    #define SHT1X_DATA_BIT          1

    //#warning "SHT1X_HARDWARE_EXTRA is not defined; default configuration will be used."
#endif

#endif
