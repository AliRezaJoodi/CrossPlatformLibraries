/**
 * @file    buzzer.h
 * @brief   Public API for non-blocking buzzer control.
 *
 * This module provides a simple interface to control a buzzer using
 * the TimeBase module for timing. The buzzer operates in a non-blocking
 * manner and requires periodic calls to AJ_Buzzer_Refresh() from the main loop.
 *
 * The TimeBase module must be configured so that AJ_TimeBase_CountTicks()
 * is called from a hardware timer interrupt (typically every 1 ms).
 *
 * @note The TimeBase module must be initialized and running before
 *       using any buzzer API functions.
 *
 * Hardware abstraction for the buzzer is provided by the layers
 * defined in buzzer_hw.h and AJ_BUZZER_PORT.h.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_BUZZER_INCLUDED
#define AJ_BUZZER_INCLUDED

#include <stdint.h>
#include "aj_timebase_type.h"

void AJ_Buzzer_TurnOff(void);
void AJ_Buzzer_TurnOn(void);

/**
 * @brief   Initialize the buzzer
 *
 * This function configures the GPIO pin connected to the buzzer
 * as an output and sets it to the inactive state.
 *
 * @note
 * Must be called before using any other buzzer functions.
 * Hardware configuration is defined in AJ_BUZZER_PORT.h and buzzer_hw.h.
 */
void AJ_Buzzer_Init(void);

/**
 * @brief   Activate the buzzer for a specified duration.
 *
 * This function turns the buzzer on and records the start time using the
 * provided system tick. The buzzer will remain active until the specified
 * duration has elapsed.
 *
 * @param[in] tick_now   Current system tick value (typically from AJ_TimeBase_GetTicks()).
 * @param[in] duration   Active time of the buzzer in timebase ticks.
 *
 * @note
 * AJ_Buzzer_Refresh() must be called regularly (e.g., in the main loop)
 * to monitor the elapsed time and automatically turn the buzzer off
 * when the specified duration expires.
 */
void AJ_Buzzer_Start(aj_timebase_t tick_now, aj_timebase_t duration);

/**
 * @brief   Refresh the buzzer state.
 *
 * This function manages the buzzer's non-blocking operation. It checks if the
 * buzzer's active duration has elapsed by comparing the current tick with the
 * start time. If the duration has passed, it automatically turns off the buzzer.
 *
 * @param   tick_now  The current system tick value (typically obtained via AJ_TimeBase_GetTicks()).
 *                    Passing the tick as an argument avoids redundant calls to the TimeBase
 *                    get function, optimizing performance in the main loop.
 *
 * @note    This function must be called regularly in the main loop to ensure timely
 *          buzzer deactivation. If not called, the buzzer may remain active indefinitely.
 */
void AJ_Buzzer_Refresh(aj_timebase_t tick_now);

#endif  /* AJ_BUZZER_INCLUDED */
