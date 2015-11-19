#include "MapTest.h"
namespace Venus
{
	namespace Test
	{
		MapTest::MapTest()
		{
			TESTFUN_INIT(MapTest::CreateMap);
			TESTFUN_INIT(MapTest::AddElement);
			TESTFUN_INIT(MapTest::GetSize);
			TESTFUN_INIT(MapTest::RemoveElement);
			TESTFUN_INIT(MapTest::ClearMap);
			TESTFUN_INIT(MapTest::DeleteMap);
		}

		bool MapTest::CreateMap(TestInfo& info)
		{
			TEST_INIT(info, "createvector");
			m_pStringMap = new Utility::VMap < Utility::Pair < uint32, std::string >> ();
			m_pTestMap = new Utility::VMap<>
			m_pTestPointerMap = new Utility::VMap<test*>();

			if (m_pIntVector&&m_pTestVector&&m_pTestPointerVector)
				return true;
			else return false;

		}

		bool MapTest::AddElement(TestInfo& info)
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

		bool MapTest::GetSize(TestInfo& info)
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

		bool MapTest::DeleteMap(TestInfo& info)
		{
			TEST_INIT(info, "delete vector");
			try
			{
				delete m_pIntVector;
				delete m_pTestVector;
				delete m_pTestPointerVector;
			}
			catch (...)
			{
				return false;
			}

			return true;

		}

		bool MapTest::ClearMap(TestInfo& info)
		{
			TEST_INIT(info, "Clear Vector");

			m_pIntVector->clear();
			m_pTestVector->clear();
			m_pTestPointerVector->clear();


		}

		bool MapTest::RemoveElement(TestInfo& info)
		{
			TEST_INIT(info, "Remove Element");


			return true;

		}
	}
}