/******************************************************************************
 * @file    seg7_1digit_encoder.h
 * @brief   7-Segment 1-Digit Encoder Library
 *          Encode digits, letters, and symbols into 7-segment display patterns.
 *
 * @author  Ali Reza Joodi
 * @see     GitHub.com/AliRezaJoodi
 *****************************************************************************/

#ifndef SEG7_1DIGIT_ENCODER_INCLOUDED
#define SEG7_1DIGIT_ENCODER_INCLOUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @brief Encode a single digit (0-9) to its 7-segment pattern.
 * @param digit  Digit value (0-9)
 * @return 7-segment encoded value; returns 0x00 if digit > 9
 */
uint8_t Seg7_1Digit_EncodeDigit(uint8_t digit);

/**
 * @brief Encode a single digit (0-9) to its 7-segment pattern (pointer version).
 * @param digit  Digit value (0-9)
 * @param seg    Pointer to uint8_t variable to store encoded value
 * @note _ByRef version simply calls Seg7_1Digit_EncodeDigit internally
 */
void    Seg7_1Digit_EncodeDigit_ByRef(uint8_t digit,  uint8_t *seg);

/**
 * @brief Encode a letter to its 7-segment pattern.
 * @param index  Index of letter: 0=A, 1=b, 2=C, 3=d, 4=E, 5=F, 6=H, 7=L, 8=r, 9=t, 10=U
 * @return 7-segment encoded value; returns 0x00 if index > 10
 */
uint8_t Seg7_1Digit_EncodeAlpha(uint8_t index);

/**
 * @brief Encode a letter to its 7-segment pattern (pointer version).
 * @param index  Index of letter
 * @param seg    Pointer to uint8_t variable to store encoded value
 */
void    Seg7_1Digit_EncodeAlpha_ByRef(uint8_t index,  uint8_t *seg);

/**
 * @brief Encode a symbol to its 7-segment pattern.
 * @param index  Index of symbol: 0=NULL, 1=-
 * @return 7-segment encoded value; returns 0x00 if index > 1
 */
uint8_t Seg7_1Digit_EncodeSymbol(uint8_t index);

/**
 * @brief Encode a symbol to its 7-segment pattern (pointer version).
 * @param index  Index of symbol
 * @param seg    Pointer to uint8_t variable to store encoded value
 */
void    Seg7_1Digit_EncodeSymbol_ByRef(uint8_t index,  uint8_t *seg);

/**
 * @brief Toggle all segments (invert 7-segment pattern)
 * @param seg  Current 7-segment value
 * @return Inverted 7-segment value
 */
uint8_t Seg7_1Digit_ToggleSegments(uint8_t seg);

/**
 * @brief Toggle all segments (pointer version)
 * @param seg  Pointer to current 7-segment value
 */
void    Seg7_1Digit_ToggleSegments_ByRef(uint8_t *seg);

#ifdef __cplusplus
}
#endif

#endif
