#ifndef MAP_H
#define  MAP_H
#include "type.h"
#include "iterator.h"
namespace Venus
{
    namespace Utility
    {
        template<class T>
        class VMapIterator :public Random_Iterator
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
            virtual bool operator < (Random_Iterator&);
            virtual bool operator <= (Random_Iterator&);
            virtual T& getAt(size_t i);

            virtual Random_Iterator operator + (size_t);
            virtual Random_Iterator operator - (size_t);


        private:
            T* mPointer;
            // size_t sIndex;
        };


         template<class T, class V>
         class Pair
         {
         public:
            T mFirst;
            V mSecond;
         };
         template<class T, class V>
         Pair Make_Pair_Of(T t, V v)
         {
            Pair p;
            p.mFirst = t;
            p.mSecond = v;
         }

        template<class T, class V>
        class VMap
        {
        public:
            typedef VVectorIterator Iterator;

            VMap();
            VMap(size_t size);

            void insert(Pair &p);
            void delete(T t);
            void clear();
            void resize(size_t size);
            T& getAt(size_t i);
          //  VVectorIterator& begin();
          //  VVectorIterator& end();

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
        };


    }
}

#endif