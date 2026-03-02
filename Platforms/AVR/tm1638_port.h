#ifndef TM1638_PORT_INCLUDED
#define TM1638_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "utility_bit.h"
#include "tm1638_hw.h"

#define TM1638_DELAY_US(VALUE)          DELAY_US(VALUE)

/**
 * @brief TM1638 GPIO pin descriptor.
 *
 * This structure describes a GPIO pin used by the TM1638 driver.
 */
typedef struct {
    volatile uint8_t *ddr;
    volatile uint8_t *port;
    uint8_t           index;
} TM1638_Pin_t;

/**
 * @brief TM1638 device handle.
 *
 * This structure holds STB pin that required
 * to control one TM1638 device instance.
 *
 * @see Example section below.
 */
typedef struct {
    TM1638_Pin_t stb;
} TM1638_t;

/**
 * @example
 * Example: initializing a structure
 *
 * @code
 * TM1638_t tm1;
 * tm1.stb.ddr     = &TM1638_STB1_DDR;
 * tm1.stb.port    = &TM1638_STB1_PORT;
 * tm1.stb.index   =  TM1638_STB1_BIT;
 * @endcode
 */

//***************************************
static inline void TM1638_STB_InitPin(TM1638_t *tm){
    SET_BIT(*(tm->stb.ddr), tm->stb.index);
    SET_BIT(*(tm->stb.port), tm->stb.index);  // Idle bus
}

//***************************************
static inline void TM1638_STB_WritePin(TM1638_t *tm, uint8_t status){
    WRITE_BIT( *(tm->stb.port), tm->stb.index, status );
}

//***************************************
static inline void TM1638_CLK_InitPin(void){
    SET_BIT(TM1638_CLK_DDR, TM1638_CLK_BIT);
    SET_BIT(TM1638_CLK_PORT, TM1638_CLK_BIT); // Idle bus
}

//***************************************
static inline void TM1638_CLK_WritePin(uint8_t status){
    WRITE_BIT(TM1638_CLK_PORT, TM1638_CLK_BIT, status);
}

//***************************************
static inline void TM1638_DIO_ConfigPin(uint8_t mode){
    if(mode == TM1638_PIN_INPUT){
        CLEAR_BIT(TM1638_DIO_DDR, TM1638_DIO_BIT);
        CLEAR_BIT(TM1638_DIO_PORT, TM1638_DIO_BIT); // Disable pull-up
    }
    else{
        SET_BIT(TM1638_DIO_DDR, TM1638_DIO_BIT);
        SET_BIT(TM1638_DIO_PORT, TM1638_DIO_BIT); // Idle bus
    }
}

//***************************************
static inline void TM1638_DIO_WritePin(uint8_t status){
    WRITE_BIT(TM1638_DIO_PORT, TM1638_DIO_BIT, status);
}

//***************************************
static inline uint8_t TM1638_DIO_GetPin(void){
    return GET_BIT(TM1638_DIO_PIN, TM1638_DIO_BIT);
}

#ifdef __cplusplus
}
#endif

#endif
