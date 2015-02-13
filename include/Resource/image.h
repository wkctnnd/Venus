#ifndef IMAGE_H
#define IMAGE_H
#include "resource.h"

namespace Venus
{
    namespace Resource
    {
        class Image: public Res
        {
        public:
            void createFromFile(char *file);
            void createFromMemory(void* memory);

        };
    }



}

#endif