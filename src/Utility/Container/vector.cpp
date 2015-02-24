#include "Container\vector.h"
#include "assert.h"
namespace Venus
{
    namespace Utility
    {
        template<class T>
        VVectorIterator<T>::VVectorIterator(T *p):mPointer(p)
        {}

        template<class T>
        VVectorIterator<T>::VVectorIterator(VVectorIterator &v):mPointer(v.mPointer)
        {}

        template<class T>
        T* VVectorIterator<T>::operator ->()
        {
            return mPointer;
        }
        template<class T>
        Random_Iterator& VVectorIterator<T>::operator ++()
        {
            mPointer++;
            return *this;
        }

        template<class T>
        Random_Iterator& VVectorIterator<T>::operator --()
        {
            mPointer--;
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
            if(mPointer == static_cast<VVectorIterator&>(i).mPointer)   
                return true;
            else return false;

        }

        template<class T>
        bool VVectorIterator<T>::operator <(Random_Iterator& i)
        {
            if(mPointer < static_cast<VVectorIterator&>(i).mPointer)   
                return true;
            else return false;

        }

        template<class T>
        bool VVectorIterator<T>::operator <=(Random_Iterator& i)
        {
            if(mPointer <= static_cast<VVectorIterator&>(i).mPointer)   
                return true;
            else return false;

        }
        template<class T>
        Random_Iterator VVectorIterator<T>::operator + (size_t i)
        {
            VVectorIterator temp(*this);
            temp.mPointer += i;
            return temp;
        }

        template<class T>
        Random_Iterator operator - (size_t i)
        {
            VVectorIterator temp(*this);
            temp.mPointer -= i;
            return temp;
        }
    

        template<class T>
        VVector<T>::VVector()
        {

        }

        template<class T>
        VVector<T>::VVector(size_t size)
        {

        }

        template<class T>
        void VVector<T>::push_back(T &element)
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
            return mPointer[i];
        }

        template<class T>
        VVectorIterator VVectorIterator<T>::begin()
        {
            VVectorIterator<T> iter(mPointer);
            return iter;
        }
       

        template<class T>
        VVectorIterator VVectorIterator<T>::end()
        {
            VVectorIterator<T> iter(mPointer + sDataSize);
            return iter;
        }
}