/*
 * WARNING:
 * This module is a work in progress.
 * API and implementation may change.
 */

#ifndef BITMASK_INCLUDED
#define BITMASK_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

uint8_t BitMask_First8(uint8_t mask);
uint8_t BitMask_Single8(uint8_t mask);
uint8_t BitMask_PopCount8(uint8_t mask);
uint8_t BitMask_CTZ4(uint8_t mask);
uint8_t BitMask_CTZ8(uint8_t mask);

#ifdef __cplusplus
}
#endif

#endif