#ifndef RENDERENGINE_H
#define RENDERENGINE_H
//most top level of rendering 
#include "Container/vector.h"
namespace Venus
{
    namespace Graphics
    {
        class Device;
        class Context;
    }
    class RenderMesh
    {
    public:
        RenderMesh();
        ~RenderMesh();
       
    private:
        Utility::VVector<Graphics*> mbuffer;
    };

    static RenderEngine engine;
}

#endif