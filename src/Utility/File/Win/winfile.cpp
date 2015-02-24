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

		}

        uint32 WinFileImp::synRead(void* p, uint32 size)
        {
            uint32 written;
            ReadFile(hFile, p, size, (LPDWORD)(&written), 0);
            return written;
        }

		void WinFileImp::close()
		{
			CloseHandle(hFile);
		}

        void WinFileImp::seekPosition(int64 offset, VFile::StartPosition pos)
        {
            SetFilePointer();
        }
	}
}