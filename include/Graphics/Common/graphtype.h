#ifndef GRAPHTYPE_H
#define GRAPHTYPE_H

namespace Venus
{
    enum BufferType
    {
        Index_Buffer,
        Vertex_Buffer,
        Constant_Buffer,
    };

    enum ResAccess
    {
        GPU_READ = 0x01,
        GPU_WRITE = 0x02,
        CPU_READ = 0x04,
        CPU_WRITE = 0x08,
    };

    enum TextureType
    {
        Texture1D,
        Texture2D,
        Texture3D,
        TextureCube,
        Texture1DArray,
        Texture2DArray,
        TextureCubeArray,
    };

    enum ResType
    {
        CPU_RES,
        GPU_RES,
        DISK_RES,
    };

    enum VertexSemantic
    {
        SEMANTIC_POSITION,
        SEMANTIC_TEXCOORD,
        SEMANTIC_NORMAL,
        SEMANTIC_BINORMAL,
        SEMANTIC_TANGENT,
    };

    enum AccessFlag
    {
        ACCESS_READ,
        ACCESS_WRITE,
        ACCESS_READ_WRITE,
        ACCESS_WRITE_DISCARD,
        ACCESS_WRITE_NO_OVERWRITE
    }
}

#endif


