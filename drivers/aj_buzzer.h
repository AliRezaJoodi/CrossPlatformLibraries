/**
 * @brief Non-blocking buzzer driver.
 *
 * The buzzer module is independent from any specific timebase implementation.
 * It only requires a monotonically increasing tick value to be provided by
 * the application.
 *
 * The recommended usage is to generate that tick from a hardware timer
 * interrupt with a period of 1 ms, but any consistent tick source may be used.
 *
 * The buzzer is non-blocking and must be refreshed periodically from the main
 * loop using AJ_Buzzer_Refresh().
 *
 * @note The application must provide the current tick value to
 *       AJ_Buzzer_Start() and AJ_Buzzer_Refresh().
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: Compilation & Linkage
 * -----------------------------------------------------------------------------
 * The following source files must be compiled and linked in the project:
 * - `aj_buzzer.c`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 2: Configuration Override
 * -----------------------------------------------------------------------------
 * The default driver macros are declared in the following headers:
 * - `aj_target.h`
 * - `aj_buzzer_config.h`
 * - `aj_buzzer_config_platform.h`
 *
 * To customize these configurations, override them inside the central project
 * hardware configuration file:
 * - `hardware.h`
 *
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
 * provided tick value. The buzzer remains active until the specified
 * duration has elapsed.
 *
 * @param[in] tick_now   Current tick value provided by the application.
 * @param[in] duration   Active time of the buzzer in ticks.
 *
 * @note
 * AJ_Buzzer_Refresh() must be called regularly (e.g., in the main loop)
 * to monitor the elapsed time and automatically turn the buzzer off
 * when the specified duration expires.
 */
void AJ_Buzzer_Start(aj_buzzer_t tick_now, aj_buzzer_t duration);

/**
 * @brief   Refresh the buzzer state.
 *
 * This function manages the buzzer's non-blocking operation. It checks whether
 * the buzzer's active duration has elapsed by comparing the current tick with
 * the stored start tick. If the specified duration has passed, the buzzer is
 * automatically turned off.
 *
 * @param[in] tick_now  Current tick value provided by the application.
 *
 * @note    This function must be called regularly in the main loop to ensure
 *          timely buzzer deactivation. If it is not called periodically,
 *          the buzzer may remain active longer than expected.
 */
void AJ_Buzzer_Refresh(aj_buzzer_t tick_now);


#ifdef __cplusplus
}
#endif

#endif  /* AJ_BUZZER_INCLUDED */
