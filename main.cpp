#include <stdio.h>

#include "Game.h"
#include "classes/Sprite.h"
#include "classes/Player.h"
#include "classes/Ammo.h"

int main()
{
    struct mfb_window* window = mfb_open_ex("Project", WINDOW_WIDTH, WINDOW_HEIGHT, WF_RESIZABLE); // width x height
    if (!window)
        return 0;

    uint32_t* frame_buffer = (uint32_t*)malloc(BG_WIDTH * BG_HEIGHT * 4); // width x height

    uint8_t* bg = load_asset(FIF_PNG, "assets/bg.png");

    // Player(int width, int height, int x, int y, int xdir, int ydir, int health, int collision, FREE_IMAGE_FORMAT format, const char* filepath);
    Player player = Player(PLAYER_WIDTH, PLAYER_HEIGHT, 0, 0, 0, 0, 3, -1, FIF_BMP, "assets/submarineSmall.bmp");
    
    // Ammo(int width, int height, int x, int y, int xdir, int ydir, FREE_IMAGE_FORMAT format, const char* filepath);
    Ammo ammo = Ammo(50, 50, 0, 0, 0, 0, FIF_PNG, "assets/ammo.png");

    // Sprite(int width, int height, int x, int y, int xdir, int ydir, FREE_IMAGE_FORMAT format, const char* filepath);
    Sprite obs1 = Sprite(100, 100, 1000, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2 = Sprite(100, 100, 2310, 360, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3 = Sprite(100, 100, 3000, 620, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs4 = Sprite(100, 100, 1000, 360, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obstacles[4] = {obs1, obs2, obs3, obs4};

    Sprite mob1 = Sprite(100, 150, 500, 70, 0, 1, true, FIF_PNG, "assets/squid.png");
    Sprite mob2 = Sprite(100, 150, 1000, 500, 0, -1, true, FIF_PNG, "assets/squid.png");
    Sprite mob3 = Sprite(100, 150, 2500, 500, 0, 1, true, FIF_PNG, "assets/squid.png");
    Sprite mob4 = Sprite(100, 150, 1500, 500, -1, 0, true, FIF_PNG, "assets/squid.png");
    Sprite mob5 = Sprite(100, 150, 2000, 100, -1, 0, true, FIF_PNG, "assets/squid.png");
    Sprite mobs[5] = {mob1, mob2, mob3, mob4, mob5};

    Sprite coral1 = Sprite(100, 100, 500, 0, -1, 1, true, FIF_PNG, "assets/coral.png");
    Sprite coral2 = Sprite(100, 100, 1500, 500, -1, -1, true, FIF_PNG, "assets/coral.png");
    Sprite coral3 = Sprite(100, 100, 2500, 400, 0, 1, true, FIF_PNG, "assets/coral.png");
    Sprite coral4 = Sprite(100, 100, 3500, 100, -1, -1, true, FIF_PNG, "assets/coral.png");
    Sprite corals[4] = {coral1, coral2, coral3, coral4};

    Sprite life1 = Sprite(25, 25, 1170, 670, 0, 0, true, FIF_PNG, "assets/heart25.png");
    Sprite life2 = Sprite(25, 25, 1200, 670, 0, 0, true, FIF_PNG, "assets/heart25.png");
    Sprite life3 = Sprite(25, 25, 1230, 670, 0, 0, true, FIF_PNG, "assets/heart25.png");
    Sprite lives[3] = {life1, life2, life3};

    game_data data;
    data.player = &player;
    data.ammo = &ammo;
    data.buffer = frame_buffer;

    bool isGameOver = false;

    // Load background to the frame buffer
    for (int i = 0; i < BG_WIDTH * BG_HEIGHT * 3; i += 3) {
        frame_buffer[i / 3] = (bg[i + 2] << 16) | (bg[i + 1] << 8) | bg[i];
    }

    mfb_set_keyboard_callback(window, key_press_handler);
    mfb_set_user_data(window, (void*)&data);

    do {
        static int bgx = 0;
        static int bgy = 0;

        data.bgx = &bgx;
        data.bgy = &bgy;

        if (!isGameOver) {
            // Game over if an obstacle pushed the player out of bounds or health is 0
            if (player.x < bgx - player.width || player.health == 0)
                isGameOver = true;

            // Check for collisions
            check_player_obstacle_collision(&player, obstacles, bgx, 4);
            check_player_sprite_collision(&player, mobs, 5, 0);
            check_player_sprite_collision(&player, corals, 4, 1);

            // Scroll bg to the right
            if (bgx >= BG_WIDTH - WINDOW_WIDTH - 1) {
                bgx = BG_WIDTH - WINDOW_WIDTH - 1;

                printf("Level Finished");

                if (ammo.isFired) {
                    printf("Next level start\n");
                    bgx = 0;
                    data.player->x = 0;
                }
            }
            else {
                if (player.collision != 2) data.player->x += BG_X_DISPLACEMENT; // If there is no collision to the right, update player x pos
                bgx += BG_X_DISPLACEMENT;

                for (int i = 0; i < MAX_LIVES; i++) {
                    lives[i].x += BG_X_DISPLACEMENT;
                }              
            }

            update_bg(frame_buffer, bg, bgx, bgy); // Update background based on player's movement
            update_sprite_position(mobs, MOB_X_DISPLACEMENT, MOB_Y_DISPLACEMENT, bgx, 5); // Update mobs positions
            update_sprite_position(corals, CORAL_X_DISPLACEMENT, CORAL_Y_DISPLACEMENT, bgx, 4); // Update corals positions

            display_asset(frame_buffer, &player); // Display player's sprite

            // Display obstacles
            for (int i = 0; i < 4; i++) {
                if (obstacles[i].isVisible == true) { // Only display visible obstacles
                    display_asset(frame_buffer, &obstacles[i]);
                }            
            }

            // Display mobs
            for (int i = 0; i < 5; i++) {
                if (mobs[i].isVisible) { // Only display active/visible mobs
                    display_asset(frame_buffer, &mobs[i]);
                }
            }

            // Display corals
            for (int i = 0; i < 4; i++) {
                if (corals[i].isVisible) { // Only display active/visible corals
                    display_asset(frame_buffer, &corals[i]);
                }
            }

            // Display lives
            for (int i = 0; i < player.health; i++) {
                if (lives[i].isVisible) {   // Only display active lives
                    display_asset(frame_buffer, &lives[i]);
                }
            }
            
            // Weapon fired 
            if (ammo.isFired) {
                display_asset(frame_buffer, &ammo);
                check_ammo_collision(&ammo, obstacles, 4);
                check_ammo_collision(&ammo, mobs, 5);
                ammo.x += 20;

                if (ammo.x >= bgx + WINDOW_WIDTH) ammo.isFired = false;
            }
        }
        else // Game over
            printf("Game over\n");

        // Update window
        uint32_t* stride = frame_buffer + (BG_WIDTH * bgy + bgx);
        int state = mfb_update_crop(window, stride, WINDOW_WIDTH, WINDOW_HEIGHT, BG_WIDTH);

        if (state < 0) {
            window = NULL;
            break;
        }
    } while (mfb_wait_sync(window));


    return 0;
}

void key_press_handler(struct mfb_window* window, mfb_key key, mfb_key_mod mod, bool isPressed)
{
    game_data* data = (game_data*)mfb_get_user_data(window);
    if (isPressed) {
        if (key == KB_KEY_LEFT && data->player->collision != 1) {
            data->player->x_old = data->player->x;
            data->player->x -= PLAYER_X_DISPLACEMENT;
            data->player->xdir = -1;
        }
        else if (key == KB_KEY_RIGHT && data->player->collision != 2) {
            data->player->x_old = data->player->x;
            data->player->x += PLAYER_X_DISPLACEMENT;
            data->player->xdir = 1;
        }
        else if (key == KB_KEY_UP && data->player->collision != 3) {
            data->player->y_old = data->player->y;
            data->player->y -= PLAYER_Y_DISPLACEMENT;

            // Update bg y position, if upper bound of the window is touched
            if (data->player->y > 0 && data->player->y == *(data->bgy)) {
                *(data->bgy) -= BG_Y_DISPLACEMENT;

                if (*(data->bgy) <= 0) { // Make sure player sprite does not go beyond the upper bound of the frame buffer
                    *(data->bgy) = 0;
                }
            }
        }
        else if (key == KB_KEY_DOWN && data->player->collision != 4) {
            data->player->y_old = data->player->y;
            data->player->y += PLAYER_Y_DISPLACEMENT;

            // Update bg y position, if lower bound touched
            if (data->player->y >= WINDOW_HEIGHT - PLAYER_HEIGHT - 1 + *(data->bgy)) {
                *(data->bgy) += BG_Y_DISPLACEMENT;

                if (*(data->bgy) >= BG_HEIGHT - WINDOW_HEIGHT - 1) { // Make sure player sprite does not go beyond the lower bound of the frame buffer
                    *(data->bgy) = BG_HEIGHT - WINDOW_HEIGHT - 1;
                }
            }
        }
        else if (key == KB_KEY_SPACE && !(data->ammo->isFired)) {
            data->ammo->x = data->player->x + data->player->width + BG_X_DISPLACEMENT;
            data->ammo->y = data->player->y + data->player->height / 2 - data->ammo->height / 2;
            data->ammo->isFired = true;
        }

        // Make sure player sprite does not go beyond boundaries
        if (data->player->x >= *(data->bgx) + WINDOW_WIDTH - PLAYER_WIDTH) { // Right bound touched
            data->player->x = *(data->bgx) + WINDOW_WIDTH - PLAYER_WIDTH;
        }
        else if (data->player->x <= *(data->bgx)) {// Left bound touched
            data->player->x = *(data->bgx);
        }

        if (data->player->y >= BG_HEIGHT - PLAYER_HEIGHT - 1) { // Lower bound touched
            data->player->y = BG_HEIGHT - PLAYER_HEIGHT - 1;
        }
        else if (data->player->y <= 0) {// Upper bound touched
            data->player->y = 0;
        }
    }
}
