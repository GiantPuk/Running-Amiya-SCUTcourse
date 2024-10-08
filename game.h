#pragma once
#include<easyx.h>
#include<iostream>
#include<vector>
#include<windows.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<graphics.h>
#include"scene.h"
#include"unit.h"
#include"Timer.h"
#include"Mydefine.h"
#include<ctime>
#pragma comment(lib,"Winmm.lib")
class game {
	map m;
	Amiya role;
	record rec;
	menu me;
	timer tim;
	levelselection level;
	ExMessage msg;
	stoppage stop;
	HWND screen;
	help he;
	IMAGE success;
	int choosemap;
	int state = 1;//先默认为玩游戏的状态
public:
	game();
	void play();
};