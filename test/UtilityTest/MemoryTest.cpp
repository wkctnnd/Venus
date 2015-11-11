#include "MemoryTest.h"
#include "Memory/memory.h"
namespace Venus
{
	namespace Test
	{
		MemoryTest::MemoryTest()
		{
			TESTFUN_INIT(MemoryTest::SimpleNewClass);
			TESTFUN_INIT(MemoryTest::SimpleDeleteClass);

		}

		bool MemoryTest::SimpleNewClass(TestInfo& info)
		{
			TEST_INIT(info, "simple allocator new");

			bool res = true;
			Utility::Allocator *allocator = Utility::SimpleAllocator::getInstance();	
			try
			{
				m_pInt = allocator->allocateNew<int>();
				if (!m_pInt)  res = false;
				m_pString = allocator->allocateNew<std::string>();
				if (!m_pString)  res = false;
				m_pTestA = allocator->allocateNew<testA>(1, 3.0, std::string("c"));
				if (!m_pTestA)  res = false;
				m_pIntArray = allocator->allocateNewArray<int>(10);
				if (!m_pIntArray)  res = false;
				m_pTestArray = allocator->allocateNewArray<testA>(10);
				if (!m_pTestArray)  res = false;
				m_pStringArray = allocator->allocateNewArray<std::string>(10);
				if (!m_pStringArray)  res = false;
			}
			catch (...)
			{
				res = false;
			}
			return res;
		}

		bool MemoryTest::SimpleDeleteClass(TestInfo& info)
		{
			TEST_INIT(info, "simple allocator delete");
			Utility::Allocator *allocator = Utility::SimpleAllocator::getInstance();
			try
			{
				allocator->dellocateDelete<int>(m_pInt);
				allocator->dellocateDelete<testA>(m_pTestA);
				allocator->dellocateDelete<std::string>(m_pString);

				allocator->dellocateDeleteArray<int>(m_pIntArray);
				allocator->dellocateDeleteArray<testA>(m_pTestA);
				allocator->dellocateDeleteArray<std::string>(m_pString);
			}
			catch (...)
			{
				return false;
			}
			
			return true;
		}
	}
}