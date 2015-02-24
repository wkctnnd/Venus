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
            TextureDx11(ID3D11Device* device, BufferType type, uint32 size, ResGpuUsage gusage, ResCpuAcess cusage, const void* data = 0);
            void updateTexture();
            ID3D11Buffer* getRealBuffer();
        private:
            void getBufferUsageAccess(ResGpuUsage, ResCpuAcess);

            ID3D11Resource *mTexture;
        };

    }
}
