#ifndef RENDERENGINE_H
#define RENDERENGINE_H
//most top level of rendering 
namespace Venus
{
    namespace Graphics
    {
        class Device;
        class Context;
    }
    class RenderEngine
    {
    public:
        RenderEngine();
        ~RenderEngine();
        void createWindow();
        Graphics::Device* getDevice();
        Graphics::Context* getContext();
        void init();
        void unInit();
    private:
        
    };

    static RenderEngine engine;
}

#endif