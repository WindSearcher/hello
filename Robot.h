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
	static char* DIGITCHAR;		// ˫�ַ�
	static char* SPACECHAR;
	static int x;
	static int y;
	int dir;   //��������
	int speed;  //�������ٶ�
	int iFrame;  //����֡��
	char c;     //�����˳�ʼ������
	int width;   //����̨�Ŀ�
	int height;
	static int RobFrames[4][3][4][4];//ȫ������֡��

public:
	Robot();

	void control();//�߼�����

	void screen1();//��ʾ����
	void screen2();//��ʾ����

	void move();//���Լ��ƶ�

	void clear(int, int);//�����ǰ����

};

#endif // !ROBOT_H
