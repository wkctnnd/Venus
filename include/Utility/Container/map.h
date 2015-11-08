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

            VMapIterator<element> insert(Pair &p);
            void delete(T t);
            void clear();
            void resize(size_t size);
            T& getAt(size_t i);
            VMapIterator begin();
           VMapIterator end();
           bool isEmpty();
           void adjust(element* node)

            V& operator [](T t);
        private:
            struct  element
            {
                element(key, value):mKey(key),mValue(value),vLeft(0),vRight(0){}
                element(){}
                T mKey;
                V mValue;
                int priority;

                value *pLeft;
                value *pRight;
                value *pPrev;
            };
            element* mHead;
            element* mEnd;
            unsigned int uSize;
        };


    }
}

#endif