#include "Container\map.h"
namespace Venus
{
    namespace Utility
    {
        template<class T, class V>
        VMap::VMap()
        {
            mHead = mEnd = new element();
            mEnd->pPrev = 0;
            uSize = 0;
        }

        template<class T, class V>
        VMapIterator<element> VMap::insert(Pair &p)
        {
            bool end = true;
            bool left = true;
            T key = p.mFirst;
            V value = p.mSecond;
            element *e = mHead;
            element *p = e;
            while (e)
            {
                if(key < e->mKey)
                {
                    p = e;
                    e = e->pLeft;
                    end = false;
                    left = true;
                }
                else if(key > e->mKey)
                {
                    p = e;
                    e = e->pRight;
                    left = false;
                }
                else
                {
                    return VMapIterator<element>(e);
                }
            }

            if (e == 0)
            {
                element *newNode = new element(key, value);
                newNode->pLeft = 0;
                newNode->pRight = 0;
                if (isEmpty())
                {
                    mHead = newNode;
                    newNode->pPrev = 0;
                }
                else
                {
                    if (left)
                        p->pLeft = newNode;
                    else
                        p->pRight = newNode;

                    newNode->pPrev = p;  
                    uSize++;
                }


                if (end == true)
                {
                    mEnd->pPrev = newNode;
                }

                adjust(newNode);
                return VMapIterator<element>(newNode);
            }
        }

        template<class T, class V>
        VMapIterator<T, V> VMap::begin()
        {
            VMapIterator<T, V> iterator(vHead);
            return iterator;
        }

        template<class T, class V>
        VMapIterator<T, V> VMap::end()
        {
            VMapIterator<T, V> iterator(vEnd);
            return iterator;
        }

        template<class T, class V>
        bool VMap::isEmpty()
        {
            return uSize==0;
        }

        template<class T, class V>
        void VMap::adjust(element* node)
        {
            element *adjust = node;
            element *pre = adjust->pPrev;
            while (true)
            {
                if (adjust == pre->pLeft)
                {
                    if(adjust->mKey > pre->mKey)
                    {

                    }
                }
                else
                {

                }
            }
        }
    }

}