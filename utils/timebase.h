/**
 * @file    timebase.h
 * @brief   System Tick Management Library for Microcontrollers.
 * @details This library provides a non-blocking timing mechanism using a system tick.
 *          The core function @ref TimeBase_CountTicks must be called periodically
 *          inside a Timer Interrupt Service Routine (ISR).
 *          It is highly recommended to set the timer period to 1 millisecond.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef TIMEBASE_INCLUDED
#define TIMEBASE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "timebase_type.h"

/**
 * @brief  Increments the system tick counter.
 * @details This function should be called periodically inside a Timer Interrupt
 *          Service Routine (ISR). It handles the time-keeping mechanism of the library.
 * @return None
 */
void TimeBase_CountTicks(void);

/**
 * @brief  Returns the current system tick count.
 * @details This function provides an atomic read of the system tick counter.
 *          It is safe to call from any context (Main loop or Interrupts).
 * @note   The return type (timebase_t) depends on the configuration in hardware.h
 *         (8, 16, or 32-bit).
 * @return The current tick value since the system started.
 */
timebase_t TimeBase_GetTicks(void);

/**
 * @brief  Checks if a specific duration has elapsed since last_tick.
 * @param  last_tick: The starting point of time.
 * @param  duration: The time interval to check (in ticks).
 * @retval 1 if elapsed, 0 otherwise.
 */
static inline uint8_t TimeBase_CheckElapsed(timebase_t last_tick, timebase_t duration) {
    return (timebase_t)(TimeBase_GetTicks() - last_tick) >= duration;
}

#ifdef __cplusplus
}
#endif

#endif  /* TIMEBASE_INCLUDED */

