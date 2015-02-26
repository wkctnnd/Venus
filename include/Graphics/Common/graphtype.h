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

    enum ResGpuUsage
    {
        Imutable,
        Default,
        Dynamic,
        Stage
    };

    enum ResCpuAcess
    {
        WriteOnly,
        ReadOnly
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
}

#endif


