#pragma once
#include<iostream>
#include<ctime>
#include<string>
#include<cstring>
#include<graphics.h>
#include<easyx.h>
#include<time.h>
#include<conio.h>
class timer {
	double time;
public:
	void init();
	void add(double i);
	void show();
	double gettime();
};