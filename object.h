#pragma once
#include<easyx.h>
#include<iostream>
#include<vector>
#include<windows.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<graphics.h>
#include<vector>
#include"Mydefine.h"
#include"unit.h"
#include"role.h"
class object :virtual public unit {
protected:
public:
	object();
	object(int h, int w);
	void putxy(int a, int b);
	bool check_r(unit* s, int xM);
	bool check_l(unit* s, int xM);
	bool check_ground(unit* s, int xM);
	bool check_ground_black(unit* s, int xM);
	bool check_ceiling(unit* s, int xM);
	bool check_r(Amiya* s, int xM);
	bool check_l(Amiya* s, int xM);
	bool check_ground(Amiya* s, int xM);
	bool check_ceiling(Amiya* s, int xM);
};
class stone_controller;
class fixture :public object {//¹Ì¶¨µ¥Î»
	
protected:
	static IMAGE ground1;
	static IMAGE ground2;
	int flag;
	int damage;
	friend stone_controller;
public:
	virtual IMAGE* getimage() = 0;
	fixture();
	int getflag();
	int getdamage();
	virtual void change() = 0;
	IMAGE* getimage1();
	IMAGE* getimage2();
};
class fixture1:public fixture {
	static IMAGE ground;
public:
	fixture1();
	IMAGE* getimage();
	void change();
};
class fixture2 :public fixture {
	static IMAGE ground;
protected:
public:
	fixture2();
	IMAGE* getimage();
	void change();
};
class medicine :public object {
	static IMAGE medi;
	int medicine_sum;
	unit a[30];
public:
	medicine();
	void init(int map_id);
	void check(Amiya& amiya, int xM);
	void show(int xM);
};
class stone_controller {
	fixture* a[600];
	int ground_sum;
	bool start_boss_battle;
	int special_ground_sum;
public:
	void init(int map_id);
	bool check_ifcanmove(int x, int width, int y);
	bool getifstart();
	void boss_area_create();
	void boss_area_destroy();
	bool check_lr(unit* amiya, int xM = 0);
	bool check_lr(Amiya* amiya, int xM);
	void check_onground(Amiya& amiya, int xM);
	void check_onground(unit& black, int xM);
	void check_ceiling(Amiya& amiya, int xM);
	void check_amiyaonground(Amiya& amiya, int xM);
	void check_bossonground(unit& black, int xM);
	void fire_stone_hurt(Amiya& amiya, int xM);
	void role_bullet_check(Amiya& amiya, int xM);
	/*~stone_controller() {
		delete[]a;
	}*/
	void show(int xM);
};