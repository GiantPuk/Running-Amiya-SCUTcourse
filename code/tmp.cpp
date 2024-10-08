/*for (i = 0; i <= (map_w + screem_w) / ground_w; i++) {
				if (i >= 13 && i <= 20)continue;
				if (i > 35 && i < 70 && (i / 3) % 2) {
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
			for (i = 25; i < 32; i++) {
				a[ground_sum] = new fixture1;
				a[ground_sum++]->putxy(i * ground_w, map_h - second_floor * ground_h);
			}
			for (i = 18; i < 29; i++) {
				a[ground_sum] = new fixture1;
				a[ground_sum++]->putxy(i * ground_w, map_h - third_floor * ground_h);
			}
			a[ground_sum] = new fixture1;
			a[ground_sum]->putxy(i * ground_w, map_h - third_floor * ground_h);*/
			/*stone.init(map_id);
			b[insect_sum++].init(30 * ground_w, map_h - enemy1_h - ground_h);
			c[scorcerer_sum].init(30 * ground_w, map_h - enemy2_h - ground_h, 25 * ground_w, 40 * ground_w);
			scorcerer_sum++;
			d[elite_sum].init(5 * ground_w, map_h - enemy3_h - ground_h, 5 * ground_w, 19 * ground_w);
			elite_sum++;
			boss.init(140 * ground_w, map_h - boss_height - ground_h);*/

			//for (int i = 0; i <= ground_sum; i++) {//每一个地板遍历看看有没有碰撞
						//	if (a[i]->check_r(&amiya,xM)) {//有缺陷的判断，因为采用的是先x后y，所以速度不能太大，尤其不能比块大
						//		amiya.getvx() = 0; 
						//		break;
						//	}
						//}
/*gravity(amiya.getvy());*/
			/*for (int i = 0; i <= ground_sum; i++) {
				if (a[i]->check_ground(&amiya,xM)) {
					std::cout << "land" << std::endl;
					amiya.getvy() = 0;
					amiya.land();
					amiya.gety() = a[i]->gety() - c_height;
					break;
				}
			}
			for (int i = 0; i <= ground_sum; i++) {
				if (a[i]->check_ceiling(&amiya, xM)) {
					amiya.getvy() =0;
					amiya.gety() = a[i]->gety() + a[i]->getheight();
					break;
				}
			}*/

			//for (int i = 0; i < scorcerer_sum; i++) {
					//	if (c[i].getstate() == walk) {
					//		c[i].getspeed(amiya, xM);
					//		if (c[i].getvx() > 0) {
					//			for (int j = 0; j <= ground_sum; j++) {//每一个地板遍历看看有没有碰撞
					//				if (a[j]->check_r(&c[i], xM)) {//有缺陷的判断，因为采用的是先x后y，所以速度不能太大，尤其不能比块大
					//					c[i].getvx() = -c[i].getvx();
					//					c[i].getdirection() = -c[i].getdirection();
					//					break;
					//				}
					//			}
					//		}
					//		else if (c[i].getvx() < 0) {
					//			for (int j = 0; j <= ground_sum; j++) {//每一个地板遍历看看有没有碰撞
					//				if (a[j]->check_l(&c[i], xM)) {
					//					c[i].getvx() = -c[i].getvx();
					//					c[i].getdirection() = -c[i].getdirection();
					//					break;
					//				}
					//			}
					//		}
					//		c[i].getx() += c[i].getvx();
					//	}
					//}//术士位置更新
					//for (int i = 0; i < elite_sum; i++) {
					//	if (d[i].getstate() == walk) {
					//		d[i].getspeed(amiya, xM);
					//		if (d[i].getvx() > 0) {
					//			for (int j = 0; j <= ground_sum; j++) {//每一个地板遍历看看有没有碰撞
					//				if (a[j]->check_r(&d[i], xM)) {//有缺陷的判断，因为采用的是先x后y，所以速度不能太大，尤其不能比块大
					//					d[i].getvx() = -d[i].getvx();
					//					d[i].getdirection() = -d[i].getdirection();
					//					break;
					//				}
					//			}
					//		}
					//		else if (d[i].getvx() < 0) {
					//			for (int j = 0; j <= ground_sum; j++) {//每一个地板遍历看看有没有碰撞
					//				if (a[j]->check_l(&d[i], xM)) {
					//					d[i].getvx() = -d[i].getvx();
					//					d[i].getdirection() = -d[i].getdirection();
					//					break;
					//				}
					//			}
					//		}
					//		d[i].getx() += d[i].getvx();
					//	}
					//}//精英怪位置更新
//for (int i = 0; i < scorcerer_sum; i++) {//术士子弹更新
		//	c[i].bullet_update();
		//}
		//for (int i = 0; i < elite_sum; i++) {//子弹更新
		//	d[i].bullet_update();
		//}

/*for (int i = 0; i < insect_sum; i++) {
			if (b[i].getalive()&&b[i].getawake() && b[i].getstate() == toattack_close) {
				b[i].close_attack_update(amiya, xM);
			}
		}
		for (int i = 0; i < insect_sum; i++) {
			if (b[i].getawake() && b[i].getstate() == walk) {
				if (b[i].attack_close(amiya, xM)) {
					continue;
				}
			}
		}
		for (int i = 0; i <insect_sum; i++) {
			for (int j = 0; j < amiya.getbullet_sum(); j++) {
				if (b[i].getalive()&&amiya.bullet_check(&b[i], j)) {
					b[i].behurt(amiya.get_bulletdamage(j));
				}
			}
		}*/
		//下面是术士的攻击更新
				//下面//如果在游走状态，判断是否满足发射条件
				//for (int i = 0; i < scorcerer_sum; i++) {
				//	if (c[i].getstate() == walk) {
				//		c[i].ifshoot(amiya, xM);
				//	}
				//}
				////下面如果在攻击状态，那么就更新术士的攻击状态和动作
				//for (int i = 0; i < scorcerer_sum; i++) {
				//	if (c[i].getstate() == toattack_distant) {
				//		c[i].distant_attack_update(xM);
				//	}
				//}
				////判断阿米娅的子弹有没有打到小怪
				//for (int i = 0; i < scorcerer_sum; i++) {
				//	for (int j = 0; j < amiya.getbullet_sum(); j++) {
				//		if (c[i].getalive() && amiya.bullet_check(&c[i], j)) {
				//			c[i].behurt(amiya.get_bulletdamage(j));
				//		}
				//	}
				//}
				////下面判断是否撞墙
				//for (int i = 0; i <= ground_sum; i++) {
				//	for (int k = 0; k < scorcerer_sum; k++) {
				//		for (int j = 0; j < c[k].getbullet_sum(); j++) {
				//			if (c[k].bullet_check(a[i], j)) {
				//				continue;
				//			}
				//		}
				//	}
				//}
				////下面判断术士子弹有没有命中amiya
				//for (int i = 0; i < scorcerer_sum; i++) {
				//	for (int j = 0; j < c[i].getbullet_sum(); j++) {
				//		if (amiya.getalive() && c[i].bullet_check(&amiya, j,xM)) {
				//			amiya.behurt(c[i].get_bulletdamage(j));
				//		}
				//	}
				//}
				//下面是精英怪的
				//下面是攻击检查
				//把攻击检查放在攻击更新后面可以解决停顿一步的问题，但是因为有攻击cd，所以该不该一样
				//for (int i = 0; i < elite_sum; i++) {
				//	if (d[i].getalive() && d[i].getstate() == walk) {
				//		d[i].check_attack(amiya, xM);
				//	}
				//}
				////下面是攻击帧更新
				//for (int i = 0; i < elite_sum; i++) {
				//	if (d[i].getstate() == toattack_distant) {
				//		d[i].distant_attack_update(xM);
				//	}
				//	else if (d[i].getstate() == toattack_close) {
				//		d[i].close_attack_update(amiya,xM);//因为近战攻击是实时判断命中的，没有办法像远程一样和子弹分离判断，因此这里要穿进去两个参数
				//	}
				//}
				////判断阿米娅子弹有没有命中
				//for (int i = 0; i < elite_sum; i++) {
				//	for (int j = 0; j < amiya.getbullet_sum(); j++) {
				//		if (d[i].getalive() && amiya.bullet_check(&d[i], j)) {
				//			d[i].behurt(amiya.get_bulletdamage(j));
				//		}
				//	}
				//}
				////下面判断是否撞墙
				//for (int i = 0; i <= ground_sum; i++) {
				//	for (int k = 0; k < elite_sum; k++) {
				//		for (int j = 0; j < d[k].getbullet_sum(); j++) {
				//			if (d[k].bullet_check(a[i], j)) {
				//				continue;
				//			}
				//		}
				//	}
				//}
				//火地板伤害判断
				//for (int i = 0; i < ground_sum; i++) {
				//	if (a[i]->getflag() == 2&&a[i]->check_ground(&amiya,xM)) {
				//		amiya.behurt(a[i]->getdamage());
				//		std::cout << "amiya hurt" << std::endl;
				//	}
				//}//处理
				//下面判断精英怪子弹有没有命中amiya
				/*for (int i = 0; i < elite_sum; i++) {
					for (int j = 0; j < d[i].getbullet_sum(); j++) {
						if (amiya.getalive() && d[i].bullet_check(&amiya, j, xM)) {
							amiya.behurt(d[i].get_bulletdamage(j));
						}
					}
				}*/
				/*for (int i = 0; i <=ground_sum; i++) {
							putimage(a[i]->getx()+xM, a[i]->gety()+yM, a[i]->getimage());
						}*/

						/*for (int i = 0; i < insect_sum; i++) {
							if (b[i].getalive()) {
								b[i].show(xM);
							}
						}
						for (int i = 0; i < scorcerer_sum; i++) {
							if (c[i].getalive()) {
								c[i].show(xM);
							}
						}
						for (int i = 0; i < elite_sum; i++) {
							if (d[i].getalive()) {
								d[i].show(xM);
							}
						}*/
						/*bool flash_move(Amiya& amiya,int xM,stone_controller& stone) {
								int x1 = amiya.getx() - width;
								int x2 = amiya.getx() + amiya.getwidth();
								int tmpy = amiya.gety() + amiya.getheight();
								if (stone.check_ifcanmove(x1,width,tmpy)) {
									y = tmpy - height;
									x = x1;
									return 1;
								}
								else if (stone.check_ifcanmove(x2, width, tmpy)) {
									y = tmpy - height;
									x = x2;
									return 1;
								}
								return 0;
							}*/
							//class object :public enemy {
							//protected:
							//public:
							//	object() {}
							//	object(int h, int w) { height = h, width = w; }
							//	void putxy(int a, int b) {
							//		x = a; y = b;
							//	}
							//	int getx() { return x; }
							//	int gety() { return y; }
							//	int getheight() { return height; }
							//	int getwidth() { return width; }
							//	bool check_r(unit* s, int xM) {//左右碰撞都是先镶嵌进去再不动的，因此速度不能比木块大，不然会冲进去
							//		Point character[4];
							//		//character[0].x = s.getx(), character[0].y = s.gety();//左上
							//		//character[1].x = s.getx()+c_height, character[1].y = s.gety();//左下
							//		//character[0].x = s.getx(), character[0].y = s.gety()+c_width;//右上
							//		//character[0].x = s.getx()+c_height, character[0].y = s.gety()+c_width;//右下
							//		if (x > s->getx() && s->getx() + s->getwidth() > x && y - s->getheight() < s->gety() && y + height > s->gety()) {
							//			return 1;
							//		}
							//		return 0;
							//	}
							//	bool check_l(unit* s, int xM) {
							//		if (x < s->getx() && s->getx() <= x + width && y - s->getheight() < s->gety() && y + height > s->gety()) {//往左的话，因为速度固定，所以是速度的倍速
							//			return 1;
							//		}
							//		return 0;
							//	}
							//	bool check_ground(unit* s, int xM) {
							//		if (x < s->getx() + s->getwidth() - s->getjudging() && s->getx() + s->getjudging() < x + width) {
							//			if (s->gety() + s->getheight() <= y && s->getvy() + s->gety() + s->getheight() >= y)
							//			{
							//				return 1;
							//			}
							//		}
							//		return 0;
							//	}
							//	bool check_ceiling(unit* s, int xM) {
							//		if (x < s->getx() + s->getwidth() - s->getjudging() && s->getx() + s->getjudging() < x + width) {
							//			if (s->gety() >= y + height && s->getvy() + s->gety() <= y + height)
							//			{
							//				return 1;
							//			}
							//		}
							//		return 0;
							//	}
							//	bool check_r(Amiya* s, int xM) {//左右碰撞都是先镶嵌进去再不动的，因此速度不能比木块大，不然会冲进去
							//		Point character[4];
							//		//character[0].x = s.getx(), character[0].y = s.gety();//左上
							//		//character[1].x = s.getx()+c_height, character[1].y = s.gety();//左下
							//		//character[0].x = s.getx(), character[0].y = s.gety()+c_width;//右上
							//		//character[0].x = s.getx()+c_height, character[0].y = s.gety()+c_width;//右下
							//		if (x + xM > s->getx() && s->getx() + s->getwidth() > x + xM && y - s->getheight() < s->gety() && y + height > s->gety()) {
							//			return 1;
							//		}
							//		return 0;
							//	}
							//	bool check_l(Amiya* s, int xM) {
							//		if (x + xM < s->getx() && s->getx() <= x + xM + width && y - s->getheight() < s->gety() && y + height > s->gety()) {//往左的话，因为速度固定，所以是速度的倍速
							//			return 1;
							//		}
							//		return 0;
							//	}
							//	bool check_ground(Amiya* s, int xM) {
							//		if (x + xM < s->getx() + s->getwidth() - s->getjudging() && s->getx() + s->getjudging() < x + xM + width) {
							//			if (s->gety() + s->getheight() <= y && s->getvy() + s->gety() + s->getheight() >= y)
							//			{
							//				return 1;
							//			}
							//		}
							//		return 0;
							//	}
							//	bool check_ceiling(Amiya* s, int xM) {
							//		if (x + xM < s->getx() + s->getwidth() - s->getjudging() && s->getx() + s->getjudging() < x + xM + width) {
							//			if (s->gety() >= y + height && s->getvy() + s->gety() <= y + height)
							//			{
							//				return 1;
							//			}
							//		}
							//		return 0;
							//	}
//							//};
//bool enemy::attack_close(Amiya& amiya, int xM) {
//	if (state != toattack_close && amiya.ifonground()) {
//		if (amiya.gety() + c_height == y + height && amiya.ifonground()) {//站在同一高度上并且站在地面上
//			if (((amiya.getx() - (x + xM + width / 2)) <= attack_close_range + width / 2 && (amiya.getx() - (x + xM + width / 2)) >= 0)) {//从boss的中间判断左右和距离
//				state = toattack_close;
//				direction = 1;
//				close_attack_frame = 0;
//				return 1;
//			}
//			else if (abs(amiya.getx() + amiya.getwidth() - (x + xM + width / 2)) <= attack_close_range + width / 2 && (amiya.getx() + amiya.getwidth() - (x + xM + width / 2)) < 0) {
//				state = toattack_close;
//				direction = -1;
//				close_attack_frame = 0;
//				return 1;
//			}//这样子没有判定amiya压在中线上的情况，但是无伤大雅，boss会自己走一两步去攻击
//		}
//	}
//	return 0;
//}
//bool enemy::attack_distant(Amiya& amiya, int xM) {//可以考虑改成不一定在地上，两个块在y轴方向有重叠，后期可以优化
//	if (state != toattack_close && amiya.ifonground()) {
//		if (amiya.gety() + c_height == y + height && amiya.ifonground()) {//站在同一高度上并且站在地面上
//			if (((amiya.getx() - (x + xM + width / 2)) <= attack_distant_range + width / 2 && (amiya.getx() - (x + xM + width / 2)) >= 0)) {//从boss的中间判断左右和距离
//				state = toattack_distant;
//				direction = 1;
//				distant_attack_frame = 0;
//				return 1;
//			}
//			else if (abs(amiya.getx() + amiya.getwidth() - (x + xM + width / 2)) <= attack_distant_range + width / 2 && (amiya.getx() + amiya.getwidth() - (x + xM + width / 2)) < 0) {
//				state = toattack_distant;
//				direction = -1;
//				distant_attack_frame = 0;
//				return 1;
//			}//这样子没有判定amiya压在中线上的情况，但是无伤大雅，boss会自己走一两步去攻击
//		}
//	}
//	return 0;
//}