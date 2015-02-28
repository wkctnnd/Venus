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
            
        }


    }
}