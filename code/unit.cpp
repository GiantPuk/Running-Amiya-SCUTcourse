#include"unit.h"
unit::unit() { vx = vy = 0; alive = 1; }
int& unit::getx() {
	return x;
}
int& unit::gety() {
	return y;
}
int unit::getxcheck() {
	return x + c_judge;
}
int unit::getycheck() {
	return y;
}
int& unit::getvx() { return vx; }
int& unit::getvy() {
	return vy;
}
int& unit::getheight() {
	return height;
}
int& unit::getwidth() {
	return width;
}
int& unit::getdirection() {
	return direction;
}
int unit::getjudging() { return judging; }
void unit::showblood(int xM , int tmp ) {
	setfillcolor('r');
	solidrectangle(x + xM, y - 7 + tmp, x + xM + ((double)hp / hp_max) * width, y - 5 + tmp);//ÑªÌõ
}
bool& unit::getexist() {
	return exist;
}
bool unit::ifonground() { return onground; }
void unit::land() { onground = 1; state = walk; }
void unit::fall() { onground = 0; state = jump; }
int& unit::changestate() { return state; }
int unit::getstage() { return stage; }
void unit::init(int a, int b, int h, int w) {
	x = a;
	y = b;
	height = h;
	width = w;
	exist = 1;
}