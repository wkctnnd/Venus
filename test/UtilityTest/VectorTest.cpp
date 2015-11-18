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
			TEST_INIT(info, "add elements");
			try
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
					test t;
					(*m_pTestVector)[i] = t;
				}

				m_pTestPointerVector->reserve(30);
				for (int32 i = 0; i < 20; i++)
				{
					test* t = new test();
					(*m_pTestPointerVector)[i] = t;
				}
			}
			catch (...)
			{
				return false;
			}
			return true;
			
		}

		bool VectorTest::GetSizeAndCapacity(TestInfo& info)
		{
			TEST_INIT(info, "get vector size and capacity");
			if (m_pIntVector->getSize() == 10 && m_pIntVector->getCapacity() == 16)
			{
				if (m_pTestVector->getSize() == 20 && m_pTestVector->getCapacity() == 20)
				{
					if (m_pTestPointerVector->getSize() == 20 && m_pTestPointerVector->getCapacity() == 30)
					{
						return true;
					}
				}
			}
			return false;
		}

		bool VectorTest::DeleteVector(TestInfo& info)
		{
			TEST_INIT(info, "delete vector");
			delete m_pIntVector;
			delete m_pTestVector;
			delete m_pTestPointerVector;
		
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