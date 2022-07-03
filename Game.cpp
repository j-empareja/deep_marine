#include <stdio.h>

#include "Game.h"

// Retrieve the bits of an asset
uint8_t* load_asset(FREE_IMAGE_FORMAT format, const char* filepath) {
    FIBITMAP* asset_fi = FreeImage_Load(format, filepath);
    FreeImage_FlipVertical(asset_fi);
    uint8_t* asset = FreeImage_GetBits(asset_fi);

    return asset;
}

// Update background
void update_bg(uint32_t* buffer, uint8_t* bg, int x_old, int y_old) {
    for (int i = 0; i < WINDOW_HEIGHT; i++) // rows (height)
    {
        for (int j = 0; j < WINDOW_WIDTH; j++) // cols (width)
        {
            uint8_t blue = bg[BG_WIDTH * 3 * (i + y_old) + 3 * (j + x_old)];
            uint8_t green = bg[BG_WIDTH * 3 * (i + y_old) + 3 * (j + x_old) + 1];
            uint8_t red = bg[BG_WIDTH * 3 * (i + y_old) + 3 * (j + x_old) + 2];
            
            uint32_t pixel = (red << 16) | (green << 8) | blue; // BGR format
            buffer[BG_WIDTH * (i + y_old) + (j + x_old)] = pixel;
        }
    }
}

// Display an asset
void display_asset(uint32_t* buffer, Sprite* sprite, int x_offset, int y_offset) {
    for (int i = 0; i < sprite->height; i++) { // Rows (height)
        for (int j = 0; j < sprite->width; j++) { // Cols (width)						   
            uint8_t blue = sprite->img[sprite->pitch * i + 3 * j];
            uint8_t green = sprite->img[sprite->pitch * i + 3 * j + 1];
            uint8_t red = sprite->img[sprite->pitch * i + 3 * j + 2];
            uint32_t pixel = (red << 16) | (green << 8) | blue; // BGR format

            if (pixel) buffer[BG_WIDTH * (i + sprite->y + y_offset) + (j + sprite->x + x_offset)] = pixel; // Filter black color and set pixel location
        }
    }
}

// Display player sprite (with motion)
void display_player(uint32_t* buffer, Player* player, int x_offset, int y_offset) {
    for (int i = 0; i < player->height; i++) { // Rows (height)
        for (int j = 0; j < player->width; j++) { // Cols (width)						   
            uint8_t blue = player->sprites[player->sprite_var][player->pitch * i + 3 * j];
            uint8_t green = player->sprites[player->sprite_var][player->pitch * i + 3 * j + 1];
            uint8_t red = player->sprites[player->sprite_var][player->pitch * i + 3 * j + 2];
            uint32_t pixel = (red << 16) | (green << 8) | blue; // BGR format

            if (pixel) buffer[BG_WIDTH * (i + player->y + y_offset) + (j + player->x + x_offset)] = pixel; // Filter black color and set pixel location
        }
    }
}

// Check collision between player and stationary obstacles
void check_player_obstacle_collision(Player* player, Sprite* obstacles, int bgx, int obstacle_count) {
    player->collision = -1; // Reset collision flag
    int player_right = player->x + player->width;
    int player_bot = player->y + player->height;

    // Iterate over obstacles to determine collisions
    for (int i = 0; i < obstacle_count; i++) {
        // Only check for obstacles within the screen
        if ((obstacles + i)->x >= bgx - (obstacles + i)->width && (obstacles + i)->x <= bgx + WINDOW_WIDTH - 1 && (obstacles + i)->isVisible) { 
            int obstacle_right = (obstacles + i)->x + (obstacles + i)->width;
            int obstacle_bot = (obstacles + i)->y + (obstacles + i)->height;

            if (player_right >= (obstacles + i)->x && obstacle_right >= player->x) { // Check collision in the x-axis
                if (player_bot >= (obstacles + i)->y && obstacle_bot >= player->y) { // Check collision in the y-axis

                    // Calculate for direction of collision
                    int r_col = player_right - (obstacles + i)->x;
                    int l_col = obstacle_right - player->x;
                    int t_col = obstacle_bot - player->y;
                    int b_col = player_bot - (obstacles + i)->y;

                    if (l_col < r_col && l_col < t_col && l_col < b_col) { // Left collision
                        player->collision = 1;
                    }
                    if (r_col < l_col && r_col < t_col && r_col < b_col) { // Right collision
                        player->collision = 2;
                    }
                    if (t_col < b_col && t_col < r_col && t_col < l_col) { // Top collision
                        player->collision = 3;
                    }
                    if (b_col < t_col && b_col < r_col && b_col < l_col) { // Bot collision
                        player->collision = 4;
                    }
                }
            }
        }      
    }
}

// Update the positions of mobs
void update_sprite_position(Sprite* sprites, int x_displacement, int y_displacement, int bgx, int sprite_count) {
    for (int i = 0; i < sprite_count; i++) {
        // Only update position of active/visible sprites
        if ((sprites + i)->x >= bgx - (sprites + i)->width && (sprites + i)->x <= bgx + WINDOW_WIDTH - 1 && (sprites + i)->isVisible) { 
            if ((sprites + i)->xdir == -1) { // Move left
                (sprites + i)->x -= x_displacement;
            }

            if ((sprites + i)->x < bgx - (sprites + i)->width) { // Mob went out the screen
                (sprites + i)->xdir = 0;
                (sprites + i)->isVisible = false;
            }

            if ((sprites + i)->ydir == 1) { // Move down
                (sprites + i)->y += y_displacement;
            }
            else if ((sprites + i)->ydir == -1) { // Move up
                (sprites + i)->y -= y_displacement;
            }

            if ((sprites + i)->y >= BG_HEIGHT - (sprites + i)->height - 1) { // Lower bound touched
                (sprites + i)->y = BG_HEIGHT - (sprites + i)->height - 1;
                (sprites + i)->ydir = -1;
            }
            else if ((sprites + i)->y <= 0) { // Upper bound touched
                (sprites + i)->y = 0;
                (sprites + i)->ydir = 1;
            }
        }
    }
}

// Check collision between player and mobs
void check_player_sprite_collision(Player* player, Sprite* sprites, int bgx, int sprite_count, int type) {
    int player_right = player->x + player->width;
    int player_bot = player->y + player->height;

    // Iterate over obstacles to determine collisions
    for (int i = 0; i < sprite_count; i++) {
        // Only check for active/visible mobs or corals
        if ((sprites + i)->x >= bgx - (sprites + i)->width && (sprites + i)->x <= bgx + WINDOW_WIDTH - 1 && (sprites + i)->isVisible) { 
            int obstacle_right = (sprites + i)->x + (sprites + i)->width;
            int obstacle_bot = (sprites + i)->y + (sprites + i)->height;

            if (player_right >= (sprites + i)->x && obstacle_right >= player->x) { // Check collision in the x-axis
                if (player_bot >= (sprites + i)->y && obstacle_bot >= player->y) { // Check collision in the y-axis
                    if (type == 0) { // Collision with a mob
                        player->health--; // Decrement health
                    }
                    else { // Collision with a coral
                        if (player->health < MAX_LIVES) {
                            player->health++;
                        }  
                    }

                    (sprites + i)->isVisible = false; // Remove sprite from the screen 
                }
            }
        }
    }
}

// Check collision between ammo and mobs/obstacles
void check_ammo_collision(Ammo* ammo, Sprite* entities, int entity_count) {
    int ammo_right = ammo->x + ammo->width;
    int ammo_bot = ammo->y + ammo->height;

    // Iterate over obstacles to determine collisions
    for (int i = 0; i < entity_count; i++) {
        if ((entities + i)->isVisible) { // Only check for active/visible mobs
            int entity_right = (entities + i)->x + (entities + i)->width;
            int entity_bot = (entities + i)->y + (entities + i)->height;

            if (ammo_right >= (entities + i)->x && entity_right >= ammo->x) { // Check collision in the x-axis
                if (ammo_bot >= (entities + i)->y && entity_bot >= ammo->y) { // Check collision in the y-axis
                    (entities + i)->isVisible = false; // Remove entity from the screen
                    ammo->isFired = false; // Remove ammo from the screen
                }
            }
        }
    }
}

// Reset sprite attributes to initial values when game restarted
void reset_sprite_attributes(Sprite* sprites, int sprite_count) {
    for (int i = 0; i < sprite_count; i++) {
        (sprites + i)->x = (sprites + i)->x_initial;
        (sprites + i)->xdir = (sprites + i)->xdir_initial;
        (sprites + i)->y = (sprites + i)->y_initial;
        (sprites + i)->ydir = (sprites + i)->ydir_initial;
        (sprites + i)->isVisible = true;
    }
}

