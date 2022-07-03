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
    int x_initial;
    int xdir;
    int xdir_initial;
    int y;
    int y_old;
    int y_initial;
    int ydir;
    int ydir_initial;
    uint8_t* img;
    int pitch;
    bool isVisible;

    Sprite();
    Sprite(int width, int height, int x, int y, int xdir, int ydir, bool isVisible, FREE_IMAGE_FORMAT format, const char* filepath);
};
#endif
