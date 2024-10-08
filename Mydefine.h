#pragma once
#define c_height 70 
#define c_width 50
#define c_jump 1;
#define ground_h (20*2)
#define ground_w (20*2)
#define map_w (3000*2)
#define map_h (300*2)
#define screem_h (300*2)//拼写错误，记得改
#define screem_w (500*2)
#define left_barrier (100*2)
#define right_barrier (300*2)
#define enemy1_h (60)
#define enemy1_w (90)
#define enemy2_h (60)
#define enemy2_w (50)
#define enemy3_h (80)
#define enemy3_w (60)
#define boss_height (90)
#define boss_width (120)
#define c_judge 10
#define bullet_sum 2
#define second_floor 5
#define third_floor 9
#define fourth_floor 14
#define special_bullet_sum 20
#define g 10
#define master 10
#define swordman 11
#define boss_battle_left 4000
#define boss_battle_right 5800
#define boss_battle_left_secondfloor1 4300
#define boss_battle_right_secondfloor1 4800
#define boss_battle_left_secondfloor2 5200 
#define boss_battle_right_secondfloor2 5600
#define buffer 80
#define max_record 10
//状态值的定义
#define stand 0
#define jump 2
#define walk 1
#define toattack_close 3
#define toattack_distant 4
#define spectial_attack 6
#define reborn 5
class Point {
public:
	int x;
	int y;
};
extern inline void putimage_alpha(int x, int y, IMAGE* img) {
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h, GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}