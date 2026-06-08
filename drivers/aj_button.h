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
 * layers defined in AJ_Button_Init.h and button_port.h.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_BUTTON_INCLUDED
#define AJ_BUTTON_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_button_type.h"

/**
 * @brief Initialize a button object.
 *
 * Configures the hardware pin for input and pull mode,
 * and resets the button state and internal counter.
 *
 * @param btn Pointer to the Button_t object to initialize.
 */
void AJ_Button_Init(aj_button_t *btn);

/**
 * @brief Detect a single button trigger event (non-blocking).
 *
 * Uses a state-machine based debounce mechanism to filter noise
 * and confirm a valid button press after the aj_button_tIME_TRIGGER
 * interval has elapsed.
 *
 * The current system tick must be provided by the caller, allowing
 * the button module to remain independent of any specific timebase
 * implementation.
 *
 * @param btn Pointer to the Button_t instance.
 * @param now Current system tick used for timing comparison.
 * @return 1 if a valid trigger event is detected, 0 otherwise.
 */
uint8_t AJ_Button_GetTrigger(aj_button_t *btn, aj_timebase_t now);

/**
 * @brief Check for auto-repeat events on a button (non-blocking).
 *
 * Detects whether the button is held and generates an auto-repeat
 * event whenever the configured repeat interval has elapsed.
 * The function is non-blocking and returns 1 once per repeat period
 * while the button remains pressed.
 *
 * The current system tick must be provided by the caller. This keeps
 * the button module independent from any specific timebase implementation.
 *
 * @param btn Pointer to the Button_t instance.
 * @param now Current system tick used for timing comparison.
 * @return 1 if an auto-repeat event is generated, 0 otherwise.
 */
uint8_t AJ_Button_GetAutoRepeat(aj_button_t *btn, aj_timebase_t now);

#ifdef __cplusplus
}
#endif

#endif  /* AJ_BUTTON_INCLUDED */
