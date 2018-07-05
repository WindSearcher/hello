#include"stdafx.h"
#include"Map3.h"

/*
�������꣺17,8  7,10  9,15  25,8  27,1  39,3  31,13  35,6  39,15
�������꣺41,10
Կ�����꣺5,1
*/
void Map3::MapPart(Hero &hero)
{
	Hero Kat = hero;
	_iY = 1;
	int map1[Y][X] = {
		{ 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 3, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 3, 1 },
		{ 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1 },
		{ 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 3, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 3, 1, 1, 1, 3, 0, 0, 0, 1, 1, 1, 0, 1 },
		{ 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1 },
		{ 0, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 4 },
		{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1 },
		{ 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 3, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1 },
		{ 1, 1, 1, 1, 3, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 3, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};
	con.SetColor("0D");
	for (int i = 0; i < Y; i++)
	{
		con.SetCoord(1, _iY);
		for (int j = 0; j < X; j++)
		{
			if (map1[i][j] == 0)
			{
				cout << "  ";
			}
			if (map1[i][j] == 1)
			{
				cout << "��"; //���������ѡ�������
			}
			if (map1[i][j] == 2||map1[i][j] == 3)
			{
				cout << "??";
			}
			if (map1[i][j] == 4)
			{
				cout << "��";
			}
		}
		_iY++;
	}
	MapPart3(map1, Kat);
}

void Map3::MapPart2(Hero &Kat)
{
	int map2[Y][X] = {
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 4, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 4, 0, 0, 0, 4, 0, 0, 4, 1 },
		{ 1, 0, 0, 0, 6, 0, 0, 0, 0, 4, 0, 4, 5, 4, 0, 4, 5, 4, 0, 4, 1 },
		{ 1, 0, 0, 0, 3, 0, 0, 0, 0, 4, 0, 4, 5, 4, 0, 4, 5, 4, 0, 4, 1 },
		{ 1, 0, 6, 3, 5, 3, 6, 0, 0, 4, 0, 0, 4, 0, 0, 0, 4, 0, 0, 4, 1 },
		{ 1, 0, 0, 0, 3, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1 },
		{ 1, 0, 0, 0, 6, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 1 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 2, 0, 2, 0, 1 },
		{ 1, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 0, 2, 0, 0, 0, 2, 0, 4, 0, 1 },
		{ 1, 0, 0, 4, 2, 4, 0, 0, 0, 0, 0, 4, 0, 2, 0, 2, 0, 4, 0, 0, 1 },
		{ 1, 0, 2, 0, 2, 0, 2, 0, 0, 0, 0, 4, 0, 2, 0, 2, 0, 4, 0, 0, 1 },
		{ 1, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 4, 0, 2, 0, 2, 0, 4, 0, 0, 1 },
		{ 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 1 },
		{ 1, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};
	for (int k = 0; k < 10; k++)
	{
		Sleep(500);
		_iY = 1;
		for (int i = 0; i < Y; i++)
		{
			con.SetCoord(44, _iY);
			for (int j = 0; j < X; j++)
			{
				if (i == 9 && (k % 2 == 0))
				{
					i++;
				}
				if (map2[i][j] == 0)
				{
					cout << "  ";
				}
				if (map2[i][j] == 1)
				{
					cout << "��";   //�������ѡ���
				}
				if (map2[i][j] == 2)
				{
					cout << "��";
				}
				if (map2[i][j] == 4)
				{
					cout << "��";
				}
				if (k >= 6)
				{
					if (map2[i][j] == 3)
					{
						cout << "��";
					}
					if (map2[i][j] == 5)
					{
						cout << "��";
					}
					if (map2[i][j] == 6)
					{
						cout << "��";
					}
				}
				else
				{
					if (map2[i][j] == 3 || map2[i][j] == 5 || map2[i][j] == 6)
					{
						cout << "  ";
					}
				}
			}
			_iY++;
		}
		if (k == 6)
		{
			con.SetColor("C0");
			Sleep(1000);
		}
	}
	Sleep(1000);
	con.SetColor("07");
	con.SetCoord(1, 19);
	cout << "  [��ӭ��������С���ȥ�Ĺ���,���������Ѿ�����ħռ���ˣ����С��Ŷ@q@]";
	Kat.i_Hp = Kat.BasicHp;
	Monster Boss;	
	Boss.PersonInitual(3, 0, 0);
	Kat.Fighting(Boss);
}

void Map3::MapPart3(int map1[Y][X], Hero &Kat)
{                                   //����ͼ����1Ϊ8����Ѫ�� ����2Ϊ9��ҹ����
	                               // ����3Ϊ10���ڻ�Сǿ BossΪ3���ű���ħ
	bool key = false ;
	Monster monster1;
	monster1.PersonInitual(8, 0, 0);
	Monster monster2;
	monster2.PersonInitual(9, 0, 0);
	Monster monster3;
	monster3.PersonInitual(10, 0, 0);
	//�����������ɫ����任��ʽ��m_iX=2*_y+1 ,m_iY=_x+1
	Kat.SetPos(15, 18);
	con.SetCoord(5, Tip);
	cout<<"�������˹ű����С���飺���߰����ű������ſ��µĶ�ħ���޾��ĺڰ��������Ҫ���ǹ�ģ�����";
	Sleep(500);
	con.SetCoord(Kat.m_iX, Kat.m_iY);
	cout << "��";
	Sleep(500);
	con.SetCoord(Kat.m_iX, Kat.m_iY);
	cout << "��";
	Sleep(500);
	con.SetCoord(Kat.m_iX, Kat.m_iY);
	cout << "��";
	Sleep(500);
	con.SetCoord(Kat.m_iX, Kat.m_iY);
	cout << "��";
	Sleep(500);
	con.SetCoord(Kat.m_iX, Kat.m_iY);
	cout << "��";
	con.SetCoord(1, Tip+1);
	cout<<"������С�����͵��ǹ��";
	//music.Play();
	//Kat.Dead==false
	//system("pause");
	while (Kat.Dead!=true)
	{
		Kat.Move();
		con.SetCoord(30, 25);
		cout << Kat.m_iX << "," << Kat.m_iY << "  ";//��ʾ��ɫ����
		if (map1[Kat.m_iY - 1][(Kat.m_iX - 1) / 2] == 1)//��ǰ����ǽ��1��ǰ����λ������ص�֮ǰ������
		{

			con.SetCoord(Kat.m_iX, Kat.m_iY);
			cout << "��";
			Kat.m_iX = Kat.F_iX;
			Kat.m_iY = Kat.F_iY;
			con.SetCoord(Kat.m_iX, Kat.m_iY);
			cout << "��";
		}
		if (map1[Kat.m_iY - 1][(Kat.m_iX - 1) / 2] == 3)//��ǰ����3����ʾ�й������ս��
		{
			if ((Kat.m_iX == 17 && Kat.m_iY == 8) || (Kat.m_iX == 7 && Kat.m_iY == 10) || (Kat.m_iX == 39 && Kat.m_iY == 15))
			{
				Kat.Fighting(monster1);
			}
			if ((Kat.m_iX == 9 && Kat.m_iY == 15) || (Kat.m_iX == 25 && Kat.m_iY == 8) || (Kat.m_iX == 27 && Kat.m_iY == 1))
			{
				Kat.Fighting(monster2);
			}
			if ((Kat.m_iX == 39 && Kat.m_iY == 3) || (Kat.m_iX == 31 && Kat.m_iY == 13) || (Kat.m_iX == 35 && Kat.m_iY == 6))
			{
				Kat.Fighting(monster3);
			}
		}
		if (map1[Kat.m_iY - 1][(Kat.m_iX - 1) / 2] == 2)//��ǰ����2����ʾ�õ�Կ��
		{
			con.SetCoord(1, Tip);
			cout << "[��ù���Կ�ף�]";
			key = true;
		}
		if (key == true&&Kat.m_iX == 41 && Kat.m_iY == 10)
		{
			con.SetCoord(1, Tip);
			cout << "[��ȷ��ʵ���㹻ǰ������?(y/��ͷ n/���ˣ��ٶ�ˢ���)]";
			char ch;
			ch = _getch();
			if (ch == 'y' || ch == 'Y')
			{
				key = false;
				MapPart2(Kat);
				if (Kat.Dead != true)
				{
					con.SetCoord(1, Tip + 1);
					cout << "  [ð�ճɹ�����������Ϣ��!]";
					system("pause");
				}
				break;
			}
			else if (ch == 'N' || ch == 'n')
			{
				con.SetCoord(Kat.m_iX, Kat.m_iY);
				cout << "��";
				Kat.m_iX = Kat.F_iX;
				Kat.m_iY = Kat.F_iY;
				con.SetCoord(Kat.m_iX, Kat.m_iY);
				cout << "��";
			}
		}
		if (key != true && Kat.m_iX == 41 && Kat.m_iY == 10)
		{
			con.SetCoord(1, Tip);
			cout << "[�򿪹��������ҪԿ��!]";
			con.SetCoord(Kat.m_iX, Kat.m_iY);
			cout << "��";
			Kat.m_iX = Kat.F_iX;
			Kat.m_iY = Kat.F_iY;
			con.SetCoord(Kat.m_iX, Kat.m_iY);
			cout << "��";
		}
	}
	//system("pause");
}

//void Map3::MapPart4(int map1[Y][X], Hero &Kat)
//{                                   
//	Monster monster1;
//	monster1.PersonInitual(4, 0, 0);
//	Monster monster2;
//	monster2.PersonInitual(5, 0, 0);
//	Monster monster3;
//	monster3.PersonInitual(4, 0, 0);
//	if ((Kat.m_iX == 17 && Kat.m_iY == 8) || (Kat.m_iX == 7 && Kat.m_iY == 10) || (Kat.m_iX == 39 && Kat.m_iY == 15))
//	{
//		Kat.Fighting(monster1);
//	}
//	if ((Kat.m_iX == 9 && Kat.m_iY == 15) || (Kat.m_iX == 25 && Kat.m_iY == 8) || (Kat.m_iX == 27 && Kat.m_iY == 1))
//	{
//		Kat.Fighting(monster2);
//	}
//	if ((Kat.m_iX == 39 && Kat.m_iY == 3) || (Kat.m_iX == 31 && Kat.m_iY == 13) || (Kat.m_iX == 35 && Kat.m_iY == 6))
//	{
//		Kat.Fighting(monster3);
//	}
//���ܵĹ���ĵص���֨w���ţ���ʾ�Ѿ�����������ﻹ��
//	con.SetCoord(Kat.m_iX, Kat.m_iY);
//	cout << "�w";
//	Kat.m_iX = Kat.F_iX;
//	Kat.m_iY = Kat.F_iY;
//	con.SetCoord(Kat.m_iX, Kat.m_iY);
//	cout << "��";
//}