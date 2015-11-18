#ifndef STRINGTEST_H
#define STRINGTEST_H
#include "Container/vector.h"
#include "../BaseTest.h"
namespace Venus
{
	namespace Test
	{

		struct test
		{
			test(){ param0 = 1; param1 = 2; }
			f32 param0;
			bool param1;
		};
		class VectorTest:public BaseTest
		{
		public:
			VectorTest();
			~VectorTest();
		private:
			bool CreateVector(TestInfo& info);
			bool AddElement(TestInfo& info);
			bool GetSizeAndCapacity(TestInfo& info);
			bool DeleteVector(TestInfo& info);
			bool ClearVector(TestInfo& info);
			bool RemoveElement(TestInfo& info);
		private:
			
			Utility::VVector<int32> *m_pIntVector;
			Utility::VVector<test> *m_pTestVector;
			Utility::VVector<test*> *m_pTestPointerVector;
		};
	}
}

#endif // STRINGTEST_H
