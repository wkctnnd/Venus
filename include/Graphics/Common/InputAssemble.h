#ifndef INPUTASSEMBLE_H
#define INPUTASSEMBLE_H
#include "Container\vector.h"
#include "VertexDeclaration.h"
namespace Venus
{
    namespace Graphics
    {
        class GraphicsBuffer;
        class InputAssemble
        {
        public:
        private:
            Utility::VVector<GraphicsBuffer*> vVertexBuffer;
            GraphicsBuffer* vIndexBuffer;
            VertexDeclaration mDeclaration;
        };
    }
}


#endif