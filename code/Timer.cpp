#include"Timer.h"
void timer::init() {
	time = 0;
}
void timer::add(double i) {
	time += i;
}
void timer::show() {
	char str[20];
	sprintf_s(str, "ÓÃÊ±£º %.2f", time / 1000.0);
	setbkmode(TRANSPARENT);
	settextstyle(20, 0, _T("ËÎÌå"));
	outtextxy(20, 150, str);
}
double timer::gettime() {
	return time;
}