#include "VectorTest.h"
namespace Venus
{
	namespace Test
	{
		VectorTest::VectorTest()
		{
			TESTFUN_INIT(VectorTest::CreateVector);
			TESTFUN_INIT(VectorTest::DeleteVector);
			TESTFUN_INIT(VectorTest::ClearVector);
			TESTFUN_INIT(VectorTest::RemoveElement);
		}

		bool VectorTest::CreateVector(TestInfo& info)
		{
			TEST_INIT(info, "createvector");
			m_pIntVector = new Utility::VVector<int32>();
			m_pTestVector = new Utility::VVector<test>();
			m_pTestPointerVector = new Utility::VVector<test*>();

			if (m_pIntVector&&m_pTestVector&&m_pTestPointerVector)
				return true;
			else return false;
			
		}

		bool VectorTest::AddElement(TestInfo& info)
		{
			int a = 3;
			m_pIntVector->push_back(1);
			m_pIntVector->push_back(a);
			for (int32 i = 2; i < 10; i++)
			{
				m_pIntVector->push_back(i);
			}

			m_pTestVector->resize(20);
			for (int32 i = 0; i < 20; i++)
			{
			}
		}

		bool VectorTest::DeleteVector(TestInfo& info)
		{
			TEST_INIT(info, "get string length");

		
		}

		bool VectorTest::ClearVector(TestInfo& info)
		{
			TEST_INIT(info, "get char");

			
			

		}

		bool VectorTest::RemoveElement(TestInfo& info)
		{
			TEST_INIT(info, "get char");

			


		}
	}
}