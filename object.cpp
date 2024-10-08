#include"object.h"
object::object() {}
object::object(int h, int w) { height = h, width = w; }
void object::putxy(int a, int b) {
	x = a; y = b;
}
bool object::check_r(unit* s, int xM) {//左右碰撞都是先镶嵌进去再不动的，因此速度不能比木块大，不然会冲进去
	Point character[4];
	if (x > s->getx() && s->getx() + s->getwidth() > x && y - s->getheight() < s->gety() && y + height > s->gety()) {
		return 1;
	}
	return 0;
}
bool object::check_l(unit* s, int xM) {
	if (x < s->getx() && s->getx() <= x + width && y - s->getheight() < s->gety() && y + height > s->gety()) {//往左的话，因为速度固定，所以是速度的倍速
		return 1;
	}
	return 0;
}
bool object::check_ground(unit* s, int xM) {
	if (x < s->getx() + s->getwidth() - s->getjudging() && s->getx() + s->getjudging() < x + width) {
		if (s->gety() + s->getheight() <= y && s->getvy() + s->gety() + s->getheight() >= y)
		{
			return 1;
		}
	}
	return 0;
}
bool object::check_ground_black(unit* s, int xM) {
	if (s->getdirection() < 0) {
		if (x < s->getx() + s->getwidth() - boss_width / 2 && s->getx() < x + width) {
			if (s->gety() + s->getheight() <= y && s->getvy() + s->gety() + s->getheight() >= y)
			{
				return 1;
			}
		}
		return 0;
	}
	else {
		if (x < s->getx() + s->getwidth() && s->getx() + boss_width / 2 < x + width) {
			if (s->gety() + s->getheight() <= y && s->getvy() + s->gety() + s->getheight() >= y)
			{
				return 1;
			}
		}
		return 0;
	}
	return 0;
}
bool object::check_ceiling(unit* s, int xM) {
	if (x < s->getx() + s->getwidth() - s->getjudging() && s->getx() + s->getjudging() < x + width) {
		if (s->gety() >= y + height && s->getvy() + s->gety() <= y + height)
		{
			return 1;
		}
	}
	return 0;
}
bool object::check_r(Amiya* s, int xM) {//左右碰撞都是先镶嵌进去再不动的，因此速度不能比木块大，不然会冲进去
	Point character[4];
	if (x + xM > s->getx() && s->getx() + s->getwidth() > x + xM && y - s->getheight() < s->gety() && y + height > s->gety()) {
		return 1;
	}
	return 0;
}
bool object::check_l(Amiya* s, int xM) {
	if (x + xM < s->getx() && s->getx() <= x + xM + width && y - s->getheight() < s->gety() && y + height > s->gety()) {//往左的话，因为速度固定，所以是速度的倍速
		return 1;
	}
	return 0;
}
bool object::check_ground(Amiya* s, int xM) {
	if (x + xM < s->getx() + s->getwidth() - s->getjudging() && s->getx() + s->getjudging() < x + xM + width) {
		if (s->gety() + s->getheight() <= y && s->getvy() + s->gety() + s->getheight() >= y)
		{
			return 1;
		}
	}
	return 0;
}
bool object::check_ceiling(Amiya* s, int xM) {
	if (x + xM < s->getx() + s->getwidth() - s->getjudging() && s->getx() + s->getjudging() < x + xM + width) {
		if (s->gety() >= y + height && s->getvy() + s->gety() <= y + height)
		{
			return 1;
		}
	}
	return 0;
}
fixture::fixture() :object(ground_h, ground_w) {
	loadimage(&ground1, _T("resourse/地板/地板.png"), ground_w, ground_h);
	loadimage(&ground2, _T("resourse/地板/火地板.png"), ground_w, ground_h);
}
int fixture::getflag() { return flag; }
int fixture::getdamage() { return damage; }
IMAGE* fixture::getimage1() { return &ground1; }
IMAGE* fixture::getimage2() { return &ground2; }
fixture1::fixture1() {
	loadimage(&ground, _T("resourse/地板/地板.png"), ground_w, ground_h);
	flag = 1;
	damage = 0;
}
IMAGE* fixture1::getimage() { return &ground; }
void fixture1::change() {
	flag = 2;
	damage = 1;
}
fixture2::fixture2() {
	loadimage(&ground, _T("resourse/地板/火地板.png"), ground_w, ground_h);
	damage = 1;
	flag = 2;
}
IMAGE* fixture2::getimage() { return &ground; }
void fixture2::change() {
	flag = 1;
}
medicine::medicine() {
	loadimage(&medi, _T("resourse/理智剂.tif"), 50, 50);
}
void medicine::init(int map_id) {
	medicine_sum = 0;
	width = 50; height = 50;
	if (map_id == 3 || map_id == 2) {
		a[medicine_sum++].init(12 * ground_w, screem_h - second_floor * ground_h - height, height, width);
		a[medicine_sum++].init(33 * ground_w, screem_h - third_floor * ground_h - height, height, width);
		a[medicine_sum++].init(29 * ground_w, screem_h - ground_h - height, height, width);
		a[medicine_sum++].init(82 * ground_w, screem_h - 6 * ground_h - height, height, width);
		a[medicine_sum++].init(85 * ground_w, screem_h - 5 * ground_h - height, height, width);
		a[medicine_sum++].init(55 * ground_w, screem_h - 10 * ground_h - height, height, width);
		a[medicine_sum++].init(70 * ground_w, screem_h - 12 * ground_h - height, height, width);
		a[medicine_sum++].init(84 * ground_w, screem_h - 11 * ground_h - height, height, width);
		a[medicine_sum++].init(33 * ground_w, screem_h - fourth_floor * ground_h - height, height, width);
		a[medicine_sum++].init(120 * ground_w, screem_h - ground_h - height, height, width);
		a[medicine_sum++].init(133 * ground_w, screem_h - 8 * ground_h - height, height, width);
		a[medicine_sum++].init(38 * ground_w, screem_h - ground_h - height, height, width);
		a[medicine_sum++].init(61 * ground_w, screem_h - ground_h - height, height, width);

	}
}
void medicine::check(Amiya& amiya, int xM) {
	for (int i = 0; i < medicine_sum; i++) {
		if (a[i].getexist()) {
			if (a[i].getx() + xM <= amiya.getx() + amiya.getwidth() && amiya.getx() < a[i].getx() + xM + width && a[i].gety() - amiya.getheight() < amiya.gety() && a[i].gety() + height > amiya.gety()) {
				a[i].getexist() = 0;
				amiya.getmedicine();
			}
		}
	}
}
void medicine::show(int xM) {
	for (int i = 0; i < medicine_sum; i++) {
		if (a[i].getexist()) {
			putimage_alpha(a[i].getx() + xM, a[i].gety(), &medi);
		}
	}
}
void stone_controller::init(int map_id) {
	start_boss_battle = 0;
	special_ground_sum = 10;
	for (int i = 0; i <ground_sum; i++) {
		delete a[i];
	}
	ground_sum = 0;
	if (map_id == 3 || map_id == 2) {
		int i;
		for (i = 0; i <= (map_w + screem_w) / ground_w; i++) {
			if (i >= 13 && i <= 20)continue;
			if (i >= 80 && i <= 98)continue;
			if (i > 35 && i < 68 && (i / 3) % 2) {
				a[ground_sum] = new fixture2;
			}
			else {
				a[ground_sum] = new fixture1;
			}
			a[ground_sum]->putxy(i * ground_w, map_h - ground_h);
			ground_sum++;
		}
		for (i = 10; i < 18; i++) {
			a[ground_sum] = new fixture1;
			a[ground_sum++]->putxy(i * ground_w, map_h - second_floor * ground_h);
		}
		for (i = 91; i < 98; i++) {
			a[ground_sum] = new fixture1;
			a[ground_sum++]->putxy(i * ground_w, map_h - second_floor * ground_h);
		}
		for (i = 91; i < 98; i++) {
			a[ground_sum] = new fixture1;
			a[ground_sum++]->putxy(i * ground_w, map_h - third_floor * ground_h);
		}
		for (i = 25; i < 31; i++) {
			a[ground_sum] = new fixture1;
			a[ground_sum++]->putxy(i * ground_w, map_h - second_floor * ground_h);
		}
		for (i = 34; i < 37; i++) {
			a[ground_sum] = new fixture1;
			a[ground_sum++]->putxy(i * ground_w, map_h - second_floor * ground_h);
		}
		for (i = 31; i < 36; i++) {
			a[ground_sum] = new fixture1;
			a[ground_sum++]->putxy(i * ground_w, map_h - fourth_floor * ground_h);
		}
		for (i = 1; i <= 5; i++) {
			for (int j = 69 + i; j < 75; j++) {
				a[ground_sum] = new fixture1;
				a[ground_sum++]->putxy(j * ground_w, map_h - (i + 1) * ground_h);
			}
		}
		for (i = 2; i < 5; i++) {
			a[ground_sum] = new fixture1;
			a[ground_sum++]->putxy(75 * ground_w, map_h - (i)*ground_h);
		}
		for (i = 4; i < 9; i++) {
			a[ground_sum] = new fixture1;
			a[ground_sum++]->putxy(77 * ground_w, map_h - (i)*ground_h);
		}
		for (int j = 79; j <= 88; j++) {
			if (!(j % 2)) {
				for (i = 1; i <= (95 - j) / 3; i++) {
					a[ground_sum] = new fixture1;
					a[ground_sum++]->putxy(j * ground_w, map_h - (i)*ground_h);
				}
				a[ground_sum] = new fixture1;
				a[ground_sum++]->putxy(j * ground_w, map_h - (i + 5) * ground_h);
				a[ground_sum] = new fixture1;
				a[ground_sum++]->putxy((j - 1) * ground_w, map_h - (i + 5) * ground_h);
			}
		}
		for (i = 45; i < 51; i++) {
			a[ground_sum] = new fixture1;
			a[ground_sum++]->putxy(i * ground_w, map_h - second_floor * ground_h);
		}
		for (i = 0; i <= 3; i++) {
			for (int j = 69 - i; j <= 69 + i; j++) {
				if ((i + j) % 2) {
					a[ground_sum] = new fixture1;
					a[ground_sum++]->putxy(j * ground_w, map_h - (7 + i) * ground_h);
				}
			}
		}
		for (i = 0; i <= 3; i++) {
			for (int j = 62 - i; j <= 62 + i; j++) {
				if ((i + j) % 2) {
					a[ground_sum] = new fixture1;
					a[ground_sum++]->putxy(j * ground_w, map_h - (14 - i) * ground_h);
				}
			}
		}
		for (i = 62; i < 65; i++) {
			a[ground_sum] = new fixture1;
			a[ground_sum++]->putxy(i * ground_w, map_h - second_floor * ground_h);
		}
		for (i = 40; i < 42; i++) {
			a[ground_sum] = new fixture1;
			a[ground_sum++]->putxy(i * ground_w, map_h - third_floor * ground_h);
		}
		for (i = 50; i < 56; i++) {
			a[ground_sum] = new fixture1;
			a[ground_sum++]->putxy(i * ground_w, map_h - third_floor * ground_h);
		}
		for (i = 18; i < 29; i++) {
			a[ground_sum] = new fixture1;
			a[ground_sum++]->putxy(i * ground_w, map_h - third_floor * ground_h);
		}
		for (int i = boss_battle_left_secondfloor1; i <= boss_battle_right_secondfloor1; i += ground_w) {
			a[ground_sum] = new fixture1;
			a[ground_sum++]->putxy(i, map_h - second_floor * ground_h);
		}
		for (int i = boss_battle_left_secondfloor2; i < boss_battle_right_secondfloor2; i += ground_w) {
			a[ground_sum] = new fixture1;
			a[ground_sum++]->putxy(i, map_h - second_floor * ground_h);
		}
		a[ground_sum] = new fixture1;
		a[ground_sum]->putxy(i * ground_w, map_h - third_floor * ground_h);
	}
	else if (map_id == 1) {
		int i;
		for (i = 0; i <= (map_w + screem_w) / ground_w; i++) {
			a[ground_sum] = new fixture1;
			a[ground_sum]->putxy(i * ground_w, map_h - ground_h);
			ground_sum++;
		}
		srand(time(0));
		for (i = 10; i <= (map_w) / ground_w; i++) {
			int flag = 0;
			for (int j = 2; j <= 10; j++) {
				flag--;
				int tmp = rand() % 100;
				if (tmp < 60 - 6 * j) {
					if (j >= 4) {
						if (flag <= 0)flag = 3;
						else {
							continue;
						}
					}
					a[ground_sum] = new fixture1;
					a[ground_sum]->putxy(i * ground_w, map_h - j * ground_h);
					ground_sum++;
				}
			}
			if (ground_sum > 460)break;
		}
		a[ground_sum] = new fixture1;
		a[ground_sum]->putxy(i * ground_w, map_h - third_floor * ground_h);
	}
}
bool stone_controller::check_ifcanmove(int x, int width, int y) {
	for (int i = 0; i <= ground_sum; i++) {
		if (y == a[ground_sum]->gety() && a[ground_sum]->getx() >= x && a[ground_sum]->getx() <= x + width) {
			return 1;
		}
	}
	return 0;
}
bool stone_controller::getifstart() { return start_boss_battle; }
void stone_controller::boss_area_create() {
	start_boss_battle = 1;
	for (int i = 1; i <= special_ground_sum; i++) {
		a[++ground_sum] = new fixture1;
		a[ground_sum]->putxy(boss_battle_left, map_h - i * ground_h - ground_h);
	}
	for (int i = 1; i <= special_ground_sum; i++) {
		a[++ground_sum] = new fixture1;
		a[ground_sum]->putxy(boss_battle_right, map_h - i * ground_h - ground_h);
	}
}
void stone_controller::boss_area_destroy() {
	/*ground_sum -= 2 * special_ground_sum;
	for (int i = 1; i <= special_ground_sum; i++) {
		delete a[++ground_sum];
	}
	for (int i = 1; i <= special_ground_sum; i++) {
		delete a[++ground_sum];
	}*/
	ground_sum -= 2 * special_ground_sum;
	start_boss_battle = 0;
}
bool stone_controller::check_lr(unit* amiya, int xM ) {
	if (amiya->getdirection() > 0) {
		for (int i = 0; i <= ground_sum; i++) {//每一个地板遍历看看有没有碰撞
			if (a[i]->check_r(amiya, xM)) {//有缺陷的判断，因为采用的是先x后y，所以速度不能太大，尤其不能比块大
				return 1;
			}
		}
	}
	else {
		for (int i = 0; i <= ground_sum; i++) {//每一个地板遍历看看有没有碰撞
			if (a[i]->check_l(amiya, xM)) {//有缺陷的判断，因为采用的是先x后y，所以速度不能太大，尤其不能比块大
				return 1;
			}
		}
	}
	return 0;
}
bool stone_controller::check_lr(Amiya* amiya, int xM) {
	if (amiya->getdirection() > 0) {
		for (int i = 0; i <= ground_sum; i++) {//每一个地板遍历看看有没有碰撞
			if (a[i]->check_r(amiya, xM)) {//有缺陷的判断，因为采用的是先x后y，所以速度不能太大，尤其不能比块大
				return 1;
			}
		}
	}
	else {
		for (int i = 0; i <= ground_sum; i++) {//每一个地板遍历看看有没有碰撞
			if (a[i]->check_l(amiya, xM)) {//有缺陷的判断，因为采用的是先x后y，所以速度不能太大，尤其不能比块大
				return 1;
			}
		}
	}
	return 0;
}
void stone_controller::check_onground(Amiya& amiya, int xM) {
	int tmp = -1;
	for (int i = 0; i <= ground_sum; i++) {
		if (a[i]->check_ground(&amiya, xM)) {
			if (tmp == -1)tmp = i;
			else {
				if (a[tmp]->gety() > a[i]->gety()) {
					tmp = i;
				}
			}
		}
	}
	if (tmp != -1) {
		std::cout << "land" << std::endl;
		amiya.getvy() = 0;
		amiya.land();
		amiya.gety() = a[tmp]->gety() - c_height;
	}
}
void stone_controller::check_onground(unit& black, int xM) {
	for (int i = 0; i <= ground_sum; i++) {
		if (a[i]->check_ground_black(&black, xM)) {
			std::cout << "land black" << std::endl;
			black.getvy() = 0;
			black.land();
			black.gety() = a[i]->gety() - boss_height;
			return;
		}
	}
}
void stone_controller::check_ceiling(Amiya& amiya, int xM) {
	for (int i = 0; i <= ground_sum; i++) {
		if (a[i]->check_ceiling(&amiya, xM)) {
			amiya.getvy() = 0;
			amiya.gety() = a[i]->gety() + a[i]->getheight();
			return;
		}
	}
}
void stone_controller::check_amiyaonground(Amiya& amiya, int xM) {
	bool flag = 0;
	for (int i = 0; i <= ground_sum; i++) {
		if (a[i]->check_ground(&amiya, xM)) {
			flag = 1;
			break;
		}
	}
	if (!flag) {
		amiya.changestate() = jump;
		amiya.fall();
		amiya.getvy() += g;
		amiya.gety() += amiya.getvy();
	}
}
void stone_controller::check_bossonground(unit& black, int xM) {
	bool flag = 0;
	for (int i = 0; i <= ground_sum; i++) {
		if (a[i]->check_ground_black(&black, xM)) {
			flag = 1;
			if (black.getstage() > 1 && a[i]->getflag() == 1) {
				int tmp = rand() % 200;
				if (tmp < 3) {
					a[i]->change();
				}
			}
			break;
		}
	}
	if (!flag) {
		black.changestate() = jump;
		black.fall();
		black.getvy() += g;
		black.gety() += black.getvy();
	}
}
void stone_controller::fire_stone_hurt(Amiya& amiya, int xM) {
	for (int i = 0; i < ground_sum; i++) {
		if (a[i]->getflag() == 2 && a[i]->check_ground(&amiya, xM)) {
			amiya.behurt(a[i]->getdamage());
			std::cout << "amiya hurt" << std::endl;
		}
	}
}
void stone_controller::role_bullet_check(Amiya& amiya, int xM) {
	for (int i = 0; i < ground_sum; i++) {
		for (int j = 0; j < amiya.getbullet_sum(); j++) {
			amiya.bullet_check(a[i], j);
		}
	}
}
/*~stone_controller() {
	delete[]a;
}*/
void stone_controller::show(int xM) {
	for (int i = 0; i <= ground_sum; i++) {
		if (a[i]->getflag() == 1) {
			putimage(a[i]->getx() + xM, a[i]->gety(),&fixture::ground1);
			/*std::cout << "stone"<<i<<"show successfully" << std::endl;*/
			/*std::cout << i << std::endl;*/
		}
		else {
			putimage(a[i]->getx() + xM, a[i]->gety(), &fixture::ground2);
		}
	}
}