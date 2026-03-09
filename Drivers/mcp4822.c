// GitHub Account: GitHub.com/AliRezaJoodi
// This library use of the SPI interfacing
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First

#include "hardware.h"       /**< Project-level overrides */
#include "mcp4822.h"

#define MCP4822_ENABLE      1U
#define MCP4822_DISABLE     0U

/* DACA or DACB Select bit
1 = Write to DACB
0 = Write to DACA */
#define     _MCP4822_REGISTER_AB      15

/* Output Gain Select bit
1 = 1x (VOUT = VREF * D/4096)
0 = 2x (VOUT = 2 * VREF * D/4096) */
#define     _MCP4822_REGISTER_GA      13

/* Output Power-down Control bit
1 = Output Power-down Control bit
0 = Output buffer disabled, Output is high-impedance */
#define     _MCP4822_REGISTER_SHDN      12

#define MCP4822_GAIN    2000    // Gain = Resolution/VREF = 4096/2.048

//********************************************************
void MCP4822_Init(void){
    MCP4822_CS_DDR=1;   MCP4822_CS_PORT=1;
    MCP4822_LDAC_DDR=1; MCP4822_LDAC_PORT=1;
}

//********************************************************
void _MCP4822_WriteCommand(unsigned int data){
    uint8_t msb = (uint8_t)(data >> 8);
    uint8_t lsb = (uint8_t)(data & 0x00FF);

    MCP4822_CS_PORT=0;
    MCP3208_SPI_Transfer(msb);      //Send MSB
    MCP3208_SPI_Transfer(lsb);      //Send LSB
    MCP4822_CS_PORT=1;
    #asm("nop");            // Minimum Setup Time = 40ns

    MCP4822_LDAC_PORT=0;
    #asm("nop");
    #asm("nop");           // Minimum Pulse Width = 100ns
    MCP4822_LDAC_PORT=1;
}

//********************************************************
void MCP4822_SetOutput(uint8_t ch, uint8_t gain, uint16_t data){
    uint8_t msb =   ((ch & 0x01U) << 7) |
                    ((gain & 0x01U) << 5) |
                    (MCP4822_ENABLE << 4) |
                    ((data >> 8) & 0x0F);

    uint8_t lsb =   (uint8_t)(data & 0x00FF);

    MCP4822_CS_PORT = 0;
    MCP3208_SPI_Transfer(msb);
    MCP3208_SPI_Transfer(lsb);
    MCP4822_CS_PORT = 1;
    #asm("nop");            // Minimum Setup Time = 40ns

    MCP4822_LDAC_PORT = 0;
    #asm("nop");
    #asm("nop");           // Minimum Pulse Width = 100ns
    MCP4822_LDAC_PORT = 1;
}

//********************************************************
void MCP4822_SetOutput_(char ch, float volt){
    unsigned int data = 0;

    if(volt<=2.048){
        data=volt*MCP4822_GAIN;
        SetBit(data, _MCP4822_REGISTER_GA); // Gain=1x
    }
    else if(volt<=4.096){
        data=(volt/2)*MCP4822_GAIN;
        ClearBit(data, _MCP4822_REGISTER_GA);   // Gain=2x
    }

    if(ch<=1){
        WriteBit(data, _MCP4822_REGISTER_AB, ch);
        SetBit(data, _MCP4822_REGISTER_SHDN)
        _MCP4822_WriteCommand(data);
    }
}

//********************************************************
void MCP4822_ShutDown(char ch){
    unsigned int data=0;

    if(ch<=1){
        WriteBit(data, _MCP4822_REGISTER_AB, ch);
        ClearBit(data,_MCP4822_REGISTER_SHDN)
        _MCP4822_WriteCommand(data);
    }
}

