/**
 * @brief Non-blocking buzzer driver.
 *
 * The buzzer module owns and maintains its own internal down-counter. Timing
 * is driven by a periodic 1 ms timer interrupt that calls AJ_Buzzer_Handler().
 *
 * Each call to AJ_Buzzer_Handler() decrements the internal counter. When the
 * counter reaches zero, the buzzer is automatically turned off. This keeps the
 * driver self-contained and independent of the main-loop execution rate.
 *
 * The buzzer is turned on with AJ_Buzzer_Start(duration); afterwards the
 * application only needs to call AJ_Buzzer_Handler() from the 1 ms timer
 * interrupt.
 *
 * @note The internal counter is managed by the library; the application must
 *       only call AJ_Buzzer_Start() and AJ_Buzzer_Handler().
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: Source Files to Build
 * -----------------------------------------------------------------------------
 * The following source files must be compiled and linked in the project:
 * - `aj_buzzer.c`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 2: Default Configuration
 * -----------------------------------------------------------------------------
 * The default driver macros are declared in the following headers:
 * - `aj_target.h`
 * - `aj_buzzer_config.h`
 * - `aj_buzzer_config_platform.h`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 3: User Configuration Override
 * -----------------------------------------------------------------------------
 * This library's default configuration can be customized via the central
 * project hardware configuration file, which MUST be present alongside your
 * project source files. Override the macros inside it:
 * - `hardware.h`
 *
 * -----------------------------------------------------------------------------
 * EXAMPLE PROJECT
 * -----------------------------------------------------------------------------
 * @see    
 *     
 * -----------------------------------------------------------------------------
 * Source
 * -----------------------------------------------------------------------------
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_BUZZER_INCLUDED
#define AJ_BUZZER_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_buzzer_config.h"
#include "aj_buzzer_type.h"
#include "aj_buzzer_port.h"

static inline void AJ_Buzzer_TurnOff(void){
	AJ_Buzzer_WritePin(!AJ_BUZZER_ACTIVE);
}

static inline void AJ_Buzzer_TurnOn(void){
	AJ_Buzzer_WritePin(AJ_BUZZER_ACTIVE);
}

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
 * This function turns the buzzer on and loads the internal down-counter with
 * the provided duration. The buzzer remains active until the counter reaches
 * zero.
 *
 * @param[in] duration   Active time of the buzzer in ticks (ms).
 *
 * @note
 * AJ_Buzzer_Handler() must be called periodically from a 1 ms timer interrupt
 * to decrement the internal counter and automatically turn the buzzer off
 * when the specified duration expires.
 */
void AJ_Buzzer_Start(aj_buzzer_t duration);

/**
 * @brief   Periodic handler, call from a 1 ms timer interrupt.
 *
 * This function manages the buzzer's non-blocking operation. Each call
 * decrements the internal counter by one. Once the counter reaches zero,
 * the buzzer is automatically turned off.
 *
 * @note    This function must be called every 1 ms (e.g., inside a timer
 *          interrupt). This library owns and maintains its own counter.
 */
void AJ_Buzzer_Handler(void);


#ifdef __cplusplus
}
#endif

#endif  /* AJ_BUZZER_INCLUDED */
