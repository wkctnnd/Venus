#ifndef IMAGELOADER_H
#define IMAGELOADER_H

namespace Venus
{
    namespace Utility
    {
        class VString;
    }
    namespace Resource
    {
        class Image;
        class ImageLoader
        {
        public:
            void loadImageFile(Utility::VString &file, const Image* image);
        };
    }
}

#endif