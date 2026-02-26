#ifndef TM1637_PORT_INCLUDED
#define TM1637_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "compiler_port.h"

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

#ifdef __cplusplus
}
#endif

#endif
