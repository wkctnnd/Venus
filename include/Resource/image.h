#ifndef IMAGE_H
#define IMAGE_H

//#include "resource.h"
//#include "Container\vector.h"
#include "resenum.h"
#include "ColorFormat.h"
namespace Venus
{
    namespace Utility
    {
        class VString;
    }
    namespace Resource
    {
        class Image;
        class ImageLoader;
        //used to composite many image to a composite image.
        class ImageCompositor
        {
        public:
            ImageCompositor();
            ~ImageCompositor();
            //all array must have same property
            Image* CompositeArray(Image *image[], uint32 size);
            //the size if cube must be 6, the image's array num must be 1.
            //Image* CompositeCube(Image* image[]);
            //start from the 0 level to size level, the image
            Image* CompositeMipMap(Image* image[], uint32 size);
        };


        class Image
        {
            // ImageCompositor;
        public:
            friend ImageCompositor;
            struct ImageInfo
            {
                uint32 uWidth;
                uint32 uHeight;
                uint32 uDepth;
               
                uint32 uArrayNum;

                VColorFormat mFormat;
                uint32 mMipNum;

             //Image is in either composite of data or Images. If pData is not null contains
             //image data or a image array .
             //Images witch used to comprise the composite image are restrict to the same size, 
             //same mipmapnum, same format and etc...thus the composite image can summarize the imageinfo.

                // 0 is pure image
                // 1 is mipmap composite
                // 2 is array composite
                uint16 bComposite;
            };
            Image();
            Image(ImageInfo& i);
            ~Image();

            void createFromFile(Utility::VString &file, ImageLoader*);
            void createFromMemory(void* memory);

            void genMipMap();
            void* getData(uint32 array, uint32 mip = 0);

           // ImageInfo& getImageInfo(){return mInfo;}
            uint32 getWidth(){return mInfo.uWidth;}
            uint32 getHeight(){return mInfo.uHeight;}
            uint32 getDepth(){return mInfo.uDepth;}

            uint32 getMipWidth(uint32 miplevel);
            uint32 getMipHeight(uint32 miplevel);
            uint32 getMipDepth(uint32 miplevel);

            uint32 getArrayNum(){return mInfo.uArrayNum;}
            uint32 isComposite(){return mInfo.bComposite;}

            uint32 getMipMapNum(){return mInfo.mMipNum;}
            void setImageInfo(ImageInfo &);
            void setImageData(void* data);

            //void addImageArray(Image *image[], uint32 size);
            //void addImageMipMap(Image *image[], uint32 startlevel, uint32 size);

            //bool isCube(){return mInfo.bCube;}
        private:  
            ImageInfo mInfo;
             void* pData;
             bool bIsDirty;

             //bad use to avoiding memory and cpu power waste to compute size of each mipmap level
             uint32* pMipmapOffset;

             void calMipMapChainOffset();
        };


     

    }
}


#endif