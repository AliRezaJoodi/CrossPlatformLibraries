// Platform-specific implementation for CodeVisionAVR

#include <io.h>
#include <spi.h>

#include <mcp3201_port.h>

//********************************************************
void MCP3201_CS_ConfigPin(MCP3201_t *mcp, uint8_t mode){    
    WRITE_BIT( *(mcp->cs.ddr), mcp->cs.index, mode );
    
    if(mode == 0){ 
        CLEAR_BIT( *(mcp->cs.port), mcp->cs.index ); // Disable pull-up
    }
    else{
        SET_BIT( *(mcp->cs.port), mcp->cs.index ); // Idle bus
    }
}

//********************************************************
void MCP3201_CS_WritePin(MCP3201_t *mcp, uint8_t status){
    WRITE_BIT( *(mcp->cs.port), mcp->cs.index, status );
}

//********************************************************
uint8_t MCP3201_SPI_Transfer(uint8_t data){
    return spi(data);
}
