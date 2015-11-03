#include "File/file.h"
#include "File/filemanager.h"
#include "assert.h"

namespace Venus
{
	namespace Utility
	{

		VFileManager* VFileManager::getInstance()
		{
			if (!m_pInstrance)
			{
				m_pInstrance = new VFileManager();
			}
			return m_pInstrance;
		}
		VFileManager::VFileManager()
		{
			
		}

		VFile* VFileManager::openFile(VString file, FileAcess acess, FileOpenMode, bool shared, bool asyn)
		{
		/*	std::string path;
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
					VAssert(name.empty()==0, "unknow file extension");
				}
			}*/

			/*VAssert(name.empty()==0, "file name wrong");
			std::string fullpath = path+name+ext;*/

		}

		void VFile::close()
		{
			implementation->close();
		}

		void VFile::spliteFilePath(VString filepath, VString& path, VString& name, VString& ext)
		{
			
		}
	}
}