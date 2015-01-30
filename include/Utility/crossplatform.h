#ifndef CROSSPLATFORM_H
#define CROSSPLATFORM_H
#endif

#ifdef _WIN32
#define VENUS_WIN32
#else _WIN64
#define VENUS_WIN64
#else _APPLE_
#define VENUS_MAC
#endif

