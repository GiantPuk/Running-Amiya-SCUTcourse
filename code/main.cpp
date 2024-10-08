#pragma once
#include<easyx.h>
#include<iostream>
#include<vector>
#include<windows.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<graphics.h>
#include"game.h"
IMAGE elite::attack1right[15];
IMAGE elite::attack1right_1[15];
IMAGE elite::attack1left[15];
IMAGE elite::attack1left_1[15];
IMAGE elite::moveright[15];
IMAGE elite::moveleft[15];
IMAGE elite::moveright_1[15];
IMAGE elite::moveleft_1[15];
IMAGE fixture1::ground;
IMAGE fixture2::ground;
IMAGE scorcerer::attackright[8];
IMAGE scorcerer::attackleft[8];
IMAGE scorcerer::moveright[8];
IMAGE scorcerer::moveright1[8];
IMAGE scorcerer::moveleft[8];
IMAGE scorcerer::moveleft1[8];
IMAGE insect::attackright[15];
IMAGE insect::attackleft[15];
IMAGE insect::moveright[15];
IMAGE insect::moveleft[15];
IMAGE scorcerer::bull;
IMAGE elite::bull;
IMAGE medicine::medi;
IMAGE fixture::ground1;
IMAGE fixture::ground2;
int main() {
	game test;
	test.play();
	/*map a;
	initgraph(screem_w, screem_h);
	a.init();
	a.show();
	system("pause");*/
}