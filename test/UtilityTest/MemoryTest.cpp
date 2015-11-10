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
			//bool res = true;
			Utility::Allocator *allocator = Utility::SimpleAllocator::getInstance();
			m_pInt = allocator->allocateNew<int>();
			m_pString = allocator->allocateNew<std::string>();
			m_pTestA = allocator->allocateNew<testA>(1,3.0,std::string("c"));

			m_pIntArray = allocator
			return true;
		}

		bool MemoryTest::SimpleDeleteClass(TestInfo& info)
		{
			TEST_INIT(info, "get string length");

			if (m_sTestString1->length()==6)
			{
				return true;
			}
			else return false;
		}

		bool MemoryTest::GetChar(TestInfo& info)
		{
			TEST_INIT(info, "get char");

			const char* a = m_sTestString1->getChar();
			if (strcmp(a, "Wangkc"))
				return true;
			else return false;
			

		}
	}
}