#ifndef MEMORYTEST_H
#define MEMORYTEST_H
#include <string>
#include "../BaseTest.h"
namespace Venus
{
	namespace Test
	{
		class testA
		{
		public:
			testA(int a,double b,std::string c)
			{
				m_iA = a;
				m_dB = b;
				m_sC = c;
			}
			testA(){}
			~testA(){}
			int m_iA;
			double m_dB;
			std::string m_sC;
		};
		class MemoryTest:public BaseTest
		{
		public:
			MemoryTest();
			~MemoryTest();
		private:
			bool SimpleNewClass(TestInfo& info);
			bool SimpleDeleteClass(TestInfo& info);

		private:
			int *m_pInt;
			testA *m_pTestA;
			std::string *m_pString;

			int *m_pIntArray;
			testA *m_pTestArray;
			std::string *m_pStringArray;
		};
	}
}

#endif // STRINGTEST_H
