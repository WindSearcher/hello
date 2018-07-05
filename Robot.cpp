#include"stdafx.h"
#include "Robot.h"

Robot robot;
char* Robot::DIGITCHAR = "��";		// ˫�ַ�
char* Robot::SPACECHAR = "  ";

int Robot::x = 20;//��ʼ������
int Robot::y = 10;

Robot::Robot()
{
	dir = 0;
	iFrame = 0;
	c = 'w';//�涨�����˵ĳ�ʼ������
	speed = 2;  //�ƶ��ٶ�
	width = 80;//����̨�Ŀ�
	height = 20;
}

//�Ի����˶����ĳ�ʼ��
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
��������:��������߼�����
*/
void Robot::control()
{

	move();
	screen1();
	screen2();
}


/*
��������:����ǰ��������
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
��������:��ʾ����
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



//�������Զ��ƶ�����
void Robot::move()
{

	iFrame = (++iFrame) % 3;
}

