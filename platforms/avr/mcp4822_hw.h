#ifndef MCP4822_HW_INCLUDED
#define MCP4822_HW_INCLUDED

#ifndef MCP4822_HARDWARE_EXTRA
#define MCP4822_HARDWARE_EXTRA
    #define MCP4822_CS_DDR      DDRB
    #define MCP4822_CS_PORT     PORTB
    #define MCP4822_CS_BIT      3

    #define MCP4822_LDAC_DDR    DDRB
    #define MCP4822_LDAC_PORT   PORTB
    #define MCP4822_LDAC_BIT    2

    //#warning "MCP4822_HARDWARE_EXTRA is not defined; default configuration will be used."
#endif

#endif
