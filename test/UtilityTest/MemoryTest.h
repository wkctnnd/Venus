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

			int *m_pIntArray[10];
			testA *m_pTestArray[10];
			std::string *m_pStringArray[10];
		};
	}
}

#endif // STRINGTEST_H
