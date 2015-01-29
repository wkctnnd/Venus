namespace Venus
{
	namespace Memory
	{

		class Allocator
		{
		public:
			void *allocate();
			void dellocate();

		};

		class DynamicPoolAllocator:public Allocator
		{
		private:
			void *buffer;
			unsigned int buffersize;
		public:
			DynamicPoolAllocator();
			void* allocate();

		};

		template <class blocktype>
		class BlockListAllocator:public Allocator
		{ 
			
		};


		void* Venus_new( int size, Allocator *allocator = 0);
		void Venus_delete(void *pointer);
		
	}
}
