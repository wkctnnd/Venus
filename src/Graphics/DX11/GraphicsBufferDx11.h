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
            //http://www.fseraph.com/?cat=3
            GraphicsBufferDx11(ID3D11Device* device, BufferType type, uint32 size, ResAccess access, const void* data = 0);
            //void updateBuffer(ID3D11DeviceContext* context );
           // void getData(void* data);
            //void Map(ID3D11DeviceContext* context, void* data, AccessFlag flag);
            //void unMap();
            //void CopyDataResource();
            ID3D11Buffer* getRealBuffer();
        private:
            void GraphicsBufferDx11::getBufferUsageAccess(ResAccess access, D3D11_USAGE& usage, UINT& cpuaccess);

            ID3D11Buffer *mBuffer;

            ID3D11Buffer *mStageBuffer;
        };
    }
}
