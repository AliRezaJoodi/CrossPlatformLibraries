/**
 * @brief   Real-time clock (RTC) interface for STM32 peripherals.
 *
 * This file provides helper APIs for managing RTC control, status and
 * data registers, including:
 * - RTC->CRL
 * - RTC->CRH
 * - RTC->CNTH + RTC->CNTL
 * - RTC->ALRH + RTC->ALRL
 * - RTC->PRLH + RTC->PRLL
 * - RTC->DIVH + RTC->DIVL
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: Compilation & Linkage
 * -----------------------------------------------------------------------------
 * The following source files must be compiled and linked in the project:
 * - `aj_rtc.c`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 2: BUS Configuration
 * -----------------------------------------------------------------------------
 * This library does not enable any peripheral clock.
 * The application must enable the required clock buses before using this driver.
 * - The clock bus of the RTC peripheral (backup domain, etc.)
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_RTC_INCLUDED
#define AJ_RTC_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include <stm32f1xx.h>
#include "aj_rtc_type.h"


#ifdef __cplusplus
}
#endif

#endif	/* AJ_RTC_INCLUDED */