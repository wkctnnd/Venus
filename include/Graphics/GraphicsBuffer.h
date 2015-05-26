#ifndef GRAPHICSBUFFER_H
#define GRAPHICSBUFFER_H

//https://msdn.microsoft.com/en-us/library/bb205075(VS.85).aspx
//http://www.cnblogs.com/mumuliang/archive/2012/06/14/2549930.html
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

