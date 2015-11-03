#include "Container\vector.h"
#include "assert.h"
namespace Venus
{
    namespace Utility
    {
        template<class T>
        VVectorIterator<T>::VVectorIterator(T *p):m_pArray(p)
        {}

        template<class T>
        VVectorIterator<T>::VVectorIterator(VVectorIterator &v):m_pArray(v.m_pArray)
        {}

        template<class T>
        T* VVectorIterator<T>::operator ->()
        {
            return m_pArray;
        }
        template<class T>
        Random_Iterator& VVectorIterator<T>::operator ++()
        {
            m_pArray++;
            return *this;
        }

        template<class T>
        Random_Iterator& VVectorIterator<T>::operator --()
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
            if(m_pArray == static_cast<VVectorIterator&>(i).m_pArray)   
                return true;
            else return false;

        }

        template<class T>
        bool VVectorIterator<T>::operator <(Random_Iterator& i)
        {
            if(m_pArray < static_cast<VVectorIterator&>(i).m_pArray)   
                return true;
            else return false;

        }

        template<class T>
        bool VVectorIterator<T>::operator <=(Random_Iterator& i)
        {
            if(m_pArray <= static_cast<VVectorIterator&>(i).m_pArray)   
                return true;
            else return false;

        }
        template<class T>
        Random_Iterator VVectorIterator<T>::operator + (size_t i)
        {
            VVectorIterator temp(*this);
            temp.m_pArray += i;
            return temp;
        }

        template<class T>
        Random_Iterator operator - (size_t i)
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
        }


        template<class T>
        void VVector<T>::clear()
        {

        }

        template<class T>
        void VVector<T>::resize()
        {

        }


        template<class T>
        T& VVector<T>::getAt(size_t i)
        {
            return m_pArray[i];
        }

        template<class T>
        VVectorIterator VVectorIterator<T>::begin()
        {
            VVectorIterator<T> iter(m_pArray);
            return iter;
        }
       

        template<class T>
        VVectorIterator VVectorIterator<T>::end()
        {
            VVectorIterator<T> iter(m_pArray + sDataSize);
            return iter;
        }
}