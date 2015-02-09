#include "File/file.h"
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
			void spliteFilePath(std::string&, std::string&, std::string&);
		}
}