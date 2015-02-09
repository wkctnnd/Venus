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
	namespace File
	{
		VFile::VFile()
		{
#if (defined VENUS_WIN32) || (defined VENUS_WIN32)
			implementation = new WinFileImp();
#elif defined VENUS_MAC
			implementation = new MacFileImp();
#endif
			
		}

		bool VFile::open(std::string file, FileAcess acess)
		{
			std::string path;
			std::string name;
			std::string ext;

			spliteFilePath(file, path, name ,ext);
			if (path.empty())
			{
				if (ext.empty())
				{
					path = mDefaultpath;
				}
				else if(ext.compare("mesh"))
				{
					
				}
				else if(ext.compare("hlsl"))
				{
				
				}
				else
				{
					assert(0);
					//unknow ext
				}
			}

			assert(name.empty()==0);
			std::string fullpath = path+name+ext;
			implementation->open(fullpath, acess);
		}

		void VFile::close()
		{
			implementation->close();
		}

		void VFile::spliteFilePath(std:: string filepath, std::string& path, std::string& name, std::string& ext)
		{
			
		}
	}
}