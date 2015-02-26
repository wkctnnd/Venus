#include "Common/graphtype.h"
#include "../../../include/Utility/type.h"
#include "Texture.h"
#include <d3d11.h>
namespace Venus
{
    namespace Graphics
    {
        class TextureDx11:public Texture
        {
        public:
            struct TextureInfo
            {
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

            TextureDx11(ID3D11Device* device, TextureInfo &info, const void* data = 0);
            ~TextureDx11();
            void updateSubTexture(void* data, uint32 mip, uint32 array, uint32 face = 0);
            ID3D11Resource* getRealTexture(){return mTexture;}
            TextureType getType(){return mInfo.mType;}
        private:
            void getTextureUsageAccess(ResGpuUsage, ResCpuAcess);
            TextureInfo mInfo;
            ID3D11Resource *mTexture;
            ResType mType;
        };

    }
}
