#ifndef MAP3_H
#define MAP3_H
#include"Hero.h"
#include"Monster.h"
#include"CMusic.h"

#define Y 18
#define X 21

class Map3
{
public:	 
	int _iY;
	void MapPart(Hero &hero);
	void MapPart2(Hero &Kat);
	void MapPart3(int map1[Y][X], Hero &Kat);
	//void MapPart4(int map1[Y][X], Hero &Kat);
	CConsole con;
	CMusic music;
};

#endif
