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
	string str_Name;//姓名
	int i_Hp;//血量
	int i_Def;//防御力
	int i_Atk;//攻击力
	int i_Money;//金钱数
	int i_Exp;//经验值
	int i_Level;//等级
	string str_Race;//种族
	string str_Sex;//性别
	bool Dead;//死亡与否	
	int F_iX, F_iY;//角色之前的坐标
	int m_iX, m_iY;//角色现在的坐标
	int x,y;
	int i_Type;
public:
	string GetName() { return str_Name; }//姓名
	int GetHp() { return i_Hp; }//血量
	int GetDef() { return i_Def; }//防御力
	int GetAtk() { return i_Atk; }//攻击力
	int GetMoney() { return i_Money; }//金钱数
	int GetExp() { return i_Exp; }//经验值
	int GetLevel() { return i_Level; }//等级
	string GetRace() { return str_Race; }//种族
	string GetSex() { return str_Sex; }//性别
	int GetType() { return i_Type; }

	void SetName(string _name) { str_Name = _name; }//姓名
	void SetHp(int _hp) { i_Hp = _hp; }//血量
	void SetDefv(int _def) { i_Def = _def; }//防御力
	void SetAtk(int _atk) { i_Atk = _atk; }//攻击力
	void SetMoney(int _money) { i_Money = _money; }//金钱数
	void SetExp(int _exp) { i_Exp = _exp; }//经验值
	void SetLevel(int _level) { i_Level = _level; }//等级
	void SetRace(int _race) { str_Race = _race; }//种族
	void SetSex(int _sex) { str_Sex = _sex; }//性别
	void SetType(int _type) { i_Type = _type; }


	
public:
	int Hit();//攻击
	virtual void BeHit(int hurt);//受伤害
	void IsDead();//判断是否死亡
	void Gothrough();

	virtual void PersonInitual(int type,int _x,int _y) = 0;//人物、怪物初始化
	virtual void GainExp(int _exp) = 0;//获得经验
	virtual void GainMoney(int _money) = 0;//获得金币
	virtual void Upgrade() = 0;//升级
	virtual void Move() = 0;//人物移动

};


#endif
