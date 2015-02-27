#include "Common/graphtype.h"
#include "../../../include/Utility/type.h"
#include "Texture.h"
#include <d3d11.h>
namespace Venus
{
    namespace Resource
    {
        class Image;
    }
    namespace Graphics
    {
        class TextureDx11:public Texture
        {
        public:
            struct TextureInfo
            {
                TextureInfo(TextureInfo &info)
                {
                    mType = info.mType;
                    uWidth = info.uWidth;
                    uHeight = info.uHeight;
                    uDepth = info.uDepth;
                    uArrayNum = info.uArrayNum;
                    uMipNum = info.uMipNum;

                    mGusage = info.mGusage;
                    mCusage = info.mCusage;
                }
                TextureType mType;
                uint32 uWidth;
                uint32 uHeight;
                uint32 uDepth;

                uint32 uArrayNum;
                //0 means auto generate, none zero means user specify mipmap data
                uint32 uMipNum;

                ResGpuUsage mGusage;
                ResCpuAcess mCusage;
            };

            //start point of sub image region or can use image.getsubimage instead
            struct Subregion
            {
                uint32 uOffsetX;
                uint32 uOffsetY;
                uint32 uOffsetZ;
            };

            TextureDx11(ID3D11Device* device, TextureInfo &info, Subregion *region, Resource::Image* image = 0);
            ~TextureDx11();
            void updateSubTexture(void* data, uint32 mip, uint32 array, uint32 face = 0);
            ID3D11Resource* getRealTexture(){return mTexture;}
            TextureType getType(){return mInfo.mType;}
        private:
            void getUsageAccess(D3D11_USAGE &usage, D3D11_CPU_ACCESS_FLAG &access);
            TextureInfo mInfo;
            ID3D11Resource *mTexture;
            ResType mType;
        };

    }
}
