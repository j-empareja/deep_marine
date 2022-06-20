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

void display_asset(uint32_t* buffer, Sprite* sprite, int offset_x, int offset_y) {
    for (int i = 0; i < sprite->height; i++) { // Rows (height)
        for (int j = 0; j < sprite->width; j++) { // Cols (width)						   
            uint8_t blue = sprite->img[sprite->pitch * i + 3 * j];
            uint8_t green = sprite->img[sprite->pitch * i + 3 * j + 1];
            uint8_t red = sprite->img[sprite->pitch * i + 3 * j + 2];
            uint32_t pixel = (red << 16) | (green << 8) | blue; // BGR format

            if (pixel) buffer[BG_WIDTH * (i + sprite->y + offset_y) + (j + sprite->x + offset_x)] = pixel; // Filter black color and set pixel location
        }
    }
}

Sprite* generate_obstacles() {
    // Sample
    Sprite obs1 = Sprite(100, 100, 120, 500, 0, 0, FIF_PNG, "assets/b1.png");
    Sprite obs2 = Sprite(100, 100, 0, 0, 0, 0, FIF_PNG, "assets/b1.png");
    Sprite obs3 = Sprite(100, 100, 3000, 1000, 0, 0, FIF_PNG, "assets/b1.png");

    Sprite obstacles[3] = { obs1, obs2, obs3 };

    return obstacles;
}

bool check_player_collision(Player* player, Sprite* obstacles, int obstacle_count) {
    bool collision = false;
    for (int i = 0; i < obstacle_count; i++) {
        printf("playerX: %d, playerY: %d, obstacleX: %d, obstacleY: %d\n", player->x, player->y, (obstacles + i)->x, (obstacles + i)->y);
        if (player->width + player->x >= (obstacles + i)->x && (obstacles + i)->width + (obstacles + i)->x >= player->x) { // Check collision in the x-axis
            if (player->height + player->y >= (obstacles + i)->y && (obstacles + i)->height + (obstacles + i)->y >= player->y) { // Check collision in the y-axis
                printf("playerX: %d, playerY: %d, obstacleX: %d, obstacleY: %d\n", player->x, player->y, (obstacles + i)->x, (obstacles + i)->y);
                collision = true; // Player collided with an obstacle
            }
        }
    }
    return collision;
}