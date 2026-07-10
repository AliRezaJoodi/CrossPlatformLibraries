/**
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: Compilation & Linkage
 * -----------------------------------------------------------------------------
 * The following source files must be compiled and linked in the project:
 * - `aj_spi.c`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 2: Configuration Override
 * -----------------------------------------------------------------------------
 * The default driver macros are declared in the following headers:
 * - `aj_spi_config.h`
 *
 * To customize these configurations, override them inside the central project
 * hardware configuration file:
 * - `hardware.h`
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_SPI_INCLUDED
#define AJ_SPI_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_compiler.h"
#include "aj_spi_config.h"

typedef enum {
    AJ_SPI_OK = 0U,
    AJ_SPI_ERROR = 1U
} aj_spi_state_t;

extern volatile aj_spi_state_t aj_spi_state;


/**
 * @brief   Send and receive a byte via SPI
 *
 * @param   data    Byte to transmit
 * @return  Received byte from SPI
 *
 * @note    The SPI peripheral must be configured and enabled
 *          before calling this function.
 */
static inline uint8_t AJ_SPI_TxRx(const uint8_t data){
    uint16_t timeout = AJ_SPI_TIMEOUT;  /* Software timeout counter */
    aj_spi_state = AJ_SPI_OK;

    SPDR = data;                        /* Start SPI transfer */

    while (!(SPSR & (1U << SPIF))) {    /* Wait for transfer complete */
        if (--timeout == 0U){           /* Check timeout expiration */
            aj_spi_state = AJ_SPI_ERROR;
            return 0U;        /* Return error value */
        }
    }

    return SPDR;                        /* Return received data */
}

/**
 * @brief Transmit one byte over SPI.
 *
 * @param data Byte to transmit.
 */
//static inline void AJ_SPI_Tx(const uint8_t data){
//    uint16_t timeout = AJ_SPI_TIMEOUT;  /* Software timeout counter */
//    aj_spi_state = AJ_SPI_OK;
//
//    SPDR = data;                        /* Start SPI transfer */
//
//    while (!(SPSR & (1U << SPIF))) {    /* Wait for transfer complete */
//        if (--timeout == 0U){           /* Check timeout expiration */
//            aj_spi_state = AJ_SPI_ERROR;
//            return;
//        }
//    }
//}

/**
 * @brief Receive one byte over SPI.
 *
 * @return Received byte.
 * @note A dummy byte (0x00) is transmitted to generate the SPI clock.
 */
//static inline uint8_t AJ_SPI_Rx(void){
//    uint16_t timeout = AJ_SPI_TIMEOUT;  /* Software timeout counter */
//    aj_spi_state = AJ_SPI_OK;
//
//    SPDR = 0U;                          /* Send dummy byte */
//
//    while (!(SPSR & (1U << SPIF))) {    /* Wait for transfer complete */
//        if (--timeout == 0U){           /* Check timeout expiration */
//            aj_spi_state = AJ_SPI_ERROR;
//            return 0U;
//        }
//    }
//
//    return SPDR;                        /* Return received data */
//}


#ifdef __cplusplus
}
#endif

#endif  /* AJ_SPI_INCLUDED */