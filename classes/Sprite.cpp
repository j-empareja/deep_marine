#include "Sprite.h"
#include <stdio.h>
#include <cstdint>

Sprite::Sprite() {}

Sprite::Sprite(int width, int height, int x, int y, int xdir, int ydir, FREE_IMAGE_FORMAT format, const char* filepath) {
    this->width = width;
    this->height = height;
    this->x = x;
    this->x_old = x;
    this->xdir = xdir;
    this->y = y;
    this->y_old = y;
    this->ydir = ydir;

    FIBITMAP* fi_asset = FreeImage_Load(format, filepath);
    FreeImage_FlipVertical(fi_asset);
    uint8_t* asset = FreeImage_GetBits(fi_asset);
    this->img = asset;
    this->pitch = FreeImage_GetPitch(fi_asset);   
}
