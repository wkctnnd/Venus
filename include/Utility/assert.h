#ifndef ASSERT_H
#define ASSERT_H
#define MAX_BUFFER 200
#ifdef WIN32
#include <windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>
namespace Venus
{
    void _assert(char* msg, char *file, unsigned line)
    {
        char buffer[MAX_BUFFER];
        sprintf(buffer, "assertion fail:\n%s\n  file: %s\nline: %d\n", msg, file, line);
#ifdef WIN32
        ::MessageBox(NULL, buffer, "assertion failure", MB_OK);
#endif

        exit(0);
    }

#define VAssert(exp1, exp2)   (exp1) || (_assert(#exp1,__FILE__, __LINE__), 0) 
}




#endif 