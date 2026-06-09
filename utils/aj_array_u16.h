/**
 * @brief Utility functions for uint16 array operations
 *
 * Lightweight array utilities for embedded systems.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_ARRAY_INCLUDED
#define AJ_ARRAY_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

#define AJ_ARRAY_U16_ERROR          ((uint16_t)0x7FFF)
#define AJ_ARRAY_U16_SIZE(arr)      (sizeof(arr) / sizeof((arr)[0]))

/**
 * @brief Find minimum value in uint16 array
 *
 * @param arr Pointer to array
 * @param len Number of elements in array
 *
 * @return Minimum value in array
 *         Returns 0xFFFF if arr == NULL or len == 0
 */
uint16_t AJ_ArrayU16_Min(const uint16_t *arr, uint16_t len);

/**
 * @brief Find maximum value in uint16 array
 *
 * @param arr Pointer to array
 * @param len Number of elements in array
 *
 * @return Maximum value in array
 *         Returns 0 if arr == NULL or len == 0
 */
uint16_t AJ_ArrayU16_Max(const uint16_t *arr, uint16_t len);

/**
 * @brief Calculate average value of uint16 array
 *
 * @param arr Pointer to array
 * @param len Number of elements in array
 *
 * @return Average value of array elements
 *         Returns 0 if arr == NULL or len == 0
 */
uint16_t AJ_ArrayU16_Average(const uint16_t *arr, uint16_t len);

/**
 * @brief Find a value in uint16 array
 *
 * @param arr Pointer to array
 * @param len Number of elements in array
 * @param value Value to search for
 *
 * @return Index of the first matching element
 *         Returns -1 if value is not found or input is invalid
 */
uint16_t AJ_ArrayU16_Find(const uint16_t *arr, uint16_t len, uint16_t value);

/**
 * @brief Reverse the order of elements in uint16 array
 *
 * @param arr Pointer to array
 * @param len Number of elements in array
 *
 * @return None
 */
void AJ_ArrayU16_Reverse(uint16_t *arr, uint16_t len);

/**
 * @brief Clear array by setting all elements to zero
 *
 * @param arr Pointer to array
 * @param len Number of elements in array
 *
 * @return None
 */
void AJ_ArrayU16_Clear(uint16_t *arr, uint16_t len);

#ifdef __cplusplus
}
#endif

#endif
