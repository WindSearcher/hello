#include "stdafx.h"
#include"Character.h"



#include"Character.h"

void Character::BeHit(int hurt)
{
	i_Hp = i_Hp - hurt;
}
int Character::Hit()
{
	return i_Atk;
}
void Character::IsDead()
{
	if (i_Hp <= 0)
	{
		SetCoord(44, 28);
		cout << str_Name << "[��Ķ���]\n";
		Dead = true;
	}
}

void Character::Gothrough()
{
	SetCoord(35, 5);
	cout << "���ƣ�" << str_Name<<"                      " ;
	SetCoord(35, 6);
	cout<< "���壺" << str_Race<<"                      " ;
	SetCoord(35, 7);
	cout<< "�Ա�" << str_Sex<<"                      " ;
	SetCoord(35, 8);
	cout<< "��������" << i_Atk<<"                      " ;
	SetCoord(35, 9);
	cout<< "����ֵ��" << i_Hp<<"                      " ; 
	SetCoord(35, 10);
	cout<< "����ֵ��" << i_Exp<<"                      " ;
	SetCoord(35, 11);
	cout<< "��ң�" << i_Money<<"                      " ;
	SetCoord(35, 12);
	cout<< "��������" << i_Def<<"                      " ;
	SetCoord(35, 13);
	cout<< "�ȼ���" << i_Level<<"                      " ;
}
