#ifndef _MCP3201_PORT_INCLUDED
#define _MCP3201_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <io.h>
#include <spi.h>

#include <utility_bit.h>

#define MCP3201_PIN_INPUT       0U
#define MCP3201_PIN_OUTPUT      1U

typedef struct {
    volatile uint8_t *ddr;
    volatile uint8_t *port;
    uint8_t           index;
} MCP3201_Pin_t;

typedef struct {
    MCP3201_Pin_t cs;
} MCP3201_t;

//********************************************************
static inline void MCP3201_CS_ConfigPin(MCP3201_t *mcp, uint8_t mode){    
    WRITE_BIT( *(mcp->cs.ddr), mcp->cs.index, mode );
    
    if(mode == MCP3201_PIN_INPUT){ 
        CLEAR_BIT( *(mcp->cs.port), mcp->cs.index ); // Disable pull-up
    }
    else{
        SET_BIT( *(mcp->cs.port), mcp->cs.index ); // Idle bus
    }
}

//********************************************************
static inline void MCP3201_CS_WritePin(MCP3201_t *mcp, uint8_t status){
    WRITE_BIT( *(mcp->cs.port), mcp->cs.index, status );
}

//********************************************************
static inline uint8_t MCP3201_SPI_Transfer(uint8_t data){
    return spi(data);
}

#ifdef __cplusplus
}
#endif

#endif
