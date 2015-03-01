#include "D:\engine\Venus\include\Resource\image.h"
//#include "imageloader.h"
#include "Container/string.h"
#include<cmath>
#include"assert.h"
namespace Venus
{
    namespace Resource
    {
        void Image::createFromFile(Utility::VString& file)
        {

        }

        void Image::createFromMemory(void* memory)
        {

        }


        uint32 Image::getMipWidth(uint32 miplevel)
        {
            VAssert(miplevel >= 0 && miplevel <= mInfo.mMipNum, "miplevel is out of the scope");
            uint32 factor = pow(2.0, miplevel);
            uint32 mipwidth = mInfo.uWidth / factor;
            return mipwidth > 0 ? mipwidth : 1;
        }

        uint32 Image::getMipHeight(uint32 miplevel)
        {
            VAssert(miplevel >= 0 && miplevel <= mInfo.mMipNum, "miplevel is out of the scope");
            uint32 factor = pow(2.0, miplevel);
            uint32 mipheight = mInfo.uHeight / factor;
            return mipheight > 0 ? mipheight : 1;
        }

        uint32 Image::getMipDepth(uint32 miplevel)
        {
            VAssert(miplevel >= 0 && miplevel <= mInfo.mMipNum, "miplevel is out of the scope");
            uint32 factor = pow(2.0, miplevel);
            uint32 mipdepth = mInfo.uDepth / factor;
            return mipdepth > 0 ? mipdepth : 1;
        }

        void* Image::getData(uint32 array, uint32 mip = 0)
        {
            calMipMapChainSize();
             void *data;
            switch (mInfo.bComposite)
            {
            case 0:
                {
                   data = (char*)pData + array * pMipmapchainsize[mInfo.mMipNum] + pMipmapchainsize[mip];
                   break;
                }
            case 1:
                {
                    Image** image = (Image**)pData;
                    data = image[array]->getData(0, mip);
                    break;
                }
            case 2:
                {
                    Image** image = (Image**)pData;
                    data = image[mip]->getData(0,0);
                    break;
                }
            }
            return data;
        }

        void Image::calMipMapChainSize()
        {
            if (pMipmapchainsize == 0)
            {
                 pMipmapchainsize = new uint32[mInfo.mMipNum + 1];
            }
            uint32 width = mInfo.uWidth;
            uint32 height = mInfo.uHeight;
            uint32 depth = mInfo.uDepth;
            uint32 formatsize = mInfo.mFormat.size(); 
            pMipmapchainsize[mInfo.mMipNum] = 0;
            for (uint32 i = 0; i< mInfo.mMipNum; i++)
            {
                width > 1 ? width = width >> 1 : 1;
                depth > 1 ? depth = depth >> 1 : 1;
                height > 1 ? height = height >> 1 : 1;

                pMipmapchainsize[i] = width * depth * height * formatsize;
                pMipmapchainsize[mInfo.mMipNum] += pMipmapchainsize[i]; 
            }

            
        }

        Image *ImageCompositor::CompositeArray(Image *image[], uint32 size)
        {
            Image* i = new Image(image[0]->mInfo);
            i->pData = (void*)image;

            i->mInfo.bComposite = 1;
            i->mInfo.uArrayNum = size;
        }

        Image *ImageCompositor::CompositeMipMap(Image* image[], uint32 size)
        {
            Image *i = new Image(image[0]->mInfo);
            i->pData = (void*)image;

            i->mInfo.bComposite = 2;
            i->mInfo.mMipNum = size;
        }
    }
}