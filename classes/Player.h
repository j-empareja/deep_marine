#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"

class Player: public Sprite {
public:
    int health;

    Player(int width, int height, int x, int y, int xdir, int ydir, int health, FREE_IMAGE_FORMAT format, const char* filepath);
  };
#endif