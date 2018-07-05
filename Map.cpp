
#include"stdafx.h"
#include"Map.h"
#include"Screen.h"
char* Map::CHART[24][51] = {"0"};
//char* Map::map[MapWidth][MapHeight] = {"0"};
//第一张地图

void Map::make_map1()
{
   int i = 0,j = 0; 
   c.SetCoord(0,0);
   for ( i = 0; i < MapWidth; i++)
	{
		for (int j = 0; j < MapHeight; j++)
		{
			CHART[i][j] = WALLCHAR;
		}
	}

   for(i = 0;i < MapWidth;++i)
   {
	   for(j = 0;j <= MapHeight ;++j)
	   {
           if( (i == 2 && (j >= 14 && j <= 36))
			   || (i == 3 &&(j >= 11 && j <= 14))
			   || ( (i == 4 || i == 5 ) && j == 11)
			   || (2 < i && i<=5 && (j == 14 || j == 36))
			   || (i == 5 &&(j >= 14 && j <= 25) )
			   || (i == 5 &&(j >= 36))
			   || (i > 5 && i <= 17 && j == 25 || j == 36)
			   || (i == 11 && j >= 8 && j <= 25)
			   || (i >= 11 && j == 8)
			   || (i == 17 && j >= 25 && j <= 36) 
			   || (i == 13 && j >= 31 && j <= 35)
			   || (i == 16 && j >= 9 && j <= 14)
			   || (j == 14 && i >=12 && i <= 16))
		   {
                  CHART[i][j] = SPACECHAR;   
		   }
		   if( (i == 16 && j == 31) 
			   
			   || (i == 13 && j == 8)
			   || (i == 5 && j == 11))
		   {
			      CHART[i][j] = MONSTER1;
		   }

		  if( (i == 11 && j == 10)
			  || (i == 9 && j == 25)
			  || (i == 17 && j == 27))
		  {
                 CHART[i][j] = MONSTER2;
		  }

		  if( (i == 2 && j== 20)
			  || (i == 5 && j == 24)
			  || (i == 2 && j == 30))
		  {
		         CHART[i][j] = MONSTER3;
		  }

		  if( (i == 8 && j == 35)
			  || (i == 17 && j == 36)
			  || (i == 12 && j == 31))
		  {
		        CHART[i][j] = MONSTER4;
		  }

		  if( i == 5 && j == 14)
		  {
		        CHART[i][j] = "♂";
		  }
               
	   } 
   }
 
   print();
   //Map2_Inc();
}


void Map::make_map2()
{
	//c.SetColor("0B");
	c.SetCoord(0,0);
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
	//Map2_Inc();
}


//地图打印
void Map::print()
{
	int i ,j ;
	for( i = 0;i < MapWidth;++i)
   {
	   for(j = 0;j < MapHeight;++j)
	   {
	       printf("%s",CHART[i][j]);
	   }
	   printf("\n");
   }
}


void Map::Fight_map1(Hero &h,File &f)
{
	Screen s;
    Monster m1;
	m1.PersonInitual(6, 0, 0);
	Monster m2;
	m2.PersonInitual(7, 0, 0);
	Monster m3;
	m3.PersonInitual(8, 0, 0);
	Monster m4;
	m4.PersonInitual(9, 0, 0);
	if ( strcmp(CHART[h.m_iY][h.m_iX/2] , MONSTER1) == 0 ){
		h.Fighting(m1);
		CHART[h.m_iY][h.m_iX/2] = SPACECHAR;
	
	}

	else if ( strcmp(CHART[h.m_iY][h.m_iX/2] , MONSTER2) == 0)
	{
		h.Fighting(m2);
        CHART[h.m_iY][h.m_iX/2] = SPACECHAR;
		
		
	}

	else if (strcmp(CHART[h.m_iY][h.m_iX/2] , MONSTER3) == 0) {
		h.Fighting(m3);
		CHART[h.m_iY][h.m_iX/2] = SPACECHAR;
		

	}

	else if (strcmp(CHART[h.m_iY][h.m_iX/2] , MONSTER4) == 0){
          h.Fighting(m4);
          CHART[h.m_iY][h.m_iX/2] = SPACECHAR;

	}

	else if (strcmp(CHART[h.m_iY][h.m_iX/2] , "♂") == 0) {
		system("cls");
		c.SetCoord(35, 13);
		cout << "恭喜少侠，通关本副本！！！";
		win = true;
		Sleep(2000);
		//.writeToFile(h);
		//s.again();
		
	}
}


void Map::Fight_map2(Hero &h,File &f) {
	Screen s;
	Monster m1;
	m1.PersonInitual(6, 0, 0);
	Monster m2;
	m2.PersonInitual(7, 0, 0);
	Monster m3;
	m3.PersonInitual(8, 0, 0);
	Monster m4;
	m4.PersonInitual(9, 0, 0);
	Monster m5;
	m5.PersonInitual(13, 0, 0);
	if (strcmp(CHART[h.m_iY][h.m_iX/2] , MONSTER1) == 0) {
		h.Fighting(m1);
	    CHART[h.m_iY][h.m_iX/2] = SPACECHAR;
	}

	else if (strcmp(CHART[h.m_iY][h.m_iX/2] , MONSTER2) == 0)
	{
		h.Fighting(m2);
        CHART[h.m_iY][h.m_iX/2] = SPACECHAR;
	}

	else if (strcmp(CHART[h.m_iY][h.m_iX/2] , MONSTER3) == 0) {
		h.Fighting(m3);
		CHART[h.m_iY][h.m_iX/2] = SPACECHAR;
	}
	else if (strcmp(CHART[h.m_iY][h.m_iX/2] , MONSTER4) == 0) {
		h.Fighting(m4);
		CHART[h.m_iY][h.m_iX/2] = SPACECHAR;
	}

	else if ((h.m_iX == 5 && h.m_iY == 16)
		|| (h.m_iX == 34 && h.m_iY == 3)
		|| (h.m_iX == 3 && h.m_iY == 17)) {
		h.Fighting(m5);
		CHART[h.m_iY][h.m_iX / 2] = SPACECHAR;
	}

	else if (h.m_iX == 62 && h.m_iY == 8) {
		c.SetCoord(35, 13);
		cout << "恭喜少侠，通关本副本！！！";
		win  =  true;
		Sleep(2000);
		//f.writeToFile(h);
		//s.again();
	}
}

//地图信息
void Map::Map2_Inc() {

	c.SetCoord(90, 2);
	cout << "怪物1：★  xxx怪";
	c.SetCoord(90, 4);
	cout << "怪物2：◎  xxx怪";
	c.SetCoord(90, 6);
	cout << "怪物3：◆  xxx怪";
	c.SetCoord(90, 8);
	cout << "怪物4：☉  xxx怪";
	c.SetCoord(90, 10);
	cout << "宝箱 ：☆   高级宝箱";
}

