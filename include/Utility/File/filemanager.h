#ifndef FILEMANAGER_H
#define FILEMANAGER_H

//what is file manager used for?
//1. find right directory according to file name
//2. if open a existing file, just return the pointer
//3. take care of all opened file, track their life time
//4. like a file factory
//5. to be supplmented.

#include "Container/string.h"
#include "utilenum.h"

namespace Venus
{
	namespace Utility
	{
        class VFile;

		class VFileManager
		{
		public:
			
			static VFileManager* getInstance();

            //create or open file
			VFile* openFile(VString file, FileAcess acess, FileOpenMode, bool shared = true, bool asyn = false);
            void   unLoadFiles();
		private:
			//void spliteFilePath(VString, VString&, VString&,  &);
			//VString mDefaultpath;
   //         VString mMeshPath;
   //         VString mShaderPath;
   //         VString mAudioPath;
			static VFileManager *m_pInstrance;
			
		private:
			VFileManager();
			~VFileManager();
		};

	}
}

#endif