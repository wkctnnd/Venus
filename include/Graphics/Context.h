#ifndef CONTEXT_H
#define CONTEXT_H

//use to switch among immediate context and deferred context.
namespace Venus
{
    namespace Graphics
    {
        //http://blog.csdn.net/pizi0475/article/details/7782932
        class Context
        {
        public:
            void switchContext();
        }
    }
}

#endif
