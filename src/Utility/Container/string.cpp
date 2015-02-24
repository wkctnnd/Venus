#include "Container/string.h"
#include <string.h>

namespace Venus
{
    namespace Utility
    {
        VString::VString(char *c)
        {
            size_t  length = strlen(c);
            cStr =  new char[length+1];
            strcpy(cStr, c);
        }

        VString::VString()
        {
             cStr = 0;
        }

        VString::VString(VString &s)
        {
            size_t length = s.length();
            cStr = new char[length + 1];
            strcpy(cStr, s.getChar());
        }

        size_t VString::length()
        {
            if (cStr != 0)
            {
                return strlen(cStr);
            }
            else return 0;
        }

        char* VString::getChar()
        {
            return cStr;
        }

        uint32 VString::compare(VString &s)
        {
            //cstr maybe null
            return strcmp(cStr, s.getChar());
        }

        uint32 VString::compareCI(VString &s)

        size_t VString::find(VString &s)
        {
            
        }

        VString VString::subStr(size_t start, size_t length)
        {

            return;
        }
    }
}