/*
 * @brief   Fast multiply/divide/mod operations using bit shifting
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef MATH_SHIFT_INCLUDED
#define MATH_SHIFT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define MUL_2(x)       ((x) << 1)
#define MUL_4(x)       ((x) << 2)
#define MUL_8(x)       ((x) << 3)
#define MUL_16(x)      ((x) << 4)
#define MUL_32(x)      ((x) << 5)
#define MUL_64(x)      ((x) << 6)
#define MUL_128(x)     ((x) << 7)
#define MUL_256(x)     ((x) << 8)
#define MUL_512(x)     ((x) << 9)
#define MUL_1024(x)    ((x) << 10)
#define MUL_2048(x)    ((x) << 11)
#define MUL_4096(x)    ((x) << 12)
#define MUL_8192(x)    ((x) << 13)
#define MUL_16384(x)   ((x) << 14)
#define MUL_32768(x)   ((x) << 15)
#define MUL_65536(x)   ((x) << 16)

#define DIV_2(x)       ((x) >> 1)
#define DIV_4(x)       ((x) >> 2)
#define DIV_8(x)       ((x) >> 3)
#define DIV_16(x)      ((x) >> 4)
#define DIV_32(x)      ((x) >> 5)
#define DIV_64(x)      ((x) >> 6)
#define DIV_128(x)     ((x) >> 7)
#define DIV_256(x)     ((x) >> 8)
#define DIV_512(x)     ((x) >> 9)
#define DIV_1024(x)    ((x) >> 10)
#define DIV_2048(x)    ((x) >> 11)
#define DIV_4096(x)    ((x) >> 12)
#define DIV_8192(x)    ((x) >> 13)
#define DIV_16384(x)   ((x) >> 14)
#define DIV_32768(x)   ((x) >> 15)
#define DIV_65536(x)   ((x) >> 16)

#define MOD_2(x)       ((x) & 0x01)
#define MOD_4(x)       ((x) & 0x03)
#define MOD_8(x)       ((x) & 0x07)
#define MOD_16(x)      ((x) & 0x0F)
#define MOD_32(x)      ((x) & 0x1F)
#define MOD_64(x)      ((x) & 0x3F)
#define MOD_128(x)     ((x) & 0x7F)
#define MOD_256(x)     ((x) & 0xFF)
#define MOD_512(x)     ((x) & 0x1FF)
#define MOD_1024(x)    ((x) & 0x3FF)
#define MOD_2048(x)    ((x) & 0x7FF)
#define MOD_4096(x)    ((x) & 0xFFF)
#define MOD_8192(x)    ((x) & 0x1FFF)
#define MOD_16384(x)   ((x) & 0x3FFF)
#define MOD_32768(x)   ((x) & 0x7FFF)
#define MOD_65536(x)   ((x) & 0xFFFF)

#ifdef __cplusplus
}
#endif

#endif
