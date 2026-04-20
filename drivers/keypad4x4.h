/**
 * @file    keypad4x4.h
 * @brief   4x4 matrix keypad driver.
 *
 * This module provides a simple interface to read keys from a 4x4 matrix keypad.
 *
 * The returned value represents the key index (0–15). If no key is pressed,
 * a default value (16) is returned.
 *
 * @note
 * The hardware configuration (pin mapping and modes) must be defined in
 * "keypad4x4_hw.h".
 *
 * @warning
 * This function does not include debounce handling. External debounce
 * (software or hardware) is recommended for stable operation.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef KEYPAD4X4_INCLUDED
#define KEYPAD4X4_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "utility_bit.h"
#include "keypad4x4_port.h"

/**
 * @brief Reads the pressed key from the 4x4 keypad.
 *
 * @return uint8_t
 *         - 0 to 15 : Key index corresponding to the pressed key
 *         - 16      : No key pressed or invalid state
 */
uint8_t Keypad4x4_GetNumber(void);

#ifdef __cplusplus
}
#endif

#endif
