#ifndef GRAPHICSBUFFER_H
#define GRAPHICSBUFFER_H
#include "Common\graphtype.h"
namespace Venus
{
    namespace Graphics
    {
        class GraphicsBuffer
        {
        public:
            GraphicsBuffer(BufferType type, UINT32 size)
            {
                mType = type; 
                size = uSize;
            }
            virtual void update(){};
            virtual void release(){};

            BufferType getBufferType(){return mType;}
            //UINT32 getBufferSize(return uSize;)


        protected:
            BufferType mType;
            UINT32 uSize;
            ResType mType;
        };
    }
}
#endif

