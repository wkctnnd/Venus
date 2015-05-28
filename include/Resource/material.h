#include "Container\string.h"
#include ""
namespace Venus
{
    namespace Resource
    {
        class BaseMaterial
        {
        public:
            void saveToFile(Utility::VString file);
            void loadFromFile(Utility::VString file);
        private:
            Utility::VString mDiffTexture;
            Utility::VString mSpecTexture;

            f32 mDiffColor[3];
            f32 mSpecColor[3];
        };
    }
}