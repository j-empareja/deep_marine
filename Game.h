#ifndef GAME_H
#define GAME_H

#include "classes/Sprite.h"
#include "classes/Player.h"
#include "classes/Ammo.h"
#include "include/MiniFB_cpp.h"
#include "include/FreeImage.h"

#define WINDOW_WIDTH            1280
#define WINDOW_HEIGHT           720
#define BG_WIDTH                15000
#define BG_HEIGHT               720
#define PLAYER_WIDTH            150
#define PLAYER_HEIGHT           100
#define PLAYER_X_DISPLACEMENT   10
#define PLAYER_Y_DISPLACEMENT   10
#define BG_X_DISPLACEMENT       5
#define BG_Y_DISPLACEMENT       20 
#define MOB_X_DISPLACEMENT      10
#define MOB_Y_DISPLACEMENT      10
#define CORAL_X_DISPLACEMENT    5
#define CORAL_Y_DISPLACEMENT    5
#define MAX_LIVES               3

typedef struct
{
    Player* player;
    Ammo* ammo;
    uint32_t* buffer;
    int* bgx;
    int* bgy;
    bool* stageStarted;
    bool* restarted;
    bool* isGameOver;
    bool* isContinued;
} game_data;

void key_press_handler(struct mfb_window* window, mfb_key key, mfb_key_mod mod, bool isPressed);
void update_bg(uint32_t* buffer, uint8_t* bg, int x_old, int y_old);
void display_asset(uint32_t* buffer, Sprite* sprite, int x_offset, int y_offset);
uint8_t* load_asset(FREE_IMAGE_FORMAT format, const char* filepath);
Sprite* generate_obstacles();
void check_player_obstacle_collision(Player* player, Sprite* obstacles, int bgx, int obstacle_count);
void update_sprite_position(Sprite* sprites, int x_displacement, int y_displacement, int bgx, int sprite_count);
void check_player_sprite_collision(Player* player, Sprite* sprites, int bgx, int sprite_count, int type);
void check_ammo_collision(Ammo* ammo, Sprite* entities, int entity_count);
void reset_sprite_attributes(Sprite* sprites, int sprite_count);

#endif
