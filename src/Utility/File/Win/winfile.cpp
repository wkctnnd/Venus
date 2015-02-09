#include "winfile.h"
namespace Venus
{
	namespace File
	{
		bool WinFileImp::open(std::string fullpath, FileAcess acess)
		{
			 mFile = CreateFile();
		}

		void WinFileImp::close()
		{
			CloseHandle(mFile);
		}
	}
}