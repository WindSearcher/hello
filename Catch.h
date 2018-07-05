#ifndef CATCH_H
#define CATCH_H
#include <iostream>
#include <string>
using namespace std;

class Catch {
public:
	virtual  char * Deal() { return "Fail......"; }
};

class FileDeal :public Catch{
public:
	char *Deal() { return "�ļ���ȡʧ��......"; }
};

class InputDeal :public Catch{
public:
	char *Deal() { return "����ʧ��......"; }
};

class OutDeal :public Catch{
public:
	char *Deal() { return "���ʧ��......"; }
};

class ChoiceDeal :public Catch{
public:
	char *Deal() { return "�ļ���ȡʧ��......"; }
};

class JudgeDeal :public Catch{
public:
	char *Deal() { return "�жϴ���ʧ��......"; }
};
class OrDeal :public Catch{
public:
	char *Deal() { return "��������ʧ��......"; }
};


#endif // !CATCH_H

