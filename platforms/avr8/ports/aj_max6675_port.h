#ifndef AJ_MAX6675_PORT_INCLUDED
#define AJ_MAX6675_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_compiler.h"
#include "aj_bit_reg.h"
#include "aj_spi.h"
#include "aj_max6675_type.h"

#define AJ_MAX6675_DELAY_US(us)    AJ_DELAY_US(us)

/**
 * @brief Initialize CS pin (output)
 * @param mcp Pointer to the MAX6675 instance.
 */
static inline void AJ_MAX6675_CS_ConfigAsOutput(aj_max6675_t *max){
    AJ_BitReg_SetBit_Mask(max->cs.ddr, max->cs.mask);
}

/**
 * @brief Select the device by driving CS low.
 * @param mcp Pointer to the MAX6675 instance.
 */
static inline void AJ_MAX6675_CS_SetActive(aj_max6675_t *max){
    AJ_BitReg_ClearBit_Mask(max->cs.port, max->cs.mask);
}

/**
 * @brief Deselect the device by driving CS high.
 * @param mcp Pointer to the MAX6675 instance.
 */
static inline void AJ_MAX6675_CS_SetIdle(aj_max6675_t *max){
    AJ_BitReg_SetBit_Mask(max->cs.port, max->cs.mask);
}

/**
 * @brief   Send and receive a byte via SPI
 *
 * @param   data    Byte to transmit
 * @return  Received byte from SPI
 *
 * @note    The SPI peripheral must be configured and enabled
 *          before calling this function.
 */
static inline uint8_t AJ_MAX6675_SPI_Rx(void){
    return AJ_SPI_TxRx(0x00U);
}


#ifdef __cplusplus
}
#endif

#endif
