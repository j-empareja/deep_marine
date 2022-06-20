#ifndef GAME_H
#define GAME_H

#include "classes/Sprite.h"
#include "classes/Player.h"
#include "include/MiniFB_cpp.h"
#include "include/FreeImage.h"

#define WINDOW_WIDTH    1280
#define WINDOW_HEIGHT   720
#define BG_WIDTH        4000
#define BG_HEIGHT       3000
#define PLAYER_WIDTH    96
#define PLAYER_HEIGHT   69

typedef struct
{
    Player* player;
    Sprite* obstacles;
    uint32_t* buffer;
} game_data;

void key_press_handler(struct mfb_window* window, mfb_key key, mfb_key_mod mod, bool isPressed);
void update_bg(uint32_t* buffer, uint8_t* bg, int x_old, int y_old);
void display_asset(uint32_t* buffer, Sprite* sprite, int offset_x, int offset_y);
uint8_t* load_asset(FREE_IMAGE_FORMAT format, const char* filepath);
Sprite* generate_obstacles();
bool check_player_collision(Player* player, Sprite* obstacles, int obstacle_count);

#endif