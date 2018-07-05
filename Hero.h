#ifndef  HERO_H
#define HERO_H

#include"Character.h"
#include"Monster.h"
#include<conio.h>

class Hero:public Character
{
	
public:
	virtual void PersonInitual(int type, int _x, int _y);//英雄初始化
	//英雄种族编号 type：1、魔族 2、人族 3、精灵族 
	virtual void BeHit(int hurt);//对人物的伤害计算方式与怪物不同，还要加上防御值
	virtual void GainExp(int _exp);//获得经验
	virtual void GainMoney(int _money);//获得金币
	virtual void Upgrade();//升级
	virtual void Move();//人物移动
	void DoubleMove();
	void GoldenFinger(string password);
	//Map2 map2;
	void Fighting(Monster &mon);
	void SetPos(int ,int );
	void HeroStatus(int Number, int _x, int _y);
	void Initial(){
	   Dead = false;
	   i_Hp = BasicHp;
	}
    Hero(){
		str_Name = "0";
	    str_Sex = "0";
	}
  
	int BasicHp;//当前级别的血量，不受攻击影响，用于升级
};

#endif
