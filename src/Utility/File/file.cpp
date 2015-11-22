#include "crossplatform.h"
#include "File/file.h"
#include "assert.h"

#if (defined VENUS_WIN32) || (defined VENUS_WIN64)
#include "Win/winfile.h"
#elif defined VENUS_MAC
#include "Mac/macfile.h"
#endif

namespace Venus
{
	namespace Utility
	{
		VFile::VFile(VString& file, FileAcess access, FileOpenMode mode, bool shared, bool asyn)
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
			return implementation->open(file, access, mode, shared, asyn);
		}

		size_t VFile::getFileSize()
		{
			return implementation->getFileSize();
		}

		size_t VFile::synRead(void* p, uint32 size)
        {
            return implementation->synRead(p, size);
        }
		bool VFile::close()
		{
			return implementation->close();
		}

        void VFile::seekPosition(int64 offset, StartPosition pos)
        {
            implementation->seekPosition(offset, pos);
        }
	}
}