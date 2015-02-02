#include "File/file.h"
namespace Venus
{
	namespace File
	{
		class WinFileImp: public FileImp
		{
		public:

			bool open();
			void close();
			void synRead();
			void asynRead();
		}
	}
}