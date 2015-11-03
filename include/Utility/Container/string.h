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

			void assign(char* c);
            size_t length();
            const char* getChar();
            size_t find(VString &s);
            uint32 compare(VString &s);
            //case-insensitive
            uint32 compareCI(VString &s);
            VString subStr(size_t begin, size_t length);
        private:
            char *cStr;
        };
    }
}

#endif