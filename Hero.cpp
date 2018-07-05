
#include"stdafx.h"
#include"Hero.h"
#include"Map.h"


void Hero::SetPos(int _x, int _y)
{
	m_iX = _x;
	m_iY = _y;
	x = m_iX / 2;
	y = m_iY;
	SetCoord(m_iX, m_iY);
	cout << "��";
}

void Hero::PersonInitual(int type, int _x, int _y)//Ӣ�۳�ʼ��
{
	Dead = false;
	i_Type = type;
	i_Level = 1;
	i_Money = 0;
	i_Exp = 0;
	switch (type)
	{
	case 1:
		str_Race = "ħ��";
		BasicHp = 200;
		i_Hp = 100;
		i_Atk = 30;
		i_Def = 2;
		break;
	case 2:
		str_Race = "����";
		BasicHp = 170;
		i_Hp = 85;
		i_Atk = 20;
		i_Def = 3;
		break;
	case 3:
		str_Race = "������";
		BasicHp = 140;
		i_Hp = 70;
		i_Atk = 40;
		i_Def = 2;
		break;
	}
}

void Hero::BeHit(int hurt)
{
	if (i_Def < hurt)
	{
		i_Hp = i_Hp + i_Def - hurt;//��ΪӢ�۾��з�����
	}
}

void Hero::GainExp(int _exp)//��þ���
{
	i_Exp = i_Exp + _exp;
	Upgrade();
}

void Hero::GainMoney(int _money)//��ý��
{
	i_Money = i_Money + _money;
}

void Hero::Upgrade()//����
{
	int FullExp = (20 * i_Level) + 40;
	if (i_Exp >= FullExp)
	{
		i_Exp -= (20 * i_Level) + 40;
		i_Level++;
		if (str_Race == "ħ��")
		{
			i_Hp = BasicHp + 16;
			i_Def = i_Def + 1;
			i_Atk = i_Atk + 5;
		}
		if (str_Race == "����")
		{
			i_Hp = BasicHp + 12;
			i_Def = i_Def + 2;
			i_Atk = i_Atk + 6;
		}
		if (str_Race == "������")
		{
			i_Hp = BasicHp + 10;
			i_Def = i_Def + 1;
			i_Atk = i_Atk + 8;
		}
	}
}

void Hero::DoubleMove()
{
	Map map;
	char direction = '0';
	int tx, ty;
	int mx, my;
	if (_kbhit())//!!
	{
		SetCoord(m_iX, m_iY);
		tx = m_iX, ty = m_iY;
		mx = x, my = y;
		cout << "  ";
		direction = _getch();//!!
		switch (direction)
		{
		case 'a':
			m_iX -= 2;
			x--;
			break;
		case 'd':
			m_iX += 2;
			x++;
			break;
		case 'w':
			m_iY -= 1;
			y--;
			break;
		case 's':
			m_iY += 1;
			y++;
			break;
		default:
			break;
		}
		/*if(strcmp(map.CHART[y][x], "��") == 0)
		{
		cout << "yyyy";
		}*/

		if (m_iX < 0 || m_iX == MapHeight * 2 || m_iY < 0 || m_iY == MapWidth)
		{
			m_iX = tx;
			m_iY = ty;
			x = mx;
			y = my;
		}
		if (strcmp(map.CHART[y][x], map.WALLCHAR) == 0)
		{
			m_iX = tx;
			m_iY = ty;
			x = mx;
			y = my;
		}


		SetCoord(m_iX, m_iY);
		cout << "��";
	}

}

//������ƶ�����a��m_iX--����ʾ����һ��;��d��m_iX++,��ʾ����һ��
void Hero::Move()   //��w��m_iY--����ʾ����һ�񣻰�s��m_iY++����ʾ����һ��
{
	char direction = '0';
	if (_kbhit())//!!
	{
		F_iX = m_iX;
		F_iY = m_iY;
		direction = _getch();//!!
		switch (direction)
		{
		case 'a':
			if ((m_iX - 2)>0)
			{
				m_iX -= 2;
			}
			break;
		case 'd':
			m_iX += 2;
			break;
		case 'w':
			if ((m_iY - 1)>0)
			{
				m_iY--;
			}
			break;
		case 's':
			m_iY++;
			break;
		default:
			break;
		}
		SetCoord(F_iX, F_iY);
		cout << " ";
		SetCoord(m_iX, m_iY);
		cout << "��";
	}
}

void Hero::Fighting(Monster &mon)//�����������ö��󣬿�ʼս��
{
	while (mon.Dead != true && Dead != true)//ֱ��һ��Ϊ����״ֹ̬ͣ
	{
		SetCoord(44, 22);
		cout << "ս����ʼ��!!!";
		mon.BeHit(Hit());//Hit()����Ӣ�۵Ĺ�������
		BeHit(mon.Hit());//BeHit()���㱻�������ʣ��Ѫ��
		SetCoord(44, 23);
		cout << "Ӣ��hp��" << i_Hp<<"  "<< "\t"<< mon.str_Name << ":" << mon.i_Hp << "  ";
		SetCoord(44, 24);
		int m = 0;
		m = ((10 * i_Hp) / BasicHp) + 1;
		for (int i = 0; i<m&&i<10; i++)
		{
			cout << "��";
		}
		for (int j = 0; j<(10 - m); j++)
		{
			cout << "��";
		}
		IsDead();     //�ֱ��ж���������Ƿ�����
		mon.IsDead();
		if (mon.Dead == true)
		{
			SetCoord(44, 25);
			cout << "[��þ���]��" << mon.i_Exp;
			SetCoord(60, 25);
			cout << "[��ý��]��" << mon.i_Money;
			SetCoord(44, 27);
			cout << "[��ǰ�ȼ�]��" << i_Level;
			GainExp(mon.i_Exp);
			GainMoney(mon.i_Money);
			Upgrade();
			break;
		}
		if (Dead == true)
		{
			SetCoord(44, 28);
			cout << "  [��ʧ���ˣ����������Ϣ,����ʵ��������!]";
			break;
		}
		Sleep(1000);
	}
}

void Hero::GoldenFinger(string password)
{
	SetCoord(35, 12);
	if (password == "���")
	{
		cout << "�ȵȣ����Ϸ��Ѿ��ڴ˵Ⱥ�����ˣ������ϹŵĴ���֮���ɣ�";
		Dead = false;
		i_Money = 10000;
		i_Exp = 0;
		str_Race = "����";
		BasicHp = 1000;
		i_Hp = 1000;
		i_Atk = 100;
		SetCoord(35, 14);
		cout << "���� ����  hpֵ";
		Sleep(500);
		cout << "��";
		Sleep(500);
		cout << "��";
		cout << i_Hp << " ������";
		Sleep(500);
		cout << "��";
		Sleep(500);
		cout << "��";
		cout << i_Atk;
		cout << " ���";
		Sleep(500);
		cout << "��";
		Sleep(500);
		cout << "��";
		cout << i_Money;
		SetCoord(35, 16);
	}
	else
	{
		SetCoord(35, 14);
		cout << "�Ǻǣ���λС�ֵ�˵ʲô���Ϸ����ˣ����䲻��ʹ��";
	}
}

void Hero::HeroStatus(int Number, int _x, int _y)//���Ӣ�۵����ϣ�_x��_yΪ��ȷ�����λ��
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, 14);
	if (Number == 1)
	{
		SetCoord(_x, _y);
		cout << "ħ��";
		SetCoord(_x, _y + 1);
		cout << "[Ѫ��] hp: 200  " ;
		SetCoord(_x, _y + 3);
		cout<< "ÿ���ɳ��ԣ�16";
		SetCoord(_x, _y + 5);
		cout << "[������] atk: 30" ;
		SetCoord(_x, _y + 7);
		cout<< "ÿ���ɳ��ԣ�5";
		SetCoord(_x, _y + 9);
		cout << "[������] def: 2" ;
		SetCoord(_x, _y + 11);
		cout<< "ÿ���ɳ��ԣ�1";
	}
	if (Number == 2)
	{
		SetCoord(_x, _y);
		cout << "����";
		SetCoord(_x, _y + 1);
		cout << "[Ѫ��] hp: 170  " ;
		SetCoord(_x, _y + 3);
		cout<< "ÿ���ɳ��ԣ�12";
		SetCoord(_x, _y + 5);
		cout << "[������] atk: 20" ;
		SetCoord(_x, _y + 7);
		cout<< "ÿ���ɳ��ԣ�6";
		SetCoord(_x, _y + 9);
		cout << "[������] def: 3" ;
		SetCoord(_x, _y + 11);
		cout<< "ÿ���ɳ��ԣ�2";
	}
	if (Number == 3)
	{
		SetCoord(_x, _y);
		cout << "������";
		SetCoord(_x, _y + 1);
		cout << "[Ѫ��] hp: 140  ";
		SetCoord(_x, _y + 3);
		cout<< "ÿ���ɳ��ԣ�10";
		SetCoord(_x, _y + 5);
		cout << "[������] atk: 40" ;
		SetCoord(_x, _y + 7);
		cout<< "ÿ���ɳ��ԣ�8";
		SetCoord(_x, _y + 9);
		cout << "[������] def: 2" ;
		SetCoord(_x, _y + 11);
		cout<< "ÿ���ɳ��ԣ�1";
	}
	system("pause");
	SetCoord(35, 22);
	//SetConsoleTextAttribute(hOut, 9 + rand() % 3 + 1);
	cout << "\t\t���������������";
	getchar();
}

