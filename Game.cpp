#include "stdio.h"

#include "Game.h"
#include "classes/Player.h"

uint8_t* load_asset(FREE_IMAGE_FORMAT format, const char* filepath) {
    FIBITMAP* asset_fi = FreeImage_Load(format, filepath);
    FreeImage_FlipVertical(asset_fi);
    uint8_t* asset = FreeImage_GetBits(asset_fi);

    return asset;
}

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

void display_asset(uint32_t* buffer, Sprite* sprite) {
    for (int i = 0; i < sprite->height; i++) { // Rows (height)
        for (int j = 0; j < sprite->width; j++) { // Cols (width)						   
            uint8_t blue = sprite->img[sprite->pitch * i + 3 * j];
            uint8_t green = sprite->img[sprite->pitch * i + 3 * j + 1];
            uint8_t red = sprite->img[sprite->pitch * i + 3 * j + 2];
            uint32_t pixel = (red << 16) | (green << 8) | blue; // BGR format

            if (pixel) buffer[BG_WIDTH * (i + sprite->y) + (j + sprite->x)] = pixel; // Filter black color and set pixel location
        }
    }
}

//void display_lives(uint32_t* buffer, Sprite* sprite, int bgx) {
//    for (int i = 0; i < sprite->height; i++) { // Rows (height)
//        for (int j = 0; j < sprite->width; j++) { // Cols (width)						   
//            uint8_t blue = sprite->img[sprite->pitch * i + 3 * j];
//            uint8_t green = sprite->img[sprite->pitch * i + 3 * j + 1];
//            uint8_t red = sprite->img[sprite->pitch * i + 3 * j + 2];
//            uint32_t pixel = (red << 16) | (green << 8) | blue; // BGR format
//
//            if (pixel) buffer[BG_WIDTH * (i + sprite->y) + (j + sprite->x)] = pixel; // Filter black color and set pixel location
//        }
//    }
//
//    if (sprite->x < bgx - (sprite->width)) {
//        sprite->xdir = 1;
//    }
//}

Sprite* generate_obstacles() {
    // Sample
    Sprite obs1 = Sprite(100, 100, 120, 500, 0, 0, FIF_PNG, "assets/b1.png");
    Sprite obs2 = Sprite(100, 100, 0, 0, 0, 0, FIF_PNG, "assets/b1.png");
    Sprite obs3 = Sprite(100, 100, 3000, 1000, 0, 0, FIF_PNG, "assets/b1.png");

    Sprite obstacles[3] = { obs1, obs2, obs3 };

    return obstacles;
}

void check_player_obstacle_collision(Player* player, Sprite* obstacles, int obstacle_count) {
    player->collision = -1; // Reset collision flag

    int player_right = player->x + player->width;
    int player_bot = player->y + player->height;
    int obstacle_right, obstacle_bot;

    // Iterate over obstacles to determine collisions
    for (int i = 0; i < obstacle_count; i++) {
        obstacle_right = (obstacles + i)->x + (obstacles + i)->width;
        obstacle_bot = (obstacles + i)->y + (obstacles + i)->height;

        if (player_right >= (obstacles + i)->x && obstacle_right >= player->x) { // Check collision in the x-axis
            if (player_bot >= (obstacles + i)->y && obstacle_bot >= player->y) { // Check collision in the y-axis
                
                // Calculate for direction of collision
                int r_col = player_right - (obstacles + i)->x;
                int l_col= obstacle_right - player->x;
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

void update_mob_position(Sprite* mobs, int bgx, int mob_count) {
    for (int i = 0; i < mob_count; i++) {
        if ((mobs + i)->xdir == -1) { // Move left
            (mobs + i)->x -= MOB_X_DISPLACEMENT;
        }

        if ((mobs + i)->x < bgx - (mobs + i)->width) {
            (mobs + i)->xdir = 0;
        }

        if ((mobs + i)->ydir == 1) { // Move down
            (mobs + i)->y += MOB_Y_DISPLACEMENT;
        }
        else if ((mobs + i)->ydir == -1) { // Move up
            (mobs + i)->y -= MOB_Y_DISPLACEMENT;
        }

        if ((mobs + i)->y >= BG_HEIGHT - (mobs + i)->height - 1) { // Lower bound touched
            (mobs + i)->ydir = -1;
        }
        else if ((mobs + i)->y <= 0) {// Upper bound touched
            (mobs + i)->ydir = 1;
        }
    }
}

void check_player_mob_collision(Player* player, Sprite* mobs, int mob_count) {
    int player_right = player->x + player->width;
    int player_bot = player->y + player->height;
    int obstacle_right, obstacle_bot;

    // Iterate over obstacles to determine collisions
    for (int i = 0; i < mob_count; i++) {
        obstacle_right = (mobs + i)->x + (mobs + i)->width;
        obstacle_bot = (mobs + i)->y + (mobs + i)->height;

        if (player_right >= (mobs + i)->x && obstacle_right >= player->x) { // Check collision in the x-axis
            if (player_bot >= (mobs + i)->y && obstacle_bot >= player->y) { // Check collision in the y-axis
                player->health--; // Decrement health
                printf("health: %d\n", player->health);

                (mobs + i)->x = 0;
            }
        }
    }
}
