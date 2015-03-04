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
            void switchContext(uint32);
            Context* getCurrentContext();
        private:
            //ppDeviceContext context pointer pool.
            //0 is imediate context
             ID3D11DeviceContext **ppDeviceContext;
             uint32 uCurrentContext;
        };

    }
}
#endif