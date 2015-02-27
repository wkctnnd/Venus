#ifndef IMAGE_H
#define IMAGE_H

//#include "resource.h"
//#include "Container\vector.h"
#include "resenum.h"

namespace Venus
{
    namespace Utility
    {
        class VString;
    }
    namespace Resource
    {
        //class Image: public Res
        //{
        //public:
        //    struct ImageInfo
        //    {
        //        uint32 uWidth;
        //        uint32 uHeight;
        //        uint32 uDepth;
        //        bool bCube;
        //        uint32 uArrayNum;

        //        //ColorFormat mFormat;
        //        uint32 mMipNum;


        //    };
        //    void createFromFile(Utility::VString &file);
        //    void createFromMemory(void* memory);

        //    void genMipMap();
        //    void* getData(uint32 array, uint32 face = 0, uint32 mip = 0);
        //    ImageInfo& getImageInfo(){return mInfo;}

        //    void setImageInfo(ImageInfo &);
        //    void setImageData(void* data);
        //private:

        //    void* pData;
        //    ImageInfo mInfo;
        //};

        class Image
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

             //Image is in either composite of data or Images. If pData is not null contains
             //image data or a image array .
             //Images witch used to comprise the composite image are restrict to the same size, 
             //same mipmapnum, same format and etc...thus the composite image can summarize the imageinfo.
                bool bComposite;
            };
            Image();
            ~Image();

            void createFromFile(Utility::VString &file);
            void createFromMemory(void* memory);

            void genMipMap();
            void* getData(uint32 array, uint32 face = 0, uint32 mip = 0);

           // ImageInfo& getImageInfo(){return mInfo;}
            uint32 getWidth(){return mInfo.uWidth;}
            uint32 getHeight(){return mInfo.uHeight;}
            uint32 getDetph(){return mInfo.uDepth;}

            uint32 getArrayNum(){return mInfo.uArrayNum;}
            uint32 isComposite(){return mInfo.bComposite;}

            uint32 getMipMapNum(){return mInfo.mMipNum;}
            void setImageInfo(ImageInfo &);
            void setImageData(void* data);

            void addImage();
            bool isCube(){return mInfo.bCube;}
        private:  
            ImageInfo mInfo;
             void* pData;
        };

    }
}


#endif