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
        public:
            VertexAttribute(uint32 stream, VertexSemantic semantic, uint32 index, uint32 instancestep)
            {
                mSemantic = semantic;
                uStream = stream;
                uIndex = index;
                uInstanceStep = instancestep;
            }
            VertexSemantic mSemantic;
            uint32 uStream;
            uint32 uIndex;
            uint32 uInstanceStep;
        };
        class VertexDeclaration
        {
        public:
            VertexDeclaration();
            void addPosition(uint32 stream, uint32 instancestep = 0);
            void addTangent(uint32 stream, uint32 instancestep = 0);
            void addBinormal(uint32 stream, uint32 instancestep = 0);
            void addTextureCoord(uint32 stream, uint32 instancestep = 0);
            void addNormal(uint32 stream, uint32 instancestep = 0);
            void addColor(uint32 stream, uint32 instancestep = 0);
        private:
            Utility::VVector<VertexAttribute> vVertexDecalare;
            uint32 uTexcoordCount;
            uint32 uNormalCount;
            uint32 uBinormalCount;
            uint32 uTangentCount;
        };
    }
}


#endif