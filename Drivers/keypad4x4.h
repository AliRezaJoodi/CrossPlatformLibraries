// GitHub Account:     GitHub.com/AliRezaJoodi

#include <io.h>
#include <delay.h>

#ifndef KEYPAD4x4_INCLUDED
#define KEYPAD4x4_INCLUDED

#include <stdint.h>
#include "utility_bit.h"
#include "keypad4x4_port.h"

unsigned char _Keypad4x4_GetInitialNumber(void);
unsigned char _Keypad4x4_ConvertNumber(unsigned char key);
unsigned char Keypad4x4_GetNumber(void);

#endif
