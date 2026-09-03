/**
 * @brief   System Tick Management Library for Microcontrollers.
 * @details This library provides a non-blocking timing mechanism using a system tick.
 *          The core function @ref AJ_TimeBase_Handler must be called periodically
 *          inside a Timer Interrupt Service Routine (ISR).
 *          It is highly recommended to set the timer period to 1 millisecond.
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: Compilation & Linkage
 * -----------------------------------------------------------------------------
 * The following source files must be compiled and linked in the project:
 * - `aj_timebase.c`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 2: Default Configuration
 * -----------------------------------------------------------------------------
 * The default driver macros are declared in the following headers:
 * - `aj_target.h`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 3: User Configuration Override
 * -----------------------------------------------------------------------------
 * This library's default configuration can be customized via the central
 * project hardware configuration file, which MUST be present alongside your
 * project source files. Override the macros inside it:
 * - `hardware.h`
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

extern volatile aj_timebase_t aj_timebase_tick;

/**
 * @brief  Increments the system tick counter.
 * @details This function should be called periodically inside a Timer Interrupt
 *          Service Routine (ISR). It handles the time-keeping mechanism of the library.
 */
static inline void AJ_TimeBase_Handler(void) {
    aj_timebase_tick++;
}

/**
 * @brief  Returns the current system tick count.
 * @details This function provides an atomic read of the system tick counter.
 *          It is safe to call from any context (Main loop or Interrupts).
 * @note   The return type (AJ_timebase_t) depends on the configuration in hardware.h
 *         (8, 16, or 32-bit).
 * @return The current tick value since the system started.
 */
static inline aj_timebase_t AJ_TimeBase_GetTick(void) {
    #if (AJ_TARGET_MCU_BITS == 8U) && (AJ_TARGET_TICK_BITS > 8U)
        aj_timebase_t t1, t2;
        do {
            t1 = aj_timebase_tick;
            t2 = aj_timebase_tick;
        } while (t1 != t2);
        return t2;
    #else
        return aj_timebase_tick;
    #endif
}

/**
 * @brief Checks whether a specified duration has elapsed since last_tick.
 *
 * @param tick_last  Reference tick value.
 * @param duration   Duration to check, in ticks.
 * @return 1 if the specified duration has elapsed, otherwise 0.
 * @note This function is safe across unsigned integer overflow.
 */
static inline uint8_t AJ_TimeBase_IsElapsed(aj_timebase_t tick_last, aj_timebase_t duration) {
    return (uint8_t)((aj_timebase_t)(AJ_TimeBase_GetTick() - tick_last) >= duration);
}

/**
 * @brief Gets the elapsed ticks since last_tick.
 *
 * @param tick_last  Previous/reference tick value.
 * @return Elapsed ticks from last_tick to now.
 * @note This function is safe across unsigned integer overflow,
 *       as long as the elapsed time does not exceed the maximum
 *       representable range of AJ_timebase_t.
 */
static inline aj_timebase_t AJ_TimeBase_GetElapsed(aj_timebase_t tick_last) {
    return (aj_timebase_t)(AJ_TimeBase_GetTick() - tick_last);
}


#ifdef __cplusplus
}
#endif

#endif  /* AJ_TIMEBASE_INCLUDED */

