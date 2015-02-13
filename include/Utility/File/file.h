#include<string>
namespace Venus
{
	namespace Utility
	{

		enum FileAcess
		{
			READ,
			WRITE,
			TRUCATE,
			CREATE,
		};

		class FileImp;

		class VFile
		{
		public:
			VFile();
			bool open(std::string file, FileAcess acess);

			void close();

			void synRead();
			void synWrite();

			void asynRead();			
			void asynWrite();

		private:
			void spliteFilePath(std::string, std::string&, std::string&, std::string&);
			FileImp* implementation;
			std::string mDefaultpath;
		};

		class FileImp
		{
		public:
			virtual bool open(std::string file, FileAcess acess) = 0;
			virtual void close() = 0;
			void synRead();
			void synWrite();

			void asynRead();			
			void asynWrite();
			

		};
	}
}