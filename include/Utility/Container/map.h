#ifndef MAP_H
#define  MAP_H
#include "type.h"
#include "iterator.h"
namespace Venus
{
    namespace Utility
    {
		class BaseRandom;
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

			struct  element
            {
                element(key, value):mKey(key),mValue(value),vLeft(0),vRight(0){}
                element(){}
                T mKey;
                V mValue;
                int priority;

				element *pLeft;
				element *pRight;
				element *pPrev;
            };
            typedef VMapIterator Iterator;

            VMap();
            VMap(size_t size);
			~VMap();
            VMapIterator<element> insert(Pair &p);
            void delete(T t);
            void clear();

            V& get(T key);
            VMapIterator begin();
           VMapIterator end();
           bool isEmpty();
		 

            V& operator [](T t);
        private:
            
            element* mHead;
            element* mEnd;
            unsigned int uSize;

		private:
			void _adjust(element* node);
			
			int32 _getPriority();
			element* _search(element* node, T key);
			void _clear(element *node);
			element* _insert(element *Node, element *root);

			BaseRandom* m_pRandom;
		};


    }
}

#endif