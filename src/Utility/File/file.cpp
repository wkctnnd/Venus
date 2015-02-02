#include "crossplatform.h"
#include "File/file.h"

#if (defined VENUS_WIN32) || (defined VENUS_WIN32)
#include "Win/winfile.h"
#elif defined VENUS_MAC
#include "Mac/macfile.h"
#endif

namespace Venus
{
	namespace File
	{
		VFile::VFile()
		{
#if (defined VENUS_WIN32) || (defined VENUS_WIN32)
			implementation = new WinFileImp();
#elif defined VENUS_MAC
			
#endif
			
		}

		bool VFile::open()
		{
			implementation->open();

		}

		void VFile::close()
		{
		
		}
	}
}