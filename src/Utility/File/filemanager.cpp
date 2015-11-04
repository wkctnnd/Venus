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

		VFile* VFileManager::openFile(VString filepath, FileAcess acess, FileOpenMode mode, bool shared, bool asyn)
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
			VFile *file = new VFile(filepath, acess, mode, shared, asyn);
			return file;
		}

	}
}