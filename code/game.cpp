#include"game.h"
game::game() {
	/*loadimage(&success[0], _T("resourse/background/vision accomplish/1.png"), screem_w, screem_h);
	loadimage(&success[1], _T("resourse/background/vision accomplish/2.png"), screem_w, screem_h);
	loadimage(&success[2], _T("resourse/background/vision accomplish/3.png"), screem_w, screem_h);
	loadimage(&success[3], _T("resourse/background/vision accomplish/4.png"), screem_w, screem_h);
	loadimage(&success[4], _T("resourse/background/vision accomplish/5.png"), screem_w, screem_h);
	loadimage(&success[5], _T("resourse/background/vision accomplish/5.png"), screem_w, screem_h);
	loadimage(&success[6], _T("resourse/background/vision accomplish/5.png"), screem_w, screem_h);
	loadimage(&success[7], _T("resourse/background/vision accomplish/6.png"), screem_w, screem_h);
	loadimage(&success[8], _T("resourse/background/vision accomplish/6.png"), screem_w, screem_h);
	loadimage(&success[9], _T("resourse/background/vision accomplish/7.png"), screem_w, screem_h);
	loadimage(&success[10], _T("resourse/background/vision accomplish/8.png"), screem_w, screem_h);
	loadimage(&success[11], _T("resourse/background/vision accomplish/9.png"), screem_w, screem_h);*/
	loadimage(&success, _T("resourse/background/vision accomplish/6.tif"), screem_w, screem_h);
}
void game::play() {
	initgraph(screem_w, screem_h);
	while (true) {
		while (state == 1) {
			mciSendString(_T("open resourse/music/主页.mp3 alias music"), 0, 0, 0);
			mciSendString(_T("play music repeat"), 0, 0, 0);
			BeginBatchDraw();
			me.display();
			EndBatchDraw();
			getmessage(&msg, EX_MOUSE);
			if (msg.message == WM_LBUTTONDBLCLK || msg.message == WM_LBUTTONDOWN) {
				switch (me.check(msg.x, msg.y)) {
				case 1:state = 2; mciSendString("close music", 0, 0, 0); break;
				case 2:state = 6; mciSendString("close music", 0, 0, 0); break;
				case 3:state = 5; mciSendString("close music", 0, 0, 0); break;
				case 0:continue;
				}
			}
		}
		while (state == 2) {
			mciSendString("open resourse/music/关卡选择.mp3 alias music", 0, 0, 0);
			mciSendString("play music repeat", 0, 0, 0);
			BeginBatchDraw();
			level.display();
			EndBatchDraw();
			getmessage(&msg, EX_MOUSE);
			if (msg.message == WM_LBUTTONDBLCLK || msg.message == WM_LBUTTONDOWN) {
				switch (level.check(msg.x, msg.y)) {
				case 1:state = 3; mciSendString("close music", 0, 0, 0); choosemap = 1; break;
				case 2:state = 3; mciSendString("close music", 0, 0, 0); choosemap = 2; break;
				case 3:state = 3; mciSendString("close music", 0, 0, 0); choosemap = 3; break;
				case 4:state = 1; mciSendString("close music", 0, 0, 0); break;
				case 0:continue;
				}
			}
		}
		while (state == 3) {
			cleardevice();
			settextstyle(50, 0, _T("宋体"));
			settextcolor(RGB(255, 255, 255));
			setbkmode(TRANSPARENT);
			outtextxy(screem_h / 2, screem_w / 2, "加载中");
			m.init(choosemap);
			role.init();
			tim.init();
			int mid_time, mid_time_start = 0, mid_time_end = 0;
			double begin, end, runing_time = 0;
			switch (choosemap) {
			case 1:mciSendString(_T("open resourse/music/关卡1.mp3 alias music"), 0, 0, 0); break;
			case 2:mciSendString(_T("open resourse/music/关卡2.mp3 alias music"), 0, 0, 0); break;
			case 3:mciSendString(_T("open resourse/music/关卡3.mp3 alias music"), 0, 0, 0); break;
			}
			IMAGE background;
			switch (choosemap) {
			case 1:loadimage(&background, _T("resourse/background/background1.jpg"), 1200, 700); break;
			case 2:loadimage(&background, _T("resourse/background/background2.jpg"), screem_w,screem_h); break;
			case 3:loadimage(&background, _T("resourse/background/background3.jpg"), screem_w, screem_h); break;
			}
			mciSendString(_T("play music repeat"), 0, 0, 0);
			while (role.getalive() && state == 3) {
				begin = GetTickCount();
				BeginBatchDraw();
				putimage(0, 0, &background);
				role.move();
				m.attack(role);
				m.move(role);
				m.show(role);
				role.check_if_die();
				tim.show();
				double record_time_tmp = rec.get_best(choosemap);
				setbkmode(TRANSPARENT);
				settextstyle(20, 0, _T("宋体"));
				if (record_time_tmp != -1) {
					char str[50];
					sprintf_s(str, "最快通关纪录:%.2f", record_time_tmp / 1000.0);
					outtextxy(20, 180, str);
				}
				else {
					outtextxy(20, 180, "当前没有通关记录");
				}
				Sleep(1);
				EndBatchDraw();
				int stop_time, stop_time_start, stop_time_end;
				stop_time_start = GetTickCount();
				if (GetAsyncKeyState('P'))goto stop_flag;
				while (peekmessage(&msg, EX_MOUSE)) {
					if (msg.message == WM_LBUTTONDBLCLK || msg.message == WM_LBUTTONDOWN) {
						if (m.check(msg.x, msg.y)) {
							std::cout << "x=" << msg.x << std::endl;
							std::cout << "y=" << msg.y << std::endl;
						stop_flag:
							mciSendString("pause music", 0, 0, 0);
							state = 4;
							while (true) {
								if (state != 4)break;
								BeginBatchDraw();
								stop.show(tim.gettime() / 1000);
								EndBatchDraw();
								peekmessage(&msg, EX_MOUSE);
								if (msg.message == WM_LBUTTONDBLCLK || msg.message == WM_LBUTTONDOWN) {
									std::cout << "x=" << msg.x << std::endl;
									std::cout << "y=" << msg.y << std::endl;
									switch (stop.check(msg.x, msg.y)) {
									case 1:state = 3;mciSendString("resume music", 0, 0, 0); break;
									case 2:state = 2; mciSendString("close music", 0, 0, 0); break;
									case 0:continue;
									}
								}
							}
						}
					}
				}
				stop_time_end = GetTickCount();
				stop_time = stop_time_end - stop_time_start;
				end = GetTickCount();
				mid_time_start = GetTickCount();
				runing_time = (end - begin);
				/*std::cout << runing_time << std::endl;*/
				if (role.getx() > screem_w - 30) {
					break;
				}
				if (runing_time >= 1000 / 20)continue;
				else
					Sleep(1000 / 20 - runing_time);
				mid_time_end = GetTickCount();
				mid_time = mid_time_end - mid_time_start;
				tim.add(mid_time + runing_time - stop_time);
			}
			if (state != 3)break;
			if (role.getalive() == 0) {
				mciSendString("close music", 0, 0, 0);
				mciSendString(_T("open resourse/music/失败.mp3 alias music"), 0, 0, 0);
				mciSendString(_T("play music repeat"), 0, 0, 0);
				IMAGE tmp;
				loadimage(&tmp, _T("resourse/background/失败背景.jpg"), screem_w, screem_h);
				putimage(0, 0, &tmp);
				Sleep(2000);
				while (true) {
					getmessage(&msg);
					if (msg.message == WM_LBUTTONDBLCLK || msg.message == WM_LBUTTONDOWN) {
						state = 2;
						mciSendString("close music", 0, 0, 0);
						break;
					}
				}
			}
			else {
				state = 2; mciSendString("close music", 0, 0, 0);
				record_time tmp;
				tmp.point = tim.gettime();
				SYSTEMTIME time_tmp;
				GetLocalTime(&time_tmp);
				tmp.time = time_tmp;
				rec.check(choosemap, tmp);
				putimage_alpha(0, 0, &success);
				Sleep(2000);
				IMAGE back;
				cleardevice();
				loadimage(&back, _T("resourse/background/成功背景.jpg"), screem_w, screem_h);
				putimage(0, 0, &back);
				char str[20];
				sprintf_s(str, "用时： %.2f", tim.gettime() / 1000.0);
				setbkmode(TRANSPARENT);
				settextcolor(RGB(255, 255, 255));
				settextstyle(30, 0, _T("宋体"));
				outtextxy(40, 400, str);
				mciSendString(_T("open resourse/music/胜利.mp3 alias music"), 0, 0, 0);
				mciSendString(_T("play music repeat"), 0, 0, 0);
				mciSendString(_T("open resourse/music/结束语音1.wav alias music1"), 0, 0, 0);
				mciSendString(_T("play music1"), 0, 0, 0);
				Sleep(2000);
				while (true) {
					getmessage(&msg);
					if (msg.message == WM_LBUTTONDBLCLK || msg.message == WM_LBUTTONDOWN) {
						state = 2;
						mciSendString("close music", 0, 0, 0);
						break;
					}
				}
			}
		}
		while (state == 5) {
			mciSendString(_T("open resourse/music/排行榜.mp3 alias music"), 0, 0, 0);
			mciSendString(_T("play music repeat"), 0, 0, 0);
			BeginBatchDraw();
			rec.show();
			EndBatchDraw();
			while (peekmessage(&msg, EX_MOUSE)) {
				if (msg.message == WM_LBUTTONDBLCLK || msg.message == WM_LBUTTONDOWN) {
					std::cout <<"x=" << msg.x << std::endl;
					std::cout << "y="<< msg.y << std::endl;
					switch (rec.back_menu(msg.x, msg.y)) {
					case 1:state = 1; mciSendString("close music", 0, 0, 0); break;
					}
				}
			}
		}
		while (state == 6) {
			mciSendString(_T("open resourse/music/帮助.mp3 alias music"), 0, 0, 0);
			mciSendString(_T("play music repeat"), 0, 0, 0);
			BeginBatchDraw();
			he.show();
			EndBatchDraw();
			while (peekmessage(&msg, EX_MOUSE)) {
				if (msg.message == WM_LBUTTONDBLCLK || msg.message == WM_LBUTTONDOWN) {
					switch (he.back_menu(msg.x, msg.y)) {
					case 1:state = 1; mciSendString("close music", 0, 0, 0); break;
					case 0:continue;
					}
				}
			}
		}
	}
}