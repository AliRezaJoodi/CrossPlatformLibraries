#ifndef UTILITY_ARRAY_INCLUDED
#define UTILITY_ARRAY_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

#ifdef __cplusplus
}
#endif

#endif
