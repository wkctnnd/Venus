#ifndef CONTEXTDX11_H
#define CONTEXTDX11_H

#include "Common/graphtype.h"
#include "Context.h"
#include <d3d11.h>
namespace Venus
{
    namespace Graphics
    {
        class ContextDx11:public Context
        {
        public:
            void switchContext();
            viod getCurrentContext();
        private:
            
             
        };

    }
}
#endif