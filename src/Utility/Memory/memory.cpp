#include "Memory/memory.h"
#include<stdlib.h>
#include<Assert.h>
namespace Venus
{
	namespace Utility
	{
			DynamicPoolAllocator::DynamicPoolAllocator(uint32 size = 8)
			{
				if(size > 8)
					mFreeList = (void*) malloc (sizeof(size));
				freeblock *free = (freeblock *) (mFreeList);
				free->mNext = NULL;
				free->msize = size;
			}


			void* DynamicPoolAllocator::allocate(uint32 size , uint8 allignment)
			{
				uint32 expandsize = size + allignment;

				void * allocateblock = NULL;
				freeblock* p = (freeblock*)mFreeList;
				freeblock* q = NULL;
				while (p)
				{
					uint32 leftsize = p->msize - expandsize;
					if(leftsize > 0)
					{	
						if(leftsize >= 8)
						{
							freeblock *splitblock = p + expandsize;
							splitblock->mNext = p->mNext;
							splitblock->msize = leftsize;
							p->mNext = splitblock;
						}

						if(q == NULL)
							mFreeList = p->mNext;
						else
							q ->mNext = p -> mNext;

						break;
					}

					p = p->mNext;
					q = p;
				}

				assert(allocateblock != NULL);
				size_t misalign = (size_t)allocateblock;
				size_t mask = (size_t)allignment - 1;
				uint32 adjust = misalign & mask;
				uint8* block = (uint8* )(misalign + adjust);

				block[-1] = adjust;
				return allocateblock;
			}


			void DynamicPoolAllocator::defragment()
			{
			
			}

			void DynamicPoolAllocator::dellocate(void* pointer, uint32 size, uint8 alignment)
			{
				assert(pointer != NULL);
				uint8 adjust = ((uint8*)pointer)[-1];
				freeblock* block = (freeblock *)((size_t)pointer - adjust);
				block->mNext = (freeblock* )mFreeList;
				block->msize = size + alignment;
				mFreeList = block;
			}

			void* Venus_new( uint32 size, Allocator *allocator = 0, uint8 alignment = ALIGN4)
			{
				allocator->allocate(size, alignment);
			}

			void Venus_delete(void *pointer, uint32 size, Allocator *allocator = 0, uint8 alignment = ALIGN4)
			{
				allocator->dellocate(pointer, size, alignment);
			}
	}
}