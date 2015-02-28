#include"ColorFormat.h"
#include "resenum.h"

namespace Venus
{
    namespace Resource
    {
        uint32 VColorFormat::size()
        {
            switch (mColor)
            {
            case Venus::Resource::VB32G32R32:
                break;
            case Venus::Resource::VB5G5R5:
                break;
            case Venus::Resource::VB5G6R5:
                break;
            case Venus::Resource::VB8G8R8:
                break;
            case Venus::Resource::VB8G8R8A8:
                break;
            default:
                break;
            }
        }
    }
}

