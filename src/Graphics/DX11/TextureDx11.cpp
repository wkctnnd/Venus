#include "TextureDx11.h"
#include <d3d11.h>
#include "image.h"
#include "assert.h"
namespace Venus
{
    namespace Graphics
    {
        TextureDx11::TextureDx11(ID3D11Device* device, TextureInfo &info, Resource::Image* image):mInfo(info)
        {
            D3D11_SUBRESOURCE_DATA *data = NULL;
            if (image != NULL)
            {
                uint32 arraynum = image->getArrayNum();
                uint32 mipmapnum = image->getMipMapNum();
                uint32 facenum;
                mInfo.bCube ? facenum = 6 : 1;
                data = new D3D11_SUBRESOURCE_DATA[arraynum * mipmapnum * facenum];
                for (uint32 i = 0; i < arraynum; i++)
                {
                    for (int j = 0; j < facenum; j++)
                    {
                        for (uint32 k = 0;  k < mipmapnum;  k++)
                        {
                            uint32 index = i * mipmapnum + j;
                            data[index].pSysMem = image->getData(i, j, k);
                            uint32 mipwidth = image->getMipWidth(k);
                            uint32 mipheight = image->getMipHeight(k);
                            data[index].SysMemPitch = mipwidth;
                            data[index].SysMemSlicePitch = mipheight * mipwidth;
                        }
                    }
                }


            }

            D3D11_USAGE usage;
            D3D11_CPU_ACCESS_FLAG access;
            getUsageAccess(usage, access);
            switch (mInfo.mType)
            {
            case Texture1D:
            case Texture1DArray:
                {
                    D3D11_TEXTURE1D_DESC desc;
                    desc.ArraySize = mInfo.uArrayNum;
                    desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
                    desc.CPUAccessFlags = access;
                    desc.Usage = usage;
                    desc.Width = mInfo.uWidth;
                    desc.Format = ;
                    desc.MipLevels = ;
                    desc.MiscFlags = ;
                    ID3D11Texture1D *texture = (ID3D11Texture1D*)mTexture);
                    device->CreateTexture1D(&desc, data, &texture);
                    break;
                }
            case Texture2D:
            case Texture2DArray:
            case TextureCube:
            case TextureCubeArray:
                {
                     D3D11_TEXTURE2D_DESC desc;
                    desc.ArraySize = mInfo.uArrayNum;
                    desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
                    desc.CPUAccessFlags = access;
                    desc.Usage = usage;
                    desc.Width =  image->getWidth();
                    desc.Height =  image->getHeight();
                    desc.Format = ;
                    desc.MipLevels = ;
                    desc.MiscFlags = ;
                    ID3D11Texture2D *texture = (ID3D11Texture2D*)mTexture;
                    device->CreateTexture2D(&desc, data, &texture);
                    break;
                }


            case Texture3D:
                {
                    D3D11_TEXTURE3D_DESC desc;
                    desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
                    desc.CPUAccessFlags = access;
                    desc.Usage = usage;
                    desc.Width = mInfo.uWidth;
                    desc.Height= mInfo.uHeight;
                    desc.Depth = mInfo.uDepth;
                    desc.Format = ;
                    desc.MipLevels = ;
                    desc.MiscFlags = ;
                    ID3D11Texture3D *texture = (ID3D11Texture3D*)mTexture);
                    device->CreateTexture3D(&desc, data, &texture);
                }

            default:
                break;
            }
            mType = GPU_RES;
        }

        TextureDx11::~TextureDx11()
        {
            mTexture->Release();
        }

        void TextureDx11::updateSubTexture(void* data, uint32 mip, uint32 array, uint32 face = 0)
        {

        }

        void TextureDx11::getUsageAccess(D3D11_USAGE &usage, D3D11_CPU_ACCESS_FLAG &access)
        {
            
        }


    }
}