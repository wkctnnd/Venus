#include "GraphicsBufferDx11.h"
#include "assert.h"
#include <D3D11.h>
namespace Venus
{
    namespace Graphics
    {
        GraphicsBufferDx11::GraphicsBufferDx11(ID3D11Device* device, BufferType type, uint32 size, ResAccess usage, const void* initdata = 0):GraphicsBuffer(type, uSize)
        {
            D3D11_BUFFER_DESC desc;
            getBufferUsageAccess(usage, desc.Usage, desc.CPUAccessFlags);
            desc.ByteWidth = size;
            desc.StructureByteStride = 0;
            desc.MiscFlags = 0;
            switch (type)
            {
            case Index_Buffer:
                desc.BindFlags = D3D11_BIND_INDEX_BUFFER; 
                break;
            case Vertex_Buffer:
                desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
                break;
            default:
                VAssert(0, "bad buffertype");
                break;
            }
            D3D11_SUBRESOURCE_DATA data;
            data.pSysMem= initdata; 
            data.SysMemPitch = 
            data.SysMemSlicePitch = 1;
            HRESULT hr = device->CreateBuffer(&desc, &data, &mBuffer);
        }


        ID3D11Buffer* GraphicsBufferDx11::getRealBuffer()
        {
            return mBuffer;
        }

      /*  void GraphicsBufferDx11::updateBuffer(ID3D11DeviceContext* context)
        {
            
            context->CopyResource();
                context->UpdateSubresource()
        }*/
        void GraphicsBufferDx11::getBufferUsageAccess(ResAccess access, D3D11_USAGE& usage, UINT& cpuaccess)
        {
            //gpu read only
            if (access == GPU_READ)
            {
                usage = D3D11_USAGE_IMMUTABLE;
                cpuaccess = 0;
            }
            //gpu can write, no cpu access
            else if((access & GPU_WRITE !=0) && (access & (CPU_READ|CPU_WRITE) ==0))
            {
                usage = D3D11_USAGE_DEFAULT;
                cpuaccess = 0;
            }

            else if((access & GPU_WRITE|GPU_READ != 0))
            {
                if(access & (CPU_READ | CPU_WRITE) != 0)
                {
                    usage = D3D11_USAGE_STAGING;
                    cpuaccess = (D3D11_CPU_ACCESS_READ | D3D10_CPU_ACCESS_WRITE);
                }

                else if(access & CPU_READ)
                {
                    usage = D3D11_USAGE_STAGING;
                    cpuaccess = D3D11_CPU_ACCESS_READ;
                }

                else
                {
                    usage = D3D11_USAGE_DYNAMIC;
                    cpuaccess = D3D11_CPU_ACCESS_WRITE;
                }
            }
          
        }
     /*   void GraphicsBufferDx11::getData(ID3D11Device* device,ID3D11DeviceContext* context, void** data, )
        {
            if (mType)
            {
                D3D11_BUFFER_DESC desc;
                mBuffer->GetDesc(&desc);
                UINT cpuflag = desc.CPUAccessFlags;
                D3D11_USAGE usage = desc.Usage;

                if (usage == D3D11_USAGE_IMMUTABLE)
                {

                }

                else if (usage != D3D11_USAGE_STAGING)
                {
                    ID3D11Buffer *stagebuffer;
                    device->CreateBuffer(
                    context->CopyResource(stagebuffer, mBuffer);
                }

                else
                {
                    context->Map(
                }
            }


        }

        void GraphicsBufferDx11::Map(ID3D11DeviceContext* context, void* data, AccessFlag flag)
        {
            
        }*/
    }
}