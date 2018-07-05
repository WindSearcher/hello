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
	//团队介绍
	void TeamIntroduction();
	//边界
	void Boundary();
	//进度条
	void proc();
	//角色生成
	void AddRole();
	//与村长对话
	void Dialogue();
	//返回主城
	void again();
	//游戏初始化界面
	void Initial();
	//主城
	void MainCity();
	//新手村
	void  NoviceVillage();
	//游戏介绍
	void GameIntroduction();
	//退出程序
	void End();
	//地图分割
	void Map_Division();
	//开始动画
	void Start();
	//过场图
	void Cut_Picture(string name);
	//游戏状态
	void GameState();
	//选择怪物
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

