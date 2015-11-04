#include "winfile.h"
namespace Venus
{
	namespace Utility
	{
        const uint32 accessmode[3]={GENERIC_READ, GENERIC_WRITE, GENERIC_READ|GENERIC_WRITE};
        const uint32 createmode[5]={CREATE_NEW,CREATE_ALWAYS,OPEN_EXISTING,OPEN_ALWAYS,TRUNCATE_EXISTING};


		bool WinFileImp::open(VString &file, FileAcess access, FileOpenMode mode, bool shared, bool asyn)
		{
            DWORD sharemode = 0;
            if (shared)
              sharemode = FILE_SHARE_DELETE|FILE_SHARE_READ|FILE_SHARE_WRITE;
			hFile = CreateFile(file.getChar(),accessmode[access],sharemode, 0, createmode[mode], 0, 0 );
			if (hFile==INVALID_HANDLE_VALUE)
			{
				return false;
			}
			else return true;
		}

		size_t WinFileImp::synRead(void* p, uint32 size)
        {
			size_t written;
            ReadFile(hFile, p, size, (LPDWORD)(&written), 0);
            return written;
        }

		size_t WinFileImp::getFileSize()
		{
			return GetFileSize(hFile, NULL);
		}

		bool WinFileImp::close()
		{
			return CloseHandle(hFile);
		}

        void WinFileImp::seekPosition(int64 offset, VFile::StartPosition pos)
        {
           // SetFilePointer();
        }

		void WinFileImp::asynRead()
		{

		}
	}
}