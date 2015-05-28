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
                virtual Random_Iterator& operator ++() = 0;
                virtual Random_Iterator& operator --() = 0;
                virtual bool operator != (Random_Iterator&) = 0;
                virtual bool operator == (Random_Iterator&) =  0;
                virtual bool operator < (Random_Iterator&) = 0;
                virtual bool operator <= (Random_Iterator&) = 0;
                virtual Random_Iterator& operator + (int);
                virtual Random_Iterator& operator - (int);
        };

        template<class T>
        class Forward_Iterator
        {
        
        };

        template<class T>
        class Bidirection_Iterator
        {
        public:
            virtual T* operator ->() = 0;
            virtual Random_Iterator& operator ++() = 0;
            virtual Random_Iterator& operator --() = 0;
            virtual bool operator != (Random_Iterator&) = 0;
            virtual bool operator == (Random_Iterator&) =  0;
          
        };

        template<class T>
        class Insert_Iterator
        {
        public:
           

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