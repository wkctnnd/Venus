#ifndef VERTEXDECLARATION_H
#define VERTEXDECLARATION_H
#include "Container\vector.h"
namespace Venus
{
    namespace Graphics
    {
        class VertexElement
        {
            
        };
        class VertexDeclaration
        {
        public:
            void addPosition();
            void addTangent();
            void addBinormal();
            void addTextureCoord();
            void addNormal();
        private:
            Utility::VVector<VertexElement> vVertexDecalare;
        };
    }
}


#endif