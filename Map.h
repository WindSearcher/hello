#ifndef MAP2_H
#define MAP2_H
#include<iostream>
#include<cstdio>
#include<conio.h>
#include<vector>
#include<string>

#include "Hero.h"
#include "Monster.h"
#include "CConsole.h"
#include"File.h"
#define MapHeight 40
#define MapWidth 20
#include<cstring>
using namespace std;

class Map
{ 
   private:
	   CConsole c;
	 
   public:
	   char* WALLCHAR ;		// ˫�ַ�
       char* SPACECHAR ;		// ˫�ַ�
       char* MONSTER1 ;		// ˫�ַ�
       char* MONSTER2 ;		// ˫�ַ�
       char* MONSTER3 ;		// ˫�ַ�
       char* MONSTER4 ;		// ˫�ַ�
	   char* BOX ;		// ˫�ַ�
	   static char* CHART[24][51];
	   char* wall ;
	   Map(){
		 WALLCHAR = "��";		// ˫�ַ�
         SPACECHAR = "  ";		// ˫�ַ�
         MONSTER1 = "��";		// ˫�ַ�
         MONSTER2 = "��";		// ˫�ַ�
         MONSTER3 = "��";		// ˫�ַ�
         MONSTER4 = "��";		// ˫�ַ�
	     BOX = "��";		// ˫�ַ�
		 win = false;
	   }
	  void make_map2();
	  bool win;
      void make_map1();   
	  void print();
	  void Fight_map1(Hero &h,File &f);
	  void Fight_map2(Hero &h,File &f);
	  //��ͼ��Ϣ
	  void Map2_Inc();
};

#endif MAP2_H