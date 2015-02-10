#include "File/file.h"
#include <windows.h>
namespace Venus
{
	namespace File
	{
		class WinFileImp: public FileImp
		{
		public:

			bool open(std::string file, FileAcess acess);
			void close();
			void synRead();
			void asynRead();
			
		private:
			HANDLE mFile;
		}
}