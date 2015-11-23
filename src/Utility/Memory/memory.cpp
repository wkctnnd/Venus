#include "Memory/memory.h"
//#include<stdlib.h>
//#include "assert.h"
//#define specialnew(buffer, classtype, param) new (buffer) classtype param
namespace Venus
{
	namespace Utility
	{
//		template<class T, class ... param>
//		T* Allocator::allocateNew(param... t)
//		{
//			void* p = allocate(sizeof(T), _ALIGN_OF(T));
//			VAssert(p != NULL, "bad allocate");
//			return new(p) T(t);
//		}
//
//		template<class T>
//		T* Allocator::allocateNew(T& t)
//		{
//			void *p = allocate(sizeof(T), _ALIGN_OF(T));
//			VAssert(p != NULL, "bad allocate");
//			return new (p) T(t);
//		}
//
//		template<class T>
//		T* Allocator::allocateNewArray(size_t num)
//		{
//			size_t head = sizeof(size_t) / sizeof(T) + 1;
//			void* p = allocate((sizeof(T) + head) * num, _ALIGN_OF(T));
//			T* mem = (T*)(p) + head;
//			*((size_t*)mem - 1) = num;
//			VAssert(p != NULL, "bad allocate");
//			for (size_t i = 0; i < num; i++)
//			{
//				new(mem) T;
//				mem += sizeof(T);
//			}
//			return mem;
//		}
//
//
//		template<class T>
//		void Allocator::dellocateDelete(void* p)
//		{
//			(T*)p->~T();
//			dellocate(p);
//		}
//
//		template<class T>
//		void Allocator::dellocateDeleteArray(void* p)
//		{
//			size_t num = *((size_t*)(p)-1);
//			for(size_t i = 0; i < num; i++)
//				(T*)p -> ~T();
//			size_t head = sizeof(size_t) / sizeof(T) + 1;
//			T* mem = (T*)p -  head;
//			dellocate(p);
//		}
//
//
//	/*	void* StackAllocator::allocate(size_t size, uint8 alignment)
//		{
//
//		}
//
//		void StackAllocator::dellocate(void* p)
//		{
//
//		}*/
//
//		//////////////////////////////////////////////////////////////////////////
//		//simpleallocator
//		//////////////////////////////////////////////////////////////////////////
//		template<class T, class ... param>
//		T* SimpleAllocator::allocateNew(param... t)
//		{
//			T *p = new T(p);
//			return p;
//		}
//
//		template<class T>
//		T* SimpleAllocator::allocateNew(T& t)
//		{
//			T *p = new T(t);
//			VAssert(p != NULL, "bad allocate");
//			return p;
//		}
//
//		template<class T>
//		void SimpleAllocator::dellocateDelete(void* p)
//		{
//			delete p;
//		}
//
//		template<class T>
//		T* SimpleAllocator::allocateNewArray(size_t num)
//		{
//			T **p = new T[num];
//			VAssert(p != NULL, "bad allocate");
//			return p;
//		}
//
//		template<class T>
//		void SimpleAllocator::dellocateDeleteArray(void* p)
//		{
//			delete[] p;
//		}
//
//		//////////////////////////////////////////////////////////////////////////
//		//linearallocator
//		//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//
//
//
//		//////////////////////////////////////////////////////////////////////////
//		//dynamicpool
//		//////////////////////////////////////////////////////////////////////////
//		//DynamicPoolAllocator::DynamicPoolAllocator(uint32 size = 8)
//		//{
//		//	if(size > 8)
//		//		mFreeList = (void*) malloc (sizeof(size));
//		//	freeblock *free = (freeblock *) (mFreeList);
//		//	free->mNext = NULL;
//		//	free->msize = size;
//		//}
//
//
//		//void* DynamicPoolAllocator::allocate(uint32 size , uint8 allignment)
//		//{
//		//	uint32 expandsize = size + allignment;
//
//		//	void * allocateblock = NULL;
//		//	freeblock* p = (freeblock*)mFreeList;
//		//	freeblock* q = NULL;
//		//	while (p)
//		//	{
//		//		uint32 leftsize = p->msize - expandsize;
//		//		if(leftsize > 0)
//		//		{	
//		//			if(leftsize >= 8)
//		//			{
//		//				freeblock *splitblock = p + expandsize;
//		//				splitblock->mNext = p->mNext;
//		//				splitblock->msize = leftsize;
//		//				p->mNext = splitblock;
//		//			}
//
//		//			if(q == NULL)
//		//				mFreeList = p->mNext;
//		//			else
//		//				q ->mNext = p -> mNext;
//
//		//			break;
//		//		}
//
//		//		p = p->mNext;
//		//		q = p;
//		//	}
//
//		//	VAssert(allocateblock != NULL, "");
//		//	size_t misalign = (size_t)allocateblock;
//		//	size_t mask = (size_t)allignment - 1;
//		//	uint32 adjust = misalign & mask;
//		//	uint8* block = (uint8* )(misalign + adjust);
//
//		//	block[-1] = adjust;
//		//	return allocateblock;
//		//}
//
//
//		//void DynamicPoolAllocator::defragment()
//		//{
//
//		//}
//
//		//void DynamicPoolAllocator::dellocate(void* pointer)
//		//{
//		//	//VAssert(pointer != NULL, "");
//		//	//uint8 adjust = ((uint8*)pointer)[-1];
//		//	//freeblock* block = (freeblock *)((size_t)pointer - adjust);
//		//	//block->mNext = (freeblock* )mFreeList;
//		//	//block->msize = size + alignment;
//		//	//mFreeList = block;
//		//}
//
//
//
//
//
//
//#ifdef CUSTOMALLOCATOR
//		void* Venus_new( uint32 size, Allocator *allocator = 0, uint8 alignment = ALIGN4)
//		{
//			allocator->allocate(size, alignment);
//		}
//
//		void Venus_delete(void *pointer)
//		{
//			allocator->dellocate(pointer);
//		}
//
//#else
//template<class T>
//		void* Venus_new(uint32 size, Allocator *allocator, uint8 alignment)
//		{
//			Allocator *myallocator = SimpleAllocator::getInstance();
//			myallocator<T>->allocate(size, alignment);
//		}
//		template<class T>
//		void Venus_delete(void *pointer)
//		{
//			Allocator *allocator = SimpleAllocator::getInstance();
//			allocator<T>->dellocate(pointer);
//		}
//#endif // CUSTOMALLOCATOR
		
		

		
	}
}