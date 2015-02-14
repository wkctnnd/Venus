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
            uint32 compare(VString &s);
        private:
            char *cStr;
        }
    };
}

#endif