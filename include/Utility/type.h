#ifndef TYPE_H
#define TYPE_H

#include "crossplatform"

typedef int16 int16_t;
typedef int32 int32_t;
typedef int64 int64_t;


typedef uint16 uint16_t;
typedef uint32 uint32_t;
typedef uint64 uint64_t;

typedef f32 float;
typedef f64 double;

#if defined(VENUS_WIN64) || defined(VENUS_WIN64)
typedef size_t uint64;
#else VENUS_WIN32
typedef size_t uint32;
#endif

