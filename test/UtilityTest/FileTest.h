#ifndef FIELTEST_H
#define FILETEST_H
#include "File/filemanager.h"
#include "../BaseTest.h"
namespace Venus
{
	namespace Test
	{
		class FileTest:public BaseTest
		{
		public:
			FileTest();
			~FileTest();
		private:
			bool OpenFile(TestInfo& info);
			bool CloseFile(TestInfo& info);
			bool SynReadFile(TestInfo& info);

		private:
			Utility::VFileManager *m_pFileManager;
		};
	}
}

#endif // FIELTEST_H
