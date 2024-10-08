#ifndef SCENE_H
#define SCENE_H
#include<easyx.h>
#include<iostream>
#include<vector>
#include<windows.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<graphics.h>
#include<cstdlib>
#include<fstream>
#include"Mydefine.h"
#include"unit.h"
#include"role.h"
//#include"gravity.h"
#include"bullet.h"
#include"enemy.h"
#include"object.h"
#include"unit.h"
#include<string.h>
#include<algorithm>
//#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)  //用来检测按键的点击事件
class scene {
protected:
	int width;
	int height;
	IMAGE background;
	IMAGE back;
public:
	int getwidth();
};
class menu :public scene {
	unit button[5];
public:
	menu();
	void display();
	int check(int x, int y);
};
struct record_time {
	double point;
	SYSTEMTIME time;
	bool operator<(const record_time& other) const {
		return point < other.point;
	}
};
class record :public scene{
	record_time time[20];
	unit button;
public:
	record();
	void check(int map_id, record_time new_record);
	void show();
	double get_best(int map_id);
	int back_menu(int x, int y);
};
class stoppage :public scene {
	unit button[2];
public:
	stoppage();
	int check(int x, int y);
	void show(double time);
};
class levelselection :public scene {
	unit button[5];
	IMAGE background;
public:
	levelselection();
	void display();
	int check(int x, int y);
};
class help :public scene {
	unit button;
	IMAGE background;
	IMAGE back;
public:
	help();
	void show();
	int back_menu(int x, int y);
};
class map :public scene {
	/*insect b[30];*/
	//Blacksnake boss;
	/*scorcerer c[30];
	elite d[100];*/
	medicine medi;
	stone_controller stone;
	enemy_controller em;
	int elite_sum = 0;
	int ground_sum = 0;
	int insect_sum = 0;
	int scorcerer_sum = 0;
	int xM=0;
	int yM=0;
	bool ifmove;//地图运动距离
	bool ifstop;
	unit button[3];
	IMAGE stop;
	IMAGE begin;
	IMAGE end;
public:
	map();
	bool getifstop();
	int check(int x, int y);
	void init(int map_id);
	void move(Amiya& amiya);
	void attack(Amiya& amiya);
	void show(Amiya& amiya);
}; 
#endif