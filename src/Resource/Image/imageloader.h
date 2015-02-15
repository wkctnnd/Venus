#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include "Container\string.h"
namespace Venus
{
    namespace Resource
    {
        class ImageLoader
        {
        public:
            void loadImageFile(Utility::VString &file);
        };
    }
}

#endif