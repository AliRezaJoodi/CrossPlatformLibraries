#ifndef MCP4822_HW_INCLUDED
#define MCP4822_HW_INCLUDED

#ifndef MCP4822_HARDWARE
#define MCP4822_HARDWARE
    #define MCP4822_CS_DDR      DDRB.3
    #define MCP4822_CS_PORT     PORTB.3
    #define MCP4822_CS_PIN      PINB.3

    #define MCP4822_LDAC_DDR    DDRB.2
    #define MCP4822_LDAC_PORT   PORTB.2
    #define MCP4822_LDAC_PIN    PINB.2

    #warning "MCP4822_HARDWARE is not defined; default configuration will be used."
#endif

#endif
