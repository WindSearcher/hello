#include"stdafx.h"
#include"Monster.h"

void Monster::PersonInitual(int type, int _x, int _y)
{
	Dead = false;
	i_Def = 0;
	i_Level = 0;
	str_Race = "0";
	str_Sex = "0";
	m_iX = _x;
	m_iY = _y;
	SetCoord(m_iX, m_iY);
	switch (type)
	{
	case 1:
		str_Name = "�޳���";
		i_Hp = 300;
		i_Atk = 30;
		i_Money = 100;
		i_Exp = 80;
		break;
	case 2:
		str_Name = "�������";
		i_Hp = 600;
		i_Atk = 25;
		i_Money = 250;
		i_Exp = 100;
		break;
	case 3:
		str_Name = "�ű���ħ";
		i_Hp = 800;
		i_Atk = 60;
		i_Money = 400;
		i_Exp = 200;
		break;
	case 4:
		str_Name = "Ϻ��";
		i_Hp = 80;
		i_Atk = 6;
		i_Money = 20;
		i_Exp = 20;
		break;
	case 5:
		str_Name = "з��";
		i_Hp = 85;
		i_Atk = 10;
		i_Money = 30;
		i_Exp = 30;
		break;
	case 6:
		str_Name = "������";
		i_Hp = 90;
		i_Atk = 15;
		i_Money = 40;
		i_Exp = 40;
		break;
	case 7:
		str_Name = "����Ⱥ";
		i_Hp = 100;
		i_Atk = 12;
		i_Money = 40;
		i_Exp = 40;
		break;
	case 8:
		str_Name = "��Ѫ��";
		i_Hp = 120;
		i_Atk = 20;
		i_Money = 60;
		i_Exp = 60;
		break;
	case 9:
		str_Name = "ҹ����";
		i_Hp = 200;
		i_Atk = 18;
		i_Money = 80;
		i_Exp = 80;
		break;
	case 10:
		str_Name = "�ڻ�Сǿ";
		i_Hp = 1000;
		i_Atk = 50;
		i_Money = 400;
		i_Exp = 400;
		break;
	case 11:
		str_Name = "������";
		i_Hp = 100;
		i_Atk = 100;
		i_Money = 100;
		i_Exp = 100;
		break;
	case 12:
		str_Name = "���͸�";
		i_Hp = 100;
		i_Atk = 100;
		i_Money = 100;
		i_Exp = 100;
		break;
	case 13:
		str_Name = "����";
		i_Hp = 0;
		i_Atk = 0;
		i_Money = 100;
		i_Exp = 100;
		break;
	}
}

void Monster::monsterStatus(int Number, int _x, int _y)//����������ϣ�_x��_yΪ��ȷ�����λ��
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, 10);
	if (Number ==  4)
	{
		PersonInitual(1, 0, 0);
	}
	if (Number ==  5)
	{
		PersonInitual(2, 0, 0);
	}
	if (Number ==  6)
	{
		PersonInitual(3, 0, 0);
	}
	if (Number == 7)
	{
		PersonInitual(4, 0, 0);
	}
	if (Number ==  8)
	{
		PersonInitual(5, 0, 0);
	}
	if (Number ==  9)
	{
		PersonInitual(6, 0, 0);
	}
	if (Number ==  10)
	{
		PersonInitual(7, 0, 0);
	}
	if (Number ==  11)
	{
		PersonInitual(8, 0, 0);
	}
	if (Number ==  12)
	{
		PersonInitual(9, 0, 0);
	}
	if (Number ==  13)
	{
		PersonInitual(10, 0, 0);
	}
	if (Number ==  14)
	{
		PersonInitual(11, 0, 0);
	}
	if (Number ==  15)
	{
		PersonInitual(12, 0, 0);
	}
	if (Number ==  16)
	{
		PersonInitual(13, 0, 0);
	}
	SetCoord(_x, _y);
	cout <<  "[����]" << str_Name;
	if (Number == 4 || Number == 5 || Number == 6)
	{
		cout << "(boss)";
	}
	SetCoord(_x, _y + 2);
	cout << "[Ѫ��] hp: " << i_Hp;
	SetCoord(_x, _y + 4);
	cout << "[������] atk: " << i_Atk;
	SetCoord(_x, _y + 6);
	cout << "���ܻ�þ��飺 " << i_Exp;
	SetCoord(_x, _y + 8);
	cout << "���ܻ�ý�ң� " << i_Money;
	SetCoord(_x, _y + 10);
	cout << "�ֲ�������";
	if (Number == 4 || Number == 7 || Number == 8)
	{
		cout << "����1";
	}
	else if (Number == 6 || Number == 9 || Number == 10)
	{
		cout << "����2";
	}
	else if (Number == 7 || Number == 11 || Number == 12)
	{
		cout << "����3";
	}
	else
	{
		cout << "����ֲ�";
	}
	system("pause");
	SetCoord(35, 22);
	//SetConsoleTextAttribute(hOut, 9 + rand() % 3 + 1);
	cout << "\t\t���������������";
	getchar();
}
