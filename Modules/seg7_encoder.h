/**
 * @file    seg7_encoder.h
 * @brief   7-segment display encoding utilities.
 *
 * This module provides functions to encode unsigned integer values
 *
 * The conversion is performed using the Double Dabble (shift-and-add-3)
 * algorithm, which efficiently transforms binary numbers into BCD
 * representation without using division operations.
 *
 * The resulting BCD digits are mapped to 7-segment font codes using
 * the `seg7_font_digit` lookup table and written into the output
 * buffer provided by the user.
 *
 * The digit ordering convention used in this library places the
 * least significant digit (units) at index 0 of the output array.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef SEG7_ENCODER_INCLOUDED
#define SEG7_ENCODER_INCLOUDED

#include <stdint.h>

#include "utility_bit.h"
#include "seg7_font.h"

/**
 * @brief Encode an 8-bit number into two 7-segment digits.
 *
 * Encodes values in the range 0–99 into two 7-segment display
 * patterns and stores the result in the array pointed to by `seg`.
 *
 * Digit ordering:
 * - seg[0] contains the least significant digit (units).
 * - seg[1] contains the most significant digit (tens).
 *
 * Behavior:
 * - If the input number is greater than 99, the output digits
 *   are cleared and the function reports overflow.
 *
 * @param seg    Pointer to an array of at least two bytes where
 *               encoded segment patterns will be written.
 * @param number Input value to encode (<= 99).
 *
 * @return 0 on success, 1 if overflow occurred (number > 99).
 */
uint8_t Seg7_EncodeNumber_2Digits(uint8_t *seg, uint8_t number);

/**
 * @brief  Set the decimal point on a specific digit of a 2-digit 7-segment display buffer.
 * @param  seg      Pointer to the 7-segment display buffer.
 * @param  position Digit position to set the decimal point (0..1).
 * @retval uint8_t  Return status:
 *         - 0U : Success
 *         - 1U : Invalid position error
 */
uint8_t Seg7_SetDecimalPoint_2Digits(uint8_t *seg, uint8_t position);

/**
 * @brief Reverse the order of a 2-byte 7-segment buffer.
 *
 * Digit ordering after execution:
 * - seg[0] becomes previous seg[1]
 * - seg[1] becomes previous seg[0]
 *
 * This is typically used when display hardware wiring requires
 * reversed digit ordering (e.g., MSB - LSB alignment adjustment).
 *
 * @param seg Pointer to an array of at least two bytes
 *            representing encoded 7-segment digit patterns.
 */
void Seg7_Reverse2Bytes(uint8_t *seg);

/**
 * @brief Encode a 16-bit number into three 7-segment digits.
 *
 * Encodes values in the range 0–999 into three 7-segment display
 * patterns and stores the result in the array pointed to by `seg`.
 *
 * Digit ordering:
 * - seg[0] contains the least significant digit (units).
 * - seg[1] contains the middle digit (tens).
 * - seg[2] contains the most significant digit (hundreds).
 *
 * Behavior:
 * - If the input number is greater than 999, the output digits
 *   are cleared and the function reports overflow.
 *
 * @param seg    Pointer to an array of at least three bytes where
 *               encoded segment patterns will be written.
 * @param number Input value to encode (<= 999).
 *
 * @return 0 on success, 1 if overflow occurred (number > 999).
 */
uint8_t Seg7_EncodeNumber_3Digits(uint8_t *seg, uint16_t number);

/**
 * @brief  Set the decimal point on a specific digit of a 3-digit 7-segment display buffer.
 * @param  seg       Pointer to the 7-segment display buffer.
 * @param  position  Digit position to set the decimal point (0..2).
 * @retval uint8_t   Return status:
 *         - 0U : Success
 *         - 1U : Invalid position error
 */
uint8_t Seg7_SetDecimalPoint_3Digits(uint8_t *seg, uint8_t position);

/**
 * @brief Reverse the order of a 3-byte 7-segment buffer.
 *
 * Digit ordering after execution:
 * - seg[0] becomes previous seg[2]
 * - seg[1] becomes previous seg[1]
 * - seg[2] becomes previous seg[0]
 *
 * This is typically used when display hardware wiring requires
 * reversed digit ordering (e.g., MSB - LSB alignment adjustment).
 *
 * @param seg Pointer to an array of at least four bytes
 *            representing encoded 7-segment digit patterns.
 */
void Seg7_Reverse3Bytes(uint8_t *seg);

/**
 * @brief Encode a 16-bit number into four 7-segment digits.
 *
 * Encodes values in the range 0–9999 into four 7-segment display
 * patterns and stores the result in the array pointed to by `seg`.
 *
 * Digit ordering:
 * - seg[0] contains the least significant digit (units).
 * - seg[1] contains the tens digit.
 * - seg[2] contains the hundreds digit.
 * - seg[3] contains the most significant digit (thousands).
 *
 * Behavior:
 * - If the input number is greater than 9999, the output digits
 *   are cleared and the function reports overflow.
 *
 * @param seg    Pointer to an array of at least four bytes where
 *               encoded segment patterns will be written.
 * @param number Input value to encode ( <= 9999).
 *
 * @return 0 on success, 1 if overflow occurred (number > 9999).
 */
uint8_t Seg7_EncodeNumber_4Digits(uint8_t *seg, uint16_t number);

/**
 * @brief  Set the decimal point on a specific digit of a 4-digit 7-segment display buffer.
 * @param  seg       Pointer to the 7-segment display buffer.
 * @param  position  Digit position to set the decimal point (0..3).
 * @retval uint8_t   Return status:
 *         - 0U : Success
 *         - 1U : Invalid position error
 */
uint8_t Seg7_SetDecimalPoint_4Digits(uint8_t *seg, uint8_t position);

/**
 * @brief Reverse the order of a 4-byte 7-segment buffer.
 *
 * Digit ordering after execution:
 * - seg[0] becomes previous seg[3]
 * - seg[1] becomes previous seg[2]
 * - seg[2] becomes previous seg[1]
 * - seg[3] becomes previous seg[0]
 *
 * This is typically used when display hardware wiring requires
 * reversed digit ordering (e.g., MSB - LSB alignment adjustment).
 *
 * @param seg Pointer to an array of at least four bytes
 *            representing encoded 7-segment digit patterns.
 */
void Seg7_Reverse4Bytes(uint8_t *seg);

#endif
