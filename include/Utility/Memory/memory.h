#include"../type.h"
#define ALIGN16 16
#define ALIGN8 8
#define ALIGN4 4
namespace Venus
{
	namespace Utility
	{

		class Allocator
		{
		public:
			void *allocate(uint32 size, uint8 alignment);
			void dellocate(void* p, uint32 size, uint8 alignment);

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
			DynamicPoolAllocator(uint32 size = 8);

			void* allocate(uint32 size , uint8 allignment);

			void defragment();

			void dellocate(void* pointer, uint32 size, uint8 alignment);

		};





		//block size is byte unit
		template <int blocksize>
		class FixBlockAllocator:public Allocator
		{ 
			void *header;
			unsigned int blockcount;


		};



		void* Venus_new( uint32 size, Allocator *allocator = 0, uint8 alignment = ALIGN4);
		void Venus_delete(void *pointer, uint32 size, Allocator *allocator = 0, uint8 alignment = ALIGN4);
		
	}
}
