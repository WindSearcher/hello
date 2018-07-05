#include"stdafx.h"

#pragma warning(disable : 4786)
#include"CountMoney.h"
#include "Screen.h"
#include"CMusic.h"
#include "Robot.h"
#include "Catch.h"
#include <stdlib.h>
#include <Windows.h>

#define ScreenWidth  110
#define ScreenHeight 30

//团队介绍
void Screen::TeamIntroduction() {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Boundary();
	cconsole.SetCoord(20, 7);
	SetConsoleTextAttribute(hOut, 12);
	cout << "队长: 李强";
	Sleep(500);
	cconsole.SetCoord(20, 9);
	SetConsoleTextAttribute(hOut, 11);
	cout << "队员: 李刚\n";
	Sleep(500);
	cconsole.SetCoord(20, 11);
	SetConsoleTextAttribute(hOut, 14);
	cout << "队员: 杨善权";
	Sleep(1000);
	cconsole.SetCoord(40, 7);
	SetConsoleTextAttribute(hOut, 12);
	cout << "学号：8002117131\n";
	Sleep(500);
	cconsole.SetCoord(40, 9);
	SetConsoleTextAttribute(hOut, 11);
	cout << "学号：8002117157\n";
	Sleep(500);
	cconsole.SetCoord(40, 11);
	SetConsoleTextAttribute(hOut, 14);
	cout << "学号：8002117165\n";
	Sleep(500);
	cconsole.SetCoord(20, 13);
	SetConsoleTextAttribute(hOut, 7);
	cout << "班级：软件工程1704\n";
	Sleep(500);
	cconsole.SetCoord(20, 15);
	SetConsoleTextAttribute(hOut, 7);
	Sleep(500);
	cout << "介绍：///////////////////////////\n";
	cconsole.SetCoord(10, 17);
	cout << "\t\t（按任意键继续）";
	getchar();
	
}

//边界
void Screen::Boundary() {
	system("cls");
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	int i;
	cconsole.SetTitle("奇怪的小强");
	cconsole.SetSize(ScreenWidth, ScreenHeight);
	SetConsoleTextAttribute(hOut, 15);
	for ( i = 0; i < ScreenWidth; i++)
	{
		cout << "*";
		cconsole.SetCoord(i, 0);
	}
	
	for ( i = 0; i < ScreenWidth; i++)
	{
		cout << "*";
		cconsole.SetCoord(i, ScreenHeight-1);
		//cconsole.SetCoord(i, 30);
	}
	for ( i = 1; i < ScreenHeight-1; i++)
	{
		cconsole.SetCoord(0, i);
		cout << "#";
	}
	for ( i = 1; i < ScreenHeight-1; i++)
	{
		cconsole.SetCoord(ScreenWidth-1, i);
		cout << "#";

	}
}

//返回主城
void Screen::again()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	
	char ch;
	int x;   //用来判断
	static int i = 6;
	Boundary();
	cconsole.SetCoord(30, 5);
	SetConsoleTextAttribute(hOut, 11);
	cout << "返回主城或者退出游戏？（y/n）\n";
	
	do {
		cconsole.SetCoord(30, i);
		try {
			cout << "输入你的选择 >>"; cin >> ch;
			if (ch == 'Y' || ch == 'y')
			{
				x = 0;
				MainCity();
			}
			else if (ch == 'N' || ch == 'n')
			{
				x = 0;
				End();
			}
			else {
				x = 1;
				i += 2;
				throw InputDeal();
			}
		}
		catch (Catch &p) {
			cconsole.SetCoord(30, i+2);
			cout << p.Deal() << endl;
		}
	} while (x == 1);
	
}

//角色生成
void Screen::AddRole() {
	system("cls");
	Boundary();
	int n;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//string name;
	char response = 13;
	cconsole.SetCoord(30, 5);
	SetConsoleTextAttribute(hOut, 11);
	cout << "这是一个需要英雄的年代";
	Sleep(500);
	cconsole.SetCoord(34, 7);
	SetConsoleTextAttribute(hOut, 11);
	cout << "我们的勇士请你告诉我你要选择的种族：";
	Sleep(500);
	cconsole.SetCoord(36, 9);
	SetConsoleTextAttribute(hOut, 12);
	cout << "（1.魔族 2. 人族 3. 精灵族）";cin >> n;
	hero.PersonInitual(n,38,9);
	cconsole.SetCoord(34, 11);
	SetConsoleTextAttribute(hOut, 11);
	cout << "我们的勇士请你告诉我你的名字";
	cconsole.SetCoord(36, 13);
	SetConsoleTextAttribute(hOut, 11);
	cout << "（按回车键确认）";
	cconsole.SetCoord(36, 15);
	SetConsoleTextAttribute(hOut, 12);
	cout << "请输入您的姓名 >>";
	cin >> hero.str_Name;
	response = getchar();
	cconsole.SetCoord(36, 17);
	cout << "人物生成中";
	proc();
}

//游戏初始化界面
void Screen::Initial() {
	int c  = 0;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	//Start();
	Boundary();
	TeamIntroduction();
	GameIntroduction();
	system("cls");
	
	do {
		Boundary();
		cconsole.SetCoord(30, 5);
		SetConsoleTextAttribute(hOut, 12);
		cout << "欢迎来到奇怪的小强\n\n";
		cconsole.SetCoord(30, 8);
		SetConsoleTextAttribute(hOut, 11);
		cout << "1. 开始游戏 \n\n";
		cconsole.SetCoord(30, 10);
		SetConsoleTextAttribute(hOut, 11);
		cout << "2. 继续游戏 \n\n";
		cconsole.SetCoord(30, 12);
		SetConsoleTextAttribute(hOut, 11);
		cout << "3. 游戏介绍 \n\n";
		cconsole.SetCoord(30, 14);
		SetConsoleTextAttribute(hOut, 11);
		cout << "4. 退出游戏 \n\n";
		SetConsoleTextAttribute(hOut, 11);
		cconsole.SetCoord(30, 16);
		SetConsoleTextAttribute(hOut, 14);
		cout << "输入你的选择 >>"; cin >> c;
		switch (c)
		{
		case 1:
			AddRole();
			NoviceVillage();
			break;
		case 2:
			file.readFromFile();
			//cin.get();
			//cin.get();
			file.display(hero,0);
			//cin.get();
			//cin.get();
			//	file.writeToFile(hero,1);
			MainCity();
			break;
		case 3:
			GameIntroduction();
			break;
		case 4:
			End();
		default:
			cconsole.SetCoord(30, 19);
			cout << "输入错误！！！";
		}
	} while (c != 4);
	
}

//主城
void Screen::MainCity() {
	CountMoney c;
	CMusic music;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int xx = 1;//用来记录；
	static int ii = 18;
	int choice ;
	system("cls");
	Boundary();
	cconsole.SetCoord(12, 2);
	SetConsoleTextAttribute(hOut, 7);
	cout << "您目前所在的位置： 主城";
	cconsole.SetCoord(35, 6);
	cout << "1. 前往商店";
	cconsole.SetCoord(35, 8);
	cout << "2. 前往森林";
	cconsole.SetCoord(35, 10);
	cout << "3. 前往雪地";
	cconsole.SetCoord(35, 12);
	cout << "4. 前往魔王城堡";
	cconsole.SetCoord(35, 14);
	cout << "5. 游戏状态";
	cconsole.SetCoord(35, 16);
	cout << "6. 退出游戏";
	do {
		cconsole.SetCoord(35, ii);
		try {
			SetConsoleTextAttribute(hOut, 12);
			cout << "输入你的选择 >>";
			cin >> choice;		
			if(choice >5 || choice < 0) {
				xx = 1;
				ii += 2;
				throw InputDeal();
			}
		}

		catch (Catch &p) {
			cconsole.SetCoord(35, ii + 2);
			cout << p.Deal() << endl;
		}

		switch (choice)
		{
		case 1:
			system("cls");
			c.order(hero);
			again();
			break;
		case 2:
			system("cls");
			Cut_Picture("森林");
			system("cls");
			file.readFromFile();
			
			map.make_map1();
			music.Play();
			Map_Division();
			hero.SetPos(16, 19);
			if(hero.i_Hp < 0)
				hero.i_Hp = 100;
			    //hero.Initial();
			//hero.PersonInitual(hero.i_Type,16,19);
		hello:
			music.Play();
			while (1)
			{
				hero.DoubleMove();
				map.Fight_map1(hero,file);
				if(map.win == true)
				{
					map.win = false;
				    again();
				}
				    
				cconsole.SetCoord(0, 22);
				file.display(hero,1);
					
				if (music.isStopped() == true)
					goto hello;
				if (hero.Dead == true)
				{
					hero.Dead = false;
					file.writeToFile(hero);
					again();
					break;
				}
			}
			break;
		case 3:
			system("cls");
			Cut_Picture("雪地");
			system("cls");
			file.readFromFile();
			map.make_map2();
			music.Play();
			Map_Division();
			//hero.PersonInitual(hero.i_Type,12,19);
			hero.SetPos(12, 19);
			if(hero.i_Hp < 0)
				hero.i_Hp = 200;
			   //hero.Initial();
		end:
			music.Play();
			while (1)
			{
				hero.DoubleMove();
				map.Fight_map2(hero,file);
				if(map.win == true)
				{
					map.win = false;
				    again();
				}

				cconsole.SetCoord(0, 22);
				if (music.isStopped() == true)
					goto end;
				file.display(hero,1);
				if (hero.Dead == true)
				{
					hero.Dead = false;
					file.writeToFile(hero);
					again();
					break;
				}
			}

			break;
		case 4:
			system("cls");
			Cut_Picture("魔王城堡");
			system("cls");
			Boundary();
			Map_Division();
			cconsole.SetCoord(0, 22);
			file.readFromFile();
			file.display(hero,1);
			if(hero.i_Hp < 0)
				hero.i_Hp = 300;
			//hero.Initial();
			hero.Dead = false;
			map3.MapPart(hero);
			break;
		case 5:
			GameState();
		case 6:
			goto aa;
			break;
		default:
			
			break;
		}
	} while (xx == 1);
	
	aa:End();
}

//新手村
void Screen::NoviceVillage() {
	int n = 0;
	while (1)
	{
		system("cls");
		Boundary();
		cconsole.SetCoord(12, 2);
		cout << "您目前所在的位置： 新手村";
		cconsole.SetCoord(35, 6);
		cout << "1. 与村长对话";
		cconsole.SetCoord(35, 7);
		cout << "2. 前往主城";
		cconsole.SetCoord(35, 8);
		cout << "3. 退出游戏";
		cconsole.SetCoord(35, 10);
		cout << "(一旦返回主城，就无法到达新手村了哦)";
		cconsole.SetCoord(35, 12);
		cout << "输入你的选择 >> "; cin >> n;
		switch (n)
		{
		case 1:
			Dialogue();
			break;
		case 2:
			MainCity();
			break;
		case 3:
			End();
			break;
		default:
			
			cout << "输入有误！！！";
			break;
		}
		if (n == 3 ||n == 2)
		{
			break;
		}
	}
}

//与村长对话
void Screen::Dialogue() {
	system("cls");
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	char response = 13;
	cconsole.SetCoord(35, 8);
	SetConsoleTextAttribute(hOut, 14);
	cout << "村长说：小伙子，魔王就住在魔王城堡里面，打倒他，才能获得最终的胜利" << endl;
	cconsole.SetCoord(35, 10);
	SetConsoleTextAttribute(hOut, 11);
	cout << "与村长对话，你想说 ：";
	string Words;
	cin >> Words;
	SetConsoleTextAttribute(hOut, 12);
	hero.GoldenFinger(Words);
	system("pause");
	cout << "(按回车键返回)";
	response = getchar();
}

//游戏介绍
void Screen::GameIntroduction() {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Boundary();
	cconsole.SetCoord(10, 5);
	SetConsoleTextAttribute(hOut, 10);
	cout << "\t\t================== 使用须知 ===================";
	cconsole.SetCoord(10, 7);
	SetConsoleTextAttribute(hOut, 7);
	cout << "\t\t  1. 请将输入法切换至英文模式";
	Sleep(500);
	cconsole.SetCoord(10, 9);
	SetConsoleTextAttribute(hOut, 7);
	cout << "\t\t  2. 玩家通过";
	SetConsoleTextAttribute(hOut, 12);
	cout << " “wasd”";
	SetConsoleTextAttribute(hOut, 7);
	cout << "来控制人物";

	Sleep(500);
	cconsole.SetCoord(10, 11);
	SetConsoleTextAttribute(hOut, 7);
	cout << "\t\t  3. 戴上耳机体验更棒！！！";
	Sleep(500);
	cconsole.SetCoord(10, 13);
	SetConsoleTextAttribute(hOut,7);
	cout << "\t\t  4. 更多玩法尽请期待......";
	Sleep(500);
	cconsole.SetCoord(10, 15);
	SetConsoleTextAttribute(hOut, 7);
	cout << "\t\t  作者联系方式：1212121212";
	Sleep(500);
	cconsole.SetCoord(10, 17);
	SetConsoleTextAttribute(hOut, 14);
	cout << "\t\t      祝您使用愉快!!!";
	Sleep(500);
	cconsole.SetCoord(10, 19);
	SetConsoleTextAttribute(hOut, 10);
	cout << "\t\t==============================================";
	cconsole.SetCoord(10, 21);
	SetConsoleTextAttribute(hOut, 9 + rand() % 3 + 1);
	cout << "\t\t（按任意键继续）";
	getchar();
	system("cls");
	Boundary();
	cconsole.SetCoord(15, 5);
	SetConsoleTextAttribute(hOut, 11);
	cout << "元祖魔塔 >>>>>> ";
	cconsole.SetCoord(10, 7);
	cout << "    一位魔王为了想要一比他更厉害的人来拯救世界,拿公主做诱饵，引诱了一位勇者（就是你）进入";
	Sleep(100);
	cconsole.SetCoord(10, 9);
	cout << "魔塔。但是到塔顶后，魔王逃跑了，没办法，再来一遍。这时，勇者保持第一遍道最后的能力，但是";
	Sleep(100);
	cconsole.SetCoord(10, 11);
	cout << "其它数据会乘44倍，到最后魔王仍然逃跑，到底有没有尽头呢？\n";
	Sleep(100);
	cconsole.SetCoord(10, 13);
	cout << "	作者说明：这个游戏没有结束。这个游戏虽然不大，\n";
	Sleep(100);
	cconsole.SetCoord(10, 15);
	cout << "			  但制作精美，是对智商也是一次艰巨的考验\n";
	Sleep(100);
	cconsole.SetCoord(10, 17);
	cout << "             所以如果你喜欢挑战，就一定不要错过！\n";
	Sleep(100);
	cconsole.SetCoord(10, 21);
	cout << "\t\t（按任意键继续）";
	getchar();

}

//退出程序
void  Screen::End() {
	system("cls");
	Boundary();
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cconsole.SetCoord(35, 13);
	SetConsoleTextAttribute(hOut, 14);
	cout << "Game Over";
	exit(1);
}

//进度条
void Screen::proc() {
	cconsole.SetCoord(1, 22);
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	
	int i = 0;
	char bar[120] = { 0 };
	//const char *lable = "|/-\\";
	while (i <= 100)
	{
		//system("cls");
		cconsole.SetCoord(1,22);
		SetConsoleTextAttribute(hOut, 9+rand()%3+1);
		printf("[%s][%d%%]\r", bar, i);
		fflush(stdout);   //fflush(stdout)：清空输出缓冲区，并把缓冲区内容输出
		bar[i] = '>';
		i++;
		bar[i] = 0;
		Sleep(50);
	}
	//printf("\n");
}

//开始动画
void Screen::Start() {
	Boundary();
	int i;               //控制空格
	int j = 62;            //63刚好到黑框最右侧
	int t = 0;
	while (1) {
		system("CLS");   //清屏
		cconsole.SetCoord(10, 8);
		for (i = 0; i < t; i++) {
			printf(" ");
		}
		printf("--- 欢迎");
		for (i = 0; i < j; i++) {
			printf(" ");
		}
		printf("使用 ---");
		if (t == 31) {
			Sleep(200);
			printf("\n\n                                   Welcome\n");
			printf("\n\t\t\t\t姓名：     李刚\n");
			printf("\n\t\t\t\t学号：     8002117157\n");
			printf("\n\t\t\t\t班级：     软件工程1704\n");
			printf("\n\t\t\t\t程序名称： 通讯录1.0\n");
			printf("\n\t\t\t\t实验时间： 2018.5.25\n");
			printf("\n\n\n");
			printf("                                                                 支持正版...");
			Sleep(300);
			system("CLS");
			printf("\n\n\n\n\n\n\n\n\n");
			for (i = 0; i < t; i++) {
				printf(" ");
			}
			printf("--- 欢迎");
			for (i = 0; i < j; i++) {
				printf(" ");
			}
			printf("使用 ---");
			Sleep(200);
			printf("\n\n                                   Welcome\n");
			printf("\n\t\t\t\t姓名：     李刚\n");
			printf("\n\t\t\t\t学号：     8002117157\n");
			printf("\n\t\t\t\t班级：     软件工程1704\n");
			printf("\n\t\t\t\t程序名称：通讯录1.0\n");
			printf("\n\t\t\t\t实验时间： 2018.5.25\n");
			printf("\n\n\n");

			printf("                                                                 支持正版...");
			Sleep(1500);
			system("CLS");
			break;
		}
		printf("\n\n\t\t\t\t姓名：     李刚\n");
		printf("\n\t\t\t\t学号：     8002117157\n");
		printf("\n\t\t\t\t班级：     软件工程1704\n");
		printf("\n\t\t\t\t程序名称：通讯录1.0\n");
		printf("\n\t\t\t\t实验时间： 2018.5.25\n");
		printf("\n\n\n");
		printf("                                                                 支持正版...");
		t++;
		j -= 2;
		Sleep(85);  //停顿
	}
}

//地图分割
void Screen::Map_Division() {
	Robot robot;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	cconsole.SetCoord(0, 21);
	int i = 0;
	for ( i = 0; i < 88; i++)
	{
		SetConsoleTextAttribute(hOut, 12);
		cconsole.SetCoord(i, 21);
		cout << "=";
	}
	cconsole.SetCoord(88, 0);
	for ( i = 0; i < 30; i++)
	{
		SetConsoleTextAttribute(hOut, 12);
		cconsole.SetCoord(88, i);
		cout << "*";
	}
	cconsole.SetCoord(40, 22);
	for ( i = 22; i < 30; i++)
	{
		SetConsoleTextAttribute(hOut, 12);
		cconsole.SetCoord(40, i);
		cout << "*";
	}
	cconsole.SetCoord(89,11);
	for ( i = 89; i < 110; i++)
	{
		SetConsoleTextAttribute(hOut, 12);
		cconsole.SetCoord(i,11);
		cout << "=";
	}
	cconsole.SetCoord(3, 23);
	/*while (1)
	{
		robot.control();
		Sleep(500);

	}*/
}

//过场图
void Screen::Cut_Picture(string name) {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	char *cut[20][40] = { 0 };
	int i, j;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 40; j++)
		{
			cut[i][j] = "■";
		}
	}
	for (i = 0; i < 20; i++)
	{
		SetConsoleTextAttribute(hOut, 6);
		for (j = 0; j < 40; j++)
		{
			cout << cut[i][j];
		}
		cout << "\n";
		Sleep(200);
	}
	SetConsoleTextAttribute(hOut, 12);
	cconsole.SetCoord(23, 8);
	cout << "副本：         " << name;
	cconsole.SetCoord(23, 9);
	cout << "                        ";
	cconsole.SetCoord(23, 10);
	SetConsoleTextAttribute(hOut, 12);
	cout << "操作指南：     WASD 控制";
	cconsole.SetCoord(23, 11);
	cout << "                        ";
	cconsole.SetCoord(23, 12);
	SetConsoleTextAttribute(hOut, 12);
	cout << "副本难度：     ★★★★";
	Sleep(1500);
}

//游戏状态
void Screen::GameState() {
	
	int choice = 0;
	int x = 1;
	static int j = 15;
	HANDLE hOut;
	while (choice != 4)
	{
		Boundary();
		cconsole.SetCoord(35, 5);
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOut, 11);
		cout << "=========================";
		cconsole.SetCoord(38, 7);
		SetConsoleTextAttribute(hOut, 14);
		cout << "1. 英雄状态";
		cconsole.SetCoord(38, 9);
		SetConsoleTextAttribute(hOut, 14);
		cout << "2. 怪物图鉴";
		cconsole.SetCoord(38, 11);
		SetConsoleTextAttribute(hOut, 14);
		cout << "3. 副本攻略";
		cconsole.SetCoord(38, 13);
		SetConsoleTextAttribute(hOut, 14);
		cout << "4. 返回主城";
		do {
			try {
				cconsole.SetCoord(30, j);
				SetConsoleTextAttribute(hOut, 12);
				cout << "输入你的选择 >>>";  cin >> choice;
				if (choice >= 1 && choice <= 4)
				{
					x = 0;
				}
				else {
					x = 1;
					j += 2;
					throw InputDeal();
				}
			}
			catch (Catch &p) {
				cconsole.SetCoord(30, j + 2);
				cout << p.Deal() << endl;
			}
			switch (choice) {
			case 1:
				hero.Gothrough();
				system("pause");
				break;
			case 2:
				List(35, 3);
				break;
			case 3:
				Boundary();
				cconsole.SetCoord(35, 5);
				cout << "副本： 1. 森林副本    2 . 雪地   3. 魔王城堡";
				cconsole.SetCoord(35, 7);
				cout << "        1.wasd 来控制人物移动";
				cconsole.SetCoord(35, 9);
				cout << "        2.遇到怪物量力而行";
				cconsole.SetCoord(35, 11);
				cout << "        3.主城商店是一个很好的选择";
				cconsole.SetCoord(35, 13);
				cout << "        4. 前两个副本找到出口钥匙即为胜利";
				cconsole.SetCoord(35, 15);
				cout << "        5. 第三个副本要打到魔王才行哦";
				cconsole.SetCoord(35, 18);
				Sleep(100);
				system("pause");
				break;
			case 4:
				MainCity();
				break;
			default:
				break;
			}
		} while (x == 1);
	}
}


void Screen::List(int _x, int _y)//角色列表，_x、_y为了确定输出位置
{
	Boundary();
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, 11);
	CConsole cons;
	Monster mon;
	Hero hero;
	cons.SetCoord(_x, _y);
	cout << "1、人族";
	cons.SetCoord(_x, _y + 1);
	cout << "2、魔族";
	cons.SetCoord(_x, _y + 2);
	cout << "3、精灵族";
	cons.SetCoord(_x, _y + 3);
	cout << "4、巨齿鲨";
	cons.SetCoord(_x, _y + 4);
	cout << "5、猛犸巨象";
	cons.SetCoord(_x, _y + 5);
	cout << "6、古堡巨魔";
	cons.SetCoord(_x, _y + 6);
	cout << "7、虾兵";
	cons.SetCoord(_x, _y + 7);
	cout << "8、蟹将";
	cons.SetCoord(_x, _y + 8);
	cout << "9、啮齿鼠 ";
	cons.SetCoord(_x, _y + 9);
	cout << "10、噬蚁群";
	cons.SetCoord(_x, _y + 10);
	cout << "11、吸血蝠";
	cons.SetCoord(_x, _y + 11);
	cout << "12、夜人狼";
	cons.SetCoord(_x, _y + 12);
	cout << "13、黑化小强";
	cons.SetCoord(_x, _y + 13);
	cout << "14、酱油杨";
	cons.SetCoord(_x, _y + 14);
	cout << "15、酱油刚";
	cons.SetCoord(_x, _y + 15);
	cout << "16、宝箱";
	cons.SetCoord(_x, _y + 17);
	cout << "编号查询：";
	int Order;
	cin >> Order;
	if (Order<4 && Order>0)
	{
		hero.HeroStatus(Order, 60, 5);
	}
	else if (Order<16 && Order >= 4)
	{
		mon.monsterStatus(Order, 60, 5);
	}
	else
	{
		cons.SetCoord(60, 2);
		cout << "没有该角色!!";
	}
}
