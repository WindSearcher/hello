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

//�Ŷӽ���
void Screen::TeamIntroduction() {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Boundary();
	cconsole.SetCoord(20, 7);
	SetConsoleTextAttribute(hOut, 12);
	cout << "�ӳ�: ��ǿ";
	Sleep(500);
	cconsole.SetCoord(20, 9);
	SetConsoleTextAttribute(hOut, 11);
	cout << "��Ա: ���\n";
	Sleep(500);
	cconsole.SetCoord(20, 11);
	SetConsoleTextAttribute(hOut, 14);
	cout << "��Ա: ����Ȩ";
	Sleep(1000);
	cconsole.SetCoord(40, 7);
	SetConsoleTextAttribute(hOut, 12);
	cout << "ѧ�ţ�8002117131\n";
	Sleep(500);
	cconsole.SetCoord(40, 9);
	SetConsoleTextAttribute(hOut, 11);
	cout << "ѧ�ţ�8002117157\n";
	Sleep(500);
	cconsole.SetCoord(40, 11);
	SetConsoleTextAttribute(hOut, 14);
	cout << "ѧ�ţ�8002117165\n";
	Sleep(500);
	cconsole.SetCoord(20, 13);
	SetConsoleTextAttribute(hOut, 7);
	cout << "�༶���������1704\n";
	Sleep(500);
	cconsole.SetCoord(20, 15);
	SetConsoleTextAttribute(hOut, 7);
	Sleep(500);
	cout << "���ܣ�///////////////////////////\n";
	cconsole.SetCoord(10, 17);
	cout << "\t\t���������������";
	getchar();
	
}

//�߽�
void Screen::Boundary() {
	system("cls");
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	int i;
	cconsole.SetTitle("��ֵ�Сǿ");
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

//��������
void Screen::again()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	
	char ch;
	int x;   //�����ж�
	static int i = 6;
	Boundary();
	cconsole.SetCoord(30, 5);
	SetConsoleTextAttribute(hOut, 11);
	cout << "�������ǻ����˳���Ϸ����y/n��\n";
	
	do {
		cconsole.SetCoord(30, i);
		try {
			cout << "�������ѡ�� >>"; cin >> ch;
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

//��ɫ����
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
	cout << "����һ����ҪӢ�۵����";
	Sleep(500);
	cconsole.SetCoord(34, 7);
	SetConsoleTextAttribute(hOut, 11);
	cout << "���ǵ���ʿ�����������Ҫѡ������壺";
	Sleep(500);
	cconsole.SetCoord(36, 9);
	SetConsoleTextAttribute(hOut, 12);
	cout << "��1.ħ�� 2. ���� 3. �����壩";cin >> n;
	hero.PersonInitual(n,38,9);
	cconsole.SetCoord(34, 11);
	SetConsoleTextAttribute(hOut, 11);
	cout << "���ǵ���ʿ����������������";
	cconsole.SetCoord(36, 13);
	SetConsoleTextAttribute(hOut, 11);
	cout << "�����س���ȷ�ϣ�";
	cconsole.SetCoord(36, 15);
	SetConsoleTextAttribute(hOut, 12);
	cout << "�������������� >>";
	cin >> hero.str_Name;
	response = getchar();
	cconsole.SetCoord(36, 17);
	cout << "����������";
	proc();
}

//��Ϸ��ʼ������
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
		cout << "��ӭ������ֵ�Сǿ\n\n";
		cconsole.SetCoord(30, 8);
		SetConsoleTextAttribute(hOut, 11);
		cout << "1. ��ʼ��Ϸ \n\n";
		cconsole.SetCoord(30, 10);
		SetConsoleTextAttribute(hOut, 11);
		cout << "2. ������Ϸ \n\n";
		cconsole.SetCoord(30, 12);
		SetConsoleTextAttribute(hOut, 11);
		cout << "3. ��Ϸ���� \n\n";
		cconsole.SetCoord(30, 14);
		SetConsoleTextAttribute(hOut, 11);
		cout << "4. �˳���Ϸ \n\n";
		SetConsoleTextAttribute(hOut, 11);
		cconsole.SetCoord(30, 16);
		SetConsoleTextAttribute(hOut, 14);
		cout << "�������ѡ�� >>"; cin >> c;
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
			cout << "������󣡣���";
		}
	} while (c != 4);
	
}

//����
void Screen::MainCity() {
	CountMoney c;
	CMusic music;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int xx = 1;//������¼��
	static int ii = 18;
	int choice ;
	system("cls");
	Boundary();
	cconsole.SetCoord(12, 2);
	SetConsoleTextAttribute(hOut, 7);
	cout << "��Ŀǰ���ڵ�λ�ã� ����";
	cconsole.SetCoord(35, 6);
	cout << "1. ǰ���̵�";
	cconsole.SetCoord(35, 8);
	cout << "2. ǰ��ɭ��";
	cconsole.SetCoord(35, 10);
	cout << "3. ǰ��ѩ��";
	cconsole.SetCoord(35, 12);
	cout << "4. ǰ��ħ���Ǳ�";
	cconsole.SetCoord(35, 14);
	cout << "5. ��Ϸ״̬";
	cconsole.SetCoord(35, 16);
	cout << "6. �˳���Ϸ";
	do {
		cconsole.SetCoord(35, ii);
		try {
			SetConsoleTextAttribute(hOut, 12);
			cout << "�������ѡ�� >>";
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
			Cut_Picture("ɭ��");
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
			Cut_Picture("ѩ��");
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
			Cut_Picture("ħ���Ǳ�");
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

//���ִ�
void Screen::NoviceVillage() {
	int n = 0;
	while (1)
	{
		system("cls");
		Boundary();
		cconsole.SetCoord(12, 2);
		cout << "��Ŀǰ���ڵ�λ�ã� ���ִ�";
		cconsole.SetCoord(35, 6);
		cout << "1. ��峤�Ի�";
		cconsole.SetCoord(35, 7);
		cout << "2. ǰ������";
		cconsole.SetCoord(35, 8);
		cout << "3. �˳���Ϸ";
		cconsole.SetCoord(35, 10);
		cout << "(һ���������ǣ����޷��������ִ���Ŷ)";
		cconsole.SetCoord(35, 12);
		cout << "�������ѡ�� >> "; cin >> n;
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
			
			cout << "�������󣡣���";
			break;
		}
		if (n == 3 ||n == 2)
		{
			break;
		}
	}
}

//��峤�Ի�
void Screen::Dialogue() {
	system("cls");
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	char response = 13;
	cconsole.SetCoord(35, 8);
	SetConsoleTextAttribute(hOut, 14);
	cout << "�峤˵��С���ӣ�ħ����ס��ħ���Ǳ����棬���������ܻ�����յ�ʤ��" << endl;
	cconsole.SetCoord(35, 10);
	SetConsoleTextAttribute(hOut, 11);
	cout << "��峤�Ի�������˵ ��";
	string Words;
	cin >> Words;
	SetConsoleTextAttribute(hOut, 12);
	hero.GoldenFinger(Words);
	system("pause");
	cout << "(���س�������)";
	response = getchar();
}

//��Ϸ����
void Screen::GameIntroduction() {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Boundary();
	cconsole.SetCoord(10, 5);
	SetConsoleTextAttribute(hOut, 10);
	cout << "\t\t================== ʹ����֪ ===================";
	cconsole.SetCoord(10, 7);
	SetConsoleTextAttribute(hOut, 7);
	cout << "\t\t  1. �뽫���뷨�л���Ӣ��ģʽ";
	Sleep(500);
	cconsole.SetCoord(10, 9);
	SetConsoleTextAttribute(hOut, 7);
	cout << "\t\t  2. ���ͨ��";
	SetConsoleTextAttribute(hOut, 12);
	cout << " ��wasd��";
	SetConsoleTextAttribute(hOut, 7);
	cout << "����������";

	Sleep(500);
	cconsole.SetCoord(10, 11);
	SetConsoleTextAttribute(hOut, 7);
	cout << "\t\t  3. ���϶����������������";
	Sleep(500);
	cconsole.SetCoord(10, 13);
	SetConsoleTextAttribute(hOut,7);
	cout << "\t\t  4. �����淨�����ڴ�......";
	Sleep(500);
	cconsole.SetCoord(10, 15);
	SetConsoleTextAttribute(hOut, 7);
	cout << "\t\t  ������ϵ��ʽ��1212121212";
	Sleep(500);
	cconsole.SetCoord(10, 17);
	SetConsoleTextAttribute(hOut, 14);
	cout << "\t\t      ף��ʹ�����!!!";
	Sleep(500);
	cconsole.SetCoord(10, 19);
	SetConsoleTextAttribute(hOut, 10);
	cout << "\t\t==============================================";
	cconsole.SetCoord(10, 21);
	SetConsoleTextAttribute(hOut, 9 + rand() % 3 + 1);
	cout << "\t\t���������������";
	getchar();
	system("cls");
	Boundary();
	cconsole.SetCoord(15, 5);
	SetConsoleTextAttribute(hOut, 11);
	cout << "Ԫ��ħ�� >>>>>> ";
	cconsole.SetCoord(10, 7);
	cout << "    һλħ��Ϊ����Ҫһ������������������������,�ù������ն���������һλ���ߣ������㣩����";
	Sleep(100);
	cconsole.SetCoord(10, 9);
	cout << "ħ�������ǵ�������ħ�������ˣ�û�취������һ�顣��ʱ�����߱��ֵ�һ�����������������";
	Sleep(100);
	cconsole.SetCoord(10, 11);
	cout << "�������ݻ��44���������ħ����Ȼ���ܣ�������û�о�ͷ�أ�\n";
	Sleep(100);
	cconsole.SetCoord(10, 13);
	cout << "	����˵���������Ϸû�н����������Ϸ��Ȼ����\n";
	Sleep(100);
	cconsole.SetCoord(10, 15);
	cout << "			  �������������Ƕ�����Ҳ��һ�μ�޵Ŀ���\n";
	Sleep(100);
	cconsole.SetCoord(10, 17);
	cout << "             ���������ϲ����ս����һ����Ҫ�����\n";
	Sleep(100);
	cconsole.SetCoord(10, 21);
	cout << "\t\t���������������";
	getchar();

}

//�˳�����
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

//������
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
		fflush(stdout);   //fflush(stdout)�������������������ѻ������������
		bar[i] = '>';
		i++;
		bar[i] = 0;
		Sleep(50);
	}
	//printf("\n");
}

//��ʼ����
void Screen::Start() {
	Boundary();
	int i;               //���ƿո�
	int j = 62;            //63�պõ��ڿ����Ҳ�
	int t = 0;
	while (1) {
		system("CLS");   //����
		cconsole.SetCoord(10, 8);
		for (i = 0; i < t; i++) {
			printf(" ");
		}
		printf("--- ��ӭ");
		for (i = 0; i < j; i++) {
			printf(" ");
		}
		printf("ʹ�� ---");
		if (t == 31) {
			Sleep(200);
			printf("\n\n                                   Welcome\n");
			printf("\n\t\t\t\t������     ���\n");
			printf("\n\t\t\t\tѧ�ţ�     8002117157\n");
			printf("\n\t\t\t\t�༶��     �������1704\n");
			printf("\n\t\t\t\t�������ƣ� ͨѶ¼1.0\n");
			printf("\n\t\t\t\tʵ��ʱ�䣺 2018.5.25\n");
			printf("\n\n\n");
			printf("                                                                 ֧������...");
			Sleep(300);
			system("CLS");
			printf("\n\n\n\n\n\n\n\n\n");
			for (i = 0; i < t; i++) {
				printf(" ");
			}
			printf("--- ��ӭ");
			for (i = 0; i < j; i++) {
				printf(" ");
			}
			printf("ʹ�� ---");
			Sleep(200);
			printf("\n\n                                   Welcome\n");
			printf("\n\t\t\t\t������     ���\n");
			printf("\n\t\t\t\tѧ�ţ�     8002117157\n");
			printf("\n\t\t\t\t�༶��     �������1704\n");
			printf("\n\t\t\t\t�������ƣ�ͨѶ¼1.0\n");
			printf("\n\t\t\t\tʵ��ʱ�䣺 2018.5.25\n");
			printf("\n\n\n");

			printf("                                                                 ֧������...");
			Sleep(1500);
			system("CLS");
			break;
		}
		printf("\n\n\t\t\t\t������     ���\n");
		printf("\n\t\t\t\tѧ�ţ�     8002117157\n");
		printf("\n\t\t\t\t�༶��     �������1704\n");
		printf("\n\t\t\t\t�������ƣ�ͨѶ¼1.0\n");
		printf("\n\t\t\t\tʵ��ʱ�䣺 2018.5.25\n");
		printf("\n\n\n");
		printf("                                                                 ֧������...");
		t++;
		j -= 2;
		Sleep(85);  //ͣ��
	}
}

//��ͼ�ָ�
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

//����ͼ
void Screen::Cut_Picture(string name) {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	char *cut[20][40] = { 0 };
	int i, j;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 40; j++)
		{
			cut[i][j] = "��";
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
	cout << "������         " << name;
	cconsole.SetCoord(23, 9);
	cout << "                        ";
	cconsole.SetCoord(23, 10);
	SetConsoleTextAttribute(hOut, 12);
	cout << "����ָ�ϣ�     WASD ����";
	cconsole.SetCoord(23, 11);
	cout << "                        ";
	cconsole.SetCoord(23, 12);
	SetConsoleTextAttribute(hOut, 12);
	cout << "�����Ѷȣ�     �����";
	Sleep(1500);
}

//��Ϸ״̬
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
		cout << "1. Ӣ��״̬";
		cconsole.SetCoord(38, 9);
		SetConsoleTextAttribute(hOut, 14);
		cout << "2. ����ͼ��";
		cconsole.SetCoord(38, 11);
		SetConsoleTextAttribute(hOut, 14);
		cout << "3. ��������";
		cconsole.SetCoord(38, 13);
		SetConsoleTextAttribute(hOut, 14);
		cout << "4. ��������";
		do {
			try {
				cconsole.SetCoord(30, j);
				SetConsoleTextAttribute(hOut, 12);
				cout << "�������ѡ�� >>>";  cin >> choice;
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
				cout << "������ 1. ɭ�ָ���    2 . ѩ��   3. ħ���Ǳ�";
				cconsole.SetCoord(35, 7);
				cout << "        1.wasd �����������ƶ�";
				cconsole.SetCoord(35, 9);
				cout << "        2.����������������";
				cconsole.SetCoord(35, 11);
				cout << "        3.�����̵���һ���ܺõ�ѡ��";
				cconsole.SetCoord(35, 13);
				cout << "        4. ǰ���������ҵ�����Կ�׼�Ϊʤ��";
				cconsole.SetCoord(35, 15);
				cout << "        5. ����������Ҫ��ħ������Ŷ";
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


void Screen::List(int _x, int _y)//��ɫ�б�_x��_yΪ��ȷ�����λ��
{
	Boundary();
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, 11);
	CConsole cons;
	Monster mon;
	Hero hero;
	cons.SetCoord(_x, _y);
	cout << "1������";
	cons.SetCoord(_x, _y + 1);
	cout << "2��ħ��";
	cons.SetCoord(_x, _y + 2);
	cout << "3��������";
	cons.SetCoord(_x, _y + 3);
	cout << "4���޳���";
	cons.SetCoord(_x, _y + 4);
	cout << "5���������";
	cons.SetCoord(_x, _y + 5);
	cout << "6���ű���ħ";
	cons.SetCoord(_x, _y + 6);
	cout << "7��Ϻ��";
	cons.SetCoord(_x, _y + 7);
	cout << "8��з��";
	cons.SetCoord(_x, _y + 8);
	cout << "9�������� ";
	cons.SetCoord(_x, _y + 9);
	cout << "10������Ⱥ";
	cons.SetCoord(_x, _y + 10);
	cout << "11����Ѫ��";
	cons.SetCoord(_x, _y + 11);
	cout << "12��ҹ����";
	cons.SetCoord(_x, _y + 12);
	cout << "13���ڻ�Сǿ";
	cons.SetCoord(_x, _y + 13);
	cout << "14��������";
	cons.SetCoord(_x, _y + 14);
	cout << "15�����͸�";
	cons.SetCoord(_x, _y + 15);
	cout << "16������";
	cons.SetCoord(_x, _y + 17);
	cout << "��Ų�ѯ��";
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
		cout << "û�иý�ɫ!!";
	}
}
