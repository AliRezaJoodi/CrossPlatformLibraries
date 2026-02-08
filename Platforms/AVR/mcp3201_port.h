/*
 * CS pin macros example:
 *     #define MCP3201_CS1_DDR      DDRB
 *     #define MCP3201_CS1_PORT     PORTB
 *     #define MCP3201_CS1_BIT      4U
 *
 */
 
#ifndef MCP3201_PORT_INCLUDED
#define MCP3201_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef struct {
    volatile uint8_t *ddr;
    volatile uint8_t *port;
    uint8_t           index;
} MCP3201_Pin_t;

typedef struct {
    MCP3201_Pin_t cs;
} MCP3201_t;

/**
 * @brief   Configure the CS pin of MCP3201 as input or output
 *
 * @param   mcp     Pointer to the MCP3201 instance
 * @param   mode    set pin mode
 *                  - 0: configure as input and disable pull-up
 *                  - 1: configure as output and sets the pin high (idle state)
 */
void MCP3201_CS_ConfigPin(MCP3201_t *mcp, uint8_t mode);
void MCP3201_CS_WritePin(MCP3201_t *mcp, uint8_t status);
uint8_t MCP3201_SPI_Transfer(uint8_t data);

#ifdef __cplusplus
}
#endif

#endif
