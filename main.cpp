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

    uint8_t* bg1 = load_asset(FIF_PNG, "assets/bg1.png");
    uint8_t* bg2 = load_asset(FIF_PNG, "assets/bg2.png");
    uint8_t* bg3 = load_asset(FIF_PNG, "assets/bg3.png");

    // Player(int width, int height, int x, int y, int xdir, int ydir, int health, int collision, FREE_IMAGE_FORMAT format, const char* filepath);
    Player player = Player(PLAYER_WIDTH, PLAYER_HEIGHT, 0, 0, 0, 0, 3, -1, FIF_PNG, "assets/submarine.png");
    
    // Ammo(int width, int height, int x, int y, int xdir, int ydir, FREE_IMAGE_FORMAT format, const char* filepath);
    Ammo ammo = Ammo(50, 50, 0, 0, 0, 0, FIF_PNG, "assets/ammo.png");

    // Sprite(int width, int height, int x, int y, int xdir, int ydir, FREE_IMAGE_FORMAT format, const char* filepath);
    // Declare stage 1 sprites
    Sprite obs11 = Sprite(100, 100, 1000, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs12 = Sprite(100, 100, 2310, 360, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs13 = Sprite(100, 100, 3000, 620, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs14 = Sprite(100, 100, 1000, 360, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obstacles1[4] = {obs11, obs12, obs13, obs14};

    Sprite mob1 = Sprite(100, 150, 500, 70, 0, 1, true, FIF_PNG, "assets/squid.png");
    Sprite mob2 = Sprite(100, 150, 1000, 500, 0, -1, true, FIF_PNG, "assets/squid.png");
    Sprite mob3 = Sprite(100, 150, 2500, 500, 0, 1, true, FIF_PNG, "assets/squid.png");
    Sprite mob4 = Sprite(100, 150, 1500, 500, -1, 0, true, FIF_PNG, "assets/squid.png");
    Sprite mob5 = Sprite(100, 150, 2000, 100, -1, 0, true, FIF_PNG, "assets/squid.png");
    Sprite mobs1[5] = {mob1, mob2, mob3, mob4, mob5};

    Sprite coral1 = Sprite(100, 100, 500, 0, -1, 1, true, FIF_PNG, "assets/coral.png");
    Sprite coral2 = Sprite(100, 100, 1500, 500, -1, -1, true, FIF_PNG, "assets/coral.png");
    Sprite coral3 = Sprite(100, 100, 2500, 400, 0, 1, true, FIF_PNG, "assets/coral.png");
    Sprite coral4 = Sprite(100, 100, 3500, 100, -1, -1, true, FIF_PNG, "assets/coral.png");
    Sprite corals1[4] = {coral1, coral2, coral3, coral4};

    // Declare stage 2 sprites
    Sprite obs21 = Sprite(100, 100, 800, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs22 = Sprite(100, 100, 750, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs23 = Sprite(100, 100, 750, 320, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs24 = Sprite(100, 100, 750, 620, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs25 = Sprite(100, 100, 2100, 620, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs26 = Sprite(100, 100, 4000, 360, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obstacles2[6] = {obs21, obs22, obs23, obs24, obs25, obs26};

    Sprite mob21 = Sprite(100, 150, 300, 70, 0, 1, true, FIF_PNG, "assets/squid.png");
    Sprite mob22 = Sprite(100, 150, 600, 620, 0, -1, true, FIF_PNG, "assets/squid.png");
    Sprite mob23 = Sprite(100, 150, 1100, 130, -1, 1, true, FIF_PNG, "assets/squid.png");
    Sprite mob24 = Sprite(100, 150, 2000, 0, -1, 0, true, FIF_PNG, "assets/squid.png");
    Sprite mob25 = Sprite(100, 150, 4100, 100, -1, 1, true, FIF_PNG, "assets/squid.png");
    Sprite mob26 = Sprite(100, 150, 4300, 100, -1, 0, true, FIF_PNG, "assets/squid.png");
    Sprite mobs2[6] = {mob21, mob22, mob23, mob24, mob25, mob26};

    Sprite coral21 = Sprite(100, 100, 1000, 0, -1, 1, true, FIF_PNG, "assets/coral.png");
    Sprite coral22 = Sprite(100, 100, 2000, 500, 0, -1, true, FIF_PNG, "assets/coral.png");
    Sprite coral23 = Sprite(100, 100, 3000, 400, -1, 1, true, FIF_PNG, "assets/coral.png");
    Sprite corals2[3] = {coral21, coral22, coral23};

    // Declare stage 3 sprites
    Sprite obs31 = Sprite(100, 100, 800, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs32 = Sprite(100, 100, 750, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs33 = Sprite(100, 100, 750, 320, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs34 = Sprite(100, 100, 750, 620, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs35 = Sprite(100, 100, 2100, 620, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs36 = Sprite(100, 100, 4000, 360, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obstacles3[6] = { obs31, obs32, obs33, obs34, obs35, obs36 };

    Sprite mob31 = Sprite(100, 150, 300, 70, 0, 1, true, FIF_PNG, "assets/squid.png");
    Sprite mob32 = Sprite(100, 150, 600, 620, 0, -1, true, FIF_PNG, "assets/squid.png");
    Sprite mob33 = Sprite(100, 150, 1100, 130, -1, 1, true, FIF_PNG, "assets/squid.png");
    Sprite mob34 = Sprite(100, 150, 2000, 0, -1, 0, true, FIF_PNG, "assets/squid.png");
    Sprite mob35 = Sprite(100, 150, 4100, 100, -1, 1, true, FIF_PNG, "assets/squid.png");
    Sprite mob36 = Sprite(100, 150, 4300, 100, -1, 0, true, FIF_PNG, "assets/squid.png");
    Sprite mobs3[6] = { mob31, mob32, mob33, mob34, mob35, mob36 };

    Sprite coral31 = Sprite(100, 100, 1000, 0, -1, 1, true, FIF_PNG, "assets/coral.png");
    Sprite coral32 = Sprite(100, 100, 2000, 500, 0, -1, true, FIF_PNG, "assets/coral.png");
    Sprite coral33 = Sprite(100, 100, 3000, 400, -1, 1, true, FIF_PNG, "assets/coral.png");
    Sprite corals3[3] = { coral31, coral32, coral33 };

    Sprite life1 = Sprite(25, 25, 1170, 670, 0, 0, true, FIF_PNG, "assets/heart25.png");
    Sprite life2 = Sprite(25, 25, 1200, 670, 0, 0, true, FIF_PNG, "assets/heart25.png");
    Sprite life3 = Sprite(25, 25, 1230, 670, 0, 0, true, FIF_PNG, "assets/heart25.png");
    Sprite lives[3] = {life1, life2, life3};

    Sprite start1 = Sprite(250, 100, WINDOW_WIDTH / 2 - 125, WINDOW_HEIGHT / 2 - 50, 0, 0, true, FIF_PNG, "assets/start1.png");
    Sprite start2 = Sprite(250, 100, WINDOW_WIDTH / 2 - 125, WINDOW_HEIGHT / 2 - 50, 0, 0, true, FIF_PNG, "assets/start2.png");
    Sprite start3 = Sprite(250, 100, WINDOW_WIDTH / 2 - 125, WINDOW_HEIGHT / 2 - 50, 0, 0, true, FIF_PNG, "assets/start3.png");
    Sprite cont = Sprite(250, 100, WINDOW_WIDTH / 2 - 125, WINDOW_HEIGHT / 2 - 50, 0, 0, true, FIF_PNG, "assets/continue.png");
    Sprite gameover = Sprite(250, 100, WINDOW_WIDTH / 2 - 125, WINDOW_HEIGHT / 2 - 50, 0, 0, true, FIF_PNG, "assets/gameover.png");

    bool isGameOver = false;
    bool isContinued = true;
    int stage = 1;
    bool stageStarted = false;
    bool restarted = false;

    game_data data;
    data.player = &player;
    data.ammo = &ammo;
    data.buffer = frame_buffer;
    data.stageStarted = &stageStarted;

    mfb_set_keyboard_callback(window, key_press_handler);
    mfb_set_user_data(window, (void*)&data);

    do {
        static int bgx = 0;
        static int bgy = 0;

        // Updates every stage
        static Sprite* current_obstacles;
        static Sprite* current_mobs;
        static Sprite* current_corals;
        static uint8_t* current_bg;
        static int obstacle_count;
        static int mob_count;
        static int coral_count;

        data.bgx = &bgx;
        data.bgy = &bgy;

        if (isContinued) {
            if (stage == 1) { // Set stage 1 parameters
                // Update set of sprites
                current_obstacles = obstacles1;
                current_mobs = mobs1;
                current_corals = corals1;
                obstacle_count = 4;
                mob_count = 5;
                coral_count = 4;

                isContinued = false;
                stageStarted = false;

                // Load stage background to the frame buffer
                current_bg = bg1;
                for (int i = 0; i < BG_WIDTH * BG_HEIGHT * 3; i += 3) {
                    frame_buffer[i / 3] = (current_bg[i + 2] << 16) | (current_bg[i + 1] << 8) | current_bg[i];
                }

                display_asset(frame_buffer, &player, 0, 0); // Display player's sprite
                display_asset(frame_buffer, &start1, 0, 0); // Display stage prompt
            }
            else if (stage == 2) { // Set stage 2 parameters
                // Update set of sprites
                current_obstacles = obstacles2;
                current_mobs = mobs2;
                current_corals = corals2;
                obstacle_count = 6;
                mob_count = 6;
                coral_count = 3;

                /*reset_sprite_position(obstacles2, obstacle_count);
                reset_sprite_position(mobs2, mob_count);
                reset_sprite_position(corals2, coral_count);*/

                isContinued = false;
                stageStarted = false;

                // Load stage background to the frame buffer
                current_bg = bg2;
                for (int i = 0; i < BG_WIDTH * BG_HEIGHT * 3; i += 3) {
                    frame_buffer[i / 3] = (current_bg[i + 2] << 16) | (current_bg[i + 1] << 8) | current_bg[i];
                }

                display_asset(frame_buffer, &player, 0, 0); // Display player's sprite
                display_asset(frame_buffer, &start2, 0, 0); // Display stage prompt
            }
            else if (stage == 3) { // Set stage 3 parameters
                // Update set of sprites
                current_obstacles = obstacles3;
                current_mobs = mobs3;
                current_corals = corals3;
                obstacle_count = 6;
                mob_count = 6;
                coral_count = 3;

                /*reset_sprite_position(obstacles3, obstacle_count);
                reset_sprite_position(mobs3, mob_count);
                reset_sprite_position(corals3, coral_count);*/

                isContinued = false;
                stageStarted = false;

                // Load stage background to the frame buffer
                current_bg = bg3;
                for (int i = 0; i < BG_WIDTH * BG_HEIGHT * 3; i += 3) {
                    frame_buffer[i / 3] = (current_bg[i + 2] << 16) | (current_bg[i + 1] << 8) | current_bg[i];
                }

                display_asset(frame_buffer, &player, 0, 0); // Display player's sprite
                display_asset(frame_buffer, &start3, 0, 0); // Display stage prompt
            }
        }

        if (!isGameOver && stageStarted) {
            // Stage completed
            if (bgx >= BG_WIDTH - WINDOW_WIDTH - 1) { 
                bgx = BG_WIDTH - WINDOW_WIDTH - 1;
                display_asset(frame_buffer, &cont, bgx, bgy); // Show stage complete prompt

                if (ammo.isFired) {
                    // Reset/update the necessary variables
                    bgx = 0;
                    bgy = 0;
                    player.x = 0;
                    player.y = 0;
                    stage++;
                    isContinued = true;
                    
                    reset_sprite_position(lives, MAX_LIVES); 
                }
            }
            else { // Scroll bg to the right, stage not yet done
                // Game over if an obstacle pushed the player out of bounds or health is 0
                if (player.x < bgx - player.width || player.health == 0) {
                    isGameOver = true;
                }
                   
                // Check for collisions
                check_player_obstacle_collision(&player, current_obstacles, bgx, obstacle_count);
                check_player_sprite_collision(&player, current_mobs, bgx, mob_count, 0);
                check_player_sprite_collision(&player, current_corals, bgx, coral_count, 1);

                if (player.collision != 2) { // If there is no collision to the right, update player x pos
                    data.player->x += BG_X_DISPLACEMENT; 
                }

                bgx += BG_X_DISPLACEMENT;

                update_bg(frame_buffer, current_bg, bgx, bgy); // Update background based
                update_sprite_position(current_mobs, MOB_X_DISPLACEMENT, MOB_Y_DISPLACEMENT, bgx, mob_count); // Update mobs positions
                update_sprite_position(current_corals, CORAL_X_DISPLACEMENT, CORAL_Y_DISPLACEMENT, bgx, coral_count); // Update corals positions

                display_asset(frame_buffer, &player, 0, 0); // Display player's sprite

                // Display obstacles
                for (int i = 0; i < obstacle_count; i++) {
                    if (current_obstacles[i].isVisible == true) { // Only display visible obstacles
                        display_asset(frame_buffer, &current_obstacles[i], 0, 0);
                    }
                }

                // Display mobs
                for (int i = 0; i < mob_count; i++) {
                    if (current_mobs[i].isVisible) { // Only display active/visible mobs
                        display_asset(frame_buffer, &current_mobs[i], 0, 0);
                    }
                }

                // Display corals
                for (int i = 0; i < coral_count; i++) {
                    if (current_corals[i].isVisible) { // Only display active/visible mobs
                        display_asset(frame_buffer, &current_corals[i], 0, 0);
                    }
                }

                // Display lives
                for (int i = 0; i < player.health; i++) {
                    if (lives[i].isVisible) {   // Only display active lives
                        display_asset(frame_buffer, &lives[i], bgx, bgy);
                    }
                }

                if (ammo.isFired) {
                    display_asset(frame_buffer, &ammo, 0, 0);
                    check_ammo_collision(&ammo, current_obstacles, obstacle_count);
                    check_ammo_collision(&ammo, current_mobs, mob_count);
                    ammo.x += 20;

                    if (ammo.x >= bgx + WINDOW_WIDTH) ammo.isFired = false;
                }
            }
        }
        if (isGameOver) { // Game over
            display_asset(frame_buffer, &gameover, bgx, bgy);
            // stage = 1;
        }

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
        if (key == KB_KEY_LEFT && data->player->collision != 1 && *(data->stageStarted)) { // Move left
            data->player->x_old = data->player->x;
            data->player->x -= PLAYER_X_DISPLACEMENT;
            data->player->xdir = -1;
        }
        else if (key == KB_KEY_RIGHT && data->player->collision != 2 && *(data->stageStarted)) { // Move right
            data->player->x_old = data->player->x;
            data->player->x += PLAYER_X_DISPLACEMENT;
            data->player->xdir = 1;
        }
        else if (key == KB_KEY_UP && data->player->collision != 3 && *(data->stageStarted)) { // Move up
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
        else if (key == KB_KEY_DOWN && data->player->collision != 4 && *(data->stageStarted)) { // Move down
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
        else if (key == KB_KEY_SPACE && !(data->ammo->isFired) && *(data->stageStarted)) { // Fire weapon
            data->ammo->x = data->player->x + data->player->width + BG_X_DISPLACEMENT;
            data->ammo->y = data->player->y + data->player->height / 2 - data->ammo->height / 2;
            data->ammo->isFired = true;
        }
        else if (key == KB_KEY_ENTER && !*(data->stageStarted)) { // Start stage
            *(data->stageStarted) = true;
        }

        // Make sure player sprite does not go beyond boundaries
        if (data->player->x >= *(data->bgx) + WINDOW_WIDTH - PLAYER_WIDTH) { // Right bound touched
            data->player->x = *(data->bgx) + WINDOW_WIDTH - PLAYER_WIDTH;
        }
        //else if (data->player->x <= *(data->bgx)) {// Left bound touched
        //    data->player->x = *(data->bgx);
        //}

        if (data->player->y >= BG_HEIGHT - PLAYER_HEIGHT - 1) { // Lower bound touched
            data->player->y = BG_HEIGHT - PLAYER_HEIGHT - 1;
        }
        else if (data->player->y <= 0) {// Upper bound touched
            data->player->y = 0;
        }
    }
}
