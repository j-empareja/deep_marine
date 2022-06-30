#ifndef AMMO_H
#define AMMO_H

#include "Sprite.h"

class Ammo : public Sprite {
public:
    bool isFired;

    Ammo(int width, int height, int x, int y, int xdir, int ydir, FREE_IMAGE_FORMAT format, const char* filepath);
};
#endif#pragma once
