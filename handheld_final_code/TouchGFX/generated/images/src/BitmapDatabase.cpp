// 4.23.2 0xce0bfeb4
// Generated by imageconverter. Please, do not edit!

#include <images/BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_gctmclogo[]; // BITMAP_GCTMCLOGO_ID = 0, Size: 199x202 pixels
extern const unsigned char image_wifiicon[]; // BITMAP_WIFIICON_ID = 1, Size: 26x20 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] = {
    { image_gctmclogo, 0, 199, 202, 38, 61, 30, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 84, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_wifiicon, 0, 26, 20, 9, 7, 8, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 1, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 }
};

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance()
{
    return bitmap_database;
}

uint16_t getInstanceSize()
{
    return (uint16_t)(sizeof(bitmap_database) / sizeof(touchgfx::Bitmap::BitmapData));
}
} // namespace BitmapDatabase
