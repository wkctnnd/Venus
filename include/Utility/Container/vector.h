#ifndef VECTOR_H
#define  VECTOR_H
#include "type.h"
#include "iterator.h"
#include "assert.h"
#include "stdlib.h"
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





		template<class T>
		VVectorIterator<T>::VVectorIterator(T *p) :m_pArray(p)
		{}

		template<class T>
		VVectorIterator<T>::VVectorIterator(VVectorIterator &v) : m_pArray(v.m_pArray)
		{}

		template<class T>
		T* VVectorIterator<T>::operator ->()
		{
			return m_pArray;
		}
		template<class T>
		Random_Iterator<T>& VVectorIterator<T>::operator ++()
		{
			m_pArray++;
			return *this;
		}

		template<class T>
		Random_Iterator<T>& VVectorIterator<T>::operator --()
		{
			m_pArray--;
			return *this;

		}
		template<class T>
		bool VVectorIterator<T>::operator !=(Random_Iterator& i)
		{
			return !operator == (i);
		}

		template<class T>
		bool VVectorIterator<T>::operator ==(Random_Iterator& i)
		{
			if (m_pArray == static_cast<VVectorIterator&>(i).m_pArray)
				return true;
			else return false;

		}

		template<class T>
		bool VVectorIterator<T>::operator <(Random_Iterator& i)
		{
			if (m_pArray < static_cast<VVectorIterator&>(i).m_pArray)
				return true;
			else return false;

		}

		template<class T>
		bool VVectorIterator<T>::operator <=(Random_Iterator& i)
		{
			if (m_pArray <= static_cast<VVectorIterator&>(i).m_pArray)
				return true;
			else return false;

		}
		template<class T>
		Random_Iterator<T> VVectorIterator<T>::operator + (size_t i)
		{
			VVectorIterator temp(*this);
			temp.m_pArray += i;
			return temp;
		}

		template<class T>
		Random_Iterator<T> VVectorIterator<T>::operator - (size_t i)
		{
			VVectorIterator temp(*this);
			temp.m_pArray -= i;
			return temp;
		}


		template<class T>
		VVector<T>::VVector()
		{
			m_pArray = 0;
			m_sDataSize = 0;
			m_sFullSize = 0;
		}

		template<class T>
		VVector<T>::VVector(size_t size)
		{
			m_pArray = new T[size];
			m_sDataSize = 0;
			m_sFullSize = size;
		}

		template<class T>
		void VVector<T>::push_back(T &element)
		{
			if (m_sDataSize + 1 < m_sFullSize)
			{
				m_pArray[m_sDataSize] = element;
			}
			else
			{
				m_sFullSize = 2 * m_sFullSize;
				m_pArray = (T*)realloc(m_pArray, m_sFullSize);
				m_pArray[m_sDataSize] = element;
				m_sDataSize++;
			}
		}

		template<class T>
		void VVector<T>::push_back(T &&element)
		{
			if (m_sDataSize + 1 < m_sFullSize)
			{
				m_pArray[m_sDataSize] = element;
			}
			else
			{
				m_sFullSize = 2 * m_sFullSize;
				m_pArray = (T*)realloc(m_pArray, m_sFullSize);
				m_pArray[m_sDataSize] = element;
				m_sDataSize++;
			}
		}


		template<class T>
		void VVector<T>::clear()
		{
			for (size_t i = 0; i < m_sDataSize; i++)
			{
				m_pArray[i].~T();
			}
			m_sDataSize = 0;
		}

		template<class T>
		void VVector<T>::resize(size_t size, T *value /* = 0 */)
		{
			/*	if (size)
			{
			}*/
		}

		template<class T>
		void VVector<T>::reserve(size_t size)
		{
			if (size > m_sFullSize)
			{
				m_pArray = (T*)realloc(m_pArray, size);
				m_sFullSize = size;
			}
		}


		template<class T>
		T& VVector<T>::getAt(size_t i)
		{
			return m_pArray[i];
		}

		template<class T>
		size_t VVector<T>::getSize()
		{
			return m_sDataSize;
		}

		template<class T>
		size_t VVector<T>::getCapacity()
		{
			return m_sFullSize;
		}

		template<class T>
		VVector<T>::~VVector()
		{
			clear();
			delete m_pArray;
		}

		template<class T>
		T& VVector<T>::operator [](size_t i)
		{
			return getAt(i);
		}

		template<class T>
		VVectorIterator<T> VVector<T>::begin()
		{
			VVectorIterator<T> iter(m_pArray);
			return iter;
		}


		template<class T>
		VVectorIterator<T> VVector<T>::end()
		{
			VVectorIterator<T> iter(m_pArray + sDataSize);
			return iter;
		}

    }
}

#endif
