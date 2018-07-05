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
	char *Deal() { return "文件读取失败......"; }
};

class InputDeal :public Catch{
public:
	char *Deal() { return "输入失败......"; }
};

class OutDeal :public Catch{
public:
	char *Deal() { return "输出失败......"; }
};

class ChoiceDeal :public Catch{
public:
	char *Deal() { return "文件读取失败......"; }
};

class JudgeDeal :public Catch{
public:
	char *Deal() { return "判断处理失败......"; }
};
class OrDeal :public Catch{
public:
	char *Deal() { return "其他处理失败......"; }
};


#endif // !CATCH_H

