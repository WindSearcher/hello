#ifndef HOTEL_H
#define HOTEL_H

#pragma warning(disable : 4786)
#include<iostream>
#include<utility>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<iomanip>
#include<conio.h>
#include"CConsole.h"
using namespace std;


class Hotel
{
private:
	string line[100];
	ifstream inData;
	ofstream outData;
	char* WALLCHAR;
	CConsole console;
public:
	vector<int> price;
	vector<string> equip;
	void readFromFile();//从文件中读取菜品信息
	void display();
	void draw();
	void apart();
	Hotel();

};

#endif HOTEL_H
