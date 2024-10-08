
#include"enemy.h"
void enemy::checkawake(Amiya& amiya, int xM) {
	if (amiya.ifonground()) {
		if (amiya.gety() + c_height == y + height && amiya.ifonground()) {
			if (abs(amiya.getx() - (x + xM)) <= 200) {
				wake = 1;
				state = walk;
			}
		}
	}
}
bool enemy::attack_close(Amiya& amiya, int xM) {
	if (state != toattack_close && amiya.ifonground()) {
		if (amiya.gety() + c_height == y + height && amiya.ifonground()) {//站在同一高度上并且站在地面上
			if (((amiya.getx() - (x + xM + width / 2)) <= attack_close_range + width / 2 && (amiya.getx() - (x + xM + width / 2)) >= 0)) {//从boss的中间判断左右和距离
				state = toattack_close;
				direction = 1;
				close_attack_frame = 0;
				return 1;
			}
			else if (abs(amiya.getx() - (x + xM + width / 2)) <= attack_close_range + width / 2 && (amiya.getx() - (x + xM + width / 2)) < 0) {
				state = toattack_close;
				direction = -1;
				close_attack_frame = 0;
				return 1;
			}//这样子没有判定amiya压在中线上的情况，但是无伤大雅，boss会自己走一两步去攻击
		}
	}
	return 0;
}
bool enemy::attack_distant(Amiya& amiya, int xM) {//可以考虑改成不一定在地上，两个块在y轴方向有重叠，后期可以优化
	if (state != toattack_close && amiya.ifonground()) {
		if (amiya.gety() + c_height == y + height && amiya.ifonground()) {//站在同一高度上并且站在地面上
			if (((amiya.getx() - (x + xM + width / 2)) <= attack_distant_range + width / 2 && (amiya.getx() - (x + xM + width / 2)) >= 0)) {//从boss的中间判断左右和距离
				state = toattack_distant;
				direction = 1;
				distant_attack_frame = 0;
				return 1;
			}
			else if (abs(amiya.getx()- (x + xM + width / 2)) <= attack_distant_range + width / 2 && (amiya.getx() - (x + xM + width / 2)) < 0) {
				state = toattack_distant;
				direction = -1;
				distant_attack_frame = 0;
				return 1;
			}//这样子没有判定amiya压在中线上的情况，但是无伤大雅，boss会自己走一两步去攻击
		}
	}
	return 0;
}
void enemy::getspeed(Amiya& amiya, int xM) {
	if (amiya.gety() + c_height == y + height) {
		if (amiya.getx() - (x + xM + width) > 0) {
			direction = 1;
			vx = 5 * direction;
		}
		else if (amiya.getx() - (x + xM) <= 0) {
			direction = -1;
			vx = 5 * direction;
		}
		else {
			vx = 0;
		}
		state = walk;
	}
	else {
		state = stand;
		vx = 0;
	}
}
bool enemy::ifshoot(Amiya& amiya, int xM) {//判断是否发射子弹
	if (shooting_cd == 0)
		return attack_distant(amiya, xM);
	else return 0;
}
bool enemy::check_ifstrike(Amiya& amiya, int xM) {//判断是否发射子弹
	if (close_attack_cdcounting == 0)
		return attack_close(amiya, xM);
}
bool enemy::getawake() { return wake; }
bool enemy::getalive() { return alive; }
void enemy::behurt(int i) {
	hp -= i;
	hp = max(hp, 0);
	if (hp == 0) {
		alive = 0;
	}
}
int enemy::getstate() { return state; }
int enemy::getbullet_sum() { return bullet_sum; }
void enemy::bullet_update() {
	for (int i = 0; i < bullet_sum; i++) {
		if (bul[i].getshoot()) {
			bul[i].update();
		}
	}
}
int enemy::get_bulletdamage(int i) {
	return bul[i].getdamage();
}
int enemy::getid() { return id; }
int& enemy::getvalue() {
	return value;
}
insect::insect() {
	state = stand;
	id = 1;
}
insect::insect(int x, int y) {
	state = stand;
	id = 1;
	init(x, y);
}
void insect::init(int a, int b) {
	x = a;
	y = b;
	hp_max = hp = 400;
	wake = 0;
	alive = 1;
	state = stand;
	height = enemy1_h;
	width = enemy1_w;
	judging = 0;
	attack_close_range = 0;
	damage = 100;
	value = 100;
	loadimage(&attackright[0], _T("resourse/小怪源石虫/attack/right_1.tif"), width, height);
	loadimage(&attackright[1], _T("resourse/小怪源石虫/attack/right_2.tif"), width, height);
	loadimage(&attackright[2], _T("resourse/小怪源石虫/attack/right_3.tif"), width, height);
	loadimage(&attackright[3], _T("resourse/小怪源石虫/attack/right_4.tif"), width, height);
	loadimage(&attackright[4], _T("resourse/小怪源石虫/attack/right_5.tif"), width, height);
	loadimage(&attackright[5], _T("resourse/小怪源石虫/attack/right_6.tif"), width, height);
	loadimage(&attackright[6], _T("resourse/小怪源石虫/attack/right_7.tif"), width, height);
	loadimage(&attackright[7], _T("resourse/小怪源石虫/attack/right_8.tif"), width, height);
	loadimage(&attackright[8], _T("resourse/小怪源石虫/attack/right_9.tif"), width, height);
	loadimage(&attackright[9], _T("resourse/小怪源石虫/attack/right_10.tif"), width, height);

	loadimage(&attackleft[0], _T("resourse/小怪源石虫/attack/left_1.tif"), width, height);
	loadimage(&attackleft[1], _T("resourse/小怪源石虫/attack/left_2.tif"), width, height);
	loadimage(&attackleft[2], _T("resourse/小怪源石虫/attack/left_3.tif"), width, height);
	loadimage(&attackleft[3], _T("resourse/小怪源石虫/attack/left_4.tif"), width, height);
	loadimage(&attackleft[4], _T("resourse/小怪源石虫/attack/left_5.tif"), width, height);
	loadimage(&attackleft[5], _T("resourse/小怪源石虫/attack/left_6.tif"), width, height);
	loadimage(&attackleft[6], _T("resourse/小怪源石虫/attack/left_7.tif"), width, height);
	loadimage(&attackleft[7], _T("resourse/小怪源石虫/attack/left_8.tif"), width, height);
	loadimage(&attackleft[8], _T("resourse/小怪源石虫/attack/left_9.tif"), width, height);
	loadimage(&attackleft[9], _T("resourse/小怪源石虫/attack/left_10.tif"), width, height);

	loadimage(&moveright[0], _T("resourse/小怪源石虫/move/right_1.tif"), width, height);
	loadimage(&moveright[1], _T("resourse/小怪源石虫/move/right_2.tif"), width, height);
	loadimage(&moveright[2], _T("resourse/小怪源石虫/move/right_3.tif"), width, height);
	loadimage(&moveright[3], _T("resourse/小怪源石虫/move/right_4.tif"), width, height);
	loadimage(&moveright[4], _T("resourse/小怪源石虫/move/right_5.tif"), width, height);
	loadimage(&moveright[5], _T("resourse/小怪源石虫/move/right_6.tif"), width, height);
	loadimage(&moveright[6], _T("resourse/小怪源石虫/move/right_7.tif"), width, height);
	loadimage(&moveright[7], _T("resourse/小怪源石虫/move/right_8.tif"), width, height);
	loadimage(&moveright[8], _T("resourse/小怪源石虫/move/right_9.tif"), width, height);

	loadimage(&moveleft[0], _T("resourse/小怪源石虫/move/left_1.tif"), width, height);
	loadimage(&moveleft[1], _T("resourse/小怪源石虫/move/left_2.tif"), width, height);
	loadimage(&moveleft[2], _T("resourse/小怪源石虫/move/left_3.tif"), width, height);
	loadimage(&moveleft[3], _T("resourse/小怪源石虫/move/left_4.tif"), width, height);
	loadimage(&moveleft[4], _T("resourse/小怪源石虫/move/left_5.tif"), width, height);
	loadimage(&moveleft[5], _T("resourse/小怪源石虫/move/left_6.tif"), width, height);
	loadimage(&moveleft[6], _T("resourse/小怪源石虫/move/left_7.tif"), width, height);
	loadimage(&moveleft[7], _T("resourse/小怪源石虫/move/left_8.tif"), width, height);
	loadimage(&moveleft[8], _T("resourse/小怪源石虫/move/left_9.tif"), width, height);
}
void insect::show(int xM) {
	if (state == toattack_close) {
		if (direction > 0) {
			putimage_alpha(x + xM, y, &attackright[close_attack_frame / 3]);
		}
		else if (direction < 0) {
			putimage_alpha(x + xM, y, &attackleft[close_attack_frame / 3]);
		}
	}
	else if (state == walk) {
		if (move_frame > 8 * 2 - 1) {
			move_frame = 0;
		}
		if (direction > 0) {
			putimage_alpha(x + xM, y, &moveright[move_frame / 2]);
		}
		else if (direction < 0) {
			putimage_alpha(x + xM, y, &moveleft[move_frame / 2]);
		}
		move_frame++;
	}
	else {
		if(direction<0)
		putimage_alpha(x + xM, y, &attackleft[0]);
		else {
			putimage_alpha(x + xM, y, &attackright[0]);
		}
	}
	setfillcolor('r');
	if (direction > 0)
		solidrectangle(x + xM + width / 7, y - 7, x + xM + ((double)hp / hp_max) * width * 0.4 + width / 7, y - 5);//血条
	else
		solidrectangle(x + xM + width / 2, y - 7, x + xM + ((double)hp / hp_max) * width * 0.4 + width / 2, y - 5);//血条
}
void insect::close_attack_update(Amiya& amiya, int xM) {
	if (close_attack_frame == 3 * 5)
	{
		if (direction > 0)
			sw.create(x, y - 10, height + 10, attack_close_range + width, direction);
		else {
			sw.create(x - attack_close_range, y - 10, height + 10, attack_close_range + width, direction);//攻击判断，注意左右攻击范围要对称处理
		}
		if (sw.checkhit(&amiya, xM)) {
			amiya.behurt(damage);
		}
	}
	close_attack_frame++;
	if (close_attack_frame >= 3 * 9 - 1) { state = walk; }
}
void insect::attack_update(Amiya& amiya, int xM, stone_controller& stone) {
	if (alive && wake && state == toattack_close) {
		close_attack_update(amiya, xM);
	}
	if (wake && state == walk) {
		attack_close(amiya, xM);
	}
	for (int j = 0; j < amiya.getbullet_sum(); j++) {
		if (alive && amiya.bullet_check(this, j)) {
			this->behurt(amiya.get_bulletdamage(j));
		}
	}
}
void insect::move_update(Amiya& amiya, int xM, stone_controller& stone) {}
void insect::behurt(int i) {
	hp -= i;
	hp = max(hp, 0);
	if (hp == 0) {
		alive = 0;
	}
}
scorcerer::scorcerer(int a, int b, int l, int r) { init(a, b, l, r); }
void scorcerer::init(int a, int b, int l, int r) {
	x = a;
	y = b;
	vx = 5;
	vy = 0;
	hp_max = hp = 600;
	wake = 1;
	alive = 1;
	state = walk;
	height = enemy2_h;
	width = enemy2_w;
	left_wander_barrier = l;
	right_wander_barrier = r;
	attack_distant_range = 200;
	move_frame = 0;
	judging = 0;
	damage = 120;
	shooting_cd = 0;
	shoot_cd = 50;
	direction = 1;
	id = 2;
	value = 150;
	loadimage(&bull, _T("resourse/乌萨斯着铠术师/子弹.png"), 20, 20);
	//这里可以调用子弹的init函数来初始化子弹数值
	loadimage(&attackright[0], _T("resourse/乌萨斯着铠术师/attack/right_1.tif"), width, height);//加载图片可以优化成一次
	loadimage(&attackright[1], _T("resourse/乌萨斯着铠术师/attack/right_2.tif"), width, height);
	loadimage(&attackright[2], _T("resourse/乌萨斯着铠术师/attack/right_3.tif"), width, height);
	loadimage(&attackright[3], _T("resourse/乌萨斯着铠术师/attack/right_4.tif"), width, height);
	loadimage(&attackright[4], _T("resourse/乌萨斯着铠术师/attack/right_5.tif"), width, height);
	loadimage(&attackright[5], _T("resourse/乌萨斯着铠术师/attack/right_6.tif"), width, height);
	loadimage(&attackright[6], _T("resourse/乌萨斯着铠术师/attack/right_7.tif"), width, height);

	loadimage(&attackleft[0], _T("resourse/乌萨斯着铠术师/attack/left_1.tif"), width, height);
	loadimage(&attackleft[1], _T("resourse/乌萨斯着铠术师/attack/left_2.tif"), width, height);
	loadimage(&attackleft[2], _T("resourse/乌萨斯着铠术师/attack/left_3.tif"), width, height);
	loadimage(&attackleft[3], _T("resourse/乌萨斯着铠术师/attack/left_4.tif"), width, height);
	loadimage(&attackleft[4], _T("resourse/乌萨斯着铠术师/attack/left_5.tif"), width, height);
	loadimage(&attackleft[5], _T("resourse/乌萨斯着铠术师/attack/left_6.tif"), width, height);
	loadimage(&attackleft[6], _T("resourse/乌萨斯着铠术师/attack/left_7.tif"), width, height);

	loadimage(&moveright[0], _T("resourse/乌萨斯着铠术师/move/right_1.png"), width, height);
	loadimage(&moveright[1], _T("resourse/乌萨斯着铠术师/move/right_2.png"), width, height);
	loadimage(&moveright[2], _T("resourse/乌萨斯着铠术师/move/right_3.png"), width, height);
	loadimage(&moveright[3], _T("resourse/乌萨斯着铠术师/move/right_4.png"), width, height);
	loadimage(&moveright[4], _T("resourse/乌萨斯着铠术师/move/right_5.png"), width, height);
	loadimage(&moveright[5], _T("resourse/乌萨斯着铠术师/move/right_6.png"), width, height);
	loadimage(&moveright[6], _T("resourse/乌萨斯着铠术师/move/right_7.png"), width, height);
	loadimage(&moveright[7], _T("resourse/乌萨斯着铠术师/move/right_8.png"), width, height);

	loadimage(&moveright1[0], _T("resourse/乌萨斯着铠术师/move/right_1_1.png"), width, height);
	loadimage(&moveright1[1], _T("resourse/乌萨斯着铠术师/move/right_2_1.png"), width, height);
	loadimage(&moveright1[2], _T("resourse/乌萨斯着铠术师/move/right_3_1.png"), width, height);
	loadimage(&moveright1[3], _T("resourse/乌萨斯着铠术师/move/right_4_1.png"), width, height);
	loadimage(&moveright1[4], _T("resourse/乌萨斯着铠术师/move/right_5_1.png"), width, height);
	loadimage(&moveright1[5], _T("resourse/乌萨斯着铠术师/move/right_6_1.png"), width, height);
	loadimage(&moveright1[6], _T("resourse/乌萨斯着铠术师/move/right_7_1.png"), width, height);
	loadimage(&moveright1[7], _T("resourse/乌萨斯着铠术师/move/right_8_1.png"), width, height);

	loadimage(&moveleft[0], _T("resourse/乌萨斯着铠术师/move/left_1.png"), width, height);
	loadimage(&moveleft[1], _T("resourse/乌萨斯着铠术师/move/left_2.png"), width, height);
	loadimage(&moveleft[2], _T("resourse/乌萨斯着铠术师/move/left_3.png"), width, height);
	loadimage(&moveleft[3], _T("resourse/乌萨斯着铠术师/move/left_4.png"), width, height);
	loadimage(&moveleft[4], _T("resourse/乌萨斯着铠术师/move/left_5.png"), width, height);
	loadimage(&moveleft[5], _T("resourse/乌萨斯着铠术师/move/left_6.png"), width, height);
	loadimage(&moveleft[6], _T("resourse/乌萨斯着铠术师/move/left_7.png"), width, height);
	loadimage(&moveleft[7], _T("resourse/乌萨斯着铠术师/move/left_8.png"), width, height);

	loadimage(&moveleft1[0], _T("resourse/乌萨斯着铠术师/move/left_1_1.png"), width, height);
	loadimage(&moveleft1[1], _T("resourse/乌萨斯着铠术师/move/left_2_1.png"), width, height);
	loadimage(&moveleft1[2], _T("resourse/乌萨斯着铠术师/move/left_3_1.png"), width, height);
	loadimage(&moveleft1[3], _T("resourse/乌萨斯着铠术师/move/left_4_1.png"), width, height);
	loadimage(&moveleft1[4], _T("resourse/乌萨斯着铠术师/move/left_5_1.png"), width, height);
	loadimage(&moveleft1[5], _T("resourse/乌萨斯着铠术师/move/left_6_1.png"), width, height);
	loadimage(&moveleft1[6], _T("resourse/乌萨斯着铠术师/move/left_7_1.png"), width, height);
	loadimage(&moveleft1[7], _T("resourse/乌萨斯着铠术师/move/left_8_1.png"), width, height);
}
//bool ifshoot(Amiya& amiya,int xM) {//判断是否发射子弹
//	if (shooting_cd == 0)
//		return attack_distant(amiya, xM);
//}
int scorcerer::get_bulletdamage(int i) {
	return bul[i].getdamage();
}
void scorcerer::creat_bullet(int damage) {
	for (int i = 0; i < bullet_sum; i++) {//可优化，合并到enemy类
		if (!bul[i].getshoot()) {
			if (direction > 0) {
				bul[i].create(x + width, y + height / 2, damage, direction);
			}
			else {
				bul[i].create(x, y + height / 2, damage, direction);
			}
			break;

		}
	}
}
void scorcerer::getspeed(Amiya& amiya, int xM) {
	if (x >= right_wander_barrier) {
		direction = -1;
		std::cout << 1 << std::endl;
	}
	else if (x <= left_wander_barrier) {
		direction = 1;
	}
	if (vx < 0 && direction>0) {
		vx = -vx;
	}
	else if (vx > 0 && direction < 0) {
		vx = -vx;
	}
	if (shooting_cd > 0) { shooting_cd--; }
}
bool scorcerer::bullet_check(unit* s, int i, int xM) {//这里和阿米娅的判断不一样，阿米娅的的子弹在创造的时候被放到了地图参考系里面
	if (bul[i].getshoot()) {//但是这里需要xM把子弹转换到阿米娅的参考系
		if (bul[i].checkhit(s, xM)) {
			std::cout << "hit" << std::endl;
			bul[i].changeshoot();
			return 1;
		}
	}
	return 0;
}
void scorcerer::distant_attack_update(int xM) {
	if (distant_attack_frame == 4 * 3) {
		this->creat_bullet();
	}
	distant_attack_frame++;
	if (distant_attack_frame >= 7 * 3 - 1) {
		shooting_cd = shoot_cd;
		state = walk;
	}
}
void scorcerer::show(int xM) {
	if (state == toattack_distant) {
		if (direction > 0) {
			putimage_alpha(x + xM, y, &attackright[distant_attack_frame / 3]);
		}
		else if (direction < 0) {
			putimage_alpha(x + xM, y, &attackleft[distant_attack_frame / 3]);
		}
	}
	else if (state == walk) {
		if (move_frame > 8 * 2 - 1) {
			move_frame = 0;
		}
		if (direction > 0) {
			putimage(x + xM, y, &moveright1[move_frame / 2], SRCAND);
			putimage(x + xM, y, &moveright[move_frame / 2], SRCPAINT);
		}
		else if (direction < 0) {
			putimage(x + xM, y, &moveleft1[move_frame / 2], SRCAND);
			putimage(x + xM, y, &moveleft[move_frame / 2], SRCPAINT);
		}
		move_frame++;
	}
	for (int i = 0; i < bullet_sum; i++) {
		if (bul[i].getshoot()) {
			bul[i].show(bull, xM);
		}
	}
	showblood(xM);
}
void scorcerer::attack_update(Amiya& amiya, int xM, stone_controller& stone) {
	if (alive && state == walk) {
		ifshoot(amiya, xM);
	}
	if (alive && state == toattack_distant) {
		distant_attack_update(xM);
	}
	for (int j = 0; j < amiya.getbullet_sum(); j++) {
		if (alive && amiya.bullet_check(this, j)) {
			behurt(amiya.get_bulletdamage(j));
		}
	}
	for (int j = 0; j < getbullet_sum(); j++) {
		if (bul[j].getshoot() && stone.check_lr(&bul[j])) {
			bul[j].changeshoot();//有时候之所以能够传过去，是因为子弹太长，再加上怪物的身体有一部分x+width在石块里，所以加上以后右边//
		}
	}
	for (int j = 0; j < getbullet_sum(); j++) {
		if (amiya.getalive() && bullet_check(&amiya, j, xM)) {
			amiya.behurt(damage);
		}
	}
}
void scorcerer::move_update(Amiya& amiya, int xM, stone_controller& stone) {}
void scorcerer::behurt(int i) {
	hp -= i;
	hp = max(hp, 0);
	if (hp == 0) {
		alive = 0;
	}
}
elite::elite(int a, int b, int l, int r) { init(a, b, l, r); }
void elite::init(int a, int b, int l, int r) {
	x = a;
	y = b;
	vx = 4;
	vy = 0;
	hp_max = hp = 1000;
	wake = 1;
	alive = 1;
	left_wander_barrier = l;
	right_wander_barrier = r;
	move_frame = 0;
	state = walk;
	height = enemy3_h;
	width = enemy3_w;
	attack_distant_range = 600;
	attack_close_range = 100;
	judging = 0;
	damage = 150;
	close_attack_cdcounting = 0;
	close_attack_cd = 20;
	shooting_cd = 0;
	shoot_cd = 40;
	direction = 1;
	value = 200;
	id = 3;
	loadimage(&bull, _T("resourse/帝国前锋精锐/子弹.png"), 20, 20);
	//这里可以调用子弹的init函数来初始化子弹数值
	loadimage(&attack1right[0], _T("resourse/帝国前锋精锐/attack_1/right_1.png"), width, height);
	loadimage(&attack1right[1], _T("resourse/帝国前锋精锐/attack_1/right_2.png"), width, height);
	loadimage(&attack1right[2], _T("resourse/帝国前锋精锐/attack_1/right_3.png"), width, height);
	loadimage(&attack1right[3], _T("resourse/帝国前锋精锐/attack_1/right_4.png"), width, height);
	loadimage(&attack1right[4], _T("resourse/帝国前锋精锐/attack_1/right_5.png"), width, height);
	loadimage(&attack1right[5], _T("resourse/帝国前锋精锐/attack_1/right_6.png"), width, height);
	loadimage(&attack1right[6], _T("resourse/帝国前锋精锐/attack_1/right_7.png"), width, height);
	loadimage(&attack1right[7], _T("resourse/帝国前锋精锐/attack_1/right_8.png"), width, height);
	loadimage(&attack1right[8], _T("resourse/帝国前锋精锐/attack_1/right_9.png"), width, height);
	loadimage(&attack1right[9], _T("resourse/帝国前锋精锐/attack_1/right_10.png"), width, height);
	loadimage(&attack1right[10], _T("resourse/帝国前锋精锐/attack_1/right_11.png"), width, height);

	loadimage(&attack1right_1[0], _T("resourse/帝国前锋精锐/attack_1/right_1_1.png"), width, height);
	loadimage(&attack1right_1[1], _T("resourse/帝国前锋精锐/attack_1/right_2_1.png"), width, height);
	loadimage(&attack1right_1[2], _T("resourse/帝国前锋精锐/attack_1/right_3_1.png"), width, height);
	loadimage(&attack1right_1[3], _T("resourse/帝国前锋精锐/attack_1/right_4_1.png"), width, height);
	loadimage(&attack1right_1[4], _T("resourse/帝国前锋精锐/attack_1/right_5_1.png"), width, height);
	loadimage(&attack1right_1[5], _T("resourse/帝国前锋精锐/attack_1/right_6_1.png"), width, height);
	loadimage(&attack1right_1[6], _T("resourse/帝国前锋精锐/attack_1/right_7_1.png"), width, height);
	loadimage(&attack1right_1[7], _T("resourse/帝国前锋精锐/attack_1/right_8_1.png"), width, height);
	loadimage(&attack1right_1[8], _T("resourse/帝国前锋精锐/attack_1/right_9_1.png"), width, height);
	loadimage(&attack1right_1[9], _T("resourse/帝国前锋精锐/attack_1/right_10_1.png"), width, height);
	loadimage(&attack1right_1[10], _T("resourse/帝国前锋精锐/attack_1/right_11_1.png"), width, height);

	loadimage(&attack1left[0], _T("resourse/帝国前锋精锐/attack_1/left_1.png"), width, height);
	loadimage(&attack1left[1], _T("resourse/帝国前锋精锐/attack_1/left_2.png"), width, height);
	loadimage(&attack1left[2], _T("resourse/帝国前锋精锐/attack_1/left_3.png"), width, height);
	loadimage(&attack1left[3], _T("resourse/帝国前锋精锐/attack_1/left_4.png"), width, height);
	loadimage(&attack1left[4], _T("resourse/帝国前锋精锐/attack_1/left_5.png"), width, height);
	loadimage(&attack1left[5], _T("resourse/帝国前锋精锐/attack_1/left_6.png"), width, height);
	loadimage(&attack1left[6], _T("resourse/帝国前锋精锐/attack_1/left_7.png"), width, height);
	loadimage(&attack1left[7], _T("resourse/帝国前锋精锐/attack_1/left_8.png"), width, height);
	loadimage(&attack1left[8], _T("resourse/帝国前锋精锐/attack_1/left_9.png"), width, height);
	loadimage(&attack1left[9], _T("resourse/帝国前锋精锐/attack_1/left_10.png"), width, height);
	loadimage(&attack1left[10], _T("resourse/帝国前锋精锐/attack_1/left_11.png"), width, height);

	loadimage(&attack1left_1[0], _T("resourse/帝国前锋精锐/attack_1/left_1_1.png"), width, height);
	loadimage(&attack1left_1[1], _T("resourse/帝国前锋精锐/attack_1/left_2_1.png"), width, height);
	loadimage(&attack1left_1[2], _T("resourse/帝国前锋精锐/attack_1/left_3_1.png"), width, height);
	loadimage(&attack1left_1[3], _T("resourse/帝国前锋精锐/attack_1/left_4_1.png"), width, height);
	loadimage(&attack1left_1[4], _T("resourse/帝国前锋精锐/attack_1/left_5_1.png"), width, height);
	loadimage(&attack1left_1[5], _T("resourse/帝国前锋精锐/attack_1/left_6_1.png"), width, height);
	loadimage(&attack1left_1[6], _T("resourse/帝国前锋精锐/attack_1/left_7_1.png"), width, height);
	loadimage(&attack1left_1[7], _T("resourse/帝国前锋精锐/attack_1/left_8_1.png"), width, height);
	loadimage(&attack1left_1[8], _T("resourse/帝国前锋精锐/attack_1/left_9_1.png"), width, height);
	loadimage(&attack1left_1[9], _T("resourse/帝国前锋精锐/attack_1/left_10_1.png"), width, height);
	loadimage(&attack1left_1[10], _T("resourse/帝国前锋精锐/attack_1/left_11_1.png"), width, height);

	loadimage(&moveright[0], _T("resourse/帝国前锋精锐/move/right_1.png"), width, height);
	loadimage(&moveright[1], _T("resourse/帝国前锋精锐/move/right_2.png"), width, height);
	loadimage(&moveright[2], _T("resourse/帝国前锋精锐/move/right_3.png"), width, height);
	loadimage(&moveright[3], _T("resourse/帝国前锋精锐/move/right_4.png"), width, height);
	loadimage(&moveright[4], _T("resourse/帝国前锋精锐/move/right_5.png"), width, height);
	loadimage(&moveright[5], _T("resourse/帝国前锋精锐/move/right_6.png"), width, height);
	loadimage(&moveright[6], _T("resourse/帝国前锋精锐/move/right_7.png"), width, height);
	loadimage(&moveright[7], _T("resourse/帝国前锋精锐/move/right_8.png"), width, height);
	loadimage(&moveright[8], _T("resourse/帝国前锋精锐/move/right_9.png"), width, height);

	loadimage(&moveright_1[0], _T("resourse/帝国前锋精锐/move/right_1_1.png"), width, height);
	loadimage(&moveright_1[1], _T("resourse/帝国前锋精锐/move/right_2_1.png"), width, height);
	loadimage(&moveright_1[2], _T("resourse/帝国前锋精锐/move/right_3_1.png"), width, height);
	loadimage(&moveright_1[3], _T("resourse/帝国前锋精锐/move/right_4_1.png"), width, height);
	loadimage(&moveright_1[4], _T("resourse/帝国前锋精锐/move/right_5_1.png"), width, height);
	loadimage(&moveright_1[5], _T("resourse/帝国前锋精锐/move/right_6_1.png"), width, height);
	loadimage(&moveright_1[6], _T("resourse/帝国前锋精锐/move/right_7_1.png"), width, height);
	loadimage(&moveright_1[7], _T("resourse/帝国前锋精锐/move/right_8_1.png"), width, height);
	loadimage(&moveright_1[8], _T("resourse/帝国前锋精锐/move/right_9_1.png"), width, height);

	loadimage(&moveleft[0], _T("resourse/帝国前锋精锐/move/left_1.png"), width, height);
	loadimage(&moveleft[1], _T("resourse/帝国前锋精锐/move/left_2.png"), width, height);
	loadimage(&moveleft[2], _T("resourse/帝国前锋精锐/move/left_3.png"), width, height);
	loadimage(&moveleft[3], _T("resourse/帝国前锋精锐/move/left_4.png"), width, height);
	loadimage(&moveleft[4], _T("resourse/帝国前锋精锐/move/left_5.png"), width, height);
	loadimage(&moveleft[5], _T("resourse/帝国前锋精锐/move/left_6.png"), width, height);
	loadimage(&moveleft[6], _T("resourse/帝国前锋精锐/move/left_7.png"), width, height);
	loadimage(&moveleft[7], _T("resourse/帝国前锋精锐/move/left_8.png"), width, height);
	loadimage(&moveleft[8], _T("resourse/帝国前锋精锐/move/left_9.png"), width, height);

	loadimage(&moveleft_1[0], _T("resourse/帝国前锋精锐/move/left_1_1.png"), width, height);
	loadimage(&moveleft_1[1], _T("resourse/帝国前锋精锐/move/left_2_1.png"), width, height);
	loadimage(&moveleft_1[2], _T("resourse/帝国前锋精锐/move/left_3_1.png"), width, height);
	loadimage(&moveleft_1[3], _T("resourse/帝国前锋精锐/move/left_4_1.png"), width, height);
	loadimage(&moveleft_1[4], _T("resourse/帝国前锋精锐/move/left_5_1.png"), width, height);
	loadimage(&moveleft_1[5], _T("resourse/帝国前锋精锐/move/left_6_1.png"), width, height);
	loadimage(&moveleft_1[6], _T("resourse/帝国前锋精锐/move/left_7_1.png"), width, height);
	loadimage(&moveleft_1[7], _T("resourse/帝国前锋精锐/move/left_8_1.png"), width, height);
	loadimage(&moveleft_1[8], _T("resourse/帝国前锋精锐/move/left_9_1.png"), width, height);
}
void elite::creat_bullet(int damage) {
	for (int i = 0; i < bullet_sum; i++) {//可优化，合并到enemy类
		if (!bul[i].getshoot()) {
			if (direction > 0) {
				bul[i].create(x + width, y + height / 2, damage, direction);
			}
			else {
				bul[i].create(x, y + height / 2, damage, direction);
			}
			break;

		}
	}
}
bool elite::bullet_check(unit* s, int i, int xM) {//这里和阿米娅的判断不一样，阿米娅的的子弹在创造的时候被放到了地图参考系里面
	if (bul[i].getshoot()) {//但是这里需要xM把子弹转换到阿米娅的参考系
		if (bul[i].checkhit(s, xM)) {
			std::cout << "hit" << std::endl;
			bul[i].changeshoot();
			return 1;
		}
	}
	return 0;
}
void elite::check_attack(Amiya& amiya, int xM) {
	ifshoot(amiya, xM);
}
void elite::getspeed(Amiya& amiya, int xM) {//可以合并到enemy里面，把两种行动方式弄一个重载或者名字类似的函数
	if (x >= right_wander_barrier) {
		direction = -1;
		std::cout << 1 << std::endl;
	}
	else if (x <= left_wander_barrier) {
		direction = 1;
	}
	if (vx < 0 && direction>0) {
		vx = -vx;
	}
	else if (vx > 0 && direction < 0) {
		vx = -vx;
	}
	if (shooting_cd > 0) { shooting_cd--; }
	if (close_attack_cdcounting > 0) { close_attack_cdcounting--; }
}
void elite::distant_attack_update(int xM) {
	if (distant_attack_frame == 7 * 2) { this->creat_bullet(); }
	if (distant_attack_frame > 10 * 2) {
		shooting_cd = shoot_cd;
		state = walk;
	}
	distant_attack_frame++;
}
void elite::close_attack_update(Amiya& amiya, int xM) {
	if (close_attack_frame == 30)
	{
		if (direction > 0)
			sw.create(x, y - 10, height + 10, attack_close_range + width, direction);
		else {
			sw.create(x - attack_close_range, y - 10, height + 10, attack_close_range + width, direction);//攻击判断，注意左右攻击范围要对称处理
		}
		if (sw.checkhit(&amiya, xM)) {
			std::cout << "xiaoguai hit" << std::endl;
			amiya.behurt(damage);
		}
	}
	close_attack_frame++;
	if (close_attack_frame >= 40) { state = walk; close_attack_cdcounting = close_attack_cd; }
}
void elite::show(int xM) {
	if (state == toattack_distant) {
		if (direction > 0) {
			putimage(x + xM, y, &attack1right_1[distant_attack_frame / 2], SRCAND);
			putimage(x + xM, y, &attack1right[distant_attack_frame / 2], SRCPAINT);
		}
		else if (direction < 0) {
			putimage(x + xM, y, &attack1left_1[distant_attack_frame / 2], SRCAND);
			putimage(x + xM, y, &attack1left[distant_attack_frame / 2], SRCPAINT);
		}
	}
	else if (state == walk) {
		if (move_frame > 8) {
			move_frame = 0;
		}
		if (direction > 0) {
			putimage(x + xM, y, &moveright_1[move_frame], SRCAND);
			putimage(x + xM, y, &moveright[move_frame], SRCPAINT);
		}
		else if (direction < 0) {
			putimage(x + xM, y, &moveleft_1[move_frame], SRCAND);
			putimage(x + xM, y, &moveleft[move_frame], SRCPAINT);
		}
		move_frame++;
	}
	for (int i = 0; i < bullet_sum; i++) {
		if (bul[i].getshoot()) {
			bul[i].show(bull, xM);
		}
	}
	showblood(xM, 20);
}
void elite::attack_update(Amiya& amiya, int xM, stone_controller& stone) {
	if (alive && state == walk) {
		ifshoot(amiya, xM);
	}
	if (alive && state == toattack_distant) {
		distant_attack_update(xM);
	}
	for (int j = 0; j < amiya.getbullet_sum(); j++) {
		if (alive && amiya.bullet_check(this, j)) {
			behurt(amiya.get_bulletdamage(j));
		}
	}
	for (int j = 0; j < getbullet_sum(); j++) {
		if (bul[j].getshoot() && stone.check_lr(&bul[j])) {
			bul[j].changeshoot();
		}
	}
	for (int j = 0; j < getbullet_sum(); j++) {
		if (amiya.getalive() && bullet_check(&amiya, j, xM)) {
			amiya.behurt(damage);
		}
	}
}
void elite::move_update(Amiya& amiya, int xM, stone_controller& stone) {}
void elite::behurt(int i) {
	hp -= i;
	hp = max(hp, 0);
	if (hp == 0) {
		alive = 0;
	}
}
Blacksnake::Blacksnake(int a, int b) { init(a, b); }
void Blacksnake::init(int a, int b) {
	x = a;
	y = b;
	vx = 0;
	vy = 0;
	cd1 = 300;
	cd2 = 50;
	cd3 = 200;
	id = 4;
	judging = 40;
	value = 1000;
	stage = 1;
	cd1_counter = 0;
	cd2_counter = 0;
	cd3_counter = 0;
	damage1 = 100;
	damage2 = 200;
	hp_max = hp = 5000;
	wake = 0;
	alive = 1;
	height = boss_height;
	width = boss_width;
	attack_close_range = 30;
	attack_distant_range = 400;
	damage = 30;
	onground = 1;
	attacking_speed = 2;
	boss_vx = 5;
	direction = 1;
	loadimage(&bull_right, _T("resourse/boss/子弹.tif"), 50, 30);
	loadimage(&bull_left, _T("resourse/boss/子弹_左.tif"), 50, 30);
	loadimage(&special_bull, _T("resourse/boss/子弹_特殊.tif"), 30, 60);
	loadimage(&right_move[0], _T("resourse/boss/move/right_1.png"), boss_width, boss_height);
	loadimage(&right_move[1], _T("resourse/boss/move/right_2.png"), boss_width, boss_height);
	loadimage(&right_move[2], _T("resourse/boss/move/right_3.png"), boss_width, boss_height);
	loadimage(&right_move[3], _T("resourse/boss/move/right_4.png"), boss_width, boss_height);
	loadimage(&right_move[4], _T("resourse/boss/move/right_5.png"), boss_width, boss_height);
	loadimage(&right_move[5], _T("resourse/boss/move/right_6.png"), boss_width, boss_height);
	loadimage(&right_move[6], _T("resourse/boss/move/right_7.png"), boss_width, boss_height);
	loadimage(&right_move[7], _T("resourse/boss/move/right_8.png"), boss_width, boss_height);
	loadimage(&right_move[8], _T("resourse/boss/move/right_9.png"), boss_width, boss_height);
	loadimage(&right_move[9], _T("resourse/boss/move/right_10.png"), boss_width, boss_height);
	loadimage(&right_move[10], _T("resourse/boss/move/right_11.png"), boss_width, boss_height);
	loadimage(&right_move[11], _T("resourse/boss/move/right_12.png"), boss_width, boss_height);
	loadimage(&right_move_1[0], _T("resourse/boss/move/right_1_1.png"), boss_width, boss_height);
	loadimage(&right_move_1[1], _T("resourse/boss/move/right_2_1.png"), boss_width, boss_height);
	loadimage(&right_move_1[2], _T("resourse/boss/move/right_3_1.png"), boss_width, boss_height);
	loadimage(&right_move_1[3], _T("resourse/boss/move/right_4_1.png"), boss_width, boss_height);
	loadimage(&right_move_1[4], _T("resourse/boss/move/right_5_1.png"), boss_width, boss_height);
	loadimage(&right_move_1[5], _T("resourse/boss/move/right_6_1.png"), boss_width, boss_height);
	loadimage(&right_move_1[6], _T("resourse/boss/move/right_7_1.png"), boss_width, boss_height);
	loadimage(&right_move_1[7], _T("resourse/boss/move/right_8_1.png"), boss_width, boss_height);
	loadimage(&right_move_1[8], _T("resourse/boss/move/right_9_1.png"), boss_width, boss_height);
	loadimage(&right_move_1[9], _T("resourse/boss/move/right_10_1.png"), boss_width, boss_height);
	loadimage(&right_move_1[10], _T("resourse/boss/move/right_11_1.png"), boss_width, boss_height);
	loadimage(&right_move_1[11], _T("resourse/boss/move/right_12_1.png"), boss_width, boss_height);
	//加载向右移动图像
	loadimage(&left_move[0], _T("resourse/boss/move/left_1.png"), boss_width, boss_height);
	loadimage(&left_move[1], _T("resourse/boss/move/left_2.png"), boss_width, boss_height);
	loadimage(&left_move[2], _T("resourse/boss/move/left_3.png"), boss_width, boss_height);
	loadimage(&left_move[3], _T("resourse/boss/move/left_4.png"), boss_width, boss_height);
	loadimage(&left_move[4], _T("resourse/boss/move/left_5.png"), boss_width, boss_height);
	loadimage(&left_move[5], _T("resourse/boss/move/left_6.png"), boss_width, boss_height);
	loadimage(&left_move[6], _T("resourse/boss/move/left_7.png"), boss_width, boss_height);
	loadimage(&left_move[7], _T("resourse/boss/move/left_8.png"), boss_width, boss_height);
	loadimage(&left_move[8], _T("resourse/boss/move/left_9.png"), boss_width, boss_height);
	loadimage(&left_move[9], _T("resourse/boss/move/left_10.png"), boss_width, boss_height);
	loadimage(&left_move[10], _T("resourse/boss/move/left_11.png"), boss_width, boss_height);
	loadimage(&left_move[11], _T("resourse/boss/move/left_12.png"), boss_width, boss_height);
	loadimage(&left_move_1[0], _T("resourse/boss/move/left_1_1.png"), boss_width, boss_height);
	loadimage(&left_move_1[1], _T("resourse/boss/move/left_2_1.png"), boss_width, boss_height);
	loadimage(&left_move_1[2], _T("resourse/boss/move/left_3_1.png"), boss_width, boss_height);
	loadimage(&left_move_1[3], _T("resourse/boss/move/left_4_1.png"), boss_width, boss_height);
	loadimage(&left_move_1[4], _T("resourse/boss/move/left_5_1.png"), boss_width, boss_height);
	loadimage(&left_move_1[5], _T("resourse/boss/move/left_6_1.png"), boss_width, boss_height);
	loadimage(&left_move_1[6], _T("resourse/boss/move/left_7_1.png"), boss_width, boss_height);
	loadimage(&left_move_1[7], _T("resourse/boss/move/left_8_1.png"), boss_width, boss_height);
	loadimage(&left_move_1[8], _T("resourse/boss/move/left_9_1.png"), boss_width, boss_height);
	loadimage(&left_move_1[9], _T("resourse/boss/move/left_10_1.png"), boss_width, boss_height);
	loadimage(&left_move_1[10], _T("resourse/boss/move/left_11_1.png"), boss_width, boss_height);
	loadimage(&left_move_1[11], _T("resourse/boss/move/left_12_1.png"), boss_width, boss_height);
	//加载向左移动图像
	loadimage(&right_attack[0], _T("resourse/boss/attack_close/right_1.png"), boss_width, boss_height);
	loadimage(&right_attack[1], _T("resourse/boss/attack_close/right_2.png"), boss_width, boss_height);
	loadimage(&right_attack[2], _T("resourse/boss/attack_close/right_3.png"), boss_width, boss_height);
	loadimage(&right_attack[3], _T("resourse/boss/attack_close/right_4.png"), boss_width, boss_height);
	loadimage(&right_attack[4], _T("resourse/boss/attack_close/right_5.png"), boss_width, boss_height);
	loadimage(&right_attack[5], _T("resourse/boss/attack_close/right_6.png"), boss_width, boss_height);
	loadimage(&right_attack[6], _T("resourse/boss/attack_close/right_7.png"), boss_width, boss_height);
	loadimage(&right_attack[7], _T("resourse/boss/attack_close/right_8.png"), boss_width, boss_height);
	loadimage(&right_attack[8], _T("resourse/boss/attack_close/right_9.png"), boss_width, boss_height);
	loadimage(&right_attack[9], _T("resourse/boss/attack_close/right_10.png"), boss_width, boss_height);
	loadimage(&right_attack[10], _T("resourse/boss/attack_close/right_11.png"), boss_width, boss_height);
	loadimage(&right_attack[11], _T("resourse/boss/attack_close/right_12.png"), boss_width, boss_height);
	int widthtmp = 60, heighttmp = 20;
	loadimage(&right_attack[12], _T("resourse/boss/attack_close/right_13.png"), boss_width + widthtmp, boss_height + heighttmp + 20);
	loadimage(&right_attack[13], _T("resourse/boss/attack_close/right_14.png"), boss_width + widthtmp, boss_height + heighttmp + 20);
	loadimage(&right_attack[14], _T("resourse/boss/attack_close/right_15.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&right_attack[15], _T("resourse/boss/attack_close/right_16.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&right_attack[16], _T("resourse/boss/attack_close/right_17.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&right_attack[17], _T("resourse/boss/attack_close/right_18.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&right_attack[18], _T("resourse/boss/attack_close/right_19.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&right_attack[19], _T("resourse/boss/attack_close/right_20.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&right_attack[20], _T("resourse/boss/attack_close/right_21.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&right_attack[21], _T("resourse/boss/attack_close/right_22.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&right_attack[22], _T("resourse/boss/attack_close/right_23.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&right_attack[23], _T("resourse/boss/attack_close/right_24.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&right_attack[24], _T("resourse/boss/attack_close/right_25.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&right_attack[25], _T("resourse/boss/attack_close/right_26.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&right_attack_1[0], _T("resourse/boss/attack_close/right_1_1.png"), boss_width, boss_height);
	loadimage(&right_attack_1[1], _T("resourse/boss/attack_close/right_2_1.png"), boss_width, boss_height);
	loadimage(&right_attack_1[2], _T("resourse/boss/attack_close/right_3_1.png"), boss_width, boss_height);
	loadimage(&right_attack_1[3], _T("resourse/boss/attack_close/right_4_1.png"), boss_width, boss_height);
	loadimage(&right_attack_1[4], _T("resourse/boss/attack_close/right_5_1.png"), boss_width, boss_height);
	loadimage(&right_attack_1[5], _T("resourse/boss/attack_close/right_6_1.png"), boss_width, boss_height);
	loadimage(&right_attack_1[6], _T("resourse/boss/attack_close/right_7_1.png"), boss_width, boss_height);
	loadimage(&right_attack_1[7], _T("resourse/boss/attack_close/right_8_1.png"), boss_width, boss_height);
	loadimage(&right_attack_1[8], _T("resourse/boss/attack_close/right_9_1.png"), boss_width, boss_height);
	loadimage(&right_attack_1[9], _T("resourse/boss/attack_close/right_10_1.png"), boss_width, boss_height);
	loadimage(&right_attack_1[10], _T("resourse/boss/attack_close/right_11_1.png"), boss_width, boss_height);
	loadimage(&right_attack_1[11], _T("resourse/boss/attack_close/right_12_1.png"), boss_width, boss_height);
	loadimage(&right_attack_1[12], _T("resourse/boss/attack_close/right_13_1.png"), boss_width + widthtmp, boss_height + heighttmp + 20);
	loadimage(&right_attack_1[13], _T("resourse/boss/attack_close/right_14_1.png"), boss_width + widthtmp, boss_height + heighttmp + 20);
	loadimage(&right_attack_1[14], _T("resourse/boss/attack_close/right_15_1.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&right_attack_1[15], _T("resourse/boss/attack_close/right_16_1.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&right_attack_1[16], _T("resourse/boss/attack_close/right_17_1.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&right_attack_1[17], _T("resourse/boss/attack_close/right_18_1.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&right_attack_1[18], _T("resourse/boss/attack_close/right_19_1.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&right_attack_1[19], _T("resourse/boss/attack_close/right_20_1.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&right_attack_1[20], _T("resourse/boss/attack_close/right_21_1.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&right_attack_1[21], _T("resourse/boss/attack_close/right_22_1.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&right_attack_1[22], _T("resourse/boss/attack_close/right_23_1.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&right_attack_1[23], _T("resourse/boss/attack_close/right_24_1.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&right_attack_1[24], _T("resourse/boss/attack_close/right_25_1.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&right_attack_1[25], _T("resourse/boss/attack_close/right_26_1.png"), boss_width + widthtmp, boss_height + heighttmp);
	//加载向右攻击图像（两张图）
	loadimage(&left_attack[0], _T("resourse/boss/attack_close/left_1.png"), boss_width, boss_height);
	loadimage(&left_attack[1], _T("resourse/boss/attack_close/left_2.png"), boss_width, boss_height);
	loadimage(&left_attack[2], _T("resourse/boss/attack_close/left_3.png"), boss_width, boss_height);
	loadimage(&left_attack[3], _T("resourse/boss/attack_close/left_4.png"), boss_width, boss_height);
	loadimage(&left_attack[4], _T("resourse/boss/attack_close/left_5.png"), boss_width, boss_height);
	loadimage(&left_attack[5], _T("resourse/boss/attack_close/left_6.png"), boss_width, boss_height);
	loadimage(&left_attack[6], _T("resourse/boss/attack_close/left_7.png"), boss_width, boss_height);
	loadimage(&left_attack[7], _T("resourse/boss/attack_close/left_8.png"), boss_width, boss_height);
	loadimage(&left_attack[8], _T("resourse/boss/attack_close/left_9.png"), boss_width, boss_height);
	loadimage(&left_attack[9], _T("resourse/boss/attack_close/left_10.png"), boss_width, boss_height);
	loadimage(&left_attack[10], _T("resourse/boss/attack_close/left_11.png"), boss_width, boss_height);
	loadimage(&left_attack[11], _T("resourse/boss/attack_close/left_12.png"), boss_width, boss_height);
	loadimage(&left_attack[12], _T("resourse/boss/attack_close/left_13.png"), boss_width + widthtmp, boss_height + heighttmp + 20);
	loadimage(&left_attack[13], _T("resourse/boss/attack_close/left_14.png"), boss_width + widthtmp, boss_height + heighttmp + 20);
	loadimage(&left_attack[14], _T("resourse/boss/attack_close/left_15.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&left_attack[15], _T("resourse/boss/attack_close/left_16.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&left_attack[16], _T("resourse/boss/attack_close/left_17.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&left_attack[17], _T("resourse/boss/attack_close/left_18.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&left_attack[18], _T("resourse/boss/attack_close/left_19.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&left_attack[19], _T("resourse/boss/attack_close/left_20.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&left_attack[20], _T("resourse/boss/attack_close/left_21.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&left_attack[21], _T("resourse/boss/attack_close/left_22.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&left_attack[22], _T("resourse/boss/attack_close/left_23.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&left_attack[23], _T("resourse/boss/attack_close/left_24.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&left_attack[24], _T("resourse/boss/attack_close/left_25.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&left_attack[25], _T("resourse/boss/attack_close/left_26.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&left_attack_1[0], _T("resourse/boss/attack_close/left_1_1.png"), boss_width, boss_height);
	loadimage(&left_attack_1[1], _T("resourse/boss/attack_close/left_2_1.png"), boss_width, boss_height);
	loadimage(&left_attack_1[2], _T("resourse/boss/attack_close/left_3_1.png"), boss_width, boss_height);
	loadimage(&left_attack_1[3], _T("resourse/boss/attack_close/left_4_1.png"), boss_width, boss_height);
	loadimage(&left_attack_1[4], _T("resourse/boss/attack_close/left_5_1.png"), boss_width, boss_height);
	loadimage(&left_attack_1[5], _T("resourse/boss/attack_close/left_6_1.png"), boss_width, boss_height);
	loadimage(&left_attack_1[6], _T("resourse/boss/attack_close/left_7_1.png"), boss_width, boss_height);
	loadimage(&left_attack_1[7], _T("resourse/boss/attack_close/left_8_1.png"), boss_width, boss_height);
	loadimage(&left_attack_1[8], _T("resourse/boss/attack_close/left_9_1.png"), boss_width, boss_height);
	loadimage(&left_attack_1[9], _T("resourse/boss/attack_close/left_10_1.png"), boss_width, boss_height);
	loadimage(&left_attack_1[10], _T("resourse/boss/attack_close/left_11_1.png"), boss_width, boss_height);
	loadimage(&left_attack_1[11], _T("resourse/boss/attack_close/left_12_1.png"), boss_width, boss_height);
	loadimage(&left_attack_1[12], _T("resourse/boss/attack_close/left_13_1.png"), boss_width + widthtmp, boss_height + heighttmp + 20);
	loadimage(&left_attack_1[13], _T("resourse/boss/attack_close/left_14_1.png"), boss_width + widthtmp, boss_height + heighttmp + 20);
	loadimage(&left_attack_1[14], _T("resourse/boss/attack_close/left_15_1.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&left_attack_1[15], _T("resourse/boss/attack_close/left_16_1.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&left_attack_1[16], _T("resourse/boss/attack_close/left_17_1.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&left_attack_1[17], _T("resourse/boss/attack_close/left_18_1.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&left_attack_1[18], _T("resourse/boss/attack_close/left_19_1.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&left_attack_1[19], _T("resourse/boss/attack_close/left_20_1.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&left_attack_1[20], _T("resourse/boss/attack_close/left_21_1.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&left_attack_1[21], _T("resourse/boss/attack_close/left_22_1.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&left_attack_1[22], _T("resourse/boss/attack_close/left_23_1.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&left_attack_1[23], _T("resourse/boss/attack_close/left_24_1.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&left_attack_1[24], _T("resourse/boss/attack_close/left_25_1.png"), boss_width + widthtmp, boss_height + heighttmp);
	loadimage(&left_attack_1[25], _T("resourse/boss/attack_close/left_26_1.png"), boss_width + widthtmp, boss_height + heighttmp);
	//左边攻击
	//向左攻击图像

	loadimage(&right_distant_attack[0], _T("resourse/boss/远程/right_1.tif"), boss_width, boss_height);//特殊攻击图像
	loadimage(&right_distant_attack[1], _T("resourse/boss/远程/right_2.tif"), boss_width, boss_height);
	loadimage(&right_distant_attack[2], _T("resourse/boss/远程/right_3.tif"), boss_width, boss_height);
	loadimage(&right_distant_attack[3], _T("resourse/boss/远程/right_4.tif"), boss_width, boss_height);
	loadimage(&right_distant_attack[4], _T("resourse/boss/远程/right_5.tif"), boss_width, boss_height);
	loadimage(&right_distant_attack[5], _T("resourse/boss/远程/right_6.tif"), boss_width, boss_height);
	loadimage(&right_distant_attack[6], _T("resourse/boss/远程/right_7.tif"), boss_width, boss_height);
	loadimage(&right_distant_attack[7], _T("resourse/boss/远程/right_8.tif"), boss_width, boss_height);
	loadimage(&right_distant_attack[8], _T("resourse/boss/远程/right_9.tif"), boss_width, boss_height);
	loadimage(&right_distant_attack[9], _T("resourse/boss/远程/right_10.tif"), boss_width, boss_height);
	loadimage(&right_distant_attack[10], _T("resourse/boss/远程/right_11.tif"), boss_width, boss_height);
	loadimage(&right_distant_attack[11], _T("resourse/boss/远程/right_12.tif"), boss_width, boss_height);
	loadimage(&right_distant_attack[12], _T("resourse/boss/远程/right_13.tif"), boss_width, boss_height);
	loadimage(&right_distant_attack[13], _T("resourse/boss/远程/right_14.tif"), boss_width, boss_height);
	loadimage(&right_distant_attack[14], _T("resourse/boss/远程/right_15.tif"), boss_width, boss_height);

	loadimage(&left_distant_attack[0], _T("resourse/boss/远程/left_1.tif"), boss_width, boss_height);//特殊攻击图像
	loadimage(&left_distant_attack[1], _T("resourse/boss/远程/left_2.tif"), boss_width, boss_height);
	loadimage(&left_distant_attack[2], _T("resourse/boss/远程/left_3.tif"), boss_width, boss_height);
	loadimage(&left_distant_attack[3], _T("resourse/boss/远程/left_4.tif"), boss_width, boss_height);
	loadimage(&left_distant_attack[4], _T("resourse/boss/远程/left_5.tif"), boss_width, boss_height);
	loadimage(&left_distant_attack[5], _T("resourse/boss/远程/left_6.tif"), boss_width, boss_height);
	loadimage(&left_distant_attack[6], _T("resourse/boss/远程/left_7.tif"), boss_width, boss_height);
	loadimage(&left_distant_attack[7], _T("resourse/boss/远程/left_8.tif"), boss_width, boss_height);
	loadimage(&left_distant_attack[8], _T("resourse/boss/远程/left_9.tif"), boss_width, boss_height);
	loadimage(&left_distant_attack[9], _T("resourse/boss/远程/left_10.tif"), boss_width, boss_height);
	loadimage(&left_distant_attack[10], _T("resourse/boss/远程/left_11.tif"), boss_width, boss_height);
	loadimage(&left_distant_attack[11], _T("resourse/boss/远程/left_12.tif"), boss_width, boss_height);
	loadimage(&left_distant_attack[12], _T("resourse/boss/远程/left_13.tif"), boss_width, boss_height);
	loadimage(&left_distant_attack[13], _T("resourse/boss/远程/left_14.tif"), boss_width, boss_height);
	loadimage(&left_distant_attack[14], _T("resourse/boss/远程/left_15.tif"), boss_width, boss_height);

	loadimage(&special_effect_left[0], _T("resourse/boss/特效/left_1.tif"), 200, 200);
	loadimage(&special_effect_left[1], _T("resourse/boss/特效/left_2.tif"), 200, 200);
	loadimage(&special_effect_right[0], _T("resourse/boss/特效/right_1.tif"), 200, 200);
	loadimage(&special_effect_right[1], _T("resourse/boss/特效/right_2.tif"), 200, 200);

	loadimage(&head, _T("resourse/boss/boss_头像/头像_敌人_“不死的黑蛇”.png"), 100, 100);
	move_frame = 0;
	state = stand;

}
void Blacksnake::getspeed(Amiya& amiya, int xM) {
	if (amiya.gety() + c_height == y + height && abs(amiya.getx() - (x + xM)) <= 2000) {
		if (amiya.getx() - (x + xM) > 0) {
			direction = 1;
			vx = 4 * direction;
		}
		else if (amiya.getx() - (x + xM) == 0)vx = 0;
		else {
			direction = -1;
			vx = 4 * direction;
		}
	}
	else {
		vx = 0;
	}
}
void Blacksnake::bullet_update() {
	enemy::bullet_update();
	for (int i = 0; i < special_bullet_sum; i++) {
		if (special_bullet[i].getshoot()) {
			special_bullet[i].update();
		}
	}
}
void Blacksnake::move_update(Amiya& amiya, int xM, stone_controller& stone) {
	if (onground) {
		stone.check_bossonground(*this, xM);
	}
	else {
		stone.check_onground(*this, xM);
		if (!onground) {
			vy += g;
		}
	}
	if (state == toattack_close || state == toattack_distant) {
		vx = 0;
	}
	if (state == walk && amiya.ifonground() && onground && amiya.gety() + amiya.getheight() == height + y) {
		enemy::getspeed(amiya, xM);
		if (stone.check_lr(this, xM)) {
			vx = 0;
		}
	}
	else if (amiya.ifonground() && onground && amiya.gety() + amiya.getheight() < height + y) {
		if (state == walk) {
			if (amiya.getx() - xM <= boss_battle_right_secondfloor1) {
				if ((abs(x - boss_battle_left_secondfloor1) < abs(boss_battle_right_secondfloor1 - x) && x > boss_battle_left_secondfloor1 - buffer) || x > boss_battle_right_secondfloor1) {
					vx = -boss_vx;
					direction = -1;
				}
				else {
					vx = boss_vx;
					direction = 1;
				}
			}
			else if (amiya.getx() - xM >= boss_battle_left_secondfloor2) {
				if ((abs(boss_battle_right_secondfloor2 - x) > abs(x - boss_battle_left_secondfloor2) && x > boss_battle_left_secondfloor2 - buffer) || x > boss_battle_right_secondfloor2) {
					vx = -boss_vx;
					direction = -1;
				}
				else {
					vx = boss_vx;
					direction = 1;
				}
			}
			if (x<boss_battle_left_secondfloor1 && x>boss_battle_left_secondfloor1 - 1.1 * buffer && direction > 0) {
				vy = -65;
				state = jump;
				onground = 0;
			}
			else if (x > boss_battle_right_secondfloor1 && x < boss_battle_right_secondfloor1 + 1.1 * buffer && direction < 0) {
				state = jump;
				onground = 0;
				vy = -65;
			}
			else if (x<boss_battle_left_secondfloor2 && x>boss_battle_left_secondfloor2 - 1.1 * buffer && direction > 0) {
				state = jump;
				onground = 0;
				vy = -65;
			}
			else if (x > boss_battle_right_secondfloor2 && x < boss_battle_right_secondfloor2 + 1.1 * buffer && direction < 0) {
				state = jump;
				onground = 0;
				vy = -65;
			}
		}
	}
	else if (amiya.ifonground() && onground && amiya.gety() + amiya.getheight() > height + y) {
		if (x < boss_battle_right_secondfloor1) {
			if (amiya.getx() - xM < (boss_battle_left_secondfloor1 + boss_battle_right_secondfloor1) / 2) {
				vx = -boss_vx;
				direction = -1;
			}
			else {
				vx = boss_vx;
				direction = 1;
			}
		}
		else {
			if (amiya.getx() - xM > (boss_battle_left_secondfloor2 + boss_battle_right_secondfloor2) / 2) {
				vx = boss_vx;
				direction = 1;
			}
			else {
				vx = -boss_vx;
				direction = -1;
			}
		}
	}
	if (state == reborn) {
		vx = vy = 0;
	}
	x += vx;
	y += vy;
}
void Blacksnake::close_attack_update(Amiya& amiya, int xM) {
	if (close_attack_frame == 13 * attacking_speed)
	{
		if (direction > 0)
			sw.create(x, y - 10, height + 10, attack_close_range + width, direction);
		else {
			sw.create(x - attack_close_range, y - 10, height + 10, attack_close_range + width, direction);
		}
		if (sw.checkhit(&amiya, xM)) {
			std::cout << "talula hit" << std::endl;
			amiya.behurt(damage2);
		}
	}
	close_attack_frame++;
	if (close_attack_frame >= 26 * attacking_speed) { state = walk; cd2_counter = cd2; }
}
bool Blacksnake::bullet_check(unit* s, int i, int xM) {//这里和阿米娅的判断不一样，阿米娅的的子弹在创造的时候被放到了地图参考系里面
	if (bul[i].getshoot()) {//但是这里需要xM把子弹转换到阿米娅的参考系
		if (bul[i].checkhit(s, xM)) {
			std::cout << "hit" << std::endl;
			bul[i].changeshoot();
			return 1;
		}
	}
	return 0;
}
bool Blacksnake::special_bullet_check(unit* s, int i, int xM) {//这里和阿米娅的判断不一样，阿米娅的的子弹在创造的时候被放到了地图参考系里面
	if (special_bullet[i].getshoot()) {//但是这里需要xM把子弹转换到阿米娅的参考系
		if (special_bullet[i].checkhit(s, xM)) {
			std::cout << "hit" << std::endl;
			special_bullet[i].changeshoot();
			return 1;
		}
	}
	return 0;
}
void Blacksnake::special_attack_update() {
	special_attack_frame++;
	if (!(special_attack_frame % 2)) {
		for (int i = 0; i < special_bullet_sum; i++) {
			if (!special_bullet[i].getshoot()) {
				special_bullet[i].create(boss_battle_left + rand() % (boss_battle_right - boss_battle_left), 0, damage1, direction, 0, 10);
				break;
			}
		}
	}
	if (special_attack_frame >= 50 && state == spectial_attack) {
		state = walk;
		cd3_counter = cd3;
	}
	else if (special_attack_frame >= 50 && state == reborn) {
		cd3_counter = cd3;
	}
}
void Blacksnake::creat_bullet(int damage) {
	for (int i = 0; i < bullet_sum; i++) {//可优化，合并到enemy类
		if (!bul[i].getshoot()) {
			if (direction > 0) {
				bul[i].create(x + width, y + height / 2, damage1, direction);
			}
			else {
				bul[i].create(x, y + height / 2, damage1, direction);
			}
			break;

		}
	}
}
void Blacksnake::distant_attack_update() {
	if (distant_attack_frame == 8 * attacking_speed) { this->creat_bullet(); }
	if (distant_attack_frame >= 15 * attacking_speed - 1) {
		cd1_counter = cd1;
		state = walk;
	}
	distant_attack_frame++;
}
void Blacksnake::reborn_update() {
	hp += 30;
	hp = min(hp, hp_max);
	if (hp == hp_max) {
		stage = 2;
		state = spectial_attack;
	}
}
void Blacksnake::attack_update(Amiya& amiya, int xM, stone_controller& stone) {
	int distant;
	if (!wake) {
		checkawake(amiya, xM);
	}
	if (!wake)return;
	if (!onground)return;
	if (cd1_counter)cd1_counter--;
	if (cd2_counter)cd2_counter--;
	if (cd3_counter)cd3_counter--;
	if (cd1_counter == 0 && state == walk) {
		attack_distant(amiya, xM);
	}
	else if (cd2_counter == 0 && state == walk) {
		attack_close(amiya, xM);
	}
	else if (cd3_counter == 0 && stage > 1 && state == walk) {
		state = spectial_attack;
		special_attack_frame = 0;
	}
	else if (state == reborn) {
		reborn_update();
		std::cout << "reborning" << std::endl;
	}
	if (state == toattack_close) {
		close_attack_update(amiya, xM);
	}
	else if (state == toattack_distant) {
		distant_attack_update();
	}
	else if (state == spectial_attack || state == reborn) {
		special_attack_update();
	}
	for (int j = 0; j < getbullet_sum(); j++) {
		if (bul[j].getshoot() && stone.check_lr(&bul[j], xM)) {
			bul[j].changeshoot();
		}
	}
	for (int j = 0; j < getbullet_sum(); j++) {
		if (amiya.getalive() && bullet_check(&amiya, j, xM)) {
			amiya.behurt(damage1);
		}
	}
	for (int j = 0; j < getbullet_sum(); j++) {
		if (amiya.getalive() && bullet_check(&amiya, j, xM)) {
			amiya.behurt(damage1);
		}
	}
	for (int i = 0; i < special_bullet_sum; i++) {
		if (amiya.getalive() && special_bullet_check(&amiya, i, xM)) {
			amiya.behurt(damage1);
		}
		if (special_bullet[i].getshoot()) {
			if (special_bullet[i].gety() > screem_h) {
				special_bullet[i].changeshoot();
			}
		}
	}
	for (int j = 0; j < amiya.getbullet_sum(); j++) {
		if (alive && amiya.bullet_check(this, j)) {
			behurt(amiya.get_bulletdamage(j));
		}
	}
	std::cout << "stage" << stage << std::endl;
	if (hp == 0 && stage == 1) {
		state = reborn;
		boss_vx = 7;
		damage1 *= 2;
		damage2 *= 2;
		attacking_speed = 2;
	}
	else if (hp == 0 && stage == 2) {
		alive = 0;
		stone.boss_area_destroy();
	}
}//测试用
void Blacksnake::show(int xM) {
	std::cout << state << std::endl;
	if (state == walk || state == spectial_attack) {
		move_frame++;
		if (move_frame > 11 * 3) { move_frame = 0; }
		if (direction > 0) {
			putimage(x + xM, y, &right_move_1[move_frame / 3], SRCAND);
			putimage(x + xM, y, &right_move[move_frame / 3], SRCPAINT);
		}
		else {
			putimage(x + xM, y, &left_move_1[move_frame / 3], SRCAND);
			putimage(x + xM, y, &left_move[move_frame / 3], SRCPAINT);
		}
	}
	else if (state == stand || state == jump || state == reborn) {
		if (direction > 0) {
			putimage(x + xM, y, &right_move_1[0], SRCAND);
			putimage(x + xM, y, &right_move[0], SRCPAINT);
		}
		else {
			putimage(x + xM, y, &left_move_1[0], SRCAND);
			putimage(x + xM, y, &left_move[0], SRCPAINT);
		}
	}
	else if (state == toattack_distant) {
		if (direction > 0) {
			putimage_alpha(x + xM, y, &right_distant_attack[distant_attack_frame / attacking_speed]);
		}
		else {
			putimage_alpha(x + xM, y, &left_distant_attack[distant_attack_frame / attacking_speed]);
		}
	}
	else if (state == toattack_close) {
		int tmpx = 0, tmpy = 0;
		if (direction > 0) {
			if (close_attack_frame >= 12 * attacking_speed) { tmpx = 0; tmpy = -20; }
			if (close_attack_frame >= 12 * attacking_speed && close_attack_frame < 14 * attacking_speed) { tmpx = 0; tmpy = 0; }
			putimage(x + xM + tmpx, y + tmpy, &right_attack_1[close_attack_frame / attacking_speed], SRCAND);
			putimage(x + xM + tmpx, y + tmpy, &right_attack[close_attack_frame / attacking_speed], SRCPAINT);
		}
		if (direction <= 0) {
			if (close_attack_frame >= 12 * attacking_speed) { tmpx = -60; tmpy = -20; }
			if (close_attack_frame >= 12 * attacking_speed && close_attack_frame < 14 * attacking_speed) { tmpx = -60; tmpy = 0; }
			putimage(x + xM + tmpx, y + tmpy, &left_attack_1[close_attack_frame / attacking_speed], SRCAND);
			putimage(x + xM + tmpx, y + tmpy, &left_attack[close_attack_frame / attacking_speed], SRCPAINT);
		}
		if (stage == 2 && (close_attack_frame / attacking_speed) == 12) {
			std::cout << "show special effect" << std::endl;
			std::cout << close_attack_frame / attacking_speed << std::endl;
			if (direction > 0)
				putimage_alpha(x + xM + 10, y - 30, &special_effect_right[0]);
			else {
				putimage_alpha(x + xM - 130, y - 30, &special_effect_left[0]);
			}
		}
		else if (stage == 2 && (close_attack_frame / attacking_speed) == 13) {
			if (direction > 0)
				putimage_alpha(x + xM + 10, y - 30, &special_effect_right[1]);
			else {
				putimage_alpha(x + xM - 130, y - 30, &special_effect_left[1]);
			}
		}
	}
	if (wake) {
		putimage(300, 30, &head);
		setfillcolor('r');
		solidrectangle(400, 50, 400 + ((double)hp / hp_max) * 400, 90);//血条
		//outtextxy(220, 50, ((double)hp / hp_max));
		setfillcolor('r');
		setbkmode(TRANSPARENT);
		settextcolor(RGB(255, 255, 255));
		settextstyle(30, 0, _T("宋体"));
		char str[1180];
		sprintf_s(str, "%d/%d", hp, hp_max);
		outtextxy(410, 50, str);
	}
	for (int i = 0; i < bullet_sum; i++) {
		if (bul[i].getshoot()) {
			if (bul[i].getdirection() > 0) {
				bul[i].show(bull_right, xM);
			}
			else {
				bul[i].show(bull_left, xM);
			}
		}
	}
	for (int i = 0; i < special_bullet_sum; i++) {
		if (special_bullet[i].getshoot()) {
			special_bullet[i].show(special_bull, xM);
		}
	}
}
void Blacksnake::behurt(int i) {
	hp -= i;
	hp = max(hp, 0);
}
void enemy_controller::init(int map_id) {
	for (int i = 0; i < enemy_sum; i++) {
		delete e[i];
	}
	if (map_id == 3) {
		enemy_sum = 0;
		for (int i = 30; i <= 60; i++) {
			if (!(i % 10)) {
				e[enemy_sum++] = new insect(i* ground_w, map_h - enemy1_h - ground_h);
			}
		}
		e[enemy_sum++] = new scorcerer(30 * ground_w, map_h - enemy2_h - ground_h, 25 * ground_w, 40 * ground_w);
		e[enemy_sum++] = new scorcerer(11 * ground_w, map_h - enemy2_h - second_floor * ground_h, 12 * ground_w, 17 * ground_w);
		e[enemy_sum++] = new scorcerer(26 * ground_w, map_h - enemy2_h - second_floor * ground_h, 26* ground_w, 29 * ground_w);
		e[enemy_sum++] = new scorcerer(35 * ground_w, map_h - enemy2_h - second_floor * ground_h, 35 * ground_w, 36 * ground_w);
		e[enemy_sum++] = new scorcerer(46 * ground_w, map_h - enemy2_h - second_floor * ground_h, 46 * ground_w, 49 * ground_w);
		e[enemy_sum++] = new scorcerer(63 * ground_w, map_h - enemy2_h - second_floor * ground_h, 62 * ground_w, 64 * ground_w);
		e[enemy_sum++] = new scorcerer(94 * ground_w, map_h - enemy2_h - second_floor * ground_h, 92 * ground_w, 97 * ground_w);
		e[enemy_sum++] = new scorcerer(96 * ground_w, map_h - enemy2_h - second_floor * ground_h, 91 * ground_w, 96 * ground_w);
		e[enemy_sum++] = new scorcerer(19 * ground_w, map_h - enemy2_h - third_floor * ground_h, 18 * ground_w, 27 * ground_w);
		e[enemy_sum++] = new scorcerer(50 * ground_w, map_h - enemy2_h - third_floor * ground_h, 50 * ground_w, 54 * ground_w);
		e[enemy_sum++] = new elite(50 * ground_w, map_h - enemy3_h - ground_h, 50 * ground_w, 57* ground_w);
		e[enemy_sum++] = new elite(25 * ground_w, map_h - enemy3_h - ground_h, 23 * ground_w, 27 * ground_w);
		e[enemy_sum++] = new elite(33 * ground_w, map_h - enemy3_h - fourth_floor*ground_h, 31 * ground_w, 35 * ground_w);
		e[enemy_sum++] = new elite(92 * ground_w, map_h - enemy3_h - third_floor * ground_h, 92 * ground_w, 96 * ground_w);
		e[enemy_sum++] = new elite(95 * ground_w, map_h - enemy3_h - third_floor * ground_h, 94 * ground_w, 97 * ground_w);
		e[enemy_sum++] = new Blacksnake(140 * ground_w, map_h - boss_height - ground_h);
	}
	else if (map_id == 2) {
		enemy_sum = 0;
		for (int i = 30; i <= 60; i++) {
			if (!(i % 14)) {
				e[enemy_sum++] = new insect(i * ground_w, map_h - enemy1_h - ground_h);
			}
		}
		for (int i = 100; i <= 140; i++) {
			if (!(i % 17)) {
				e[enemy_sum++] = new insect(i * ground_w, map_h - enemy1_h - ground_h);
			}
		}
		e[enemy_sum++] = new scorcerer(30 * ground_w, map_h - enemy2_h - ground_h, 25 * ground_w, 40 * ground_w);
		e[enemy_sum++] = new scorcerer(26 * ground_w, map_h - enemy2_h - second_floor * ground_h, 26 * ground_w, 29 * ground_w);
		e[enemy_sum++] = new scorcerer(63 * ground_w, map_h - enemy2_h - second_floor * ground_h, 62 * ground_w, 64 * ground_w);
		e[enemy_sum++] = new scorcerer(94 * ground_w, map_h - enemy2_h - second_floor * ground_h, 92 * ground_w, 97 * ground_w);
		e[enemy_sum++] = new scorcerer(19 * ground_w, map_h - enemy2_h - third_floor * ground_h, 18 * ground_w, 27 * ground_w);
		e[enemy_sum++] = new scorcerer(50 * ground_w, map_h - enemy2_h - third_floor * ground_h, 50 * ground_w, 54 * ground_w);
		e[enemy_sum++] = new elite(25 * ground_w, map_h - enemy3_h - ground_h, 23 * ground_w, 27 * ground_w);
		e[enemy_sum++] = new elite(33 * ground_w, map_h - enemy3_h - fourth_floor * ground_h, 31 * ground_w, 35 * ground_w);
		e[enemy_sum++] = new elite(92 * ground_w, map_h - enemy3_h - third_floor * ground_h, 92 * ground_w, 96 * ground_w);
		e[enemy_sum++] = new scorcerer(113 * ground_w, map_h - enemy2_h - second_floor * ground_h, 111 * ground_w, 118 * ground_w);
		e[enemy_sum++] = new elite(133 * ground_w, map_h - enemy3_h - second_floor * ground_h, 130 * ground_w, 135 * ground_w);
	}
	else if (map_id == 1) {
		enemy_sum = 0;
	}
}
void enemy_controller::bullet_update(Amiya& amiya, int xM) {
	for (int i = 0; i < enemy_sum; i++) {
		if (e[i]->getid() == 2 || e[i]->getid() == 3 || e[i]->getid() == 4) {
			e[i]->bullet_update();
		}
	}//子弹穿墙还要修
}
void enemy_controller::move_update(int xM, Amiya& amiya, stone_controller& stone) {
	for (int i = 0; i < enemy_sum; i++) {
		if (e[i]->getid() == 4 && e[i]->getawake() && e[i]->getalive()) {
			e[i]->move_update(amiya, xM, stone);
			if (e[i]->getawake() && !stone.getifstart()) {
				stone.boss_area_create();
			}
		}
		else if (e[i]->getid() != 1 && e[i]->getstate() == walk) {
			e[i]->getspeed(amiya, xM);
			if (e[i]->getvx() > 0) {
				if (stone.check_lr(e[i], xM)) {
					e[i]->getvx() = -e[i]->getvx();
					e[i]->getdirection() = -e[i]->getdirection();
				}
			}
			else if (e[i]->getvx() < 0) {
				if (stone.check_lr(e[i], xM)) {
					e[i]->getvx() = -e[i]->getvx();
					e[i]->getdirection() = -e[i]->getdirection();
				}
			}
			e[i]->getx() += e[i]->getvx();
		}
		else if (e[i]->getid() == 1) {
			if (!e[i]->getawake()) { e[i]->checkawake(amiya, xM); }
			if (e[i]->getawake() && e[i]->getstate() != toattack_close) {
				e[i]->getspeed(amiya, xM);
				if (stone.check_lr(e[i], xM)) {
					e[i]->getvx() = 0;
				}
				e[i]->getx() += e[i]->getvx();
			}
		}
	}//精英怪
}
void enemy_controller::grow_check(Amiya& amiya) {
	for (int i = 0; i < enemy_sum; i++) {
		if (!e[i]->getalive() && e[i]->getvalue() != 0) {
			amiya.togrow(e[i]->getvalue());
			e[i]->getvalue() = 0;
		}
	}
}
void enemy_controller::attack_check(Amiya& amiya, int xM, stone_controller& stone) {
	for (int i = 0; i < enemy_sum; i++) {
		if (e[i]->getalive()) {
			e[i]->attack_update(amiya, xM, stone);
		}
	}
}
void enemy_controller::show(int xM) {
	for (int i = 0; i < enemy_sum; i++) {
		if (e[i]->getalive()) {
			e[i]->show(xM);
		}
	}
}
void enemy_controller::role_attack_close(sword sw, int xM) {
	for (int i = 0; i < enemy_sum; i++) {
		if (e[i]->getalive()) {
			if (sw.checkhit(e[i], 0)) {
				e[i]->behurt(sw.getdamage());
			}
		}
	}
}