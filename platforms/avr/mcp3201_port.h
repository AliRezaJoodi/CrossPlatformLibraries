/**
 * @brief   SPI usage and recommended configuration for MCP3201
 *
 * @note
 * This library does NOT configure the SPI peripheral automatically.
 * The user must initialize the SPI interface according to the requirements
 * of the MCP3201 device.
 *
 * @warning
 * Ensure the SPI peripheral is configured before calling any MCP3201 functions.
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

#ifndef MCP3201_PORT_INCLUDED
#define MCP3201_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "compiler_port.h"
#include "utils/bit_register.h"
#include "mcp3201_hw.h"
#include "mcp3201_types.h"

/**
 * @brief Initialize MCP3201 CS pin (output)
 *
 * @param   mcp     Pointer to the MCP3201 instance
 */
static inline void MCP3201_CS_SetOutput(MCP3201_t *mcp){
    SetBitMask_Reg8(mcp->cs.ddr, mcp->cs.mask);
}

/**
 * @brief   Set the CS pin level for MCP3201
 *
 * @param   mcp     Pointer to the MCP3201 instance
 * @param   status  Logic level to set
 *                  - 0: Pull CS low (select chip)
 *                  - 1: Pull CS high (deselect / idle)
 *
 * @note    The CS pin must be initialized with MCP3201_CS_SetOutput() before use.
 */
//static inline void MCP3201_CS_Write(MCP3201_t *mcp, uint8_t status){
//    WriteBit_Reg8(mcp->cs.port, mcp->cs.index, status);
//}

static inline void MCP3201_CS_WriteLow(MCP3201_t *mcp){
    ClearBitMask_Reg8(mcp->cs.port, mcp->cs.mask);
}

static inline void MCP3201_CS_WriteHigh(MCP3201_t *mcp){
    SetBitMask_Reg8(mcp->cs.port, mcp->cs.mask);
}

/**
 * @brief   Send and receive a byte via SPI for MCP3201
 *
 * @param   data    Byte to transmit
 * @return  Received byte from SPI
 *
 * @note    The SPI peripheral must be configured and enabled
 *          before calling this function.
 */
static inline uint8_t MCP3201_SPI_Transfer(uint8_t data){
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
