#ifndef VECTOR_H
#define  VECTOR_H
#include "type.h"
#include "iterator.h"
namespace Venus
{
    namespace Utility
    {
        template<class T>
        class VVectorIterator
        {
            
        };

        template<class T>
        class VVector
        {
            public:
                typedef VVectorIterator Iterator;
                VVector(size_t size);

                void push_back(T element);
                void clear();
                void resize(size_t size);
        private:
            
            VVectorIterator *iterator<T>;
            size_t sSize;

        };


    }
}

#endif