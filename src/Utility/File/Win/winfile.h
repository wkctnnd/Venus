#ifndef WINFILE_H
#define WINFILE_H
#include "File/file.h"
#include <windows.h>
#include "utilenum.h"

namespace Venus
{
	namespace Utility
	{

        //https://msdn.microsoft.com/en-us/library/aa363858(v=vs.85).aspx
		class WinFileImp: public FileImp
		{
		public:

			bool open(VString &file, FileAcess acess, FileOpenMode mode, bool shared, bool asyn);
			bool close();
			size_t getFileSize();
			size_t synRead(void* p, uint32 size);
			void asynRead();
			void seekPosition(int64 offset, VFile::StartPosition pos);
		private:
			HANDLE hFile;
           
		};
    }
}

#endif