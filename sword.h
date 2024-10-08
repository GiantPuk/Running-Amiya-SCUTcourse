#pragma once
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
#include"Mydefine.h"
#include"unit.h"
class sword :public unit {//可以考虑变成碰撞类
	int damage;
public:
	void create(int xx, int yy, int l, int w, int di);
	bool checkhit(unit* s, int xM);
	int& getdamage();
};