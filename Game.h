#ifndef GAME_H
#define GAME_H

#include "classes/Sprite.h"
#include "classes/Player.h"
#include "classes/Ammo.h"
#include "include/MiniFB_cpp.h"
#include "include/FreeImage.h"

#define WINDOW_WIDTH            1280
#define WINDOW_HEIGHT           720
#define BG_WIDTH                5000
#define BG_HEIGHT               1000
#define PLAYER_WIDTH            150
#define PLAYER_HEIGHT           100
#define PLAYER_X_DISPLACEMENT   10
#define PLAYER_Y_DISPLACEMENT   10
#define BG_X_DISPLACEMENT       1
#define BG_Y_DISPLACEMENT       20 
#define MOB_X_DISPLACEMENT      10
#define MOB_Y_DISPLACEMENT      10

typedef struct
{
    Player* player;
    Ammo* ammo;
    uint32_t* buffer;
    int* bgx;
    int* bgy;
    int ammo_cntr;
} game_data;

void key_press_handler(struct mfb_window* window, mfb_key key, mfb_key_mod mod, bool isPressed);
void update_bg(uint32_t* buffer, uint8_t* bg, int x_old, int y_old);
void display_asset(uint32_t* buffer, Sprite* sprite);
uint8_t* load_asset(FREE_IMAGE_FORMAT format, const char* filepath);
Sprite* generate_obstacles();
void check_player_obstacle_collision(Player* player, Sprite* obstacles, int obstacle_count);
void update_mob_position(Sprite* mobs, int bgx, int mob_count);
void check_player_mob_collision(Player* player, Sprite* mobs, int mob_count);

#endif
