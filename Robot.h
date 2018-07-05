#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>
#include "CConsole.h"
using namespace std;

const int ROWS = 4;
const int COLS = 4;

class Robot :public CConsole {
private:
	static char* DIGITCHAR;		// 双字符
	static char* SPACECHAR;
	static int x;
	static int y;
	int dir;   //动画方向
	int speed;  //机器人速度
	int iFrame;  //动画帧数
	char c;     //机器人初始化方向
	int width;   //控制台的宽
	int height;
	static int RobFrames[4][3][4][4];//全部动画帧数

public:
	Robot();

	void control();//逻辑控制

	void screen1();//显示物体
	void screen2();//显示物体

	void move();//可自己移动

	void clear(int, int);//清除先前物体

};

#endif // !ROBOT_H
