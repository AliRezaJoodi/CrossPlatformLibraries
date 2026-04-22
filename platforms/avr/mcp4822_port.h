/**
 * @brief   SPI usage and recommended configuration for MCP4822
 *
 * @warning
 * Ensure the SPI peripheral is configured before calling any MCP4822 functions.
 * Using incorrect SPI settings may result in incorrect DAC.
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

#ifndef MCP4822_PORT_INCLUDED
#define MCP4822_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "compiler_port.h"
#include "utils/bit_register.h"
#include "mcp4822_hw.h"
#include "mcp4822_types.h"

#define MCP4822_DELAY_US(us) DELAY_US(us)

/**
 * @brief   Initialize MCP4822 CS pin
 * Sets the CS pin as output state.
 *
 * @param[in] mcp   Pointer to MCP4822 device handle
 */
static inline void MCP4822_CS_Init(MCP4822_t *mcp){
    SetBit_Reg8(mcp->cs.ddr, mcp->cs.index);
}

/**
 * @brief   Write value to MCP4822 CS pin
 * Sets the CS pin high or low.
 *
 * @param[in] mcp     Pointer to MCP4822 device handle
 * @param[in] status  Pin state (0 = low, 1 = high)
 */
static inline void MCP4822_CS_Write(MCP4822_t *mcp, uint8_t status){
    WriteBit_Reg8(mcp->cs.port, mcp->cs.index, status);
}

/**
 * @brief   Initialize MCP4822 LDAC pin
 * Sets the LDAC pin as output state.
 *
 * @param[in] mcp   Pointer to MCP4822 device handle
 */
static inline void MCP4822_LDAC_InitPin(MCP4822_t *mcp){
    SetBit_Reg8(mcp->ldac.ddr, mcp->ldac.index);
}

/**
 * @brief   Write value to MCP4822 LDAC pin
 * Sets the LDAC pin high or low.
 *
 * @param[in] mcp     Pointer to MCP4822 device handle
 * @param[in] status  Pin state (0 = low, 1 = high)
 */
static inline void MCP4822_LDAC_WritePin(MCP4822_t *mcp, uint8_t status){
    WriteBit_Reg8(mcp->ldac.port, mcp->ldac.index, status);
}

/**
 * @brief   Send a single byte via SPI
 *
 * Transmits a byte to the MCP4822 over SPI and waits for completion.
 * Returns 0 on success or 1 if timeout occurs.
 *
 * @param[in] data   Byte to transmit
 * @return          0 on success, 1 on timeout/error
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
