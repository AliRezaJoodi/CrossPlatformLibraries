#ifndef TM1637_PORT_INCLUDED
#define TM1637_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "compiler_port.h"
#include "utility_bit.h"

#define TM1637_DELAY_US(VALUE)          DELAY_US(VALUE)

/**
 * @brief TM1637 GPIO pin descriptor.
 *
 * This structure describes a GPIO pin used by the TM1637 driver.
 */
typedef struct {
    volatile uint8_t *ddr;
    volatile uint8_t *port;
    volatile uint8_t *pin;
    uint8_t           index;
} TM1637_Pin_t;

/**
 * @brief TM1637 device handle.
 *
 * This structure holds all configuration data required
 * to control one TM1637 device instance.
 *
 * Example usage:
 * @code
 * TM1637_t tm1;
 *
 * tm1.clk.ddr  = &DDRC;
 * tm1.clk.port = &PORTC;
 * tm1.clk.pin  = &PINC;
 * tm1.clk.index = 0;
 *
 * tm1.dio.ddr  = &DDRC;
 * tm1.dio.port = &PORTC;
 * tm1.dio.pin  = &PINC;
 * tm1.dio.index = 1;
 * @endcode
 */
typedef struct {
    TM1637_Pin_t clk;
    TM1637_Pin_t dio;
} TM1637_t;

/***************************************/
static inline void TM1637_CLK_WritePin(TM1637_t *tm, uint8_t status){
    if(status){
        CLEAR_BIT(*(tm->clk.ddr), tm->clk.index);
        CLEAR_BIT(*(tm->clk.port), tm->clk.index);
    }
    else{
        SET_BIT(*(tm->clk.ddr), tm->clk.index);
        CLEAR_BIT(*(tm->clk.port), tm->clk.index);
    }
}

/***************************************/
static inline void TM1637_DIO_SetInput(TM1637_t *tm){
    CLEAR_BIT(*(tm->dio.ddr), tm->dio.index);
    CLEAR_BIT(*(tm->dio.port), tm->dio.index);
}

/***************************************/
static inline void TM1637_DIO_WritePin(TM1637_t *tm, uint8_t status){
    if(status){
        TM1637_DIO_SetInput(tm);
    }
    else{
        SET_BIT(*(tm->dio.ddr), tm->dio.index);
        CLEAR_BIT(*(tm->dio.port), tm->dio.index);
    }
}

/***************************************/
static inline uint8_t TM1637_DIO_GetPin(TM1637_t *tm){
    return GET_BIT(*(tm->dio.pin), tm->dio.index);
}

#ifdef __cplusplus
}
#endif

#endif
