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
	string name;//����
	string race;//����
	string sex;//�Ա�
	int hp;//Ѫ��
	int atach;
	int def;//������
	int money;
	int exp;//����ֵ
	int level;//�ȼ�
	
	ifstream inData;
	ofstream outData;

public:
	void readFromFile();
	void writeToFile(Hero &h );
	void display(Hero &h , int);
	FILE m;
	friend ostream & operator <<(ostream &os, File &s);//�����������
	friend istream & operator >> (istream &is, File &s);//�������뺯��
};

#endif FILE1


