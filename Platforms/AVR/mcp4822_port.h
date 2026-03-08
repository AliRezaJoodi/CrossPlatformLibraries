
#ifndef MCP4822_PORT_INCLUDED
#define MCP4822_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "utility_bit.h"
#include "compiler_port.h"
#include "mcp4822_hw.h"

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
