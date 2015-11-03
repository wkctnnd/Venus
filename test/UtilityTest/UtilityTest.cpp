#include "UtilityTest.h"
#include "StringTest.h"
namespace Venus
{
	namespace Test
	{
		void showTestRes(TestInfo &info)
		{
			
		}
		void main()
		{
			StringTest test;
			test.OnTest(showTestRes);
		}
	}
}
