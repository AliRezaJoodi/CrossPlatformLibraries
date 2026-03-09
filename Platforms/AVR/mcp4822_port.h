/**
 * @brief   SPI usage and recommended configuration for MCP4822
 *
 * @note
 * This library does NOT configure the SPI peripheral automatically.
 * The user must initialize the SPI interface according to the requirements
 * of the MCP4822 device.
 *
 * Recommended SPI settings for MCP4822:
 *   - SPI Mode: Master
 *   - Clock Phase (CPHA): 0 (Cycle Start)
 *   - Clock Polarity (CPOL): 0 (Low)
 *   - Data Order: MSB First
 *   - SPI Clock: <= 2 MHz (example value)
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
