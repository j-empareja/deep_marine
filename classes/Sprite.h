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

    Sprite();
    Sprite(int width, int height, int x, int y, int xdir, int ydir, FREE_IMAGE_FORMAT format, const char* filepath);
    void set_x_old(int x);
    void set_xdir(int dir);
    void set_y_old(int y);
    void set_ydir(int dir);
};
#endif
