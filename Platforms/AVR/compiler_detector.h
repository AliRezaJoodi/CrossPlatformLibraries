
#ifndef COMPILER_DETECTOR_INCLUDED
#define COMPILER_DETECTOR_INCLUDED

#if defined(__GNUC__)
    #define COMPILER_GCC 1
    #include <avr/io.h>
#elif defined(__CODEVISIONAVR__)
    #define COMPILER_CODEVISIONAVR 1
    #include <io.h>
#elif defined(__ICCAVR__)
    #define COMPILER_IAR 1
#else
    #error "Unsupported Compiler"
#endif

#endif
