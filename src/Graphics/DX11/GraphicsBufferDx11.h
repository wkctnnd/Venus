#include "GraphicsBuffer.h"
#include "Common\graphtype.h"
#include "../../../include/Utility/type.h"

namespace Venus
{
    namespace Graphics
    {
        class GraphicsBufferDx11:public GraphicsBuffer
        {
        public:
            GraphicsBufferDx11(ID3D11Device* device, BufferType type, uint32 size, ResGpuUsage gusage, ResCpuAcess cusage, const void* data = 0);
            void updateBuffer();
            ID3D11Buffer* getRealBuffer();
        private:
            void getBufferUsageAccess(ResGpuUsage, ResCpuAcess);

            D3D11_USAGE mUsage;
            D3D11_CPU_ACCESS_FLAG mAccess;
            ID3D11Buffer *mBuffer;
        };
    }
}
