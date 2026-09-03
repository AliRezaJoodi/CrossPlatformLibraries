/*
 * @brief       Quadrature Encoder Interface (QEI) driver
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: Interrupts Configuration
 * -----------------------------------------------------------------------------
 * Usage:
 * - Configure encoder channels A, B and Z as input pins.
 * - Enable interrupt on ANY CHANGE for channels A, B and Z.
 *
 * Interrupt handlers:
 * - Call AJ_QEI_Update() inside channel A and channel B interrupt handlers.
 * - Call AJ_QEI_SetIndexFlag() inside channel Z interrupt handler.
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 2: Compilation & Linkage
 * -----------------------------------------------------------------------------
 * The following source files must be compiled and linked in the project:
 * - `aj_qei.c`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 3: Default Configuration
 * -----------------------------------------------------------------------------
 * The default driver macros are declared in the following headers:
 * - `aj_target.h`
 * - `aj_qei_config.h`
 * - `aj_qei_config_platform.h`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 4: User Configuration Override
 * -----------------------------------------------------------------------------
 * This library's default configuration can be customized via the central
 * project hardware configuration file, which MUST be present alongside your
 * project source files. Override the macros inside it:
 * - `hardware.h`
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_QEI_INCLUDED
#define AJ_QEI_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_qei_config_platform.h"     /**< refer to main.c*/
#include "aj_qei_type.h"
#include "aj_qei_port.h"

static const int8_t qei_table[16] = {
    0, -1, 1, 0,
    1, 0, 0, -1,
    -1, 0, 0, 1,
    0, 1, -1, 0
};

/**
 * @brief Initialize the quadrature encoder interface.
 *
 * This function configures channel A and channel B as input pins,
 * applies the selected input pull configuration, resets the encoder
 * count, and stores the initial quadrature phase state.
 *
 * @param qei Pointer to the QEI object.
 */
void AJ_QEI_Init(aj_qei_t *qei);

/**
 * @brief Update the quadrature decoder state.
 *
 * This function reads encoder channel A and B, decodes the quadrature
 * transition using a lookup table, and updates the internal pulse count.
 *
 * @note This function MUST be called from the interrupt handlers of
 *       both channel A and channel B for correct operation.
 *
 * @param qei Pointer to the QEI object.
 */
static inline void AJ_QEI_Update(aj_qei_t *qei){
    uint8_t phase , index;

    #if (AJ_QEI_AB_CLOSED == 0U)
    phase = (uint8_t)(
            AJ_QEI_B_Read(qei) << 1 |
            AJ_QEI_A_Read(qei)
            );
    #else
    phase = (uint8_t)(AJ_QEI_AB_Read(qei));
    #endif

    index = (uint8_t)(
            (qei->last << 2) | phase
            );

    qei->count += qei_table[index];
    qei->last = phase;
}

/**
 * @brief Get the current encoder count.
 *
 * Returns the accumulated quadrature pulse count maintained by
 * the QEI driver.
 *
 * @param qei Pointer to the QEI object.
 * @return Current encoder count value.
 */
static inline int32_t AJ_QEI_GetCount(aj_qei_t *qei){
    return qei->count;
}

/**
 * @brief Reset the encoder count.
 *
 * This function clears the accumulated quadrature pulse count
 * and sets it to zero.
 *
 * @param qei Pointer to the QEI object.
 */
static inline void AJ_QEI_ResetCount(aj_qei_t *qei){
    qei->count = 0;
}

#if (AJ_QEI_Z_USED == 1U)
/**
 * @brief Set the encoder index flag.
 *
 * This function sets the index flag when the encoder index (Z) pulse
 * is detected. It is typically called from the index channel interrupt.
 *
 * @param qei Pointer to the QEI object.
 */
static inline void AJ_QEI_SetIndexFlag(aj_qei_t *qei){
    qei->flag = 1;
}

/**
 * @brief Get the encoder index flag state.
 *
 * This function returns the current state of the index flag,
 * which indicates whether an index (Z) pulse has been detected.
 *
 * @param qei Pointer to the QEI object.
 * @return uint8_t Index flag state (1 = index detected, 0 = not detected).
 */
static inline uint8_t AJ_QEI_GetIndexFlag(const aj_qei_t *qei){
    return qei->flag;
}

/**
 * @brief Clear the encoder index flag.
 *
 * This function clears the index flag after it has been processed
 * by the application.
 *
 * @param qei Pointer to the QEI object.
 */
static inline void AJ_QEI_ClearIndexFlag(aj_qei_t *qei){
    qei->flag = 0;
}
#endif


#ifdef __cplusplus
}
#endif

#endif
