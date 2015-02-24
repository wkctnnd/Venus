#ifndef IMAGE_H
#define IMAGE_H
#include "resource.h"
#include "Container\vector.h"
#include "resenum.h"

namespace Venus
{
    namespace Utility
    {
        class VString;
    }
    namespace Resource
    {
        class Image: public Res
        {

        public:
            struct ImageInfo
            {
                uint32 uWidth;
                uint32 uHeight;
                uint32 uDepth;
                bool bCube;
                uint32 uArrayNum;
                
                ColorFormat mFormat;
                uint32 mMipNum;


            };
            void createFromFile(Utility::VString &file);
            void createFromMemory(void* memory);

            void genMipMap();
            void* getData(uint32 array, uint32 face = 0, uint32 mip = 0);

            void setImageInfo(ImageInfo &);
            void setImageData(void* data);
        private:
           
            void* pData;
            ImageInfo mInfo;
        };
    }

}

#endif