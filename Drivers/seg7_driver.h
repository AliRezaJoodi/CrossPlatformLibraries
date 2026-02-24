/**
 * @file    seg7_driver.h
 * @brief   Multiplexed 7-Segment Display Driver
 *
 * @details
 * This driver controls a multiplexed 7-segment display using
 * a time-division scanning technique.
 *
 * Operation principle:
 * - Only one digit is active at a time.
 * - The active digit is periodically switched to create
 *   the perception of a continuous display.
 *
 * Usage requirements:
 * - Seg7_Init() must be called before any other function.
 * - Seg7_SetBuffer() must be used to provide a valid
 *   segment pattern buffer.
 * - Seg7_Refresh() must be called periodically
 *   (e.g., from a timer interrupt or main loop)
 *   to maintain proper display output.
 *
 * Notes:
 * - The buffer must contain pre-encoded segment patterns.
 * - The buffer memory must remain valid during operation.
 * - Refresh rate directly affects brightness and flicker.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef SEG7_DRIVER_INCLUDED
#define SEG7_DRIVER_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "seg7_driver_config.h"
#include "seg7_driver_port.h"

/**
 * @brief Initialize the 7-segment driver.
 *
 * Configures digit and segment pins as output
 * and sets the display to an idle state.
 */
void Seg7_Init(void);

/**
 * @brief Set display buffer pointer.
 *
 * The buffer must contain pre-encoded segment patterns.
 * The buffer memory must remain valid during driver operation.
 *
 * @param buffer Pointer to segment data array.
 */
void Seg7_SetBuffer(uint8_t *buffer);

/**
 * @brief Refresh one multiplex step.
 *
 * This function must be called periodically
 * (e.g., inside a timer interrupt or main loop)
 * to maintain proper multiplexing.
 */
void Seg7_Refresh(void);

#ifdef __cplusplus
}
#endif

#endif
