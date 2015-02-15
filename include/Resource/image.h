#ifndef IMAGE_H
#define IMAGE_H
#include "resource.h"
#include "Container\vector.h"



namespace Venus
{
    namespace Utility
    {
        class VVector;
    }
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