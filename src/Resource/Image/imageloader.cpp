#include "imageloader.h"
#include "Container/string.h"
#include "File/file.h"
#include "image.h"
#include "type.h"
#include "assert.h"
#include <cmath>

namespace Venus
{
    namespace Resource
    {

        class jpgImageLoader
        {
        public :
            static void LoadImageFile(Utility::VString &file, const Image* image);
        };

        class ddsImageLoader
        {
        public:
            static void LoadImageFile(Utility::VString &file, const Image* image);
        };


        class pngImageLoader
        {

        public :
            static void LoadImageFile(Utility::VString &file, const Image* image);
        };

        //http://blog.csdn.net/songjinshi/article/details/7207735
        //http://blog.chinaunix.net/uid-23592843-id-150648.html
        class bmpImageLoader
        {
            friend Image;
        public:
            struct BITMAP_HEADER  
            {  
                char               _id0;                               ///< 两字节的内容用来识别位图的类型：‘BM’ ： Windows 3.1x, 95, NT, …, ‘BA’ ：OS/2 Bitmap Array, ‘CI’ ：OS/2 Color Icon, ‘CP’ ：OS/2 Color Pointer, ‘IC’ ： OS/2 Icon,‘PT’ ：OS/2 Pointer  
                char               _id1; 
                uint64                _file_size;                         ///< 用字节表示的整个文件的大小  
                uint32                _reserved0;                         ///< 保留，设置为0  
                uint32                _bitmap_data_offset;                ///< 从文件开始到位图数据开始之间的数据(bitmap data)之间的偏移量  
            };

            struct BITMAP_INFOR_HEADER
            {
                uint32                _bitmap_header_size;                ///< 位图信息头(Bitmap Info Header)的长度，用来描述位图的颜色、压缩方法等。下面的长度表示：28h - Windows 3.1x, 95, NT, …,  0Ch - OS/2 1.x, F0h - OS/2 2.x  
                int32                _width;                             ///< 位图的宽度，以像素为单位  
                int32                _height;                            ///< 位图的高度，以像素为单位  
                uint16               _planes;                            ///< 位图的位面数  
                uint16               _bits_per_pixel;                    ///< 每个像素的位数, 1 - Monochrome bitmap, 4 - 16 color bitmap, 8 - 256 color bitmap, 16 - 16bit (high color) bitmap, 24 - 24bit (true color) bitmap, 32 - 32bit (true color) bitmap  
                uint32                _compression;                       ///< 压缩说明：, 0 - none (也使用BI_RGB表示), 1 - RLE 8-bit / pixel (也使用BI_RLE4表示), 2 - RLE 4-bit / pixel (也使用BI_RLE8表示), 3 - Bitfields (也使用BI_BITFIELDS表示)  
                uint32                _bitmap_data_size;                  ///< 用字节数表示的位图数据的大小。该数必须是4的倍数  
                int32                _hres;                              ///< 用像素/米表示的水平分辨率  
                int32                _vres;                              ///< 用像素/米表示的垂直分辨率  
                uint32                _colors;                            ///< 位图使用的颜色数。如8-位/像素表示为100h或者 256.  
                uint32                _important_colors;                  ///< 指定重要的颜色数。当该域的值等于颜色数时，表示所有颜色都一样重要  
            };

            struct tagRGBQUAD {
                uint8 rgbBlue; //该颜色的蓝色分量
                uint8 rgbGreen; //该颜色的绿色分量
                uint8 rgbRed; //该颜色的红色分量
                uint8 rgbReserved; //保留值
            }; 

            static void LoadImageFile(Utility::VString &filename, const Image* image)
            {
                tagRGBQUAD pllate[256];
                Utility::VFile *file = new Utility::VFile(filename);
                BITMAP_HEADER head;
                BITMAP_INFOR_HEADER infohead;
                //the sizeof(BITMAP_HEADER) can be affected by memory align, maybe has problem
                file->synRead(&head, sizeof(BITMAP_HEADER));
                if (head._id0=='B'&&head._id1=='M')
                {
                    BITMAP_INFOR_HEADER infohead;
                    char *index = 0;
                    file->synRead(&head, sizeof(BITMAP_HEADER), 0);
                    Image::ImageInfo info;
                    //VAssert(inforhead._compression == 0, "not support compressed bmp");
                    uint32 paletteSize;
                    infohead._important_colors == 0 ? infohead._important_colors = pow(2.0,infohead._bits_per_pixel) : infohead._important_colors;
                    switch (infohead._bits_per_pixel)
                    {
                    case 1:
                    case 4:
                    case 8:
                        //read pallet data;
                        file->seekPosition(infohead._bitmap_header_size + sizeof(BITMAP_HEADER), Utility::VFile::FileBegin);
                        file->synRead(pllate, sizeof(tagRGBQUAD) * paletteSize);
                        char *index = new char[infohead._width * infohead._bits_per_pixel / 8];
                        //hasPalette = true;
                        break;
                    case 16:

                        if (infohead._compression == 0)
                        {
                            //hasPalette = false;
                            info.mFormat = VB5G5R5;
                        }
                        else if (infohead._compression == 3)
                        {
                            uint32 mask[3];

                            file->seekPosition(infohead._bitmap_header_size + sizeof(BITMAP_HEADER), Utility::VFile::FileBegin);
                            file->synRead(mask, 3 * sizeof(uint32));
                            if (mask[0] == 0x7C00 && mask[1] == 0x03E0 && mask[2] == 0x001F)
                            {
                                info.mFormat = VB5G6R5;
                            }
                            else if(mask[0] == 0xF800 && mask[1] == 0x07E0 && mask[2] == 0x001F)
                            {
                                info.mFormat = VB5G6R5;
                            }
                            file->synRead(&head, sizeof(BITMAP_HEADER));
                            infohead._important_colors = sizeof(uint32) * 3;
                        }
                        break;
                    case 24:
                        info.mFormat = VB8G8R8;
                        break;
                    case 32:
                        info.mFormat = VB8G8R8A8;
                        break;
                    default:
                        break;
                    }

                    info.uWidth = head._width;
                    info.uHeight = head._height;
                    info.uDepth = 1;
                    info.mMipNum = 1;
                    info.uArrayNum = 1;

                    //read image data;
                    file->seekPosition(head._bitmap_data_offset, Utility::VFile::FileBegin);
                    void *imagedata = (void*)malloc(infohead._bitmap_data_size);
                    file->synRead(imagedata, infohead._bitmap_data_size);
                    char *p = (char*)imagedata;
                    char* internalImageData = new char[];
                    uint32 realpitch = info.uWidth * infohead._bits_per_pixel / 8;
                    uint32 pitch = info.uWidth * infohead._bits_per_pixel / 8;
                    info.uWidth * infohead._bits_per_pixel % 32 == 0 ? pitch = pitch : pitch + 1;

                    for (uint32 i = 0; i < info.uHeight; i++)
                    {
                        memcpy(internalImageData, p, realpitch);
                        p += pitch;                                
                    }
                    char* finalImageData = internalImageData;
                    if (infohead._bits_per_pixel < 24)
                    {
                        finalImageData = new char[infohead._width * infohead._height * 32];
                        info.mFormat = VB8G8R8A8;

                        for (uint32 i = 0; i < infohead._height; i++)
                        {
                            uint32 bytesize = infohead._width * infohead._bits_per_pixel / 8;
                            for (uint32 j = 0; j < bytesize; j++)
                            {
                                uint32 index = i * bytesize + j; 
                                uint8 m = internalImageData[index];
                                uint32 icount = 0;
                                switch (infohead._bits_per_pixel)
                                {
                                case 1:
                                    {
                                        uint8 mask = 0x01;
                                        for (uint32 k = 0; k < 8; k++)
                                        {
                                            uint8 realindex = m & mask;
                                            mask = mask << 1;
                                            ((tagRGBQUAD*)finalImageData)->rgbBlue = pllate[internalImageData[realindex]].rgbBlue;
                                            ((tagRGBQUAD*)finalImageData)->rgbGreen = pllate[internalImageData[realindex]].rgbGreen;
                                            ((tagRGBQUAD*)finalImageData)->rgbRed = pllate[internalImageData[realindex]].rgbRed;
                                            ((tagRGBQUAD*)finalImageData)->rgbReserved = pllate[internalImageData[realindex]].rgbReserved;
                                            if (icount++ >infohead._width)
                                                break;
                                        }
                                        
                                    }
                                case 4:
                                    {
                                        uint8 mask = 0x0F;
                                        for (uint32 k = 0; k < 2; k++)
                                        {
                                            uint8 realindex = m & mask;
                                            mask = mask << 4;
                                            ((tagRGBQUAD*)finalImageData)->rgbBlue = pllate[internalImageData[realindex]].rgbBlue;
                                            ((tagRGBQUAD*)finalImageData)->rgbGreen = pllate[internalImageData[realindex]].rgbGreen;
                                            ((tagRGBQUAD*)finalImageData)->rgbRed = pllate[internalImageData[realindex]].rgbRed;
                                            ((tagRGBQUAD*)finalImageData)->rgbReserved = pllate[internalImageData[realindex]].rgbReserved;
                                            if (icount++ >infohead._width)
                                                break;
                                        }
                                    }
                                case 8:
                                    {
                                        ((tagRGBQUAD*)finalImageData)->rgbBlue = pllate[internalImageData[index]].rgbBlue;
                                        ((tagRGBQUAD*)finalImageData)->rgbGreen = pllate[internalImageData[index]].rgbGreen;
                                        ((tagRGBQUAD*)finalImageData)->rgbRed = pllate[internalImageData[index]].rgbRed;
                                        ((tagRGBQUAD*)finalImageData)->rgbReserved = pllate[internalImageData[index]].rgbReserved;
                                    }
                                }
                            }
                        }
                      
                    }
          
          
                    image->mInfo = info;
                    image->setImageData(finalImageData);
                }


            private:
               
                void* PaletteConvertToBGR32(void *pallet, void* data)
                {

                }
            }
        };


        void ImageLoader:: loadImageFile(Utility::VString &file, const Image* image)
        {
            size_t pos = file.find(Utility::VString("."));
            Utility::VString ext = file.subStr(pos, file.length() - pos);
            if (ext.compareCI(Utility::VString("jpg")))
            {
                jpgImageLoader::LoadImageFile(file, image);
            }
            else if(ext.compareCI(Utility::VString("png")))
            {
                pngImageLoader::LoadImageFile(file, image);
            }


            else if(ext.compareCI(Utility::VString("dds")))
            {
                ddsImageLoader::LoadImageFile(file, image);
            }

            else if(ext.compareCI(Utility::VString("bmp")))
            {
                bmpImageLoader::LoadImageFile(file, image);
            }
            else
            {

            }
        }

    }
}
