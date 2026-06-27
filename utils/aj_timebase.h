/**
 * @brief   System Tick Management Library for Microcontrollers.
 * @details This library provides a non-blocking timing mechanism using a system tick.
 *          The core function @ref AJ_TimeBase_CountTicks must be called periodically
 *          inside a Timer Interrupt Service Routine (ISR).
 *          It is highly recommended to set the timer period to 1 millisecond.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_TIMEBASE_INCLUDED
#define AJ_TIMEBASE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_timebase_type.h"

extern volatile aj_timebase_t timebase_tick;

/**
 * @brief  Increments the system tick counter.
 * @details This function should be called periodically inside a Timer Interrupt
 *          Service Routine (ISR). It handles the time-keeping mechanism of the library.
 */
static inline void AJ_TimeBase_CountTicks(void) {
    timebase_tick++;
}
///void AJ_TimeBase_CountTicks(void);

/**
 * @brief  Returns the current system tick count.
 * @details This function provides an atomic read of the system tick counter.
 *          It is safe to call from any context (Main loop or Interrupts).
 * @note   The return type (AJ_timebase_t) depends on the configuration in hardware.h
 *         (8, 16, or 32-bit).
 * @return The current tick value since the system started.
 */
aj_timebase_t AJ_TimeBase_GetTicks(void);

/**
 * @brief Checks whether a specified duration has elapsed since last_tick.
 *
 * @param now_tick   Current tick value.
 * @param last_tick  Reference tick value.
 * @param duration   Duration to check, in ticks.
 *
 * @return 1 if the specified duration has elapsed, otherwise 0.
 *
 * @note This function is safe across unsigned integer overflow.
 */
static inline uint8_t AJ_TimeBase_HasElapsed(aj_timebase_t tick_now, aj_timebase_t tick_last, aj_timebase_t duration) {
    return (uint8_t)((aj_timebase_t)(tick_now - tick_last) >= duration);
}

/**
 * @brief Gets the elapsed ticks between two timebase values.
 *
 * @param now_tick   Current tick value.
 * @param last_tick  Previous/reference tick value.
 *
 * @return Elapsed ticks from last_tick to now_tick.
 *
 * @note This function is safe across unsigned integer overflow,
 *       as long as the elapsed time does not exceed the maximum
 *       representable range of AJ_timebase_t.
 */
static inline aj_timebase_t AJ_TimeBase_GetElapsed(aj_timebase_t tick_now, aj_timebase_t tick_last) {
    return (aj_timebase_t)(tick_now - tick_last);
}


#ifdef __cplusplus
}
#endif

#endif  /* AJ_TIMEBASE_INCLUDED */

