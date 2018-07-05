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
#define MapHeight 40
#define MapWidth 20
using namespace std;

class Map2
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
	   Map2(){
		 WALLCHAR = "��";		// ˫�ַ�
         SPACECHAR = "  ";		// ˫�ַ�
         MONSTER1 = "��";		// ˫�ַ�
         MONSTER2 = "��";		// ˫�ַ�
         MONSTER3 = "��";		// ˫�ַ�
         MONSTER4 = "��";		// ˫�ַ�
	     BOX = "��";		// ˫�ַ�
	   }
	  void make_map2();
      void make_map1();   
	  void print();
	  void Fight_map2(Hero &h);
	  //��ͼ��Ϣ
	  void Map2_Inc();
};

#endif MAP2_H