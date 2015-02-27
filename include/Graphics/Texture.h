#ifndef TEXTURE_H
#define TEXTURE_H
namespace Venus
{
    namespace Resource
    {
        class Image;
    }
    namespace Graphics
    {
        class Texture
        {
        public:
            void update(Resource::Image *src);
        };
    }
}

#endif
