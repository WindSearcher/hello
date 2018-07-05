#include"stdafx.h"
#include "Robot.h"

Robot robot;
char* Robot::DIGITCHAR = "■";		// 双字符
char* Robot::SPACECHAR = "  ";

int Robot::x = 20;//初始化坐标
int Robot::y = 10;

Robot::Robot()
{
	dir = 0;
	iFrame = 0;
	c = 'w';//规定机器人的初始化方向
	speed = 2;  //移动速度
	width = 80;//控制台的宽
	height = 20;
}

//对机器人动画的初始化
int Robot::RobFrames[4][3][4][4] =
{
	{
		{
			{ 1,0,0,1 },
			{ 0,1,1,0 },
			{ 0,1,1,0 },
			{ 1,1,1,1 }
		},
		{
			{ 1,0,0,0 },
			{ 0,1,1,1 },
			{ 1,1,1,0 },
			{ 0,1,1,1 }
		},
		{
			{ 0,0,0,1 },
			{ 1,1,1,0 },
			{ 0,1,1,1 },
			{ 1,1,1,0 }
		}

	},

	{
		{
			{ 1,1,1,1 },
			{ 0,1,1,0 },
			{ 0,1,1,0 },
			{ 1,0,0,1 }
		},
		{
			{ 1,1,1,0 },
			{ 0,1,1,1 },
			{ 1,1,1,0 },
			{ 0,0,0,1 }
		},
		{
			{ 0,1,1,1 },
			{ 1,1,1,0 },
			{ 0,1,1,1 },
			{ 1,0,0,0 }
		}

	},

	{
		{
			{ 1,0,0,1 },
			{ 0,1,1,1 },
			{ 0,1,1,1 },
			{ 1,0,0,1 }
		},
		{
			{ 0,1,0,1 },
			{ 0,1,1,1 },
			{ 0,1,1,1 },
			{ 1,0,1,0 }
		},
		{
			{ 1,0,1,0 },
			{ 0,1,1,1 },
			{ 0,1,1,1 },
			{ 0,1,0,1 }
		}

	},

	{
		{
			{ 1,0,0,1 },
			{ 1,1,1,0 },
			{ 1,1,1,0 },
			{ 1,0,0,1 }
		},
		{
			{ 0,1,0,1 },
			{ 1,1,1,0 },
			{ 1,1,1,0 },
			{ 1,0,1,0 }
		},
		{
			{ 1,0,1,0 },
			{ 1,1,1,0 },
			{ 1,1,1,0 },
			{ 0,1,0,1 }
		}

	}

};

/*
函数功能:对物体的逻辑控制
*/
void Robot::control()
{

	move();
	screen1();
	screen2();
}


/*
函数功能:对先前物体的清除
*/

void Robot::clear(int mx, int my)
{
	for (int i = 0; i < ROWS; ++i)
	{
		robot.SetCoord(mx, my + i);
		for (int j = 0; j < COLS; ++j)
		{
			printf("  ");
		}
	}
}

/*
函数功能:显示物体
*/
void Robot::screen1()
{
	int rob[ROWS][COLS];
	memcpy(rob, RobFrames[dir][iFrame], sizeof(RobFrames[dir][iFrame]));
	for (int i = 0; i < ROWS; ++i)
	{
		robot.SetCoord(5, 24 + i);
		for (int j = 0; j < COLS; ++j)
		{
			if (rob[i][j] == 0)
			{
				cout << SPACECHAR;
			}
			else
			{
				cout << DIGITCHAR;
			}
		}
	}
}

void Robot::screen2()
{
	int rob[ROWS][COLS];
	memcpy(rob, RobFrames[dir][iFrame], sizeof(RobFrames[dir][iFrame]));
	for (int i = 0; i < ROWS; ++i)
	{
		robot.SetCoord(22, 24 + i);
		for (int j = 0; j < COLS; ++j)
		{
			if (rob[i][j] == 0)
			{
				cout << SPACECHAR;
			}
			else
			{
				cout << DIGITCHAR;
			}
		}
	}
}



//机器人自动移动函数
void Robot::move()
{

	iFrame = (++iFrame) % 3;
}

