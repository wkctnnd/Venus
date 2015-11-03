#ifndef TYPE_H
#define TYPE_H
#include<stdint.h>
#include "crossplatform.h"

namespace Venus
{
    typedef int8_t int8;
    typedef int16_t int16; 
    typedef int32_t int32;
    typedef int64_t int64 ;

    typedef uint8_t uint8;
    typedef uint16_t uint16 ;
    typedef uint32_t uint32 ;
    typedef uint64_t uint64 ;

	typedef bool bool8;

    typedef float f32;
    typedef double f64;

#if defined(VENUS_WIN64) || defined(VENUS_WIN64)
    typedef size_t uint64;
#else VENUS_WIN32
    typedef size_t uint32;
}

#endif
#endif

