/**
 * @brief DWT-based delay utility library for STM32F1xx microcontrollers.
 *
 * This file provides a blocking delay API built on the Cortex-M3 DWT cycle
 * counter (DWT->CYCCNT).
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: Compilation & Linkage
 * -----------------------------------------------------------------------------
 * The following source files must be compiled and linked in the project:
 * - `aj_dwt_delay.c`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 2: DWT Cycle Counter Enable (user responsibility)
 * -----------------------------------------------------------------------------
 * This library reads the DWT cycle counter but does NOT enable it. The caller
 * must enable the DWT cycle counter once at startup, for example:
 *
 *     CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
 *     DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
 *
 * If the counter is not enabled, DWT->CYCCNT stays frozen at zero and the
 * delay loop never finishes.
 *
 * @note    The DWT cycle counter is not present / not reliable on all chips
 *          (e.g. some STM32F103 clones). Prefer the SysTick-based delay
 *          library (`aj_systick_delay`) where portability matters.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_DWT_DELAY_INCLUDED
#define AJ_DWT_DELAY_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>

void AJ_DelayWithDWT_us(uint32_t clk_hz, uint32_t us);


#ifdef __cplusplus
}
#endif

#endif	/* AJ_DWT_DELAY_INCLUDED */
