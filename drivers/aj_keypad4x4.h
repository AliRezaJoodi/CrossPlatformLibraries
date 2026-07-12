/**
 * @brief   4x4 matrix keypad driver.
 *
 * Scanning Method: Full Pattern Scanning
 *
 * This module provides a simple interface to read keys from a 4x4 matrix keypad.
 *
 * The returned value represents the key index (0–15). If no key is pressed,
 * a default value (255) is returned.
 *
 * @warning
 * This function does not include debounce handling. External debounce
 * (software or hardware) is recommended for stable operation.
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: Compilation & Linkage
 * -----------------------------------------------------------------------------
 * The following source files must be compiled and linked in the project:
 * - `aj_keypad4x4.c`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 2: Configuration Override
 * -----------------------------------------------------------------------------
 * The default driver macros are declared in the following headers:
 * - `aj_target.h`
 * - `aj_keypad4x4_config_platform.h`
 *
 * To customize these configurations, override them inside the central project
 * hardware configuration file:
 * - `hardware.h`
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_KEYPAD4X4_INCLUDED
#define AJ_KEYPAD4X4_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @brief Reads the pressed key from the 4x4 keypad.
 *
 * @return uint8_t
 *         - 0 to 15 : Key index corresponding to the pressed key
 *         - 255     : No key pressed or invalid state
 */
uint8_t AJ_Keypad4x4_GetKey(void);

#ifdef __cplusplus
}
#endif

#endif
