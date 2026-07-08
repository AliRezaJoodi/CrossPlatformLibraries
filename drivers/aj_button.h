/**
 * @file    aj_button.h
 * @brief   Public API for non-blocking button handling.
 *
 * This library is independent of any specific timebase implementation.
 * The caller must provide the current system tick value to the button
 * processing functions.
 *
 * Requirement:
 * A periodic tick source must be available in the application and updated
 * continuously. For best results, generate this tick from a hardware timer
 * interrupt with a 1 ms period.
 *
 * The tick source and its generation method are fully user-defined. The
 * button module only uses the provided tick value for debounce and
 * auto-repeat timing.
 *
 * This API relies on the target and hardware abstraction layers defined in
 * `aj_target.h`, `aj_button_type.h`, and the related button port mappings.
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
 * @brief Detect a single valid button press event (non-blocking).
 *
 * Uses a state-machine based debounce mechanism to filter noise and
 * confirm a stable button press after the required number of tick
 * periods has elapsed.
 *
 * The current system tick value must be provided by the caller. This
 * keeps the button module independent of any specific timebase source
 * or implementation.
 *
 * @param btn Pointer to the button instance.
 * @param now Current system tick used for debounce timing.
 * @return 1 if a valid trigger event is detected, 0 otherwise.
 */
uint8_t AJ_Button_GetTrigger(aj_button_t *btn, aj_button_tick_t tick_now);

/**
 * @brief Detect auto-repeat events while a button is held (non-blocking).
 *
 * Checks the button state and generates an auto-repeat event each time
 * the repeat interval in ticks has elapsed while the button remains
 * pressed.
 *
 * The current system tick value is provided by the caller, allowing
 * the button module to remain independent of any specific tick source.
 *
 * @param btn Pointer to the button instance.
 * @param now Current system tick used for auto-repeat timing.
 * @return 1 if an auto-repeat event is generated, 0 otherwise.
 */
uint8_t AJ_Button_GetAutoRepeat(aj_button_t *btn, aj_button_tick_t tick_now);

#ifdef __cplusplus
}
#endif

#endif  /* AJ_BUTTON_INCLUDED */
