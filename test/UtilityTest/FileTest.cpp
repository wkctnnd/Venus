#include "BaseTest.h"
namespace Venus
{
	namespace Test
	{
		void BaseTest::OnTest(std::function<void(TestInfo&)> showtest)
		{
			for (auto it = m_Tests.begin(); it != m_Tests.end();++it)
			{
				TestInfo info;
				try
				{
					bool8 result = (*it)(info);
					if (info.m_bIsWantException)
					{
						info.m_bIsOK = false;
					}
					else
					{
						info.m_bIsOK = result;
					}
				}
				catch (...)
				{
					if (info.m_bIsWantException)
					{
						info.m_bIsOK = true;
					}
				}

				showtest(info);
			}

			
		}
	}
}