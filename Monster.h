#ifndef MONSTER_H
#define MONSTER_H
#include"Character.h"

class Monster :public Character
{
public:
	virtual void PersonInitual(int type, int _x, int _y);//�����ʼ��

	//������ type :1���޳��� 2��������� 3���ű���ħ 4��Ϻ�� 5��з�� 6�������� 7������Ⱥ
	              //8����Ѫ�� 9��ҹ���� 10���ڻ�Сǿ 11�������� 12�����͸�

	virtual void GainExp(int _exp){};//��þ���
	virtual void GainMoney(int _money){};//��ý��
	virtual void Upgrade(){};//����
	virtual void Move(){};//�����ƶ�
	void monsterStatus(int Number, int _x, int _y);
	
};

#endif
