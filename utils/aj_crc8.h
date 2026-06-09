/*
 * @brief CRC8 calculation functions. *
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_CRC8_INCLUDED
#define AJ_CRC8_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @brief   Compute CRC-8/ATM over one byte (bitwise, non-reflected).
 *
 * @details Parameters of CRC-8/ATM:
 *          - Polynomial: 0x07
 *          - Init value: user provided (commonly 0x00)
 *          - RefIn:      false
 *          - RefOut:     false
 *          - XorOut:     0x00
 *
 * @param   crc   Current CRC accumulator.
 * @param   data  Input byte to be processed.
 *
 * @return  Updated CRC value.
 *
 * @note    Designed for incremental (streaming) CRC calculation:
 *          crc = AJ_CRC8_ATM(crc, byte);
 */
uint8_t AJ_CRC8_ATM(uint8_t crc, uint8_t data);

/**
 * @brief   Compute CRC-8/MAXIM (Dallas 1-Wire) over one byte.
 *
 * @details Parameters of CRC-8/MAXIM:
 *          - Polynomial: 0x31
 *          - Init value: user provided (commonly 0x00)
 *          - RefIn:      true
 *          - RefOut:     true
 *          - XorOut:     0x00
 *
 * @param   crc   Current CRC accumulator (will be bit-reflected internally).
 * @param   data  Input byte to be processed (will be bit-reflected internally).
 *
 * @return  Updated CRC value (reflected output).
 *
 * @note    This is the standard Dallas/Maxim 1-Wire CRC (OWI CRC-8).
 */
uint8_t AJ_CRC8_Maxim(uint8_t crc, uint8_t data);

/**
 * @brief   Compute CRC-8/SAE J1850 over one byte (non-reflected).
 *
 * @details Parameters of CRC-8/J1850:
 *          - Polynomial: 0x1D
 *          - Init value: user provided (commonly 0xFF)
 *          - RefIn:      false
 *          - RefOut:     false
 *          - XorOut:     0xFF
 *
 * @param   crc   Current CRC accumulator.
 * @param   data  Input byte to be processed.
 *
 * @return  Updated CRC value (XorOut must be applied outside the function).
 *
 * @note    Final CRC is:  final_crc = AJ_CRC8_J1850(... ) ^ 0xFF
 */
uint8_t AJ_CRC8_J1850(uint8_t crc, uint8_t data);

#ifdef __cplusplus
}
#endif

#endif
