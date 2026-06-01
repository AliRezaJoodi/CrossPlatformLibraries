/**
 * @brief   SPI usage and recommended configuration for MCP3202
 *
 * @warning
 * Ensure the SPI peripheral is configured before calling any MCP3202 functions.
 * Using incorrect SPI settings may result in incorrect ADC readings.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

/**
 * @example
 * Example SPI configuration for CodeVision AVR (ATmega32A):
 *
 * @code
 * void SPI_Config(void) {
 *     // Pin directions
 *     DDRB.4 = 1; PORTB.4 = 0;    // CS (SS)
 *     DDRB.5 = 1; PORTB.5 = 0;    // MOSI
 *     DDRB.6 = 0; PORTB.6 = 0;    // MISO
 *     DDRB.7 = 1; PORTB.7 = 0;    // SCK
 *
 *     // SPI initialization
 *     // SPCR - SPI Control Register:
 *     //   SPIE  = 0 -> SPI interrupt disabled
 *     //   SPE   = 1 -> SPI enabled
 *     //   DORD  = 0 -> MSB first
 *     //   MSTR  = 1 -> Master mode
 *     //   CPOL  = 0 -> Clock idle low
 *     //   CPHA  = 0 -> Sample on leading edge (Cycle Start)
 *     //   SPR1, SPR0 = 0 -> Clock rate f_osc/4
 *     // SPSR - SPI Status Register:
 *     //   SPI2X = 0 -> No double speed
 *     SPCR = (0<<SPIE) | (1<<SPE) | (0<<DORD) | (1<<MSTR)
 *          | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);
 *     SPSR = (0<<SPI2X);
 * }
 * @endcode
 */

#ifndef MCP3202_PORT_INCLUDED
#define MCP3202_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "compiler_port.h"
#include "bit_register8.h"
#include "mcp3202_hw.h"
#include "mcp3202_type.h"

/**
 * @brief Initialize MCP3202 CS pin (output, idle high)
 *
 * @param   mcp     Pointer to the MCP3202 instance
 */
static inline void MCP3202_CS_ConfigAsOutput(const MCP3202_t *mcp){
    SetBitMask_Reg8(mcp->cs.ddr, mcp->cs.mask);
}

/**
 * @brief   Set the CS pin level for MCP3202
 *
 * @param   mcp     Pointer to the MCP3202 instance
 * @param   status  Logic level to set
 *                  - 0: Pull CS low (select chip)
 *                  - 1: Pull CS high (deselect / idle)
 *
 * @note    The CS pin must be initialized with MCP3202_CS_ConfigAsOutput() before use.
 */
//static inline void MCP3202_CS_Write(MCP3202_t *mcp, uint8_t status){
//    WriteBit_Reg8(mcp->cs.port, mcp->cs.index, status);
//}

static inline void MCP3202_CS_SetActive(const MCP3202_t *mcp){
    ClearBitMask_Reg8(mcp->cs.port, mcp->cs.mask);
}

static inline void MCP3202_CS_SetIdle(const MCP3202_t *mcp){
    SetBitMask_Reg8(mcp->cs.port, mcp->cs.mask);
}

/**
 * @brief   Send and receive a byte via SPI for MCP3202
 *
 * @param   data    Byte to transmit
 * @return  Received byte from SPI
 *
 * @note    The SPI peripheral must be configured and enabled
 *          before calling this function.
 */
static inline uint8_t MCP3202_SPI_Transfer(uint8_t data){
    uint16_t timeout = MCP3202_TIMEOUT;           /* Software timeout counter */

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

