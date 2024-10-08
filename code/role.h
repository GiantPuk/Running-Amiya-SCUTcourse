#pragma once
#include<easyx.h>
#include<iostream>
#include<iostream>
#include<vector>
#include<windows.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<graphics.h>
#include<cstdlib>
#include"Mydefine.h"
#include"unit.h"
#include"bullet.h"
#include"sword.h"
class Amiya :public unit {
	bool onground = 1;
	int state = 0;
	int identity;
	int left_check;
	int right_check;
	int condition;
	bool ifshoot;
	bool ifattack_close;
	bool first_jump = 0;
	int shoot_frame;
	int combat_frame;
	int attack_close_range = 50;
	int move_frame;
	int change_cd;
	int changing_cd;
	int growing;
	int max_grow;
	int medicine_sum;
	int damage_close;
	int damage_distant;
	int damage_close_init;
	int damage_distant_init;
	sword sw;
	bullet bul[5];
	IMAGE bull;
	IMAGE head[2];
	IMAGE masterright[10];
	IMAGE masterright1[10];
	IMAGE masterleft[10];
	IMAGE masterleft1[10];
	IMAGE swordright[16];
	IMAGE swordleft[16];
	IMAGE moveright[10];
	IMAGE moveleft[10];
public:
	Amiya();
	void init();
	void move();
	void show(int xM);
	void checkattack1(unit* s);
	void creat_bullet(int xM);
	void bullet_update();
	bool bullet_check(unit* s, int i);
	void behurt(int i);
	int get_bulletdamage(int i);
	void creat_sword(int xM);
	bool getalive();
	int getbullet_sum();
	bool ifonground();
	bool getifshoot();
	bool getifattack_close();
	sword& getsw();
	void land();
	void togrow(int i);
	void getmedicine();
	void fall();
	int getdirection();
	int getstate();
	int& changestate();
	void check_if_die();
	void growing_update();
};