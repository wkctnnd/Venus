#ifndef RESOURCE_H
#define RESOURCE_H

#include "../Utility/type.h"
namespace Venus
{
    namespace Resource
    {
        class Res
        {

        public:

            void load(char *path);
            void unLoad();
            void postLoad();
            void save();

        protected:
            size_t mKey;
        }; 
    }
]


#endif