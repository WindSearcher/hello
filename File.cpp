
#include "stdafx.h"
#include"File.h"

//重载输出函数
ostream &operator <<(ostream &os, File &s)
{
	//inData >> it->name >> it->sex >> it->race >> it->atach >> it->def >> it->hp >> it->level >> it->exp >> it->money >> endl;
	os << "姓名:" << s.name <<"   ";
	os << "性别:" << s.sex <<"   ";
	os << "种族: " << s.race << "   " << endl << endl;
	os << "攻击力:" << s.atach<< "   ";
	os << "防御力:" << s.def << "   ";
	os << "生命值:" << s.hp<< "   " << endl << endl;
	os << "等级:" << s.level<<  "    ";
	os << "经验值:" << s.exp<< "   ";
	os << "金币:" << s.money<< endl;
	return os;
}


//重载输入函数
istream &operator >> (istream &is, File &s)
{
	is >> s.name >> s.sex >> s.race >> s.atach >> s.def >> s.hp >> s.level >> s.exp >> s.money;//>> endl;
																								   //is >> [图片]s.name >> s.sex >> s.race >> s.mail >> s.adress ;
	return is;
}

//从文件读取数据
void File::readFromFile()
{
	inData.open("英雄.txt");
	File file;
	int n = 1;
	while (!inData.eof() && n == 1)
	{
		inData >> file.name >> file.sex >> file.race >> file.atach >> file.def >> file.hp >> file.level >> file.exp >> file.money;
		m.clear();
		m.push_back(file);
		++n;
		//cout << " name:  " << file.name << "  sex:  " <<file.sex << "  race:  " << file.race;
		//cout << "name:  " << m[0].name << "  sex:  " <<m[0].sex << "  race:  " << m[0].race;
	}
   // cout << " name:  " << file.name << "  sex:  " <<file.sex << "  race:  " << file.race;
	//cout << "name:  " << m[0].name << "  sex:  " <<m[0].sex << "  race:  " << m[0].race;
	inData.close();
}


//写入文件
void File::writeToFile(Hero &h )
{
	
	FILE::iterator it;
	outData.open("英雄.txt",ios::trunc);
	for (it = m.begin(); it != m.end(); it++)
	{
	    
		outData << it->name << "  " << it->sex  << "  " << it->race << "  " << it->atach << "  " << it->def << "  " 
			    << it->hp  << "  "  << it->level << "  "  << it->exp << "  " << it->money << endl;
	}
	outData.close();
}


void File::display(Hero &h , int choice)
{
	FILE::iterator it;
	it = m.begin();

	/*if((h.i_Hp<0||h.i_Hp>10000)||
		(h.i_Def<0||h.i_Def>10000)||
		(h.i_Atk<0||h.i_Atk>10000)||
		(h.i_Money<0||h.i_Money>10000)||
		(h.i_Exp<0||h.i_Exp>10000)||
		(h.i_Level<0||h.i_Level>10000))
	{
		//system("cls");
		cout<<"数据错误！！";
	}*/
	//else
	//{
		if(choice)
		{
			it->name = h.str_Name;
			it->hp   = h.i_Hp;
			it->def  = h.i_Def;
			it->atach= h.i_Atk;
			it->money= h.i_Money;
			it->exp  = h.i_Exp;
			it->level = h.i_Level;
			it->race  = h.str_Race;
			it->sex   = h.str_Sex;

			for ( ;it != m.end(); it++)
			{
	    		cout << *it;
			}
		}
		else
		{
		
			 h.str_Name = it->name ;
			 h.i_Hp     = it->hp   ;
			 h.i_Def    = it->def  ;
			 h.i_Atk    = it->atach;
			 h.i_Money  = it->money;
			 h.i_Exp    = it->exp  ;
			 h.i_Level  = it->level;
			 h.str_Race = it->race ;
			 h.str_Sex  = it->sex  ;
			 
		}
	//}  
	
}
