#ifndef SPRITE_H
#define SPRITE_H

#include <cstdint>
#include "../include/FreeImage.h"

class Sprite {
public:
    int width;
    int height;
    int x;
    int x_old;
    int xdir;
    int y;
    int y_old;
    int ydir;
    uint8_t* img;
    int pitch;
    bool isVisible;

    Sprite();
    Sprite(int width, int height, int x, int y, int xdir, int ydir, bool isVisible, FREE_IMAGE_FORMAT format, const char* filepath);
};
#endif
