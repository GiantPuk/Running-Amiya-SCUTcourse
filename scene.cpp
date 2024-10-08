#include"scene.h"
int scene::getwidth() {
	return width;
}
menu::menu() {
	loadimage(&background, _T("resourse/background/菜单.tif"), screem_w, screem_h);
	button[0].getx() = 100, button[0].gety() = 300;
	button[1].getx() = 100, button[1].gety() = 400;
	button[2].getx() = 100, button[2].gety() = 500;
	for (int i = 0; i <= 2; i++) {
		button[i].getheight() = 60, button[i].getwidth() = 200;
	}
}
void menu::display() {
	putimage(0, 0, &background);
	setfillcolor('gray');
	settextstyle(120, 0, _T("宋体"));
	settextcolor(RGB(255, 255, 255));
	setbkmode(TRANSPARENT);
	outtextxy(370, 400, "进击的兔兔");
	solidrectangle(button[0].getx(), button[0].gety(), button[0].getx() + button[0].getwidth(), button[0].gety() + button[0].getheight());
	solidrectangle(button[1].getx(), button[1].gety(), button[1].getx() + button[1].getwidth(), button[1].gety() + button[1].getheight());
	solidrectangle(button[2].getx(), button[2].gety(), button[2].getx() + button[2].getwidth(), button[2].gety() + button[2].getheight());
	settextstyle(50, 0, _T("宋体"));
	settextcolor(RGB(255, 255, 255));
	setbkmode(TRANSPARENT);
	outtextxy(button[0].getx(), button[0].gety(), "开始游戏");
	outtextxy(button[1].getx(), button[1].gety(), "帮助");
	outtextxy(button[2].getx(), button[2].gety(), "个人纪录");
}
int menu::check(int x, int y) {
	if (x > button[0].getx() && x< button[0].getx() + button[0].getwidth() && y>button[0].gety() && y < button[0].gety() + button[0].getheight()) {
		return 1;
	}
	else if (x > button[1].getx() && x< button[1].getx() + button[1].getwidth() && y>button[1].gety() && y < button[1].gety() + button[1].getheight())
		return 2;
	else if (x > button[2].getx() && x< button[2].getx() + button[2].getwidth() && y>button[2].gety() && y < button[2].gety() + button[2].getheight())
		return 3;
	else
		return 0;
}
record::record() {
	loadimage(&back, _T("resourse/background/返回.jpg"), 130, 40);
	loadimage(&background, _T("resourse/background/个人纪录.jpg"), screem_w, screem_h);
	button.getx() = 0;
	button.gety() = 0;
	button.getheight() = 40, button.getwidth() = 130;
	record_time flag;
	flag.point = -1;
	std::ofstream fw("resourse/record1", std::ios::binary | std::ios::out | std::ios::app);
	std::ifstream fr("resourse/record1", std::ios::binary | std::ios::in | std::ios::app);
	if (fr.tellg() == 0) {
		fw.seekp(0, std::ios::beg);
		fw.write((char*)(&flag), sizeof(record_time));
	}

	fw.close();
	fr.close();
	fw.open("resourse/record2", std::ios::binary | std::ios::out | std::ios::app);
	fr.open("resourse/record2", std::ios::binary | std::ios::in | std::ios::app);
	if (fr.tellg() == 0) {
		fw.seekp(0, std::ios::beg);
		fw.write((char*)(&flag), sizeof(record_time));
	}
	fw.close();
	fr.close();
	fw.open("resourse/record3", std::ios::binary | std::ios::out | std::ios::app);
	fr.open("resourse/record3", std::ios::binary | std::ios::in | std::ios::app);
	if (fr.tellg() == 0) {
		fw.seekp(0, std::ios::beg);
		fw.write((char*)(&flag), sizeof(record_time));
	}
}
void record::check(int map_id, record_time new_record) {
	std::ifstream read;
	switch (map_id)
	{
	case 1:read.open("resourse/record1", std::ios::binary); break;
	case 2:read.open("resourse/record2", std::ios::binary); break;
	case 3:read.open("resourse/record3", std::ios::binary); break;
	default:
		break;
	}
	int sum = -1;
	record_time tmp;
	for (sum; true;) {
		read.read((char*)(&tmp), sizeof(record_time));
		if (tmp.point == -1) { break; }
		else {
			time[++sum] = tmp;
		}
	}
	time[++sum] = new_record;
	std::sort(time, time + sum + 1);
	sum = min(sum, max_record - 1);
	read.close();
	std::ofstream write;
	switch (map_id)
	{
	case 1:write.open("resourse/record1", std::ios::binary); break;
	case 2:write.open("resourse/record2", std::ios::binary); break;
	case 3:write.open("resourse/record3", std::ios::binary); break;
	default:
		break;
	}
	for (int i = 0; i <= sum; i++) {
		write.write((char*)&time[i], sizeof(record_time));
	}
	tmp.point = -1;
	write.write((char*)&tmp, sizeof(record_time));
	write.close();
}
void record::show() {
	putimage(0, 0, &background);
	putimage(0, 0, &back);
	std::ifstream read("resourse/record1",std::ios::binary);
	record_time tmp;
	settextcolor(RGB(255, 255, 255));
	setbkmode(TRANSPARENT);
	settextstyle(45, 0, _T("黑体"));
	char str[40];
	settextstyle(25, 0, _T("黑体"));
	outtextxy(400, 10, "个人纪录榜");
	outtextxy(150, 50, "关卡1");
	outtextxy(450, 50, "关卡2");
	outtextxy(750, 50, "关卡3");
	settextstyle(20, 0, _T("宋体"));
	outtextxy(70, 100, "排名  通关时长(s) 通关日期|");
	outtextxy(350, 100, "排名  通关时长(s) 通关日期|");
	outtextxy(650, 100, "排名  通关时长(s) 通关日期");
	for (int i = 0; true; i++) {
		read.read((char*)&tmp, sizeof(record_time));
		if (tmp.point == -1)break;
		else {
			if (i != 9) {
				sprintf_s(str, "%d     %.2f       %d/%d/%d", i + 1, tmp.point / 1000, tmp.time.wYear, tmp.time.wMonth, tmp.time.wDay);
				outtextxy(70, 140 + 40 * i, str);
			}
			else {
				sprintf_s(str, "%d    %.2f       %d/%d/%d", i + 1, tmp.point / 1000, tmp.time.wYear, tmp.time.wMonth, tmp.time.wDay);
				outtextxy(70, 140 + 40 * i, str);
			}
		}
	}
	read.close();
	read.open("resourse/record2", std::ios::binary);
	for (int i = 0; true; i++) {
		read.read((char*)&tmp, sizeof(record_time));
		if (tmp.point == -1)break;
		else {
			if (i != 9) {
				sprintf_s(str, "%d     %.2f       %d/%d/%d", i + 1, tmp.point / 1000, tmp.time.wYear, tmp.time.wMonth, tmp.time.wDay);
				outtextxy(350, 140 + 40 * i, str);
			}
			else {
				sprintf_s(str, "%d    %.2f       %d/%d/%d", i + 1, tmp.point / 1000, tmp.time.wYear, tmp.time.wMonth, tmp.time.wDay);
				outtextxy(350, 140 + 40 * i, str);
			}
		}
	}
	read.close();
	read.open("resourse/record3", std::ios::binary);
	for (int i = 0; true; i++) {
		read.read((char*)&tmp, sizeof(record_time));
		if (tmp.point == -1)break;
		else {
			if (i != 9) {
				sprintf_s(str, "%d     %.2f       %d/%d/%d", i + 1, tmp.point / 1000, tmp.time.wYear, tmp.time.wMonth, tmp.time.wDay);
				outtextxy(650, 140 + 40 * i, str);
			}
			else {
				sprintf_s(str, "%d    %.2f       %d/%d/%d", i + 1, tmp.point / 1000, tmp.time.wYear, tmp.time.wMonth, tmp.time.wDay);
				outtextxy(650, 140 + 40 * i, str);
			}
		}
	}
}
double record::get_best(int map_id) {
	std::ifstream read;
	switch (map_id)
	{
	case 1:read.open("resourse/record1"); break;
	case 2:read.open("resourse/record2"); break;
	case 3:read.open("resourse/record3"); break;
	default:
		break;
	}
	record_time tmp;
	read.read((char*)(&tmp), sizeof(record_time));
	return tmp.point;
}
int record::back_menu(int x, int y) {
	if (x > button.getx() && x< button.getx() + button.getwidth() && y>button.gety() && y < button.gety() + button.getheight()) {
		return 1;
	}
	return 0;
}
stoppage::stoppage() {
	loadimage(&background, _T("resourse/background/暂停界面.tif"), screem_w, screem_h);
	button[0].getx() = 0;
	button[0].gety() = 449;
	button[0].getheight() = 62;
	button[0].getwidth() = 500;
	button[1].getx() = 500;
	button[1].gety() = 449;
	button[1].getheight() = 62;
	button[1].getwidth() = screem_w - 500;

}
int stoppage::check(int x, int y) {
	for (int i = 0; i <= 1; i++) {
		if (x > button[i].getx() && x< button[i].getx() + button[i].getwidth() && y>button[i].gety() && y < button[i].gety() + button[i].getheight()) {
			return i + 1;
		}
	}
	return 0;
}
void stoppage::show(double time) {
	putimage(0, 0, &background);
	char str[100];
	settextstyle(30, 0, _T("宋体"));
	settextcolor(RGB(0, 0, 0));
	setbkmode(TRANSPARENT);
	sprintf_s(str, "当前用时：%.2f", time);
	outtextxy(300, 250, str);
	sprintf_s(str, "W，空格/跳跃  A/向左 D/向右");
	outtextxy(300, 300, str);
	sprintf_s(str, "J/攻击  K/切换形态  I/使用理智剂  P/暂停");
	outtextxy(250, 350, str);
}
levelselection::levelselection() {
	loadimage(&background, _T("resourse/background/关卡选择.jpg"), screem_w, screem_h);
	loadimage(&back, _T("resourse/background/返回.jpg"), 130, 40);
	button[0].getx() = 200, button[0].gety() = 300;
	button[1].getx() = 500, button[1].gety() = 300;
	button[2].getx() = 800, button[2].gety() = 300;
	button[3].getx() = 0, button[3].gety() = 0;
	for (int i = 0; i < 3; i++) {
		button[i].getheight() = 70, button[i].getwidth() = 150;
	}
	button[3].getheight() = 40, button[3].getwidth() = 130;
}
void levelselection::display() {
	putimage(0, 0, &background);
	putimage(0, 0, &back);
	setfillcolor(RGB(255, 255, 255));
	setbkmode(TRANSPARENT);
	settextstyle(50, 0, _T("宋体"));
	for (int i = 0; i < 3; i++) {
		solidrectangle(button[i].getx(), button[i].gety(), button[i].getx() + button[i].getwidth(), button[i].gety() + button[i].getheight());
		settextcolor(RGB(0, 0, 0));
		if (i == 0)
			outtextxy(button[i].getx(), button[i].gety(), ("关卡1"));
		else if (i == 1)
			outtextxy(button[i].getx(), button[i].gety(), ("关卡2"));
		else
			outtextxy(button[i].getx(), button[i].gety(), ("关卡3"));
	}
}
int levelselection::check(int x, int y) {
	for (int i = 0; i <= 3; i++) {
		if (x > button[i].getx() && x< button[i].getx() + button[i].getwidth() && y>button[i].gety() && y < button[i].gety() + button[i].getheight()) {
			return i + 1;
		}
	}
	return 0;
}
bool map::getifstop() { return ifstop; }
int map::check(int x, int y) {
	for (int i = 0; i <= 0; i++) {
		if (x > button[i].getx() && x< button[i].getx() + button[i].getwidth() && y>button[i].gety() && y < button[i].gety() + button[i].getheight()) {
			ifstop = 1;
			return i + 1;
		}
	}
	return 0;
}
void map::init(int map_id) {
	int i;
	ifstop = 0;
	loadimage(&stop, _T("resourse/background/暂停.jpg"), 50, 50);
	button[0].getx() = screem_w - 60;
	button[0].gety() = 10;
	button[0].getheight() = button[0].getwidth() = 50;
	xM = 0;
	medi.init(map_id);
	stone.init(map_id);
	em.init(map_id);
}
void map::move(Amiya& amiya) {
	if (amiya.getvx() > 0) {

		if (stone.check_lr(&amiya, xM))amiya.getvx() = 0;
		if (amiya.getx() >= right_barrier && map_w + xM > screem_w) {
			ifmove = 1;
			xM -= amiya.getvx();
			std::cout << "xm" << xM;
			std::cout << "   " << amiya.getx() << std::endl;
			std::cout << " map_w+xM " << map_w + xM << std::endl;
			std::cout << " screem_w " << screem_w << std::endl;
			std::cout << amiya.getx() << std::endl;

		}//判断是图动还是角色动
		else if (amiya.getx() >= screem_w) {}
		//{ std::cout << "1" << std::endl; }
		else {
			//std::cout << "2" << amiya.getvx() << std::endl;
			//std::cout << amiya.getx() << std::endl;
			amiya.getx() += amiya.getvx();

		}
	}
	else if (amiya.getvx() < 0) {
		//for (int i = 0; i <= ground_sum; i++) {//每一个地板遍历看看有没有碰撞
		//	if (a[i]->check_l(&amiya, xM)) {
		//		amiya.getvx() = 0;
		//		break;
		//	}
		//}
		if (stone.check_lr(&amiya, xM))amiya.getvx() = 0;
		if (amiya.getx() <= left_barrier && xM < 0) {
			ifmove = 1;
			xM -= amiya.getvx();
			if (xM > 0)xM = 0;
			/*std::cout << "xm" << xM;
			std::cout << "   " << amiya.getx() << std::endl;
			std::cout << " map_w+xM " << map_w + xM << std::endl;
			std::cout << " screem_w " << screem_w << std::endl;
			std::cout << amiya.getx() << std::endl;*/

		}//判断是图动还是角色动
		else if (amiya.getx() < 0)
		{
		}
		else {
			amiya.getx() += amiya.getvx();

		}
	}
	if (!amiya.ifonground()) {
		amiya.getvy() += g;

		stone.check_onground(amiya, xM);
		stone.check_ceiling(amiya, xM);
		if (!amiya.ifonground()) {
			std::cout << "   " << amiya.getvy() << std::endl;
			amiya.gety() += amiya.getvy();
		}
	}
	else {
		stone.check_amiyaonground(amiya, xM);

		//if (!boss.getawake())
		//{
		//	boss.checkawake(amiya, xM);//判断boss是否被唤醒
		//}
		//if (boss.getawake() && boss.getstate() == walk) {
		//	boss.getspeed(amiya, xM);//更新boss位置
		//	boss.getx() += boss.getvx();
		//	boss.gety() += boss.getvy();
		//	std::cout << "walk" << std::endl;
		//}
	}
	em.move_update(xM, amiya, stone);
}
void map::attack(Amiya& amiya) {
	amiya.bullet_update();
	amiya.growing_update();

	em.bullet_update(amiya, xM);
	if (amiya.getifshoot()) {
		amiya.creat_bullet(xM);
	}
	else if (amiya.getifattack_close()) {
		amiya.creat_sword(xM);
		em.role_attack_close(amiya.getsw(), xM);
	}
	em.attack_check(amiya, xM, stone);
	em.grow_check(amiya);
	stone.fire_stone_hurt(amiya, xM);
	stone.role_bullet_check(amiya, xM);
	medi.check(amiya, xM);
	//下面是boss的
	/*if (boss.getawake() && boss.getstate() == toattack_close) {
		boss.close_attack_update(amiya, xM);
	}
	if (boss.getawake() && boss.getstate() == walk) {
		if (boss.attack_close(amiya, xM)) {
		}
	}*/
	//判断子弹有没有打到boss
	/*for (int j = 0; j < amiya.getbullet_sum(); j++) {
		if (boss.getawake()&&boss.getalive() && amiya.bullet_check(&boss, j)) {
			boss.behurt(amiya.get_bulletdamage(j));
		}
	}*/
	/*for (int i = 0; i <=ground_sum; i++) {
		for (int j = 0; j < amiya.getbullet_sum(); j++) {
			if (amiya.bullet_check(a[i], j)) {
				continue;
			}
		}
	}*/ /////这段要处理

}
void map::show(Amiya& amiya) {
	putimage(button[0].getx(), button[0].gety(), &stop);
	putimage(xM,screem_h-ground_h-100., &begin);
	putimage(map_w+xM-100, screem_h - ground_h - 100., &end);
	stone.show(xM);
	medi.show(xM);
	em.show(xM);
	amiya.show(xM);
	/*boss.show(xM);*/
}
map::map() {
	loadimage(&begin, _T("resourse/background/红门.tif"), 100, 100);
	loadimage(&end, _T("resourse/background/蓝门.tif"), 100, 100);
}
help::help() {
	loadimage(&back, _T("resourse/background/返回.jpg"), 130, 40);
	loadimage(&background, _T("进击的兔兔/resourse/background/帮助.jpg"), screem_w, screem_h);
	button.getx() = 0;
	button.gety() = 0;
	button.getheight() = 40, button.getwidth() = 130;
}
void help::show() {
	loadimage(&background, _T("resourse/background/帮助.jpg"), screem_w, screem_h);
	putimage(0, 0, &background);
	putimage(0, 0, &back);
	settextstyle(25, 0, _T("黑体"),0,0,1000,0,0,0);
	settextcolor(RGB(0, 0, 0));
	setbkmode(TRANSPARENT);
	outtextxy(100, 100, "1、W和空格控制跳跃，A控制方向左，D控制方向右");
	outtextxy(100, 150, "2、I使用理智剂，J攻击，K切换形态");
	outtextxy(100, 200, "3、使用理智剂可以恢复大量血量，甚至可以突破少量生命上限！");
	outtextxy(100, 250, "4、击败敌人单位可以获得一定的成长值，可以提高阿米娅的攻击伤害");
	settextstyle(25, 0, _T("宋体"), 0, 0, 0, 0, 0, 0);
}
int help::back_menu(int x, int y) {
	if (x > button.getx() && x< button.getx() + button.getwidth() && y>button.gety() && y < button.gety() + button.getheight()) {
		return 1;
	}
	return 0;
}