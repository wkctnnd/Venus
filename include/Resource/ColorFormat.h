#ifndef COLORFORMAT_H
#define COLORFORMAT_H

//#include "resource.h"
#include "type.h"
#include "resenum.h"

namespace Venus
{
    namespace Resource
    {
       class VColorFormat
       {
       public:
           VColorFormat(ColorFormat color):mColor(color){}
           VColorFormat(VColorFormat& color):mColor(color.mColor){}
           uint32 size();
       private:
           ColorFormat mColor;
       }
    }
}


#endif