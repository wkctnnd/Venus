#include "Container\string.h"
#include ""
namespace Venus
{
    namespace Resource
    {
        class BaseMaterial
        {
        public:


        private:
            Utility::VString mDiffTexture;
            Utility::VString mSpecTexture;

            f32 mDiffColor[3];
            f32 mSpecColor[3];
        };
    }
}