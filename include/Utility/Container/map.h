#ifndef MAP_H
#define  MAP_H
#include "type.h"
#include "iterator.h"
namespace Venus
{
    namespace Utility
    {
		class BaseRandom;
     
		template<typename T, typename V>
         class Pair
         {
         public:

             Pair(T t, V v){mFirst = t; mSecond = v;}
            T mFirst;
            V mSecond;
         };

		 template<class T,class V>
		 struct  element
		 {
			 element(T key, V value) :mKey(key), mValue(value), vLeft(0), vRight(0){}
			 element(){}
			 T mKey;
			 V mValue;
			 int priority;

			 element *pLeft;
			 element *pRight;
			 element *pPrev;
		 };

		 template<class T,class V>
		 class VMapIterator :public Bidirection_Iterator<T>
		 {
			 VMapIterator(element<T, V>*);


		 private:
			 element<T,V>* mPointer;
			 // size_t sIndex;
		 };
     
		 template<typename T, typename V>
        class VMap
        {
        public:
		
			
            typedef VMapIterator<T,V> Iterator;

            VMap();
            VMap(size_t size);
			~VMap();
			Iterator insert(Pair<T, V> &p);
            void remove(T t);
            void clear();

            V& get(T key);
			Iterator begin();
			Iterator end();
           bool isEmpty();
		 

            V& operator [](T t);
        private:
            
            element<T,V>* mHead;
			element<T, V>* mEnd;
            unsigned int uSize;

		private:
			void _adjust(element<T, V>* node);
			
			int32 _getPriority();
			element<T, V>* _search(element<T, V>* node, T key);
			void _clear(element<T,V> *node);
			element<T, V>* _insert(element<T, V> *Node, element<T, V> *root);

			BaseRandom* m_pRandom;
		};


    }
}

#endif