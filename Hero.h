#ifndef  HERO_H
#define HERO_H

#include"Character.h"
#include"Monster.h"
#include<conio.h>

class Hero:public Character
{
	
public:
	virtual void PersonInitual(int type, int _x, int _y);//Ӣ�۳�ʼ��
	//Ӣ�������� type��1��ħ�� 2������ 3�������� 
	virtual void BeHit(int hurt);//��������˺����㷽ʽ����ﲻͬ����Ҫ���Ϸ���ֵ
	virtual void GainExp(int _exp);//��þ���
	virtual void GainMoney(int _money);//��ý��
	virtual void Upgrade();//����
	virtual void Move();//�����ƶ�
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
  
	int BasicHp;//��ǰ�����Ѫ�������ܹ���Ӱ�죬��������
};

#endif
