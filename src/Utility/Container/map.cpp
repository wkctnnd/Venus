#include "Container\map.h"
#include "Auxiliary\random.h"
#include "Auxiliary\Time.h"
namespace Venus
{
    namespace Utility
    {


		template<class T, class V>
		VMap<T,V>::VMap()
		{
			m_pRandom = new BaseRandom();
			mHead = mEnd = new VMap<T, V>::element();
			mEnd->pPrev = 0;
			uSize = 0;
		}
	
		template<class T, class V>
		void VMap<T, V>::_adjust(VMap<T, V>::element* node)
		{
			if (node->pLeft->mKey > node->mKey)
			{
				VMap<T, V>::element *adjustnode = node->pLeft;
				VMap<T, V>::element *breaknode = node->pLeft->pRight;
				adjustnode->pRight = node;
				adjustnode->pPrev = node->pPrev;
				node->pPrev = adjustnode;
				node->pLeft = breaknode;
			}

			else if (node->pRight->mKey < node->mKey)
			{
				VMap<T, V>::element *adjustnode = node->pRight;
				VMap<T, V>::element *breaknode = node->pright->pLeft;
				adjustnode->pLeft = node;
				adjustnode->pPrev = node->pPrev;
				node->pPrev = adjustnode;
				node->pRight = breaknode;
			}
		}

		template<class T, class V>
		VMapIterator<VMap<T, V>::element> VMap<T, V>::insert(Pair &p)
		{
			VMap<T, V>::element *newNode = new VMap<T, V>::element(key, value);
			newNode->pLeft = 0;
			newNode->pRight = 0;
			newNode->pprev = 0;
			newNode->priority = getPriority();
			VMap<T, V>::element* res = _insert(newNode, mHead);
			return VMapIterator<res>;
		}

		template<class T, class V>
		VMapIterator<T, V> VMap<T,V>::begin()
		{
			VMapIterator<T, V> iterator(vHead);
			return iterator;
		}

		template<class T, class V>
		VMapIterator<T, V> VMap<T,V>::end()
		{
			VMapIterator<T, V> iterator(vEnd);
			return iterator;
		}

		template<class T, class V>
		bool VMap<T,V>::isEmpty()
		{
			return uSize == 0;
		}

		template<class T, class V>
		int32 VMap<T,V>::_getPriority()
		{
			return m_pRandom->getRandom();
		}


		template<class T, class V>
		V& VMap<T,V>::get(T key)
		{
			VMap<T, V>::element* node(key, T());
			VMapIterator<VMap<T, V>::element> res = _insert(mHead, node);
			return res->mValue;
		}

		template<class T, class V>
		V& VMap<T,V>::operator [](T key)
		{
			return get(key);
		}

		template<class T, class V>
		void VMap<T,V>::clear()
		{
			_clear(mHead);
		}
		template<class T, class V>
		void VMap<T, V>::_clear(VMap<T, V>::element* node)
		{
			if (node)
			{
				_clear(node->pLeft);
				_clear(node->pRight);
				delete node;
			}
		}
		
		template<class T, class V>
		VMap<T,V>::~VMap()
		{
			_clear();
			delete m_pRandom;
		}

		template<class T, class V>
		VMap<T, V>::element* VMap<T, V>::_insert(VMap<T, V>::element *Node, VMap<T, V>::element *root)
		{

			VMap<T, V>::element *res = 0;
			if (root == 0)
			{
				res = Node;
				root = Node;
			}

			else if (Node->mKey < root->mKey)
			{
				if (root->pLeft == 0)
				{
					root->pLeft = Node;
					res = Node;
				}
				else
				{
					res = _insert(Node, root->pLeft);
				}
				_adjust(root);
			}

			else if (Node->mKey > root->mKey)
			{
				if (root->pRight == 0)
				{
					root->pRight = Node;
					res = Node;
				}
				else
					res = _insert(root, Node->pRight);

				_adjust(root);
			}

			else if (Node->mKey == root->mKey)
			{
				delete Node;
				res = root;
			}

			return res;

		}

		template<class T, class V>
		VMap<T, V>::element* VMap<T, V>::_search(VMap<T, V>::element* node, T key)
		{
			if (node)
			{
				if (node->mKey == key)
				{
					return node;
				}

				else if (node->mKey < key)
				{
					return _search(node->pRight, key);
				}
				else
				{
					return _search(node->pLeft, key);
				}
			}

			else
				return mEnd;
		}

    }

}
























