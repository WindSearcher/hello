
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
	cout << "♀";
}

void Hero::PersonInitual(int type, int _x, int _y)//英雄初始化
{
	Dead = false;
	i_Type = type;
	i_Level = 1;
	i_Money = 0;
	i_Exp = 0;
	switch (type)
	{
	case 1:
		str_Race = "魔族";
		BasicHp = 200;
		i_Hp = 100;
		i_Atk = 30;
		i_Def = 2;
		break;
	case 2:
		str_Race = "人族";
		BasicHp = 170;
		i_Hp = 85;
		i_Atk = 20;
		i_Def = 3;
		break;
	case 3:
		str_Race = "精灵族";
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
		i_Hp = i_Hp + i_Def - hurt;//作为英雄具有防御力
	}
}

void Hero::GainExp(int _exp)//获得经验
{
	i_Exp = i_Exp + _exp;
	Upgrade();
}

void Hero::GainMoney(int _money)//获得金币
{
	i_Money = i_Money + _money;
}

void Hero::Upgrade()//升级
{
	int FullExp = (20 * i_Level) + 40;
	if (i_Exp >= FullExp)
	{
		i_Exp -= (20 * i_Level) + 40;
		i_Level++;
		if (str_Race == "魔族")
		{
			i_Hp = BasicHp + 16;
			i_Def = i_Def + 1;
			i_Atk = i_Atk + 5;
		}
		if (str_Race == "人族")
		{
			i_Hp = BasicHp + 12;
			i_Def = i_Def + 2;
			i_Atk = i_Atk + 6;
		}
		if (str_Race == "精灵族")
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
		/*if(strcmp(map.CHART[y][x], "△") == 0)
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
		cout << "♀";
	}

}

//人物的移动，按a键m_iX--，表示向左一格;按d键m_iX++,表示向右一格；
void Hero::Move()   //按w键m_iY--，表示向上一格；按s键m_iY++，表示向下一格
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
		cout << "☆";
	}
}

void Hero::Fighting(Monster &mon)//传入怪物的引用对象，开始战斗
{
	while (mon.Dead != true && Dead != true)//直到一方为死亡状态停止
	{
		SetCoord(44, 22);
		cout << "战斗开始了!!!";
		mon.BeHit(Hit());//Hit()返回英雄的攻击力，
		BeHit(mon.Hit());//BeHit()计算被攻击后的剩余血量
		SetCoord(44, 23);
		cout << "英雄hp：" << i_Hp<<"  "<< "\t"<< mon.str_Name << ":" << mon.i_Hp << "  ";
		SetCoord(44, 24);
		int m = 0;
		m = ((10 * i_Hp) / BasicHp) + 1;
		for (int i = 0; i<m&&i<10; i++)
		{
			cout << "■";
		}
		for (int j = 0; j<(10 - m); j++)
		{
			cout << "□";
		}
		IsDead();     //分别判断人物、怪物是否死亡
		mon.IsDead();
		if (mon.Dead == true)
		{
			SetCoord(44, 25);
			cout << "[获得经验]：" << mon.i_Exp;
			SetCoord(60, 25);
			cout << "[获得金币]：" << mon.i_Money;
			SetCoord(44, 27);
			cout << "[当前等级]：" << i_Level;
			GainExp(mon.i_Exp);
			GainMoney(mon.i_Money);
			Upgrade();
			break;
		}
		if (Dead == true)
		{
			SetCoord(44, 28);
			cout << "  [你失败了，快回主城休息,提升实力再来吧!]";
			break;
		}
		Sleep(1000);
	}
}

void Hero::GoldenFinger(string password)
{
	SetCoord(35, 12);
	if (password == "告辞")
	{
		cout << "等等！！老夫已经在此等候多年了，接受上古的传承之力吧！";
		Dead = false;
		i_Money = 10000;
		i_Exp = 0;
		str_Race = "神族";
		BasicHp = 1000;
		i_Hp = 1000;
		i_Atk = 100;
		SetCoord(35, 14);
		cout << "进阶 神族  hp值";
		Sleep(500);
		cout << "》";
		Sleep(500);
		cout << "》";
		cout << i_Hp << " 攻击力";
		Sleep(500);
		cout << "》";
		Sleep(500);
		cout << "》";
		cout << i_Atk;
		cout << " 金币";
		Sleep(500);
		cout << "》";
		Sleep(500);
		cout << "》";
		cout << i_Money;
		SetCoord(35, 16);
	}
	else
	{
		SetCoord(35, 14);
		cout << "呵呵，这位小兄弟说什么，老夫老了，耳朵不好使。";
	}
}

void Hero::HeroStatus(int Number, int _x, int _y)//输出英雄的资料，_x、_y为了确定输出位置
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, 14);
	if (Number == 1)
	{
		SetCoord(_x, _y);
		cout << "魔族";
		SetCoord(_x, _y + 1);
		cout << "[血量] hp: 200  " ;
		SetCoord(_x, _y + 3);
		cout<< "每级成长性：16";
		SetCoord(_x, _y + 5);
		cout << "[攻击力] atk: 30" ;
		SetCoord(_x, _y + 7);
		cout<< "每级成长性：5";
		SetCoord(_x, _y + 9);
		cout << "[防御力] def: 2" ;
		SetCoord(_x, _y + 11);
		cout<< "每级成长性：1";
	}
	if (Number == 2)
	{
		SetCoord(_x, _y);
		cout << "人族";
		SetCoord(_x, _y + 1);
		cout << "[血量] hp: 170  " ;
		SetCoord(_x, _y + 3);
		cout<< "每级成长性：12";
		SetCoord(_x, _y + 5);
		cout << "[攻击力] atk: 20" ;
		SetCoord(_x, _y + 7);
		cout<< "每级成长性：6";
		SetCoord(_x, _y + 9);
		cout << "[防御力] def: 3" ;
		SetCoord(_x, _y + 11);
		cout<< "每级成长性：2";
	}
	if (Number == 3)
	{
		SetCoord(_x, _y);
		cout << "精灵族";
		SetCoord(_x, _y + 1);
		cout << "[血量] hp: 140  ";
		SetCoord(_x, _y + 3);
		cout<< "每级成长性：10";
		SetCoord(_x, _y + 5);
		cout << "[攻击力] atk: 40" ;
		SetCoord(_x, _y + 7);
		cout<< "每级成长性：8";
		SetCoord(_x, _y + 9);
		cout << "[防御力] def: 2" ;
		SetCoord(_x, _y + 11);
		cout<< "每级成长性：1";
	}
	system("pause");
	SetCoord(35, 22);
	//SetConsoleTextAttribute(hOut, 9 + rand() % 3 + 1);
	cout << "\t\t（按任意键继续）";
	getchar();
}

