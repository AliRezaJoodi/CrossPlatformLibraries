/**
 * @brief   Simple buzzer driver
 *
 * This library provides basic control of a digital buzzer using a GPIO pin.
 * It supports both blocking (delay-based) and non-blocking (counter-based)
 * beep generation.
 *
 * The non-blocking mode requires periodic calling of Buzzer_Refresh()
 * to handle timing and automatically turn off the buzzer.
 *
 * @note
 * The buzzer control is implemented using a single GPIO output pin.
 * Hardware configuration must be provided via buzzer_port.h.
 *
 * @warning
 * Buzzer_Refresh() must be called periodically (e.g., in main loop or timer)
 * when using Buzzer_Active() to ensure correct timing behavior.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef BUZZER_INCLUDED
#define BUZZER_INCLUDED

#include <stdint.h>
#include "buzzer_port.h"

/**
 * @brief   Initialize the buzzer
 *
 * This function configures the GPIO pin connected to the buzzer
 * as an output and sets it to the inactive state.
 *
 * @note
 * Must be called before using any other buzzer functions.
 * Hardware configuration is defined in buzzer_port.h and buzzer_hw.h.
 */
void Buzzer_Init(void);

/**
 * @brief   Activate the buzzer for a specified duration
 *
 * This function turns the buzzer on and keeps it active for a
 * duration represented by the 'value' parameter. The actual timing
 * is handled by calling Buzzer_Refresh() periodically.
 *
 * @param[in] value   Duration counter for the buzzer; the exact timing
 *                    depends on how frequently Buzzer_Refresh() is called.
 *
 * @note
 * Must call Buzzer_Refresh() in the main loop or a timer interrupt
 * to automatically turn off the buzzer after the specified duration.
 */
void Buzzer_Active(uint16_t value);

/**
 * @brief   Update buzzer timing
 *
 * This function must be called periodically (e.g., in the main loop
 * or a timer interrupt) to handle the non-blocking buzzer timing.
 * It decrements the internal counter set by Buzzer_Active() and
 * automatically turns off the buzzer when the counter reaches zero.
 *
 * @note
 * Without calling this function regularly, the buzzer may remain
 * active indefinitely or the timing may be incorrect.
 */
void Buzzer_Refresh(void);

/**
 * @brief   Generate a short "up or down" beep sound
 *
 * This function produces a fixed, blocking beep sound with a
 * short duration (~80 ms). The function will delay execution
 * while the beep is active.
 *
 * @note
 * This is a blocking function; program execution is paused during
 * the beep. Use non-blocking functions like Buzzer_Active() for
 * background beep handling.
 */
void Buzzer_MakeBeep_UpDown(void);

/**
 * @brief   Generate a "set" beep sound
 *
 * This function produces a fixed, blocking beep sound with a
 * medium duration (~200 ms). The function will delay program
 * execution while the beep is active.
 *
 * @note
 * This is a blocking function; program execution is paused during
 * the beep. Use non-blocking functions like Buzzer_Active() if
 * background beep handling is required.
 */
void Buzzer_MakeBeep_Set(void);

/**
 * @brief   Generate an "error" beep sound
 *
 * This function produces a fixed, blocking beep sound with a
 * long duration (~500 ms), intended to indicate an error condition.
 * Program execution is paused while the beep is active.
 *
 * @note
 * This is a blocking function. For non-blocking beep handling,
 * consider using Buzzer_Active() with periodic Buzzer_Refresh().
 */
void Buzzer_MakeBeep_Error(void);

#endif
