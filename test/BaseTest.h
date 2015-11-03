#ifndef BASETEST_H
#define BASETEST_H
#include <vector>
#include <functional>
#include "type.h"
#include <string>
#include <sstream>
/*oss << "position:" << __FILE__ << "-" << __LINE__ << "-" << __FUNCTION__ << endl; \*/
#define TEST_INIT(info, sub) {\
	char oss[1000]; \
	sprintf(oss, "position:%s-%d-%s\n", __FILE__, __LINE__, __FUNCTION__);\
	info.m_sName = __FUNCTION__;/*oss.str();*/\
}\
	info.m_sSubName = sub; \
	info.m_bIsOK = ""; \
	info.m_bIsOK = true;
#define TESTFUN_INIT(name) m_Tests.push_back(std::bind(&name, this, std::tr1::placeholders::_1))

namespace Venus
{
	namespace Test
	{
		class TestInfo
		{
		public:
			TestInfo()
			{
				m_ulevel = 1;
				m_sName = "";
				m_sSubName = "";
				m_bIsOK = false;
				m_bIsWantException = false;
				m_sRemark = "";
			}

		public:
			uint32  m_ulevel;
			std::string m_sName;
			std::string m_sSubName;
			bool8  m_bIsOK;
			bool8  m_bIsWantException;
			std::string m_sRemark;
			
		};


		class BaseTest
		{
		public:
			typedef std::function<bool(TestInfo&)>  TestFun;

			void OnTest(std::function<void(TestInfo&)>);
		protected:
			std::vector<TestFun>  m_Tests;

		};
    }
}
#endif
