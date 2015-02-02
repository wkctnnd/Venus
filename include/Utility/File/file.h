#include<string>
namespace Venus
{
	namespace File
	{
		class FileImp;

		class VFile
		{
		public:
			VFile();
			bool open();
			void close();

			void synRead();
			void asynRead();
		private:
			std::string mDefaultpath;
			FileImp* implementation;
		};

		class FileImp
		{
		public:
			virtual bool open() = 0;
			virtual void close() = 0;
			virtual void synRead() = 0;
			virtual void asynRead() = 0;
		};
	}
}