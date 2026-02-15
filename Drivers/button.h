/**
 * @file    button.h
 * @brief   Public API for button handling.
 *
 * This API relies on the underlying configuration and hardware
 * layers defined in button_config.h and button_port.h.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */
 
#ifndef BUTTON_INCLUDED
#define BUTTON_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "utility_bit.h"

#include "button_config.h"
#include "button_port.h"

/**
 * @brief Initialize a button object.
 *
 * Configures the hardware pin for input and pull mode,
 * and resets the button state and internal counter.
 *
 * @param btn Pointer to the Button_t object to initialize.
 */
void Button_Config(Button_t *btn);

/**
 * @brief Check for a single click event on a button.
 *
 * Detects a single click by comparing the button pin state
 * with its active level, using a debounce delay. Returns 1
 * only once per click.
 *
 * @param btn Pointer to the Button_t object to read.
 * @return 1 if a single click is detected, 0 otherwise.
 */
uint8_t Button_GetSingleClick(Button_t *btn);

/**
 * @brief Check for auto-repeat events on a button (non-blocking).
 *
 * Detects if a button is being held and triggers an auto-repeat
 * event when the configured auto-repeat lag has elapsed.
 * The function is non-blocking and returns 1 once per repeat interval.
 *
 * @param btn Pointer to the Button_t object to read.
 * @return 1 if an auto-repeat event is detected, 0 otherwise.
 */
uint8_t Button_GetAutoRepeat_NonBlocking(Button_t *btn);

/**
 * @brief Check for a long press event on a button (non-blocking).
 *
 * Detects if a button is held longer than the configured
 * long press lag. Returns 1 once when the long press is detected.
 * The function does not block program execution.
 *
 * @param btn Pointer to the Button_t object to read.
 * @return 1 if a long press is detected, 0 otherwise.
 */
uint8_t Button_GetLongPress_NonBlocking(Button_t *btn);

#ifdef __cplusplus
}
#endif

#endif
