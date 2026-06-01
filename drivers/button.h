/**
 * @file    button.h
 * @brief   Public API for button handling.
 *
 * This library depends on the TimeBase module.
 * The user must call TimeBase_CountTicks() from a hardware timer interrupt
 * in the main application, typically with a 1 ms period.
 *
 * @note Initialize and use the TimeBase module before calling button APIs.
 *
 * This API relies on the underlying configuration and hardware
 * layers defined in Button_Init.h and button_port.h.
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
#include "button_type.h"

/**
 * @brief Initialize a button object.
 *
 * Configures the hardware pin for input and pull mode,
 * and resets the button state and internal counter.
 *
 * @param btn Pointer to the Button_t object to initialize.
 */
void Button_Init(Button_t *btn);

/**
 * @brief Detects a single button trigger event.
 *
 * Implements a state-machine based debounce logic to filter noise
 * and return 1 only after BUTTON_TIME_TRIGGER duration.
 *
 * @param btn Pointer to the button object.
 * @return 1 on valid trigger, 0 otherwise.
 */
uint8_t Button_GetTrigger(Button_t *btn);

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
uint8_t Button_GetAutoRepeat(Button_t *btn);

#ifdef __cplusplus
}
#endif

#endif
