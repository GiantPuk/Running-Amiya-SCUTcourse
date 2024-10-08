#include"role.h"
Amiya::Amiya() {
	loadimage(&head[0], _T("resourse/°¢Ã×æ«/Í·Ïñ/ÊõÊ¿.png"), 100, 100);
	loadimage(&head[1], _T("resourse/°¢Ã×æ«/Í·Ïñ/½üÎÀ.png"), 100, 100);
	loadimage(&masterright[0], _T("resourse/ÆÕ¹¥Ô¶³Ì/1.png"), c_width, c_height);
	loadimage(&masterright1[0], _T("resourse/ÆÕ¹¥Ô¶³Ì/1-1.png"), c_width, c_height);
	loadimage(&masterright[1], _T("resourse/ÆÕ¹¥Ô¶³Ì/2.png"), c_width, c_height);
	loadimage(&masterright1[1], _T("resourse/ÆÕ¹¥Ô¶³Ì/2-1.png"), c_width, c_height);
	loadimage(&masterright[2], _T("resourse/ÆÕ¹¥Ô¶³Ì/3.png"), c_width, c_height);
	loadimage(&masterright1[2], _T("resourse/ÆÕ¹¥Ô¶³Ì/3-1.png"), c_width, c_height);
	loadimage(&masterright[3], _T("resourse/ÆÕ¹¥Ô¶³Ì/4.png"), c_width, c_height);
	loadimage(&masterright1[3], _T("resourse/ÆÕ¹¥Ô¶³Ì/4-1.png"), c_width, c_height);
	loadimage(&masterright[4], _T("resourse/ÆÕ¹¥Ô¶³Ì/5.png"), c_width, c_height);
	loadimage(&masterright1[4], _T("resourse/ÆÕ¹¥Ô¶³Ì/5-1.png"), c_width, c_height);
	loadimage(&masterright[5], _T("resourse/ÆÕ¹¥Ô¶³Ì/6.png"), c_width, c_height);
	loadimage(&masterright1[5], _T("resourse/ÆÕ¹¥Ô¶³Ì/6-1.png"), c_width, c_height);
	loadimage(&masterright[6], _T("resourse/ÆÕ¹¥Ô¶³Ì/7.png"), c_width, c_height);
	loadimage(&masterright1[6], _T("resourse/ÆÕ¹¥Ô¶³Ì/7-1.png"), c_width, c_height);
	loadimage(&masterright[7], _T("resourse/ÆÕ¹¥Ô¶³Ì/8.png"), c_width, c_height);
	loadimage(&masterright1[7], _T("resourse/ÆÕ¹¥Ô¶³Ì/8-1.png"), c_width, c_height);
	loadimage(&masterright[8], _T("resourse/ÆÕ¹¥Ô¶³Ì/9.png"), c_width, c_height);
	loadimage(&masterright1[8], _T("resourse/ÆÕ¹¥Ô¶³Ì/9-1.png"), c_width, c_height);
	loadimage(&masterright[9], _T("resourse/ÆÕ¹¥Ô¶³Ì/10.png"), c_width, c_height);
	loadimage(&masterright1[9], _T("resourse/ÆÕ¹¥Ô¶³Ì/10-1.png"), c_width, c_height);

	loadimage(&masterleft[0], _T("resourse/ÆÕ¹¥Ô¶³Ì/1left.png"), c_width, c_height);
	loadimage(&masterleft[1], _T("resourse/ÆÕ¹¥Ô¶³Ì/2left.png"), c_width, c_height);
	loadimage(&masterleft[2], _T("resourse/ÆÕ¹¥Ô¶³Ì/3left.png"), c_width, c_height);
	loadimage(&masterleft[3], _T("resourse/ÆÕ¹¥Ô¶³Ì/4left.png"), c_width, c_height);
	loadimage(&masterleft[4], _T("resourse/ÆÕ¹¥Ô¶³Ì/5left.png"), c_width, c_height);
	loadimage(&masterleft[5], _T("resourse/ÆÕ¹¥Ô¶³Ì/6left.png"), c_width, c_height);
	loadimage(&masterleft[6], _T("resourse/ÆÕ¹¥Ô¶³Ì/7left.png"), c_width, c_height);
	loadimage(&masterleft[7], _T("resourse/ÆÕ¹¥Ô¶³Ì/8left.png"), c_width, c_height);
	loadimage(&masterleft[8], _T("resourse/ÆÕ¹¥Ô¶³Ì/9left.png"), c_width, c_height);
	loadimage(&masterleft1[0], _T("resourse/ÆÕ¹¥Ô¶³Ì/1-1left.png"), c_width, c_height);
	loadimage(&masterleft1[1], _T("resourse/ÆÕ¹¥Ô¶³Ì/2-1left.png"), c_width, c_height);
	loadimage(&masterleft1[2], _T("resourse/ÆÕ¹¥Ô¶³Ì/3-1left.png"), c_width, c_height);
	loadimage(&masterleft1[3], _T("resourse/ÆÕ¹¥Ô¶³Ì/4-1left.png"), c_width, c_height);
	loadimage(&masterleft1[4], _T("resourse/ÆÕ¹¥Ô¶³Ì/5-1left.png"), c_width, c_height);
	loadimage(&masterleft1[5], _T("resourse/ÆÕ¹¥Ô¶³Ì/6-1left.png"), c_width, c_height);
	loadimage(&masterleft1[6], _T("resourse/ÆÕ¹¥Ô¶³Ì/7-1left.png"), c_width, c_height);
	loadimage(&masterleft1[7], _T("resourse/ÆÕ¹¥Ô¶³Ì/8-1left.png"), c_width, c_height);
	loadimage(&masterleft1[8], _T("resourse/ÆÕ¹¥Ô¶³Ì/9-1left.png"), c_width, c_height);//ÕâÀï¿ÉÒÔ¼Ó×ª³¡¶¯×÷
	int tmpw = 40, tmph = 0;
	loadimage(&swordright[0], _T("resourse/°¢Ã×æ«/attack2/right_1.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordright[1], _T("resourse/°¢Ã×æ«/attack2/right_2.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordright[2], _T("resourse/°¢Ã×æ«/attack2/right_3.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordright[3], _T("resourse/°¢Ã×æ«/attack2/right_4.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordright[4], _T("resourse/°¢Ã×æ«/attack2/right_5.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordright[5], _T("resourse/°¢Ã×æ«/attack2/right_6.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordright[6], _T("resourse/°¢Ã×æ«/attack2/right_7.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordright[7], _T("resourse/°¢Ã×æ«/attack2/right_8.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordright[8], _T("resourse/°¢Ã×æ«/attack2/right_9.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordright[9], _T("resourse/°¢Ã×æ«/attack2/right_10.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordright[10], _T("resourse/°¢Ã×æ«/attack2/right_11.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordright[11], _T("resourse/°¢Ã×æ«/attack2/right_12.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordright[12], _T("resourse/°¢Ã×æ«/attack2/right_13.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordright[13], _T("resourse/°¢Ã×æ«/attack2/right_14.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordright[14], _T("resourse/°¢Ã×æ«/attack2/right_15.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordright[15], _T("resourse/°¢Ã×æ«/attack2/right_16.tif"), c_width + tmpw, c_height + tmph);

	loadimage(&swordleft[0], _T("resourse/°¢Ã×æ«/attack2/left_1.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordleft[1], _T("resourse/°¢Ã×æ«/attack2/left_2.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordleft[2], _T("resourse/°¢Ã×æ«/attack2/left_3.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordleft[3], _T("resourse/°¢Ã×æ«/attack2/left_4.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordleft[4], _T("resourse/°¢Ã×æ«/attack2/left_5.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordleft[5], _T("resourse/°¢Ã×æ«/attack2/left_6.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordleft[6], _T("resourse/°¢Ã×æ«/attack2/left_7.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordleft[7], _T("resourse/°¢Ã×æ«/attack2/left_8.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordleft[8], _T("resourse/°¢Ã×æ«/attack2/left_9.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordleft[9], _T("resourse/°¢Ã×æ«/attack2/left_10.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordleft[10], _T("resourse/°¢Ã×æ«/attack2/left_11.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordleft[11], _T("resourse/°¢Ã×æ«/attack2/left_12.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordleft[12], _T("resourse/°¢Ã×æ«/attack2/left_13.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordleft[13], _T("resourse/°¢Ã×æ«/attack2/left_14.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordleft[14], _T("resourse/°¢Ã×æ«/attack2/left_15.tif"), c_width + tmpw, c_height + tmph);
	loadimage(&swordleft[15], _T("resourse/°¢Ã×æ«/attack2/left_16.tif"), c_width + tmpw, c_height + tmph);

	loadimage(&moveright[0], _T("resourse/°¢Ã×æ«/move/right_1.tif"), c_width, c_height);
	loadimage(&moveright[1], _T("resourse/°¢Ã×æ«/move/right_2.tif"), c_width, c_height);
	loadimage(&moveright[2], _T("resourse/°¢Ã×æ«/move/right_3.tif"), c_width, c_height);
	loadimage(&moveright[3], _T("resourse/°¢Ã×æ«/move/right_4.tif"), c_width, c_height);
	loadimage(&moveright[4], _T("resourse/°¢Ã×æ«/move/right_5.tif"), c_width, c_height);
	loadimage(&moveright[5], _T("resourse/°¢Ã×æ«/move/right_6.tif"), c_width, c_height);

	loadimage(&moveleft[0], _T("resourse/°¢Ã×æ«/move/left_1.tif"), c_width, c_height);
	loadimage(&moveleft[1], _T("resourse/°¢Ã×æ«/move/left_2.tif"), c_width, c_height);
	loadimage(&moveleft[2], _T("resourse/°¢Ã×æ«/move/left_3.tif"), c_width, c_height);
	loadimage(&moveleft[3], _T("resourse/°¢Ã×æ«/move/left_4.tif"), c_width, c_height);
	loadimage(&moveleft[4], _T("resourse/°¢Ã×æ«/move/left_5.tif"), c_width, c_height);
	loadimage(&moveleft[5], _T("resourse/°¢Ã×æ«/move/left_6.tif"), c_width, c_height);
	x = 0;
	y = map_h - ground_h - c_height;
	vx = 0; vy = 0;
	height = c_height;
	width = c_width;
	direction = 1;
	ifattack_close = 0;
	judging = c_judge;
	hp = 1500;
	hp_max = 1500;
	shoot_frame = 0;
	state = stand;
	loadimage(&bull, _T("resourse/°¢Ã×æ«/×Óµ¯.png"), 30, 20);
	condition = master;
	combat_frame = 0;
	move_frame = 0;
	change_cd = 30;
	changing_cd = 0;
	growing = 0;
	max_grow = 1000;
	medicine_sum = 0;
}
void Amiya::init() {
	x = 0;
	y = map_h - ground_h - c_height;
	vx = 0; vy = 0;
	height = c_height;
	width = c_width;
	direction = 1;
	ifattack_close = 0;
	judging = c_judge;
	hp = 1500;
	hp_max = 1500;
	shoot_frame = 0;
	state = stand;
	loadimage(&bull, _T("resourse/ÆÕ¹¥Ô¶³Ì/9-1left.png"), 30, 20);
	condition = master;
	combat_frame = 0;
	move_frame = 0;
	change_cd = 30;
	changing_cd = 0;
	growing = 0;
	max_grow = 1000;
	medicine_sum = 0;
	alive = 1;
	damage_close_init = 300;
	damage_distant_init = 100;
	damage_close = 300;
	damage_distant = 100;
	sw.getdamage() = damage_close;
}
void Amiya::move() {
	ifshoot = 0;
	ifattack_close = 0;
	if (changing_cd > 0)changing_cd--;
	if (state <= walk)state = stand;//Ã»ÓÐÕâÒ»ÌõµÄ»°½ÇÉ«»áÒ»Ö±×ß
	if (onground)vx = 0;//ÕâÀï×¢Òâ£¬ÔÚÃ»ÓÐ×öËÀÍöÅÐ¶¨µÄÊ±ºò£¬µô³öµØÍ¼»áÒ»Ö±ÍùÄ³Ò»¸ö·½Ïò×ß
	if (x >= screem_w || x <= 0 || y >= screem_h)vx = 0;
	if (GetAsyncKeyState('K') && state <= jump && changing_cd == 0) {
		if (condition == master)condition = swordman;
		else condition = master;
		changing_cd = change_cd;
	}
	if (GetAsyncKeyState('A') && state <= walk) {
		direction = -1;
		vx = -12;
		state = max(walk, state);
		std::cout << "role left" << std::endl;
	}
	else if (GetAsyncKeyState('A')) {
		direction = -1;
		vx = -12;
		state = max(walk, state);
		std::cout << "role left" << std::endl;
	}
	if (GetAsyncKeyState('D') && state <= walk) {
		direction = 1;
		vx = 12;
		std::cout << "role right" << vx << std::endl;
		state = max(walk, state);
	}
	else if (GetAsyncKeyState('D')) {
		direction = 1;
		vx = 12;
		std::cout << "role right" << vx << std::endl;
		state = max(walk, state);
	}
	if (GetAsyncKeyState('W') || GetAsyncKeyState(32)) {
		if (onground) {
			vy = -50;
			state = max(jump, state);
			onground = 0;
			first_jump = 1;
			std::cout << "role jump" << vy << std::endl;
		}
		else {
			if (vy >= -30 && vy <= 40) {//Èç¹ûÃ¿Ò»Ö¡Ì«¿ì£¬»á¿´²»³öÀ´¶þ¶ÎÌø
				if (first_jump)
				{
					std::cout << "second junp" << std::endl;
					first_jump = 0; vy = -50;
				}
			}
		}
	}
	if (GetAsyncKeyState('J')) {
		if (condition == master && state != toattack_distant && state != toattack_close) {
			state = toattack_distant;
		}
		else if (condition == swordman && state != toattack_close && state != toattack_close) {
			state = toattack_close;
		}
	}
	if (state == toattack_distant && toattack_close) {
		vx /= 2;
	}//¹¥»÷µÄÊ±ºòËÙ¶È¼õ°ë
	if (state == toattack_distant && shoot_frame == 4) {
		ifshoot = 1;
	}
	if (state == toattack_distant) {
		shoot_frame++;
		if (shoot_frame >= 9) {
			shoot_frame = 0;
			if (!onground)state = jump;
			else {
				state = stand;
			}
		}
	}
	if (state == toattack_close && combat_frame == 8) {
		ifattack_close = 1;
	}
	if (state == toattack_close) {
		combat_frame++;
		if (combat_frame >= 15) {
			combat_frame = 0;
			if (!onground)state = jump;
			else {
				state = stand;
			}
		}
	}
	if (GetAsyncKeyState('I')) {
		if (medicine_sum != 0) {
			medicine_sum--;
			hp += 500;
			if (hp - hp_max >= 100) {
				hp_max += 100;
				hp = hp_max;
			}
		}
	}
}
void Amiya::show(int xM) {
	/*x += vx;*/
	if (state == toattack_distant) {
		if (direction > 0) {
			putimage(x, y, &masterright1[shoot_frame], SRCAND);
			putimage(x, y, &masterright[shoot_frame], SRCPAINT);
		}
		else {
			putimage(x, y, &masterleft1[shoot_frame], SRCAND);
			putimage(x, y, &masterleft[shoot_frame], SRCPAINT);
		}
	}
	else if (state == toattack_close) {
		if (direction > 0) {
			putimage_alpha(x - 30, y, &swordright[combat_frame]);
		}
		else {
			putimage_alpha(x - 30, y, &swordleft[combat_frame]);
		}
	}
	else if (state == walk) {
		move_frame++;
		if (move_frame >= 6)move_frame = 0;
		if (direction > 0)
			putimage_alpha(x, y, &moveright[move_frame]);
		else if (direction < 0) {
			putimage_alpha(x, y, &moveleft[move_frame]);
		}
	}
	else {
		if (condition == master) {
			putimage(x, y, &masterright1[0], SRCAND);
			putimage(x, y, &masterright[0], SRCPAINT);
		}
		else {
			if (direction > 0)
				putimage_alpha(x - 30, y, &swordright[0]);
			else if (direction < 0)
				putimage_alpha(x - 30, y, &swordleft[0]);
		}
	}
	for (int i = 0; i < 5; i++) {
		if (bul[i].getshoot()) {
			bul[i].show(bull, xM);
		}
	}
	if (condition == master) {
		putimage(10, 20, &head[0]);
	}
	else {
		putimage(10, 20, &head[1]);
	}
	setfillcolor('r');
	solidrectangle(120, 30, ((double)hp / hp_max) * 170 + 120, 50);//ÑªÌõ
	setbkmode(TRANSPARENT);
	settextcolor(RGB(255, 255, 255));
	settextstyle(20, 0, _T("ËÎÌå"));
	char str[20];
	sprintf_s(str, "%d/%d", hp, hp_max);
	outtextxy(120, 30, str);
	setfillcolor('blue');
	solidrectangle(120, 60, ((double)growing / max_grow) * 170 + 120, 80);//ÑªÌõ
	sprintf_s(str, "%d/%d", growing, max_grow);
	outtextxy(120, 60, str);
	outtextxy(120, 90, "ÀíÖÇ¼ÁÊýÁ¿£º");
	sprintf_s(str, "%d/%d", medicine_sum, 5);
	outtextxy(120, 110, str);
	showblood();
}
void Amiya::checkattack1(unit* s) {
	for (int i = 0; i < 100; i++) {
		if (bul[i].getshoot()) {
			bul[i].checkhit(s);
			break;
		}
	}
}
void Amiya::creat_bullet(int xM) {
	for (int i = 0; i < 5; i++) {
		if (!bul[i].getshoot()) {
			if (direction > 0) {
				bul[i].create(x - xM + width, y + height / 2, 10, direction);
				std::cout << "amiya creat bullet" << x - xM + width << std::endl;
			}
			else {
				bul[i].create(x - xM, y + height / 2, 10, direction);
			}
			break;

		}
	}
}
void Amiya::bullet_update() {
	for (int i = 0; i < 5; i++) {
		if (bul[i].getshoot()) {
			bul[i].update();
		}
	}
}
bool Amiya::bullet_check(unit* s, int i) {
	if (bul[i].getshoot()) {
		if (bul[i].checkhit(s)) {
			std::cout << "hit" << std::endl;
			bul[i].changeshoot();
			return 1;
		}
	}
	return 0;
}
void Amiya::behurt(int i) {
	hp -= i;
	hp = max(hp, 0);
	if (hp == 0) {
		alive = 0;
	}
	std::cout << hp << std::endl;
}
int Amiya::get_bulletdamage(int i) {
	return damage_distant;
}
void Amiya::creat_sword(int xM) {
	if (direction > 0) {
		sw.create(x - xM, y - 10, height + 10, attack_close_range + width, direction);
		sw.getdamage() = damage_close;
	}
	else {
		sw.create(x - xM - attack_close_range, y - 10, height + 10, attack_close_range + width, direction);//¹¥»÷ÅÐ¶Ï£¬×¢Òâ×óÓÒ¹¥»÷·¶Î§Òª¶Ô³Æ´¦Àí
		sw.getdamage() = damage_close;
	}
}
bool Amiya:: getalive() { return alive; }
int Amiya::getbullet_sum() { return 5; }
bool Amiya::ifonground() { return onground; }
bool Amiya::getifshoot() { return ifshoot; }
bool Amiya::getifattack_close() { return ifattack_close; }
sword& Amiya::getsw() {
	return sw;
}
void Amiya::land() {
	onground = 1;
	if (state == toattack_close || state == toattack_distant) {
		return;
	}
	else {
		state = stand;
	}
}
void Amiya::togrow(int i) {
	growing += i;
	growing = min(max_grow, growing);
}
void Amiya::getmedicine() {
	medicine_sum++;
	medicine_sum = min(5, medicine_sum);
}
void Amiya::fall() { onground = 0; }
int Amiya::getdirection() { return direction; }
int Amiya::getstate() { return state; }
int& Amiya::changestate() { return state; }
void Amiya::check_if_die() {
	if (hp == 0)alive = 0;
	else if (y > map_h || x<-100 || x>map_w + 300) {
		alive = 0;
	}
}
void Amiya::growing_update() {
	damage_distant = (1 + (double)growing / max_grow) * damage_distant_init;
	damage_close = (1 + (double)growing / max_grow) * damage_close_init;
}