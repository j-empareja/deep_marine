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
    uint8_t* bg2 = load_asset(FIF_PNG, "assets/bg1.png");
    uint8_t* bg3 = load_asset(FIF_PNG, "assets/bg1.png");

    // Player(int width, int height, int x, int y, int xdir, int ydir, int health, int collision, FREE_IMAGE_FORMAT format, const char* filepath);
    Player player = Player(PLAYER_WIDTH, PLAYER_HEIGHT, 0, 0, 0, 0, 3, -1, FIF_PNG, "assets/submarine.png");

    // Ammo(int width, int height, int x, int y, int xdir, int ydir, FREE_IMAGE_FORMAT format, const char* filepath);
    Ammo ammo = Ammo(50, 50, 0, 0, 0, 0, FIF_PNG, "assets/ammo.png");

    // Sprite(int width, int height, int x, int y, int xdir, int ydir, FREE_IMAGE_FORMAT format, const char* filepath);
    // Declare stage 1 sprites
    Sprite obs1_1 = Sprite(100, 100, 500, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs1_2 = Sprite(100, 100, 500, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs1_3 = Sprite(100, 100, 1400, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs1_4 = Sprite(100, 100, 1400, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs1_5 = Sprite(100, 100, 1400, 420, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs1_6 = Sprite(100, 100, 1400, 520, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs1_7 = Sprite(100, 100, 1400, 620, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs1_8 = Sprite(100, 100, 3500, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs1_9 = Sprite(100, 100, 3500, 310, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs1_10 = Sprite(100, 100, 3500, 620, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs1_11 = Sprite(100, 100, 6000, 420, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs1_12 = Sprite(100, 100, 6000, 520, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs1_13 = Sprite(100, 100, 6000, 620, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs1_14 = Sprite(100, 100, 7700, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs1_15 = Sprite(100, 100, 7700, 310, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs1_16 = Sprite(100, 100, 7700, 620, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs1_17 = Sprite(100, 100, 10500, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs1_18 = Sprite(100, 100, 10500, 310, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs1_19 = Sprite(100, 100, 10500, 620, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs1_20 = Sprite(100, 100, 14000, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs1_21 = Sprite(100, 100, 14000, 310, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs1_22 = Sprite(100, 100, 14000, 620, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obstacles1[22] = {obs1_1, obs1_2, obs1_3, obs1_4, obs1_5, obs1_6, obs1_7, obs1_8, obs1_9, obs1_10, obs1_11, 
                             obs1_12, obs1_13, obs1_14, obs1_15, obs1_16, obs1_17, obs1_18, obs1_19, obs1_20, obs1_21};

    Sprite mob1_1 = Sprite(150, 100, 800, 500, -1, 0, true, FIF_PNG, "assets/shark.png");
    Sprite mob1_2 = Sprite(150, 100, 1700, 310, -1, 0, true, FIF_PNG, "assets/shark.png");
    Sprite mob1_3 = Sprite(100, 150, 2300, 0, 0, -1, true, FIF_PNG, "assets/squid.png");
    Sprite mob1_4 = Sprite(100, 150, 3000, 500, 0, -1, true, FIF_PNG, "assets/squid.png");
    Sprite mob1_5 = Sprite(100, 150, 4200, 100, 0, 1, true, FIF_PNG, "assets/squid.png");
    Sprite mob1_6 = Sprite(100, 150, 5500, 400, 0, -1, true, FIF_PNG, "assets/squid.png");
    Sprite mob1_7 = Sprite(100, 150, 6500, 200, 0, 1, true, FIF_PNG, "assets/squid.png");
    Sprite mob1_8 = Sprite(100, 150, 8500, 500, 0, -1, true, FIF_PNG, "assets/squid.png");
    Sprite mob1_9 = Sprite(100, 150, 8700, 500, 0, 1, true, FIF_PNG, "assets/squid.png");
    Sprite mob1_10 = Sprite(150, 100, 9500, 100, -1, 0, true, FIF_PNG, "assets/shark.png");
    Sprite mob1_11 = Sprite(150, 100, 12000, 200, -1, 0, true, FIF_PNG, "assets/shark.png");
    Sprite mob1_12 = Sprite(150, 100, 13000, 400, -1, 0, true, FIF_PNG, "assets/shark.png");
    Sprite mobs1[12] = { mob1_1, mob1_2, mob1_3, mob1_4, mob1_5, mob1_6, mob1_7, mob1_8, mob1_9, mob1_10, mob1_11, mob1_12};

    Sprite coral1 = Sprite(100, 100, 500, 0, -1, 1, true, FIF_PNG, "assets/coral.png");
    Sprite coral2 = Sprite(100, 100, 1500, 500, -1, -1, true, FIF_PNG, "assets/coral.png");
    Sprite coral3 = Sprite(100, 100, 2500, 400, 0, 1, true, FIF_PNG, "assets/coral.png");
    Sprite coral4 = Sprite(100, 100, 3500, 100, -1, -1, true, FIF_PNG, "assets/coral.png");
    Sprite corals1[4] = {coral1, coral2, coral3, coral4};

    // Declare stage 2 sprites
    // LETTER C
    Sprite obs2_1 = Sprite(100, 100, 2142, 200, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_2 = Sprite(100, 100, 2042, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_3 = Sprite(100, 100, 1942, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_4 = Sprite(100, 100, 1842, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_5 = Sprite(100, 100, 1742, 200, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_6 = Sprite(100, 100, 1742, 300, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_7 = Sprite(100, 100, 1742, 400, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_8 = Sprite(100, 100, 1842, 500, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_9 = Sprite(100, 100, 1942, 600, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_10 = Sprite(100, 100, 2042, 500, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_11 = Sprite(100, 100, 2142, 400, 0, 0, true, FIF_PNG, "assets/obs.png");

    // LETTER P 
    Sprite obs2_12 = Sprite(100, 100, 3000, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_13 = Sprite(100, 100, 3000, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_14 = Sprite(100, 100, 3000, 200, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_15 = Sprite(100, 100, 3000, 300, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_16 = Sprite(100, 100, 3000, 400, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_17 = Sprite(100, 100, 3000, 500, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_18 = Sprite(100, 100, 3000, 600, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_19 = Sprite(100, 100, 3100, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_20 = Sprite(100, 100, 3200, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_21 = Sprite(100, 100, 3300, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_22 = Sprite(100, 100, 3400, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_23 = Sprite(100, 100, 3400, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_24 = Sprite(100, 100, 3100, 300, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_25 = Sprite(100, 100, 3200, 300, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_26 = Sprite(100, 100, 3300, 300, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_27 = Sprite(100, 100, 3400, 300, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_28 = Sprite(100, 100, 3400, 200, 0, 0, true, FIF_PNG, "assets/obs.png");
    
    // LETTER E
    Sprite obs2_29 = Sprite(100, 100, 4000, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_30 = Sprite(100, 100, 4000, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_31 = Sprite(100, 100, 4000, 200, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_32 = Sprite(100, 100, 4000, 300, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_33 = Sprite(100, 100, 4000, 400, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_34 = Sprite(100, 100, 4000, 500, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_35 = Sprite(100, 100, 4000, 600, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_36 = Sprite(100, 100, 4100, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_37 = Sprite(100, 100, 4200, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_38 = Sprite(100, 100, 4300, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_39 = Sprite(100, 100, 4400, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_40 = Sprite(100, 100, 4100, 300, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_41 = Sprite(100, 100, 4200, 300, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_42 = Sprite(100, 100, 4100, 600, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_43 = Sprite(100, 100, 4200, 600, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_44 = Sprite(100, 100, 4300, 600, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_45 = Sprite(100, 100, 4400, 600, 0, 0, true, FIF_PNG, "assets/obs.png");

    // LETTER C (1)
    Sprite obs2_46 = Sprite(100, 100, 5400, 200, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_47 = Sprite(100, 100, 5300, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_48 = Sprite(100, 100, 5200, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_49 = Sprite(100, 100, 5100, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_50 = Sprite(100, 100, 5000, 200, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_51 = Sprite(100, 100, 5000, 300, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_52 = Sprite(100, 100, 5000, 400, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_53 = Sprite(100, 100, 5100, 500, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_54 = Sprite(100, 100, 5200, 600, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_55 = Sprite(100, 100, 5300, 500, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_56 = Sprite(100, 100, 5400, 400, 0, 0, true, FIF_PNG, "assets/obs.png");

    // LETTER O
    Sprite obs2_57 = Sprite(100, 100, 6400, 200, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_58 = Sprite(100, 100, 6300, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_59 = Sprite(100, 100, 6200, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_60 = Sprite(100, 100, 6100, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_61 = Sprite(100, 100, 6000, 200, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_62 = Sprite(100, 100, 6000, 300, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_63 = Sprite(100, 100, 6000, 400, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_64 = Sprite(100, 100, 6100, 500, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_65 = Sprite(100, 100, 6200, 600, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_66 = Sprite(100, 100, 6300, 500, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_67 = Sprite(100, 100, 6400, 400, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_68 = Sprite(100, 100, 6400, 300, 0, 0, true, FIF_PNG, "assets/obs.png");

    // LETTER G
    Sprite obs2_69 = Sprite(100, 100, 7300, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_70 = Sprite(100, 100, 7200, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_71 = Sprite(100, 100, 7100, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_72 = Sprite(100, 100, 7000, 200, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_73 = Sprite(100, 100, 7000, 300, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_74 = Sprite(100, 100, 7000, 400, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_75 = Sprite(100, 100, 7100, 500, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_76 = Sprite(100, 100, 7200, 600, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_77 = Sprite(100, 100, 7300, 500, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_78 = Sprite(100, 100, 7400, 400, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_79 = Sprite(100, 100, 7400, 300, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_80 = Sprite(100, 100, 7300, 300, 0, 0, true, FIF_PNG, "assets/obs.png");

    // NUMBER 1
    Sprite obs2_81 = Sprite(100, 100, 8200, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_82 = Sprite(100, 100, 8200, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_83 = Sprite(100, 100, 8200, 200, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_84 = Sprite(100, 100, 8200, 300, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_85 = Sprite(100, 100, 8200, 400, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_86 = Sprite(100, 100, 8200, 500, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_87 = Sprite(100, 100, 8200, 600, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_88 = Sprite(100, 100, 8100, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_89 = Sprite(100, 100, 8100, 600, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_90 = Sprite(100, 100, 8000, 200, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_91 = Sprite(100, 100, 8000, 600, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_92 = Sprite(100, 100, 8300, 600, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs2_93 = Sprite(100, 100, 8400, 600, 0, 0, true, FIF_PNG, "assets/obs.png");

    Sprite obstacles2[93] = {obs2_1, obs2_2, obs2_3, obs2_4, obs2_5, obs2_6, obs2_7, obs2_8, obs2_9, 
        obs2_10, obs2_11, obs2_12, obs2_13, obs2_14, obs2_15, obs2_16, obs2_17, obs2_18, obs2_19,
        obs2_20, obs2_21, obs2_22, obs2_23, obs2_24, obs2_25, obs2_26, obs2_27, obs2_28, obs2_29,
        obs2_30, obs2_31, obs2_32, obs2_33, obs2_34, obs2_35, obs2_36, obs2_37, obs2_38, obs2_39,
        obs2_40, obs2_41, obs2_42, obs2_43, obs2_44, obs2_45, obs2_46, obs2_47, obs2_48, obs2_49,
        obs2_50, obs2_51, obs2_52, obs2_53, obs2_54, obs2_55, obs2_56, obs2_57, obs2_58, obs2_59,
        obs2_60, obs2_61, obs2_62, obs2_63, obs2_64,obs2_65, obs2_66, obs2_67, obs2_68, obs2_69,
        obs2_70, obs2_71,obs2_72, obs2_73, obs2_74, obs2_75, obs2_76, obs2_77, obs2_78, obs2_79,
        obs2_80, obs2_81, obs2_82, obs2_83, obs2_84, obs2_85, obs2_86, obs2_87, obs2_88, obs2_89, 
        obs2_90, obs2_91, obs2_92, obs2_93};

    Sprite mob2_1 = Sprite(100, 150, 300, 70, 0, 1, true, FIF_PNG, "assets/squid.png");
    Sprite mob2_2 = Sprite(100, 150, 600, 620, 0, -1, true, FIF_PNG, "assets/squid.png");
    Sprite mob2_3 = Sprite(100, 150, 1100, 130, -1, 1, true, FIF_PNG, "assets/squid.png");
    Sprite mob2_4 = Sprite(100, 150, 2000, 0, -1, 0, true, FIF_PNG, "assets/squid.png");
    Sprite mob2_5 = Sprite(100, 150, 4100, 100, -1, 1, true, FIF_PNG, "assets/squid.png");
    Sprite mob2_6 = Sprite(100, 150, 4300, 100, -1, 0, true, FIF_PNG, "assets/squid.png");
    Sprite mob2_7 = Sprite(100, 150, 13000, 570, 0, 1, true, FIF_PNG, "assets/squid.png");
    Sprite mob2_8 = Sprite(100, 150, 12000, 0, 0, -1, true, FIF_PNG, "assets/squid.png");
    Sprite mob2_9 = Sprite(100, 150, 10000, 570, 0, 1, true, FIF_PNG, "assets/squid.png");
    Sprite mob2_10 = Sprite(100, 150, 11000, 0, 0, -1, true, FIF_PNG, "assets/squid.png");
    Sprite mob2_11 = Sprite(150, 100, 14000, 0, -1, 0, true, FIF_PNG, "assets/shark.png");
    Sprite mob2_12 = Sprite(150, 100, 14500, 620, -1, 0, true, FIF_PNG, "assets/shark.png");
    Sprite mobs2[12] = {mob2_1, mob2_2, mob2_3, mob2_4, mob2_5, mob2_6, mob2_7, mob2_8, mob2_9, 
        mob2_10, mob2_11, mob2_12};

    Sprite coral2_1 = Sprite(100, 100, 1000, 0, -1, 1, true, FIF_PNG, "assets/coral.png");
    Sprite coral2_2 = Sprite(100, 100, 2000, 500, 0, -1, true, FIF_PNG, "assets/coral.png");
    Sprite coral2_3 = Sprite(100, 100, 3000, 400, -1, 1, true, FIF_PNG, "assets/coral.png");
    Sprite corals2[3] = {coral2_1, coral2_2, coral2_3};

    // Declare stage 3 sprites
    Sprite obs3_1 = Sprite(100, 100, 800, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_2 = Sprite(100, 100, 900, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_3 = Sprite(100, 100, 1000, 200, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_4 = Sprite(100, 100, 1100, 300, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_5 = Sprite(100, 100, 1200, 400, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_6 = Sprite(100, 100, 1300, 500, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_7 = Sprite(100, 100, 1400, 600, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_8 = Sprite(100, 100, 2000, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_9 = Sprite(100, 100, 2100, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_10 = Sprite(100, 100, 2500, 620, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_11 = Sprite(100, 100, 2500, 520, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_12 = Sprite(100, 100, 3000, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_13 = Sprite(100, 100, 3000, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_14 = Sprite(100, 100, 3000, 520, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_15 = Sprite(100, 100, 3000, 620, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_16 = Sprite(100, 100, 3800, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_17 = Sprite(100, 100, 3800, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_18 = Sprite(100, 100, 3900, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_19 = Sprite(100, 100, 3900, 100, 0, 0, true, FIF_PNG, "assets/obs.png");

    Sprite obs3_20 = Sprite(100, 100, 5000, 0, 0, 0, true, FIF_PNG, "assets/obs.png");    // START: long 'w' obstacle
    Sprite obs3_21 = Sprite(100, 100, 5100, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_22 = Sprite(100, 100, 5200, 200, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_23 = Sprite(100, 100, 5300, 300, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_24 = Sprite(100, 100, 5400, 400, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_25 = Sprite(100, 100, 5500, 500, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_26 = Sprite(100, 100, 5600, 600, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_27 = Sprite(100, 100, 5700, 500, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_28 = Sprite(100, 100, 5800, 400, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_29 = Sprite(100, 100, 5900, 300, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_30 = Sprite(100, 100, 6000, 200, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_31 = Sprite(100, 100, 6100, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_32 = Sprite(100, 100, 6200, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_33 = Sprite(100, 100, 6300, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_34 = Sprite(100, 100, 6400, 200, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_35 = Sprite(100, 100, 6500, 300, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_36 = Sprite(100, 100, 6600, 400, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_37 = Sprite(100, 100, 6700, 500, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_38 = Sprite(100, 100, 6800, 600, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_39 = Sprite(100, 100, 6900, 500, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_40 = Sprite(100, 100, 7000, 400, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_41 = Sprite(100, 100, 7100, 300, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_42 = Sprite(100, 100, 7200, 200, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_43 = Sprite(100, 100, 7300, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_44 = Sprite(100, 100, 7400, 0, 0, 0, true, FIF_PNG, "assets/obs.png");    // END: long 'w' obstacle

    Sprite obs3_45 = Sprite(100, 100, 8400, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_46 = Sprite(100, 100, 8400, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_47 = Sprite(100, 100, 8400, 200, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_48 = Sprite(100, 100, 8400, 300, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_49 = Sprite(100, 100, 8400, 400, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_50 = Sprite(100, 100, 8400, 500, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_51 = Sprite(100, 100, 8400, 600, 0, 0, true, FIF_PNG, "assets/obs.png");

    Sprite obs3_52 = Sprite(100, 100, 9000, 420, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_53 = Sprite(100, 100, 9000, 520, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_54 = Sprite(100, 100, 9000, 620, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_55 = Sprite(100, 100, 9100, 420, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_56 = Sprite(100, 100, 9100, 520, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_57 = Sprite(100, 100, 9100, 620, 0, 0, true, FIF_PNG, "assets/obs.png");

    Sprite obs3_58 = Sprite(100, 100, 9500, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_59 = Sprite(100, 100, 9500, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_60 = Sprite(100, 100, 9500, 200, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_61 = Sprite(100, 100, 9500, 300, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_62 = Sprite(100, 100, 9600, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_63 = Sprite(100, 100, 9600, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_64 = Sprite(100, 100, 9600, 200, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_65 = Sprite(100, 100, 9600, 300, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_66 = Sprite(100, 100, 9700, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_67 = Sprite(100, 100, 9700, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_68 = Sprite(100, 100, 9700, 200, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_69 = Sprite(100, 100, 9700, 300, 0, 0, true, FIF_PNG, "assets/obs.png");

    Sprite obs3_70 = Sprite(100, 100, 10100, 620, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_71 = Sprite(100, 100, 10200, 520, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_72 = Sprite(100, 100, 10200, 620, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_73 = Sprite(100, 100, 10300, 420, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_74 = Sprite(100, 100, 10300, 520, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_75 = Sprite(100, 100, 10300, 620, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_76 = Sprite(100, 100, 10400, 320, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_77 = Sprite(100, 100, 10400, 420, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_78 = Sprite(100, 100, 10400, 520, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_79 = Sprite(100, 100, 10400, 620, 0, 0, true, FIF_PNG, "assets/obs.png");

    Sprite obs3_80 = Sprite(100, 100, 11200, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_81 = Sprite(100, 100, 11200, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_82 = Sprite(100, 100, 11300, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_83 = Sprite(100, 100, 11300, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_84 = Sprite(100, 100, 11300, 200, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_85 = Sprite(100, 100, 11400, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_86 = Sprite(100, 100, 11400, 100, 0, 0, true, FIF_PNG, "assets/obs.png");

    Sprite obs3_87 = Sprite(100, 100, 11700, 420, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_88 = Sprite(100, 100, 11700, 520, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_89 = Sprite(100, 100, 11700, 620, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_90 = Sprite(100, 100, 11800, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_91 = Sprite(100, 100, 11800, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_92 = Sprite(100, 100, 11800, 0, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_93 = Sprite(100, 100, 11800, 100, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_94 = Sprite(100, 100, 11900, 200, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_95 = Sprite(100, 100, 11900, 0, 0, 0, true, FIF_PNG, "assets/obs.png");

    Sprite obs3_96 = Sprite(100, 100, 13100, 320, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_97 = Sprite(100, 100, 13200, 420, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_98 = Sprite(100, 100, 13300, 520, 0, 0, true, FIF_PNG, "assets/obs.png");
    Sprite obs3_99 = Sprite(100, 100, 13400, 620, 0, 0, true, FIF_PNG, "assets/obs.png");

    Sprite obstacles3[100] = { obs3_1, obs3_2, obs3_3, obs3_4, obs3_5, obs3_6, obs3_7, obs3_8, obs3_9, obs3_10,
                              obs3_11, obs3_12, obs3_13, obs3_14, obs3_15, obs3_16, obs3_17, obs3_18, obs3_19, obs3_20,
                              obs3_21, obs3_22, obs3_23, obs3_24, obs3_25, obs3_26, obs3_27, obs3_28, obs3_29, obs3_30,
                              obs3_31, obs3_32, obs3_33, obs3_34, obs3_35, obs3_36, obs3_37, obs3_38, obs3_39, obs3_40,
                              obs3_41, obs3_42, obs3_43, obs3_44, obs3_45, obs3_46, obs3_47, obs3_48, obs3_49, obs3_50,
                              obs3_51, obs3_52, obs3_53, obs3_54, obs3_55, obs3_56, obs3_57, obs3_58, obs3_59, obs3_60,
                              obs3_61, obs3_62, obs3_63, obs3_64, obs3_65, obs3_66, obs3_67, obs3_68, obs3_69, obs3_70,
                              obs3_71, obs3_72, obs3_73, obs3_74, obs3_75, obs3_76, obs3_77, obs3_78, obs3_79, obs3_80,
                              obs3_81, obs3_82, obs3_83, obs3_84, obs3_85, obs3_86, obs3_87, obs3_88, obs3_89, obs3_90,
                              obs3_81, obs3_92, obs3_93, obs3_94, obs3_95, obs3_96, obs3_97, obs3_98, obs3_99 };

    Sprite mob3_1 = Sprite(100, 150, 600, 0, -1, 0, true, FIF_PNG, "assets/squid.png");
    Sprite mob3_2 = Sprite(150, 100, 1000, 310, -1, 0, true, FIF_PNG, "assets/shark.png");
    Sprite mob3_3 = Sprite(100, 150, 2300, 0, 0, -1, true, FIF_PNG, "assets/squid.png");
    Sprite mob3_4 = Sprite(100, 150, 2800, 500, 0, -1, true, FIF_PNG, "assets/squid.png");
    Sprite mob3_5 = Sprite(100, 150, 3000, 100, 0, 1, true, FIF_PNG, "assets/squid.png");
    Sprite mob3_6 = Sprite(100, 150, 3000, 200, -1, 0, true, FIF_PNG, "assets/squid.png");
    Sprite mob3_7 = Sprite(100, 150, 3200, 400, 0, 1, true, FIF_PNG, "assets/squid.png");
    Sprite mob3_8 = Sprite(100, 150, 4800, 0, 0, 1, true, FIF_PNG, "assets/squid.png");
    Sprite mob3_9 = Sprite(100, 150, 8000, 520, -1, 1, true, FIF_PNG, "assets/squid.png");
    Sprite mob3_10 = Sprite(150, 100, 11000, 100, -1, 0, true, FIF_PNG, "assets/shark.png");
    Sprite mob3_11 = Sprite(150, 100, 11100, 300, -1, 0, true, FIF_PNG, "assets/shark.png");
    Sprite mob3_12 = Sprite(150, 100, 11200, 500, -1, 0, true, FIF_PNG, "assets/shark.png");
    Sprite mob3_13 = Sprite(100, 150, 14000, 500, -1, 1, true, FIF_PNG, "assets/squid.png");
    
    Sprite mobs3[13] = {mob3_1, mob3_2, mob3_3, mob3_4, mob3_5, mob3_6, mob3_7, mob3_8, mob3_9, mob3_10, mob3_11, mob3_12, mob3_13};

    Sprite coral31 = Sprite(100, 100, 1000, 0, -1, 1, true, FIF_PNG, "assets/coral.png");
    Sprite coral32 = Sprite(100, 100, 2000, 500, 0, -1, true, FIF_PNG, "assets/coral.png");
    Sprite coral33 = Sprite(100, 100, 3000, 400, -1, 1, true, FIF_PNG, "assets/coral.png");
    Sprite corals3[3] = {coral31, coral32, coral33};

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
    data.restarted = &restarted;
    data.isGameOver = &isGameOver;
    data.isContinued = &isContinued;

    mfb_set_keyboard_callback(window, key_press_handler);
    mfb_set_user_data(window, (void*)&data);

    do {
        static int bgx = 0;

        // Updates every stage
        static Sprite* current_obstacles;
        static Sprite* current_mobs;
        static Sprite* current_corals;
        static uint8_t* current_bg;
        static int obstacle_count;
        static int mob_count;
        static int coral_count;

        data.bgx = &bgx;

        if (isContinued) {
            if (stage == 1) { // Set stage 1 parameters
                // Update set of sprites
                current_obstacles = obstacles1;
                current_mobs = mobs1;
                current_corals = corals1;
                obstacle_count = 22;
                mob_count = 12;
                coral_count = 4;

                if (restarted) { // Set the sprites' positions to their initial positions
                    reset_sprite_attributes(obstacles1, obstacle_count);
                    reset_sprite_attributes(mobs1, mob_count);
                    reset_sprite_attributes(corals1, coral_count);
                }

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
                obstacle_count = 93;
                mob_count = 12;
                coral_count = 3;

                if (restarted) { // Set the sprites' positions to their initial positions
                    reset_sprite_attributes(obstacles2, obstacle_count);
                    reset_sprite_attributes(mobs2, mob_count);
                    reset_sprite_attributes(corals2, coral_count);
                }

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
            else { // Set stage 3 parameters
                // Update set of sprites
                current_obstacles = obstacles3;
                current_mobs = mobs3;
                current_corals = corals3;
                obstacle_count = 100;
                mob_count = 13;
                coral_count = 3;

                if (restarted) { // Set the sprites' positions to their initial positions
                    reset_sprite_attributes(obstacles3, obstacle_count);
                    reset_sprite_attributes(mobs3, mob_count);
                    reset_sprite_attributes(corals3, coral_count);
                }

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
                display_asset(frame_buffer, &cont, bgx, 0); // Show stage complete prompt

                if (ammo.isFired) {
                    // Reset/update the necessary variables
                    bgx = 0;
                    
                    player.x = 0;
                    player.y = 0;
                    isContinued = true;

                    if (stage < 3)
                        stage++;
                    else {
                        stage = 1; // Restart game
                        restarted = true;
                        stageStarted = false;
                        player.health = 3;
                    }
                    reset_sprite_attributes(lives, MAX_LIVES);
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

                update_bg(frame_buffer, current_bg, bgx, 0); // Update background based
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
                        display_asset(frame_buffer, &lives[i], bgx, 0);
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
            display_asset(frame_buffer, &gameover, bgx, 0);
            stage = 1;
            stageStarted = false;
        }

        // Update window
        uint32_t* stride = frame_buffer + bgx;
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
        }
        else if (key == KB_KEY_DOWN && data->player->collision != 4 && *(data->stageStarted)) { // Move down
            data->player->y_old = data->player->y;
            data->player->y += PLAYER_Y_DISPLACEMENT;
        }
        else if (key == KB_KEY_SPACE && !(data->ammo->isFired) && *(data->stageStarted)) { // Fire weapon
            data->ammo->x = data->player->x + data->player->width + BG_X_DISPLACEMENT;
            data->ammo->y = data->player->y + data->player->height / 2 - data->ammo->height / 2;
            data->ammo->isFired = true;
        }
        else if (key == KB_KEY_ENTER && !*(data->stageStarted)) { // Start stage or restart after game over
            if (!(*(data->isGameOver))) // Start stage
                *(data->stageStarted) = true; 

            if (*(data->isGameOver)) {
                // Reset the necessary variables
                data->player->x = 0;
                data->player->y = 0;
                data->player->health = 3;
                *(data->bgx) = 0;
                *(data->isGameOver) = false;
                *(data->restarted) = true;
                *(data->isContinued) = true;
            }
        }

        // Make sure player sprite does not go beyond boundaries
        if (data->player->x >= *(data->bgx) + WINDOW_WIDTH - PLAYER_WIDTH) { // Right bound touched
            data->player->x = *(data->bgx) + WINDOW_WIDTH - PLAYER_WIDTH;
        }

        if (data->player->y >= BG_HEIGHT - PLAYER_HEIGHT - 1) { // Lower bound touched
            data->player->y = BG_HEIGHT - PLAYER_HEIGHT - 1;
        }
        else if (data->player->y <= 0) {// Upper bound touched
            data->player->y = 0;
        }
    }
}
