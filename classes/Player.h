#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"

class Player : public Sprite {
public:
    int health;
    int collision;
    int sprite_var;
    uint8_t* sprites[12];

    Player(int width, int height, int x, int y, int xdir, int ydir, int health, int collision, FREE_IMAGE_FORMAT format);
};
#endif
