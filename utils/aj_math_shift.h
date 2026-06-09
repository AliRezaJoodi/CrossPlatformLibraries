/*
 * @brief   Fast multiply/divide/mod operations using bit shifting
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_MATH_SHIFT_INCLUDED
#define AJ_MATH_SHIFT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define AJ_MUL_2(x)       ((x) << 1)
#define AJ_MUL_4(x)       ((x) << 2)
#define AJ_MUL_8(x)       ((x) << 3)
#define AJ_MUL_16(x)      ((x) << 4)
#define AJ_MUL_32(x)      ((x) << 5)
#define AJ_MUL_64(x)      ((x) << 6)
#define AJ_MUL_128(x)     ((x) << 7)
#define AJ_MUL_256(x)     ((x) << 8)
#define AJ_MUL_512(x)     ((x) << 9)
#define AJ_MUL_1024(x)    ((x) << 10)
#define AJ_MUL_2048(x)    ((x) << 11)
#define AJ_MUL_4096(x)    ((x) << 12)
#define AJ_MUL_8192(x)    ((x) << 13)
#define AJ_MUL_16384(x)   ((x) << 14)
#define AJ_MUL_32768(x)   ((x) << 15)
#define AJ_MUL_65536(x)   ((x) << 16)

#define AJ_DIV_2(x)       ((x) >> 1)
#define AJ_DIV_4(x)       ((x) >> 2)
#define AJ_DIV_8(x)       ((x) >> 3)
#define AJ_DIV_16(x)      ((x) >> 4)
#define AJ_DIV_32(x)      ((x) >> 5)
#define AJ_DIV_64(x)      ((x) >> 6)
#define AJ_DIV_128(x)     ((x) >> 7)
#define AJ_DIV_256(x)     ((x) >> 8)
#define AJ_DIV_512(x)     ((x) >> 9)
#define AJ_DIV_1024(x)    ((x) >> 10)
#define AJ_DIV_2048(x)    ((x) >> 11)
#define AJ_DIV_4096(x)    ((x) >> 12)
#define AJ_DIV_8192(x)    ((x) >> 13)
#define AJ_DIV_16384(x)   ((x) >> 14)
#define AJ_DIV_32768(x)   ((x) >> 15)
#define AJ_DIV_65536(x)   ((x) >> 16)

#define AJ_MOD_2(x)       ((x) & 0x01)
#define AJ_MOD_4(x)       ((x) & 0x03)
#define AJ_MOD_8(x)       ((x) & 0x07)
#define AJ_MOD_16(x)      ((x) & 0x0F)
#define AJ_MOD_32(x)      ((x) & 0x1F)
#define AJ_MOD_64(x)      ((x) & 0x3F)
#define AJ_MOD_128(x)     ((x) & 0x7F)
#define AJ_MOD_256(x)     ((x) & 0xFF)
#define AJ_MOD_512(x)     ((x) & 0x1FF)
#define AJ_MOD_1024(x)    ((x) & 0x3FF)
#define AJ_MOD_2048(x)    ((x) & 0x7FF)
#define AJ_MOD_4096(x)    ((x) & 0xFFF)
#define AJ_MOD_8192(x)    ((x) & 0x1FFF)
#define AJ_MOD_16384(x)   ((x) & 0x3FFF)
#define AJ_MOD_32768(x)   ((x) & 0x7FFF)
#define AJ_MOD_65536(x)   ((x) & 0xFFFF)

#ifdef __cplusplus
}
#endif

#endif
