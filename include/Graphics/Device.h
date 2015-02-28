#ifndef DEVICE_H
#define DEVICE_H
namespace Venus
{
    namespace Resource
    {
        class Image;
    }
    namespace Graphics
    {
        class Texture;
        class GraphicsBuffer;
        //function like device in dx, and it is a factory of gpu resource.
        //things can be created in device:buffer, classlinkage?, shader, counter, state, view, query, inputlayout, streamoutput?, predicate?, sampler, texture, 
        class Device
        {
        public:
            Texture* CreateTexture(TextureInfo &info, Resource::Image* image);
            GraphicsBuffer* CreateVertexBuffer();
            GraphicsBuffer* CreateIndexBuffer();
        }
    }
}
#endif
