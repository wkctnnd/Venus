#include "FileTest.h"
#include "File/file.h"
namespace Venus
{
	namespace Test
	{
		FileTest::FileTest()
		{
			TESTFUN_INIT(FileTest::OpenFile);
			TESTFUN_INIT(FileTest::CloseFile);
			TESTFUN_INIT(FileTest::SynReadFile);
			
			m_pFileManager = Utility::VFileManager::getInstance();
		}

		bool FileTest::OpenFile(TestInfo& info)
		{
			TEST_INIT(info, "open file");
			//bool res = true;
			Utility::VFile *file1 = m_pFileManager->openFile("../../res/test/filetest.txt");
			if (file1)
			{
				return true;
			}
				
			else return false;
			
		}

		bool FileTest::CloseFile(TestInfo& info)
		{
			TEST_INIT(info, "close file");

			Utility::VFile *file1 = m_pFileManager->openFile("../../res/test/filetest.txt");
			return file1->close();
		}

		bool FileTest::SynReadFile(TestInfo& info)
		{
			TEST_INIT(info, "Syn read file");

			Utility::VFile *file1 = m_pFileManager->openFile("../../res/test/filetest.txt");
			size_t size = file1->getFileSize();
			char *buffer = new char[size];
			size_t read = file1->synRead(buffer, size);
			if (read == size)
			{
				return true;
			}
			else return false;
		}
	}
}