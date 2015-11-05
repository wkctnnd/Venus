#include"../type.h"
#define ALIGN16 16
#define ALIGN8 8
#define ALIGN4 4
namespace Venus
{
	namespace Utility
	{
		//http://blog.csdn.net/amwihihc/article/details/7481656
         //http://blog.csdn.net/amwihihc/article/details/8813565
		class Allocator
		{
		public:
			virtual void *allocate(size_t size, uint8 alignment) = 0;
			virtual void dellocate(void* p) = 0;

            template<class T>
            virtual T* allocateNew();

			template<class T>
			virtual T* allocateNew();

            template<class T>
			virtual T* allocateNew(T&);

            template<class T>
			virtual void dellocateDelete(void* p);

            template<class T>
			virtual T* allocateNewArray(size_t num);

            template<class T>
			virtual void dellocateDeleteArray(void* p);
		};

		class SimpleAllocator
		{
		public:
			void *allocate(size_t size, uint8 alignment){}
			void dellocate(void* p){}

			template<class T>
			virtual T* allocateNew();

			template<class T>
			virtual T* allocateNew(T&);

			template<class T>
			virtual void dellocateDelete(void* p);

			template<class T>
			virtual T* allocateNewArray(size_t num);

			template<class T>
			virtual void dellocateDeleteArray(void* p);
		};
		


        class StackAllocator:public Allocator
        {
        public:
            struct Header
            {
                size_t sPrePosition;
                size_t sLength;
            };
            StackAllocator(size_t size);
            void *allocate(size_t size, uint8 alignment);
            void dellocate(void* p);
        private:
            size_t sCurPosition;
            size_t sLength;
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
			DynamicPoolAllocator(size_t size = 8);

			void* allocate(uint32 size , uint8 allignment);

			void defragment();

			void dellocate(void* p);

		};





		//block size is byte unit
        //best for list not support for random access
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
