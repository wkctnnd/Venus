#ifndef VERTEXDECLARATION_H
#define VERTEXDECLARATION_H
#include "Container\vector.h"
#include"graphtype.h"

namespace Venus
{
    namespace Graphics
    {
        class VertexAttribute
        {
            VertexSemantic mSemantic;
            uint32 uStream;
            uint32 uIndex;
            uint32 uInstanceStep;
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
            Utility::VVector<VertexAttribute> vVertexDecalare;
        };
    }
}


#endif