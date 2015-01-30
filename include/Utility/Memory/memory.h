#include"../type.h"
#include<stdlib.h>
#include<Assert.h>
#define ALIGN16 16
#define ALIGN8 8
#define ALIGN4 4
namespace Venus
{
	namespace Memory
	{

		class Allocator
		{
		public:
			void *allocate(unsigned int size);
			void dellocate();

			void *alligned()
			{
				
			}
		};

		

		class DynamicPoolAllocator:public Allocator
		{
		private:
			struct freeblock
			{
				freeblock* mNext;
				uint32 msize;
			};

			void *mFreeList;
			
		public:
			DynamicPoolAllocator(uint32 size = 8)
			{
				if(size > 8)
					mFreeList = (void*) malloc (sizeof(size));
				freeblock *free = (freeblock *) (mFreeList);
				free->mNext = NULL;
				free->msize = size;
			}
			void* allocate(uint32 size , uint32 allignment = ALIGN4)
			{
				uint32 expandsize = size + allignment;

				void * allocateblock = NULL;
				freeblock* p = (freeblock*)mFreeList;
				freeblock* q = NULL;
				while (p)
				{
					if(p->msize > expandsize)
					{
						if(q == NULL)
							mFreeList = p->mNext;
						else
							q ->mNext = p -> mNext;

						if(p->msize - expandsize >= 8)
						{

							break;
						}

						else
						{

							break;
						}
					}

					p = p->mNext;
					q = p;
				}

				assert(allocateblock != NULL);
				size_t misalign = (size_t)allocateblock;
				size_t mask = (size_t)allignment - 1;
				uint32 adjust = misalign & mask;
				allocateblock = (void* )(misalign + adjust);

				return allocateblock;
			}

		};

		//block size is byte unit
		template <int blocksize>
		class FixBlockAllocator:public Allocator
		{ 
			void *header;
			unsigned int blockcount;


		};



		void* Venus_new( int size, Allocator *allocator = 0);
		void Venus_delete(void *pointer);
		
	}
}
