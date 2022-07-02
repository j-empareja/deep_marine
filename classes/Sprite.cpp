#include "Sprite.h"
#include <stdio.h>
#include <cstdint>

Sprite::Sprite() {}

Sprite::Sprite(int width, int height, int x, int y, int xdir, int ydir, bool isVisible, FREE_IMAGE_FORMAT format, const char* filepath) {
    this->width = width;
    this->height = height;
    this->x = x;
    this->x_old = x;
    this->x_initial = x;
    this->xdir = xdir;
    this->y = y;
    this->y_old = y;
    this->y_initial = y;
    this->ydir = ydir;
    this->isVisible = isVisible;

    FIBITMAP* fi_asset = FreeImage_Load(format, filepath);
    FreeImage_FlipVertical(fi_asset);
    uint8_t* asset = FreeImage_GetBits(fi_asset);
    this->img = asset;
    this->pitch = FreeImage_GetPitch(fi_asset);   
}
