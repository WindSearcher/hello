
#ifndef COUNT_H
#define COUNT_H

#include"Hotel.h"
#include"Hero.h"

class CountMoney
{
    private:
	   Hero hero;
       Hotel hotel;
	   vector<string> car;
	public:
		void order(Hero &h);//���
		void count(int a[] , int shop[],Hero &h);//����
};

#endif COUNT_H