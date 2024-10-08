#ifndef UNIT_H
#define UNIT_H
#include<easyx.h>
#include<cstring>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<windows.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<graphics.h> 
#include"Mydefine.h"
class unit {
protected:
	int x;//左上角横坐标
	int y;//左上角纵坐标
	int height;//图像高度
	int width;//图像宽度
	int direction;//行走方向
	int hp_max;//最大血量
	int hp;//当前血量
	int vx;//移动速度
	int vy;//每一帧移动速度
	bool alive;
	bool exist;
	int judging;
	bool onground;
	int stage;
	int state;
public:
	unit();
	//void init(){}
	int& getx();
	int& gety();
	int getxcheck();
	int getycheck();
	int& getvx();
	int& getvy();
	int& getheight();
	int& getwidth();
	int& getdirection();
	int getjudging();
	void showblood(int xM = 0, int tmp = 0);
	bool& getexist();
	bool ifonground();
	void land();
	void fall();
	int& changestate();
	int getstage();
	void init(int a, int b, int h, int w);
};
#endif