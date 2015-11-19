#ifndef MAPTEST_H
#define MAPTEST_H
#include "Container/map.h"
#include "../BaseTest.h"
namespace Venus
{
	namespace Test
	{

		struct test
		{
			test(){ param0 = 1; param1 = 2; }
			f32 param0;
			bool param1;
		};

		class MapTest :public BaseTest
		{
		public:
			MapTest();
			~MapTest();
		private:
			bool CreateMap(TestInfo& info);
			bool AddElement(TestInfo& info);
			bool GetSize(TestInfo& info);
			bool DeleteMap(TestInfo& info);
			bool ClearMap(TestInfo& info);
			bool RemoveElement(TestInfo& info);
		private:

			Utility::VMap<int32, std::string> *m_pStringMap;
			Utility::VMap<std::string, test> *m_pTestMap;
			Utility::VMap<f32, test*> *m_pTestPointerMap;
		};
	}
}

#endif // MAPTEST_H
