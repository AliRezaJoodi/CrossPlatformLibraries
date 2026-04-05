#ifndef UTILITY_ARRAY_INCLUDED
#define UTILITY_ARRAY_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

uint16_t Array_Min_u16(const uint16_t *arr, uint16_t len);
uint16_t Array_Max_u16(const uint16_t *arr, uint16_t len);
uint16_t Array_Average_u16(const uint16_t *arr, uint16_t len);
int16_t Array_Find_u16(const uint16_t *arr, uint16_t len, uint16_t value);
void Array_Reverse_u16(uint16_t *arr, uint16_t len);
void Array_Clear_u16(uint16_t *arr, uint16_t len);

#ifdef __cplusplus
}
#endif

#endif
