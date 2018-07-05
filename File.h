#ifndef FILE1
#define FILE1

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"Hero.h"
using namespace std;

class File
{
private:
	typedef vector<File> FILE;
	string name;//姓名
	string race;//种族
	string sex;//性别
	int hp;//血量
	int atach;
	int def;//防御力
	int money;
	int exp;//经验值
	int level;//等级
	
	ifstream inData;
	ofstream outData;

public:
	void readFromFile();
	void writeToFile(Hero &h );
	void display(Hero &h , int);
	FILE m;
	friend ostream & operator <<(ostream &os, File &s);//重载输出函数
	friend istream & operator >> (istream &is, File &s);//重载输入函数
};

#endif FILE1


