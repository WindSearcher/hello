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
		cout << str_Name << "[落荒而逃]\n";
		Dead = true;
	}
}

void Character::Gothrough()
{
	SetCoord(35, 5);
	cout << "名称：" << str_Name<<"                      " ;
	SetCoord(35, 6);
	cout<< "种族：" << str_Race<<"                      " ;
	SetCoord(35, 7);
	cout<< "性别：" << str_Sex<<"                      " ;
	SetCoord(35, 8);
	cout<< "攻击力：" << i_Atk<<"                      " ;
	SetCoord(35, 9);
	cout<< "生命值：" << i_Hp<<"                      " ; 
	SetCoord(35, 10);
	cout<< "经验值：" << i_Exp<<"                      " ;
	SetCoord(35, 11);
	cout<< "金币：" << i_Money<<"                      " ;
	SetCoord(35, 12);
	cout<< "防御力：" << i_Def<<"                      " ;
	SetCoord(35, 13);
	cout<< "等级：" << i_Level<<"                      " ;
}
