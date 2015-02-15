#ifndef ITERATOR_H
#define  ITERATOR_H

#include "type.h"
namespace Venus
{
    namespace Utility
    {
        template<class T>
        class Random_Iterator
        {
            public:
                virtual T* operator ->() = 0;
                virtual void operator ++() = 0;
                virtual void operator --() = 0;
                virtual bool operator !=() = 0;
                virtual bool operator ==() =  0;
                virtual T* getAt(size_t i) = 0;
        };

        template<class T>
        class Forward_Iterator
        {
        
        };

        template<class T>
        class Bidirection_Iterator
        {
        
        };


        template<class T>
        class Read_Iterator
        {
        
        };

        template<class T>
        class Write_Iterator
        {
        
        };
    }
}

#endif