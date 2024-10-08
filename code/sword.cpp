#include"sword.h"
void sword::create(int xx, int yy, int l, int w, int di) {
	x = xx;
	y = yy;
	height = l;
	width = w;
	direction = di;
}
bool sword::checkhit(unit* s, int xM) {
	if (direction > 0) {
		if (x + xM < s->getx() + s->getwidth() && s->getx() <= x + xM + width && y - s->getheight() < s->gety() && y + height > s->gety()) {
			return 1;
		}
		return 0;
	}
	else if (direction < 0) {
		if (x + xM <= s->getx() + s->getwidth() && s->getx() < x + xM + width && y - s->getheight() < s->gety() && y + height > s->gety()) {
			return 1;
		}
		return 0;
	}
}
int& sword::getdamage() {
	return damage;
}