#include "Player.h"
#include "Sprite.h"
#include <stdio.h>
#include <malloc.h>

Player::Player(int width, int height, int x, int y, int xdir, int ydir, int health, int collision, FREE_IMAGE_FORMAT format) {
    // Different sprite variations for motion illusion
     const char* player_motion[12] = { "assets/sub1.png", "assets/sub2.png", "assets/sub3.png", "assets/sub4.png", "assets/sub5.png", "assets/sub6.png",
                                     "assets/sub7.png", "assets/sub8.png", "assets/sub9.png", "assets/sub10.png", "assets/sub11.png", "assets/sub12.png" };

    this->width = width;
    this->height = height;
    this->x = x;
    this->x_old = x;
    this->xdir = xdir;
    this->y = y;
    this->y_old = y;
    this->ydir = ydir;
    this->health = health;
    this->collision = collision;
    this->sprite_var = 0;

    FIBITMAP* fi_asset = FreeImage_Load(format, player_motion[0]);
    FreeImage_FlipVertical(fi_asset);
    uint8_t* asset = FreeImage_GetBits(fi_asset);
    this->sprites[0] = asset;
    this->pitch = FreeImage_GetPitch(fi_asset);

    for (int i = 1; i < 12; i++) {
        fi_asset = FreeImage_Load(format, player_motion[i]);
        FreeImage_FlipVertical(fi_asset);
        asset = FreeImage_GetBits(fi_asset);
        this->sprites[i] = asset;
    }
}
