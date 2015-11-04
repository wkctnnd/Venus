#ifndef FILE_H
#define FILE_H

#include "Container/string.h"
#include "utilenum.h"
namespace Venus
{
	namespace Utility
	{

		class FileImp;

		class VFile
		{
		public:
			enum StartPosition
			{
				FileBegin = 0,
				FileCurrent,
				FileEnd,
			};

			VFile(){};
			VFile(VString& file, FileAcess acess = READ, FileOpenMode mode = OPEN_EXISTING, bool shared = true, bool asyn = false);
			
			bool close();

			size_t getFileSize();
			size_t synRead(void* p, uint32 size);
			void synWrite();

			void asynRead(void* p, uint32 size, uint32* offset);			
			void asynWrite();

            void seekPosition(int64 offset, StartPosition pos = FileCurrent);

		private:
            bool open(VString& file, FileAcess acess, FileOpenMode mode, bool shared, bool asyn);
			FileImp* implementation;
             bool bShared;
             bool bAsyn; 
		};

		class FileImp
		{
		public:
			virtual bool open(VString &file, FileAcess acess, FileOpenMode mode, bool shared, bool asyn) = 0;
			virtual bool close() = 0;
			uint32 synRead(void* p, uint32 size);
			void synWrite();
			size_t getFileSize();
			void asynRead(void* p, uint32 size);			
			void asynWrite();
			void seekPosition(int64 offset, VFile::StartPosition pos);

		};
	}
}

#endif