#ifndef UTILENUM_H
#define UTILENUM_H
namespace Venus
{
    namespace Utility
    {
        enum FileAcess
        {
            READ = 1,
            WRITE = 2,
        };

        enum FileOpenMode
        {
            OPEN_EXISTING,
            TRUNCATE_EXISTING,
            CREATE_NEW,
            CREATE_ALWAYS,
        };
    }
}

#endif

