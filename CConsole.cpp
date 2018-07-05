
#include "stdafx.h"
#include "CConsole.h"
#pragma warning(disable:4996)
CConsole::CConsole()
{
	HConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

CConsole::~CConsole()
{
		
}

void CConsole::SetCoord(int x, int y)
{
	// ��λ��ԭʼ�����Ͻ�λ��
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(HConsole,coord);
	// �����Ͻ�λ��Ϊ���������µ�λ��
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(HConsole,coord);
}

void CConsole::HideCursor(bool hide)
{
	// ���ؿ���̨��꣬CONSOLE_CURSOR_INFO�ṹ��ڶ�����Ա��Ϊ0�Ͳ��ɼ�
	CONSOLE_CURSOR_INFO cursor_info = {1, 1}; 
	if(hide == true) cursor_info.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void CConsole::SetTitle(char* title)
{
	SetConsoleTitle(title);
}

void CConsole::SetSize(int width, int height)
{
	char str[256];
	sprintf(str, "mode con: cols=%d lines=%d", width, height); 
	system(str); //���ڿ�ȸ߶�
}


/*
COLOR [attr]

	attr ָ������̨�������ɫ����

	��ɫ����������ʮ����������ָ��:	��һ��Ϊ�������ڶ�����Ϊǰ����
	ÿ�����ֿ���Ϊ�����κ�ֵ֮һ:

    0 = ��ɫ       8 = ��ɫ
    1 = ��ɫ       9 = ����ɫ
    2 = ��ɫ       A = ����ɫ
    3 = ǳ��ɫ     B = ��ǳ��ɫ
    4 = ��ɫ       C = ����ɫ
    5 = ��ɫ       D = ����ɫ
    6 = ��ɫ       E = ����ɫ
    7 = ��ɫ       F = ����ɫ

	���û�и����κβ�����������Ὣ��ɫ��ԭ�� CMD.EXE ����ʱ����ɫ��
	���ֵ���Ե�ǰ����̨���ڡ�/T �����п��ػ�DefaultColor ע���ֵ��

*/
void CConsole::SetColor(char* cl)
{
	char str[256];
	sprintf(str, "color %s", cl); 
	system(str);		//������ɫ
}

