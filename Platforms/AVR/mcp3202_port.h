#ifndef MCP3202_PORT_INCLUDED
#define MCP3202_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "compiler_port.h"
#include "utility_bit.h"
#include "mcp3202_hw.h"

typedef struct {
    volatile uint8_t *ddr;      /**< Data Direction Register for this pin */
    volatile uint8_t *port;     /**< PORT register for this pin */
    uint8_t           index;    /**< Bit position within DDR/PORT (0..7) */
} MCP3202_Pin_t;

typedef struct {
    MCP3202_Pin_t cs;       /**< Chip Select pin */
} MCP3202_t;

static inline void MCP3202_CS_InitPin(MCP3202_t *mcp){
    SET_BIT( *(mcp->cs.ddr), mcp->cs.index );
    SET_BIT( *(mcp->cs.port), mcp->cs.index );
}

static inline void MCP3202_CS_WritePin(MCP3202_t *mcp, uint8_t status){
    WRITE_BIT( *(mcp->cs.port), mcp->cs.index, status );
}

static inline uint8_t MCP3202_SPI_Transfer(uint8_t data){
    uint16_t timeout = 1000U;           /* Software timeout counter */

    SPDR = data;                        /* Start SPI transfer */

    while (!(SPSR & (1U << SPIF))) {    /* Wait for transfer complete */
        if (--timeout == 0U){           /* Check timeout expiration */
            return 0xFF;                /* Return error value */
        }
    }

    return SPDR;                        /* Return received data */
}

#ifdef __cplusplus
}
#endif

#endif

