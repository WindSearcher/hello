#ifndef SCREEN_H
#define SCREEN_H


#include "CConsole.h"
#include "Hero.h"
#include"Map3.h"
#include"Map.h"
#include "File.h"
#include <iostream>
#include <string>


using namespace std;

class Screen {
public:
	//�Ŷӽ���
	void TeamIntroduction();
	//�߽�
	void Boundary();
	//������
	void proc();
	//��ɫ����
	void AddRole();
	//��峤�Ի�
	void Dialogue();
	//��������
	void again();
	//��Ϸ��ʼ������
	void Initial();
	//����
	void MainCity();
	//���ִ�
	void  NoviceVillage();
	//��Ϸ����
	void GameIntroduction();
	//�˳�����
	void End();
	//��ͼ�ָ�
	void Map_Division();
	//��ʼ����
	void Start();
	//����ͼ
	void Cut_Picture(string name);
	//��Ϸ״̬
	void GameState();
	//ѡ�����
	void List(int _x, int _y);
private:
    Map3 map3;
	Map map;
	Hero hero;
	CConsole cconsole;
	File file;
	//CountMoney c;
};
#endif // !SCREEN_H

