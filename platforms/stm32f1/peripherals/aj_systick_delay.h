/**
 * @brief SysTick-based delay utility library for STM32F1xx microcontrollers.
 *
 * This file is effectively a refactor of the STM32 Low-Layer (LL) library:
 * it provides blocking delay APIs built on the SysTick COUNTFLAG,
 * re-implemented here rather than calling the LL functions directly.
 *
 * @note    (1) The clock count (reset) of the SysTick counter is intentionally
 *              not performed here; the interface keeps the SysTick configuration
 *              fully in the hands of the user.
 *          (2) AJ_Delay_us() is implemented on the SysTick timer and does not
 *              modify any register, so the 1 ms time base and any other
 *              SysTick-based timing keep working undisturbed.
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: Compilation & Linkage
 * -----------------------------------------------------------------------------
 * The following source files must be compiled and linked in the project:
 * - `aj_systick_delay.c`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 2: SysTick 1ms Time Base
 * -----------------------------------------------------------------------------
 * The delay functions assume the SysTick timer has been configured to generate a 1 ms time base.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_SYSTICK_DELAY_INCLUDED
#define AJ_SYSTICK_DELAY_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>

/**
 * @brief  Blocks for the given time in milliseconds using the SysTick timer.
 * @note   Counts down on the SysTick COUNTFLAG.
 * @param  ms  Delay in milliseconds.
 */
void AJ_SysTick_Delay_ms(uint32_t ms);

/**
 * @brief  Blocks for the given time in microseconds using the SysTick timer.
 * @note   Does not modify any SysTick register (reads only). Accumulates
 *         wrap-arounds, so it works for delays longer than one period too.
 * @param  clk_hz  Core clock frequency in Hz (e.g. 8000000U for 8 MHz).
 * @param  us      Delay in microseconds.
 */
void AJ_SysTick_Delay_us(uint32_t clk_hz, uint32_t us);


#ifdef __cplusplus
}
#endif

#endif	/* AJ_SYSTICK_DELAY_INCLUDED */
