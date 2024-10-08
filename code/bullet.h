#pragma once
#include<easyx.h>
#include<iostream>
#include<vector>
#include<windows.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<graphics.h>
#include<cmath>
#include"unit.h"
#include"Mydefine.h"
class bullet :public unit {
protected:
	bool shoot;
	int damage;
	int distance;
public:
	bullet();
	void init(int damage_tmp, int height_tmp, int width_tmp, int vx_tmp);
	bool changedamage(int i);
	bool checkhit(unit* s, int xM = 0);
	void create(int xx, int yy, int d, int di, int vxx = 30, int vyy = 0);
	int getdamage();
	void putdirection(int i);
	void update();
	void changeshoot();
	bool getshoot();
	void show(IMAGE bull, int xM);
	int& changexv();

};