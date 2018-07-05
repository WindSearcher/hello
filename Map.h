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
	   char* WALLCHAR ;		// Ë«×Ö·û
       char* SPACECHAR ;		// Ë«×Ö·û
       char* MONSTER1 ;		// Ë«×Ö·û
       char* MONSTER2 ;		// Ë«×Ö·û
       char* MONSTER3 ;		// Ë«×Ö·û
       char* MONSTER4 ;		// Ë«×Ö·û
	   char* BOX ;		// Ë«×Ö·û
	   static char* CHART[24][51];
	   char* wall ;
	   Map(){
		 WALLCHAR = "¡ö";		// Ë«×Ö·û
         SPACECHAR = "  ";		// Ë«×Ö·û
         MONSTER1 = "¡ï";		// Ë«×Ö·û
         MONSTER2 = "¡ò";		// Ë«×Ö·û
         MONSTER3 = "¨‘";		// Ë«×Ö·û
         MONSTER4 = "¡ô";		// Ë«×Ö·û
	     BOX = "¡î";		// Ë«×Ö·û
		 win = false;
	   }
	  void make_map2();
	  bool win;
      void make_map1();   
	  void print();
	  void Fight_map1(Hero &h,File &f);
	  void Fight_map2(Hero &h,File &f);
	  //µØÍ¼ÐÅÏ¢
	  void Map2_Inc();
};

#endif MAP2_H