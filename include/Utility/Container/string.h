#ifndef STRING_H
#define STRING_H
#include "type.h"
namespace Venus
{
    namespace Utility
    {
        class VString
        {
        public:
            VString();
            VString(char *c);
            VString(VString &s);

            ~VString();

            size_t length();
            char* getChar();
            size_t find(VString &s);
            uint32 compare(VString &s);
            VString subStr(size_t begin, size_t length);
        private:
            char *cStr;
        };
    }
}

#endif