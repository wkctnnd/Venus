#ifndef GRAPHICSBUFFER_H
#define GRAPHICSBUFFER_H

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
    UINT32 getBufferSize(return uSize;)
    bool isDynamic(){return bDynamic;}


protected:
    BufferType mType;
    UINT32 uSize;
    bool bDynamic;
}

#endif

