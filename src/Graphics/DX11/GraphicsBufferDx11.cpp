#include "GraphicsBufferDx11.h"
#include "assert.h"
#include <D3D11.h>
namespace Venus
{
    namespace Graphics
    {
        GraphicsBufferDx11::GraphicsBufferDx11(ID3D11Device* device, BufferType type, uint32 size, ResGpuUsage gusage, ResCpuAcess cacess, const void* initdata = 0)
        {
            getBufferUsageAccess(gusage, cacess);

            D3D11_BUFFER_DESC desc;
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
                assert(0);
                break;
            }
            D3D11_SUBRESOURCE_DATA data;
            data.pSysMem= initdata; 
            data.SysMemPitch = 
            data.SysMemSlicePitch = 1;
            HRESULT hr = device->CreateBuffer(&desc, &data, &mBuffer);


        }


        void GraphicsBufferDx11::getBufferUsageAccess(ResGpuUsage usage, ResCpuAcess acess)
        {
            
        }
    }
}