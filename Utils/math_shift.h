/*
 * @brief
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

#define MUL2(x)       ((x) << 1)
#define MUL4(x)       ((x) << 2)
#define MUL8(x)       ((x) << 3)
#define MUL10(x)      (((x) << 3) + ((x) << 1))
#define MUL16(x)      ((x) << 4)
#define MUL32(x)      ((x) << 5)
#define MUL64(x)      ((x) << 6)
#define MUL128(x)     ((x) << 7)
#define MUL256(x)     ((x) << 8)
#define MUL512(x)     ((x) << 9)
#define MUL1024(x)    ((x) << 10)
#define MUL2048(x)    ((x) << 11)
#define MUL4096(x)    ((x) << 12)
#define MUL8192(x)    ((x) << 13)
#define MUL16384(x)   ((x) << 14)
#define MUL32768(x)   ((x) << 15)
#define MUL65536(x)   ((x) << 16)

#define DIV2(x)       ((x) >> 1)
#define DIV4(x)       ((x) >> 2)
#define DIV8(x)       ((x) >> 3)
//#define DIV10(x)      (((x) * 0xCCCCCCCDULL) >> 35)
#define DIV16(x)      ((x) >> 4)
#define DIV32(x)      ((x) >> 5)
#define DIV64(x)      ((x) >> 6)
#define DIV128(x)     ((x) >> 7)
#define DIV256(x)     ((x) >> 8)
#define DIV512(x)     ((x) >> 9)
#define DIV1024(x)    ((x) >> 10)
#define DIV2048(x)    ((x) >> 11)
#define DIV4096(x)    ((x) >> 12)
#define DIV8192(x)    ((x) >> 13)
#define DIV16384(x)   ((x) >> 14)
#define DIV32768(x)   ((x) >> 15)
#define DIV65536(x)   ((x) >> 16)

#ifdef __cplusplus
}
#endif

#endif
