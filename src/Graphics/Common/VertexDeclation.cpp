#include "Common\VertexDeclaration.h"

namespace Venus
{
    namespace Graphics
    {
        VertexDeclaration::VertexDeclaration()
        {
            uTexcoordCount = 0;
            uNormalCount = 0;
            uBinormalCount = 0;
            uTangentCount = 0;
        }
        void VertexDeclaration::addPosition(uint32 stream, uint32 instancestep)
        {
            VertexAttribute attribute(stream, SEMANTIC_POSITION, 0, instancestep);
            vVertexDecalare.push_back(attribute);
        }

        void VertexDeclaration::addTextureCoord(uint32 stream, uint32 instancestep)
        {
            VertexAttribute attribute(stream, SEMANTIC_TEXCOORD, uTexcoordCount++, instancestep);
            vVertexDecalare.push_back(attribute);
        }

         void VertexDeclaration::addNormal(uint32 stream, uint32 instancestep)
        {
            VertexAttribute attribute(stream, SEMANTIC_NORMAL, uNormalCount++, instancestep);
            vVertexDecalare.push_back(attribute);
        }


          void VertexDeclaration::addBinormal(uint32 stream, uint32 instancestep)
        {
            VertexAttribute attribute(stream, SEMANTIC_BINORMAL, uBinormalCount++, instancestep);
            vVertexDecalare.push_back(attribute);
        }

           void VertexDeclaration::addTangent(uint32 stream, uint32 instancestep)
        {
            VertexAttribute attribute(stream, SEMANTIC_TANGENT, uTangentCount++, instancestep);
            vVertexDecalare.push_back(attribute);
        }
    }
}