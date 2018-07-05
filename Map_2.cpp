
#include"stdafx.h"
#include"Map_2.h"

char* Map2::CHART[24][51] = {"0"};
//char* Map::map[MapWidth][MapHeight] = {"0"};
//第一张地图
void Map2::make_map1()
{
   int i = 0,j = 0;  
   for( ;i <= 20;++i)
   {
	   for(j = 0;j <= 50;++j)
	   {
	   	   if(i <= 4 && (j <= 10 || j >=40))
	   	   	   CHART[i][j] = SPACECHAR;  
	   	   else if(i >4 && i <= 8 && (j <= 20 || j >= 30))
	   	       CHART[i][j] = SPACECHAR;
	   	   else if(i > 8 && i <=12 && (j == 20 || j == 30))
	   	       CHART[i][j] = SPACECHAR;
	   	   else if(i == 13 && ( j >=10  && j <=20 || j >= 30 && j <= 40))
	   	       CHART[i][j] = SPACECHAR;
	   	   else if(i >13 && i <=16 && (j ==10 || j == 40))
	   	       CHART[i][j] = SPACECHAR;
	   	   else if(i == 20 && (j <= 10 || j >=40))
	   	       CHART[i][j] = SPACECHAR; 
	   	   else
	   	       CHART[i][j] = WALLCHAR;
	   } 
   }
   CHART[0][5] = "△";
   print();
}

void Map2::make_map2()
{
	//c.SetColor("0B");
	int i , j;
	for ( i = 0; i < MapWidth; i++)
	{
		for (int j = 0; j < MapHeight; j++)
		{
			//strcpy(map[i][j], "■");
			//c.SetColor("0B");
			CHART[i][j] = WALLCHAR;
		}
	}
	for ( i = 0; i < MapWidth; i++)
	{
		for ( j = 0; j < MapHeight; j++)
		{
			if ((j == 3 && i <= 17 && i >= 12)
				|| (j == 6 && (i <= 20 && i >= 14))
				|| (j == 6 && i <  13 && i >= 2)
				|| (j == 10 && i <= 12 && i >= 4)
				|| (j == 19 && i <= 16 && i >= 10)
				|| (j == 24 && i <= 15 && i >= 7)
				|| (j == 28 && i <= 12 && i >= 4)
				|| (j == 32 && i <= 8 && i >= 6)
				|| (j == 32 && i <= 4 && i >= 1)
				|| (j == 34 && i <= 17 && i >= 15)
				|| (j == 36 && i <= 15 && i >  4)
				|| (j == 36 && i <= 3 && i >= 1)
				|| (i == 1 && j <= 35 && j >= 32)
				|| (i == 3 - 1 && j <= 10 && j >= 5 + 1)
				|| (i == 5 - 1 && j <= 28 && j >= 9 + 1)
				|| (i == 8 - 1 && j <= 24 && j >= 9 + 1)
				|| (i == 8 - 1 && j <= 38 && j >= 35 + 1)
				|| (i == 11 - 1 && j <= 19 && j >= 13 + 1)
				|| (i == 13 - 1 && j <= 10 && j >= 2 + 1)
				|| (i == 13 - 1 && j <= 30 && j >= 28 + 1)
				|| (i == 16 - 1 && j <= 35 && j >= 13 + 1))
			{
				
				CHART[i][j] = SPACECHAR;
			}
		}
	}
	for ( i = 0; i < MapWidth; i++)
	{
		for ( j = 0; j < MapHeight; j++)
		{
			if ((i == 5 && j == 32)
				|| (i == 13 && j == 6)
				|| (i == 2 && j == 10)) {
				
				CHART[i][j] = MONSTER1;
			}

			else if ((i == 4 && j == 36)
				|| (i == 18 && j == 34)
				|| (i == 15 && j == 13)
				|| (i == 7 && j == 5)
				|| (i == 7 && j == 11))
			{
				
				CHART[i][j] = MONSTER2;
			}

			else if ((i == 4 && j == 17)
				|| (i == 11 && j == 14)
				|| (i == 8 && j == 25)
				|| (i == 12 && j == 31)) {
			
				CHART[i][j] = MONSTER3;
			}
			else if ((i == 13 && j == 9)
				|| (i == 8 && j == 38)
				|| (i == 16 && j == 18)
				|| (i == 16 && j == 19)
				|| (i == 15 && j == 30)) {
				
				CHART[i][j] = MONSTER4;
			}
			else if ((i == 16 && j == 2)
				|| (i == 17 && j == 18)
				|| (i == 3 && j == 17)) {
				
				CHART[i][j] = BOX;
			}
			else if (i == 8 && j == 31) {
				
				CHART[i][j] = "♂";
			}
		}
	}
	for ( i = 0; i < MapWidth; i++)
	{
		//c.SetCoord(0, i );
		for (int j = 0; j < MapHeight; j++)
		{
			printf("%s",CHART[i][j]);
			//cout << map[i][j];

		}
		printf("\n");
	}
	Map2_Inc();
}

//地图打印
void Map2::print()
{
	int i ,j ;
	for( i = 0;i <= MapWidth;++i)
   {
	   for(j = 0;j <= MapHeight;++j)
	   {
	       printf("%s",CHART[i][j]);
	   }
	   printf("\n");
   }
}

void Map2::Fight_map2(Hero &h) {
	Monster m1;
	m1.PersonInitual(6, 0, 0);
	Monster m2;
	m2.PersonInitual(7, 0, 0);
	Monster m3;
	m3.PersonInitual(8, 0, 0);
	Monster m4;
	m4.PersonInitual(9, 0, 0);
	if ((h.m_iX == 20 && h.m_iY== 2)
		|| (h.m_iX == 12 && h.m_iY == 13)
		|| (h.m_iX == 64 && h.m_iY == 5)) {
		h.Fighting(m1);
		if (h.i_Hp < 0) {
			CHART[h.y][h.x] = MONSTER1;
			Sleep(100);
		}
	}

	else if ((h.m_iX == 10 && h.m_iY == 7)
		|| (h.m_iX == 22 && h.m_iY == 7)
		|| (h.m_iX == 26 && h.m_iY == 15)
		|| (h.m_iX == 68 && h.m_iY == 18)
		|| (h.m_iX == 72 && h.m_iY == 4))
	{
		h.Fighting(m2);
	}

	else if ((h.m_iX == 62 && h.m_iY == 12)
		|| (h.m_iX == 34 && h.m_iY == 4)
		|| (h.m_iX == 50 && h.m_iY == 8)
		|| (h.m_iX == 28 && h.m_iY == 11)) {
		h.Fighting(m3);
		
	}
	else if ((h.m_iX == 18 && h.m_iY == 13)
		|| (h.m_iX == 36 && h.m_iY == 16)
		|| (h.m_iX == 38 && h.m_iY == 16)
		|| (h.m_iX == 60 && h.m_iY == 15)
		|| (h.m_iX == 76 && h.m_iY == 8)) {
		h.Fighting(m4);
	}
	else if ((h.m_iX == 5 && h.m_iY == 16)
		|| (h.m_iX == 34 && h.m_iY == 3)
		|| (h.m_iX == 3 && h.m_iY == 17)) {
		//h.Fighting(m4);
	}
	else if (h.m_iX == 8 && h.m_iY == 31) {
		//CHART[i][j] = "♂";
	}
}

//地图信息
void Map2::Map2_Inc() {
	c.SetCoord(4, 23);
	cout << "1. 请按 wasd 来控制移动";
	c.SetCoord(4, 25);
	cout << "2. 找到游戏出口即可获胜";
	c.SetCoord(4, 27);
	cout << "3. 祝您游戏愉快";
	c.SetCoord(46, 23);
	cout << "怪物1：★   xxx怪     怪物2：◎  xxx怪";
	c.SetCoord(46, 25);
	cout << "怪物3：◆   xxx怪     怪物4：☉  xxx怪";
	c.SetCoord(46, 27);
	cout << "宝箱 ：☆   高级宝箱";
}

