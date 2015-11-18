#ifndef STRINGTEST_H
#define STRINGTEST_H
#include "Container/map.h"
#include "../BaseTest.h"
namespace Venus
{
	namespace Test
	{
		class MapTest:public BaseTest
		{
		public:
			StringTest();
			~StringTest();
		private:
			bool Compare(TestInfo& info);
			bool GetChar(TestInfo& info);
			bool GetLength(TestInfo& info);

		private:
			Utility::VString *m_sTestString1;
			Utility::VString *m_sTestString2;
			Utility::VString *m_sTestString3;
		};
	}
}

#endif // STRINGTEST_H
