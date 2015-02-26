#include "TextureDx11.h"

namespace Venus
{
    namespace Graphics
    {
        TextureDx11::TextureDx11(ID3D11Device* device, TextureInfo &info, const void* data = 0)
        {
        
        }

        TextureDx11::~TextureDx11()
        {
            mTexture->Release();
        }

        void TextureDx11::updateSubTexture(void* data, uint32 mip, uint32 array, uint32 face = 0)
        {
        
        }


    }
}