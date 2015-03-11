#ifndef CONTEXTDX11_H
#define CONTEXTDX11_H

#include "Common/graphtype.h"
#include "Context.h"
#include <d3d11.h>
#include <type.h>
namespace Venus
{
    namespace Graphics
    {
        class ContextDx11:public Context
        {
        public:
            void begin();
            Context* getContext();
        private:
             ID3D11DeviceContext **ppDeviceContext;
        };

    }
}
#endif