#ifndef CHARACTER_H
#define CHARACTER_H
#include<iostream>
#include"CConsole.h"
#include<string>

#define Tip 22
using namespace std;

class Character:public CConsole
{
public:
	string str_Name;//����
	int i_Hp;//Ѫ��
	int i_Def;//������
	int i_Atk;//������
	int i_Money;//��Ǯ��
	int i_Exp;//����ֵ
	int i_Level;//�ȼ�
	string str_Race;//����
	string str_Sex;//�Ա�
	bool Dead;//�������	
	int F_iX, F_iY;//��ɫ֮ǰ������
	int m_iX, m_iY;//��ɫ���ڵ�����
	int x,y;
	int i_Type;
public:
	string GetName() { return str_Name; }//����
	int GetHp() { return i_Hp; }//Ѫ��
	int GetDef() { return i_Def; }//������
	int GetAtk() { return i_Atk; }//������
	int GetMoney() { return i_Money; }//��Ǯ��
	int GetExp() { return i_Exp; }//����ֵ
	int GetLevel() { return i_Level; }//�ȼ�
	string GetRace() { return str_Race; }//����
	string GetSex() { return str_Sex; }//�Ա�
	int GetType() { return i_Type; }

	void SetName(string _name) { str_Name = _name; }//����
	void SetHp(int _hp) { i_Hp = _hp; }//Ѫ��
	void SetDefv(int _def) { i_Def = _def; }//������
	void SetAtk(int _atk) { i_Atk = _atk; }//������
	void SetMoney(int _money) { i_Money = _money; }//��Ǯ��
	void SetExp(int _exp) { i_Exp = _exp; }//����ֵ
	void SetLevel(int _level) { i_Level = _level; }//�ȼ�
	void SetRace(int _race) { str_Race = _race; }//����
	void SetSex(int _sex) { str_Sex = _sex; }//�Ա�
	void SetType(int _type) { i_Type = _type; }


	
public:
	int Hit();//����
	virtual void BeHit(int hurt);//���˺�
	void IsDead();//�ж��Ƿ�����
	void Gothrough();

	virtual void PersonInitual(int type,int _x,int _y) = 0;//��������ʼ��
	virtual void GainExp(int _exp) = 0;//��þ���
	virtual void GainMoney(int _money) = 0;//��ý��
	virtual void Upgrade() = 0;//����
	virtual void Move() = 0;//�����ƶ�

};


#endif
