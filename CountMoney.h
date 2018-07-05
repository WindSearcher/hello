
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
		void order(Hero &h);//µ„≤Õ
		void count(int a[] , int shop[],Hero &h);//Ω·À„
};

#endif COUNT_H