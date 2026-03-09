
#ifndef MCP4822_PORT_INCLUDED
#define MCP4822_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "utility_bit.h"
#include "compiler_port.h"
#include "mcp4822_hw.h"

#define MCP4822_DELAY_US(us) DELAY_US(us)

/**
 * @brief MCP4822 GPIO pin descriptor.
 *
 * This structure describes a GPIO pin used by the MCP4822 driver.
 */
typedef struct {
    volatile uint8_t *ddr;
    volatile uint8_t *port;
    uint8_t           index;
} MCP4822_Pin_t;

/**
 * @brief MCP4822 device handle.
 *
 * @see Example section below.
 */
typedef struct {
    MCP4822_Pin_t cs;
    MCP4822_Pin_t ldac;
} MCP4822_t;

/**
 * @example
 * Example: initializing a structure
 *
 * @code
 * MCP4822_t dac1;
 *
 * dac1.cs.ddr     = &MCP4822_CS_DDR;
 * dac1.cs.port    = &MCP4822_CS_PORT;
 * dac1.cs.index   =  MCP4822_CS_BIT;
 * dac1.ldac.ddr   = &MCP4822_LDAC_DDR;
 * dac1.ldac.port  = &MCP4822_LDAC_PORT;
 * dac1.ldac.index =  MCP4822_LDAC_BIT;
 * @endcode
 */

/***************************************/
static inline void MCP4822_CS_InitPin(MCP4822_t *mcp){
    SET_BIT(*(mcp->cs.ddr), mcp->cs.index);
    SET_BIT(*(mcp->cs.port), mcp->cs.index);  // Idle bus
}

/***************************************/
static inline void MCP4822_CS_WritePin(MCP4822_t *mcp, uint8_t status){
    WRITE_BIT( *(mcp->cs.port), mcp->cs.index, status );
}

/***************************************/
static inline void MCP4822_LDAC_InitPin(MCP4822_t *mcp){
    SET_BIT(*(mcp->ldac.ddr), mcp->ldac.index);
    SET_BIT(*(mcp->ldac.port), mcp->ldac.index);  // Idle bus
}

/***************************************/
static inline void MCP4822_LDAC_WritePin(MCP4822_t *mcp, uint8_t status){
    WRITE_BIT( *(mcp->ldac.port), mcp->ldac.index, status );
}

/**
 * @brief   Send a byte via SPI for MCP4822
 *
 * @param   data    Byte to transmit
 * @return  error
 *
 * @note    The SPI peripheral must be configured and enabled
 *          before calling this function.
 */
static inline uint8_t MCP3208_SPI_Transfer(uint8_t data){
    uint16_t timeout = 1000U;           /* Software timeout counter */

    SPDR = data;                        /* Start SPI transfer */

    while (!(SPSR & (1U << SPIF))) {    /* Wait for transfer complete */
        if (--timeout == 0U){           /* Check timeout expiration */
            return 0x01U;                /* Return error value */
        }
    }

    return 0x00U;
}

#ifdef __cplusplus
}
#endif

#endif
