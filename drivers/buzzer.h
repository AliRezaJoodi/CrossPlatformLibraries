/**
 * @file    buzzer.h
 * @brief   Public API for buzzer handling.
 *
 * This library depends on the TimeBase module.
 * The user must call TimeBase_CountTicks() from a hardware timer interrupt
 * in the main application, typically with a 1 ms period.
 *
 * @note Initialize and use the TimeBase module before calling buzzer APIs.
 *
 * This API relies on the underlying configuration and hardware
 * layers defined in buzzer_hw.h and buzzer_port.h.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef BUZZER_INCLUDED
#define BUZZER_INCLUDED

#include <stdint.h>

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
 * @brief   Start the buzzer for a specified duration
 *
 * This function turns the buzzer on and keeps it active for a
 * duration represented by the 'duration' parameter.
 *
 * @param[in] duration The number of refresh cycles the buzzer should remain active.
 *
 * @note
 * Must call Buzzer_Refresh() in the main loop or a timer interrupt
 * to automatically turn off the buzzer after the specified duration.
 */
void Buzzer_Start(uint32_t duration);

/**
 * @brief   Update buzzer timing
 *
 * This function must be called in the main loop to handle the non-blocking buzzer timing.
 * It decrements the internal counter set by Buzzer_Active() and
 * automatically turns off the buzzer when the counter reaches zero.
 *
 * @note
 * If this function is not called regularly, the buzzer remain active indefinitely.
 */
void Buzzer_Refresh(void);

#endif
