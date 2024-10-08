#include"bullet.h"
bullet::bullet() {
	shoot = 0;
	distance = 0;
	damage = 10;
	vx = 30;
	vy = 0;
	height = 10;
	width = 20;
}
void bullet::init(int damage_tmp, int height_tmp, int width_tmp, int vx_tmp) {
	damage = damage_tmp;
	height = height_tmp;
	width = width_tmp;
	vx = vx_tmp;
}
bool bullet::changedamage(int i) { damage = i; return 1; }
bool bullet::checkhit(unit* s, int xM) {
	//if (direction > 0) {
	//	if (x+xM < s->getx()+s->getwidth() && s->getx() <= x + xM + width && y - s->getheight() < s->gety() && y + height > s->gety()) {//往左的话，因为速度固定，所以是速度的倍速
	//		return 1;
	//	}
	//	return 0;
	//}
	//else if (direction < 0) {
	//	if (x + xM <=s->getx()+s->getwidth() && s->getx()<x + xM +width && y - s->getheight() < s->gety() && y + height > s->gety()) {
	//		return 1;
	//	}
	//	return 0;
	//}
	if (x + xM < s->getx() + s->getwidth() && s->getx() <= x + xM + width && y - s->getheight() < s->gety() && y + height > s->gety()) {//往左的话，因为速度固定，所以是速度的倍速
		return 1;
	}
	return 0;
}
void bullet::create(int xx, int yy, int d, int di, int vxx, int vyy) {
	x = xx;
	y = yy;
	vx = vxx;
	vy = vyy;
	damage = d;
	direction = di;
	shoot = 1;
	distance = 0;
}
int bullet::getdamage() { return damage; }
void bullet::putdirection(int i) { direction = i; }
void bullet::update() {
	x += vx * direction;
	y += vy;
	distance += vx;
	if (abs(distance) >= 400) { shoot = 0; }
}
void bullet::changeshoot() {
	shoot = !shoot;
}
bool bullet::getshoot() {
	return shoot;
}
void bullet::show(IMAGE bull, int xM) {
	putimage_alpha(x + xM, y, &bull);
	std::cout << "amiya bullet" << x + xM << std::endl;
}
int& bullet::changexv() { return vx; }