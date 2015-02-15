#include "imageloader.h"

namespace Venus
{
    namespace Resource
    {

        class JpgImageLoader:public ImageLoader
        {
        public :
            static void LoadImageFile(Utility::VString &file);
        };

        class ddsImageLoader:public ImageLoader
        {
        public:
            static void LoadImageFile(Utility::VString &file);
        };


        class pngImageLoader:public ImageLoader
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
                    JpgImageLoader::loadImageFile(file);
                }
                else if(ext.compare(Utility::VString("png")))
                {
                
                }


                else if(ext.compare(Utility::VString("dds")))
                {
                
                }

                else
                {
                
                }
            }

    }
}
