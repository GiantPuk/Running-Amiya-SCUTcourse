#pragma once
#pragma comment(lib, "Msimg32.lib")
#include<easyx.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<windows.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<graphics.h> 
#include<cstdlib>
#include"unit.h"
#include"sword.h"
#include"bullet.h"
#include"object.h"
#include"role.h"
class enemy :public unit {
protected:
	int shooting_cd=0;
	int id;
	int shoot_cd;//射击冷却
	int close_attack_cd=0;
	int close_attack_cdcounting;
	bool wake;
	int damage;//这里damage近战远程是一样的，可以分成两个
	int close_attack_frame=0;
	int distant_attack_frame=0;
	int move_frame=0;
	int attack_close_range = 0;
	int left_wander_barrier;
	int right_wander_barrier;
	int attack_distant_range;//方向也可以分为攻击方向和行走方向
	int value;
	bullet bul[bullet_sum];
	sword sw;
public:
	void checkawake(Amiya& amiya, int xM);
	bool attack_close(Amiya& amiya, int xM);
	bool attack_distant(Amiya& amiya, int xM);
	virtual void getspeed(Amiya& amiya, int xM);
	bool ifshoot(Amiya& amiya, int xM);
	bool check_ifstrike(Amiya& amiya, int xM);
	bool getawake();
	bool getalive();
	virtual void behurt(int i);
	int getstate();
	int getbullet_sum();
	virtual void bullet_update();
	virtual void attack_update(Amiya& amiya, int xM, stone_controller& stone) = 0;
	virtual void show(int xM) = 0;
	virtual void move_update(Amiya&amiya,int xM,stone_controller& stone) = 0;
	int get_bulletdamage(int i);
	int getid();
	int& getvalue();
};
//第一个小怪改成灰色刀哥，索敌，加上一个触地判定
class insect :public enemy {
protected:
	static IMAGE attackright[15];
	static IMAGE attackleft[15];
	static IMAGE moveright[15];
	static IMAGE moveleft[15];
public:
	insect();
	insect(int x, int y);
	void init(int a, int b);
	void show(int xM);
	void close_attack_update(Amiya& amiya, int xM);
	void attack_update(Amiya& amiya, int xM, stone_controller& stone);
	void move_update(Amiya& amiya, int xM, stone_controller& stone);
	void behurt(int i);
};
//第二个小怪术士，在区域内来回走撞墙反弹，后面加的飞机也准备这样
class scorcerer :public enemy {
	static IMAGE bull;
	static IMAGE attackright[8];
	static IMAGE attackleft[8];
	static IMAGE moveright[8];
	static IMAGE moveright1[8];
	static IMAGE moveleft[8];
	static IMAGE moveleft1[8];
public:
	scorcerer(int a, int b, int l, int r);
	void init(int a, int b, int l, int r);
	int get_bulletdamage(int i);
	void creat_bullet(int damage = 20);
	void getspeed(Amiya& amiya, int xM);
	bool bullet_check(unit* s, int i, int xM = 0);
	void distant_attack_update(int xM);
	void show(int xM);
	void attack_update(Amiya& amiya, int xM, stone_controller& stone);
	void move_update(Amiya& amiya, int xM, stone_controller& stone);
	void behurt(int i);
};
//第三个小怪精英怪，可以远程，伤害随即距离递减，距离够的话近战
//加飞机，考虑继承object和enemy，要虚继承一下unit
class elite :public enemy {
	static IMAGE bull;
	static IMAGE attack1right[15];
	static IMAGE attack1right_1[15];
	static IMAGE attack1left[15];
	static IMAGE attack1left_1[15];
	static IMAGE moveright[15];
	static IMAGE moveleft[15];
	static IMAGE moveright_1[15];
	static IMAGE moveleft_1[15];
public:
	elite(int a, int b, int l, int r);
	void init(int a, int b, int l, int r);
	void creat_bullet(int damage = 20);
	bool bullet_check(unit* s, int i, int xM = 0);
	void check_attack(Amiya& amiya, int xM);
	void getspeed(Amiya& amiya, int xM);
	void distant_attack_update(int xM);
	void close_attack_update(Amiya& amiya, int xM);
	void show(int xM);
	void attack_update(Amiya& amiya, int xM, stone_controller& stone);
	void move_update(Amiya& amiya, int xM, stone_controller& stone);
	void behurt(int i);
};
class Blacksnake :public enemy {
protected:
	int cd1;
	int cd2;
	int cd3;
	int cd1_counter;
	int cd2_counter;
	int cd3_counter;
	int attack;
	int damage1;//子弹伤害
	int damage2;//近战伤害
	int attacking_speed;
	int special_attack_frame;
	int boss_vx;
	IMAGE bull_left;
	IMAGE bull_right;
	IMAGE special_bull;
	bullet special_bullet[special_bullet_sum];
	IMAGE right_move[20];
	IMAGE right_move_1[20];
	IMAGE left_move[20];
	IMAGE left_move_1[20];
	IMAGE head;
	IMAGE right_attack[30];
	IMAGE right_attack_1[30];
	IMAGE left_attack[30];
	IMAGE left_attack_1[30];
	IMAGE right_distant_attack[15];
	IMAGE left_distant_attack[15];
	IMAGE special_effect_right[2];
	IMAGE special_effect_left[2];
public:
	//感觉塔露拉有点小，后期看看能不能调大一点
	Blacksnake(int a, int b);
	void init(int a, int b);
	void getspeed(Amiya& amiya, int xM);
	void bullet_update();
	void move_update(Amiya& amiya, int xM, stone_controller& stone);
	void close_attack_update(Amiya& amiya, int xM);
	bool bullet_check(unit* s, int i, int xM = 0);
	bool special_bullet_check(unit* s, int i, int xM = 0);
	void special_attack_update();
	void creat_bullet(int damage = 20);
	void distant_attack_update();
	void reborn_update();
	void attack_update(Amiya& amiya, int xM, stone_controller& stone);
	void show(int xM);
	void behurt(int i);
};
class enemy_controller {
	enemy* e[200];
	int enemy_sum;
public:
	void init(int map_id);
	void bullet_update(Amiya& amiya, int xM);
	void move_update(int xM, Amiya& amiya, stone_controller& stone);
	void grow_check(Amiya& amiya);
	void attack_check(Amiya& amiya, int xM, stone_controller& stone);
	void show(int xM);
	void role_attack_close(sword sw, int xM);
};