#ifndef VECTOR_H
#define  VECTOR_H
#include "type.h"
#include "iterator.h"
namespace Venus
{
    namespace Utility
    {
        template<class T>
        class VVectorIterator :public Random_Iterator<T>
        {
            friend VVectorIterator<T>;
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

        template<class T>
        class VVector
        {
            public:
                typedef VVectorIterator<T> Iterator;

				VVector();
                VVector(size_t size);
				~VVector();
                void push_back(T &element);
				void push_back(T &&element);
                void clear();
                void resize(size_t size, T *value = 0);
				void reserve(size_t size);
                T& getAt(size_t i);
				Iterator begin();
				Iterator end();
				size_t getSize();
				size_t getCapacity();
				T& operator [] (size_t i);
        private:

            T* m_pArray;
            size_t m_sDataSize;
            size_t m_sFullSize;
        };


    }
}

#endif
