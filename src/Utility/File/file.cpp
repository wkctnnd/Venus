#include "crossplatform.h"
#include "File/file.h"
#include <assert.h>

#if (defined VENUS_WIN32) || (defined VENUS_WIN32)
#include "Win/winfile.h"
#elif defined VENUS_MAC
#include "Mac/macfile.h"
#endif

namespace Venus
{
	namespace Utility
	{
		VFile::VFile(VString& file, FileAcess acess, FileOpenMode mode, bool shared, bool asyn)
		{
#if (defined VENUS_WIN32) || (defined VENUS_WIN32)
			implementation = new WinFileImp();
#elif defined VENUS_MAC
			implementation = new MacFileImp();
#endif
			open(file, access, mode, shared, asyn);
		}

		bool VFile::open(VString &file, FileAcess access, FileOpenMode mode, bool shared, bool asyn)
		{
			implementation->open(file, access, mode, shared, asyn);
		}

        uint32 VFile::synRead(void* p, uint32 size)
        {
            implementation->synRead(p, size);
        }
		void VFile::close()
		{
			implementation->close();
		}

        void VFile::seekPosition(int64 offset, StartPosition pos)
        {
            implementation->seekPosition(offset, pos);
        }
	}
}