#include "imageloader.h"

namespace Venus
{
    namespace Resource
    {

        class jpgImageLoader
        {
        public :
            static void LoadImageFile(Utility::VString &file);
        };

        class ddsImageLoader
        {
        public:
            static void LoadImageFile(Utility::VString &file);
        };


        class pngImageLoader
        {
        public :
            static void LoadImageFile(Utility::VString &file);
        };


        void ImageLoader:: loadImageFile(Utility::VString &file)
        {
            size_t pos = file.find(Utility::VString("."));
            Utility::VString ext = file.subStr(pos, file.length() - pos);
            if (ext.compare(Utility::VString("jpg")))
            {
                jpgImageLoader::LoadImageFile(file);
            }
            else if(ext.compare(Utility::VString("png")))
            {
                pngImageLoader::LoadImageFile(file);
            }


            else if(ext.compare(Utility::VString("dds")))
            {
                ddsImageLoader::LoadImageFile(file);
            }

            else
            {

            }
        }

    }
}
