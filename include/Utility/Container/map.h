#ifndef MAP_H
#define  MAP_H
#include "type.h"
#include "iterator.h"
namespace Venus
{
    namespace Utility
    {
        template<class T>
        class VMapIterator :public Bidirection_Iterator
        {
            friend VVectorIterator;
        public:
            VVectorIterator(T *p);
            VVectorIterator(VVectorIterator &v);

            virtual T* operator ->();
            virtual Random_Iterator& operator ++();
            virtual Random_Iterator& operator --();
            virtual bool operator !=(Random_Iterator& i);
            virtual bool operator ==(Random_Iterator& i);


        private:
            T* mPointer;
            // size_t sIndex;
        };


         template<class T, class V>
         class Pair
         {
         public:

             Pair(T t, V v){mFirst = t; mSecond = v;}
            T mFirst;
            V mSecond;
         };
     
        template<class T, class V>
        class VMap
        {
        public:
            typedef VMapIterator Iterator;

            VMap();
            VMap(size_t size);

            VMapIterator insert(Pair &p);
            void delete(T t);
            void clear();
            void resize(size_t size);
            T& getAt(size_t i);
            VMapIterator begin();
           VMapIterator end();

            V& operator [](T t);
        private:
            struct  value
            {
                int iKey;
                V mValue;

                value *vLeft;
                value *vRight;
            };
            value* vHead;
            value *vEnd;
        };


    }
}

#endif