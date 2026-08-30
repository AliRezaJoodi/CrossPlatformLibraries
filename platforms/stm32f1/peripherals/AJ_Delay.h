/**
 * @brief Delay utility library for STM32F1xx microcontrollers.
 *
 * This file is effectively a refactor of the STM32 Low-Layer (LL) library:
 * it provides blocking delay APIs built on the SysTick COUNTFLAG,
 * re-implemented here rather than calling the LL functions directly.
 *
 * @note    The clock count (reset) of the SysTick counter is intentionally not
 *          performed here; the interface keeps the SysTick configuration fully
 *          in the hands of the user.
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: Compilation & Linkage
 * -----------------------------------------------------------------------------
 * The following source files must be compiled and linked in the project:
 * - `AJ_Delay.c`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 2: SysTick 1ms Time Base
 * -----------------------------------------------------------------------------
 * The delay functions assume the SysTick timer has been configured to generate a 1 ms time base.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_DELAY_INCLUDED
#define AJ_DELAY_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>

void AJ_Delay_ms(uint32_t delay);


#ifdef __cplusplus
}
#endif

#endif	/* AJ_DELAY_INCLUDED */
