#include "StringTest.h"
namespace Venus
{
	namespace Test
	{
		StringTest::StringTest()
		{
			TESTFUN_INIT(StringTest::Compare);
			TESTFUN_INIT(StringTest::GetLength);
			TESTFUN_INIT(StringTest::GetChar);	
			m_sTestString1 = new Utility::VString("Wangkc");
			m_sTestString2 = new Utility::VString(*m_sTestString1);
			m_sTestString3 = new Utility::VString();
			m_sTestString3->assign("WANGKC");
		}

		StringTest::~StringTest()
		{
		}

		bool StringTest::Compare(TestInfo& info)
		{
			TEST_INIT(info, "compare");
			//bool res = true;
			if (m_sTestString1->compare(*m_sTestString2) != 0)
			{
				return false;
			}

			if (m_sTestString1->compare(*m_sTestString3) > 0)
			{
				return false;
			}

			return true;
		}

		bool StringTest::GetLength(TestInfo& info)
		{
			TEST_INIT(info, "get string length");

			if (m_sTestString1->length()==6)
			{
				return true;
			}
			else return false;
		}

		bool StringTest::GetChar(TestInfo& info)
		{
			TEST_INIT(info, "get char");

			const char* a = m_sTestString1->getChar();
			if (strcmp(a, "Wangkc"))
				return true;
			else return false;
			

		}
	}
}