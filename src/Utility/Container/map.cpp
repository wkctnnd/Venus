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

    /*    template<class T, class V>
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
        }*/

		template<class T, class V>
		VMapIterator<element> VMap::insert(Pair &p)
		{
			element *newNode = new element(key, value);
			newNode->pLeft = 0;
			newNode->pRight = 0;
			newNode->pprev = 0;
			newNode->priority = 
			insert(newNode, mHead);
		}

		template<class T, class V>
		VMapIterator<element> VMap::insert(element *Node, element *root)
		{
			if (root == 0)
			{
				root = Node;
				return root;
			}

			else if (Node->mKey < root->mKey)
			{
				insert(root, Node->pLeft);
				adjust(root);
			}

			else if (Node->mKey > root->mKey)
			{
				insert(root, Node->pRight);
				adjust(root);
			}

			else if (Node->mKey == root->mKey)
			{
				delete Node;
				return root;
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
		bool VMap::getPriority()
		{
			
		}

        template<class T, class V>
        void VMap::adjust(element* node)
        {
			element *parent = node->pPrev;
			
			if (parent->pLeft->mKey > parent->mKey)
			{
				element *adjustnode = parent->pLeft;
				element *breaknode = parent->pLeft->pRight;
				adjustnode->pRight = parent;
				adjustnode->pPrev = parent->pPrev;

				parent->pPrev = adjustnode;
				parent->pLeft = breaknode;
			}

			else if (parent->pRight->mKey < parent->mKey)
			{
				element *adjustnode = parent->pRight;
				element *breaknode = parent->pLeft->pLeft;
				adjustnode->pLeft = parent;
				adjustnode->pPrev = parent->pPrev;

				parent->pPrev = adjustnode;
				parent->pLeft = breaknode;
			}
        }
    }

}