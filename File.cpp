
#include "stdafx.h"
#include"File.h"

//�����������
ostream &operator <<(ostream &os, File &s)
{
	//inData >> it->name >> it->sex >> it->race >> it->atach >> it->def >> it->hp >> it->level >> it->exp >> it->money >> endl;
	os << "����:" << s.name <<"   ";
	os << "�Ա�:" << s.sex <<"   ";
	os << "����: " << s.race << "   " << endl << endl;
	os << "������:" << s.atach<< "   ";
	os << "������:" << s.def << "   ";
	os << "����ֵ:" << s.hp<< "   " << endl << endl;
	os << "�ȼ�:" << s.level<<  "    ";
	os << "����ֵ:" << s.exp<< "   ";
	os << "���:" << s.money<< endl;
	return os;
}


//�������뺯��
istream &operator >> (istream &is, File &s)
{
	is >> s.name >> s.sex >> s.race >> s.atach >> s.def >> s.hp >> s.level >> s.exp >> s.money;//>> endl;
																								   //is >> [ͼƬ]s.name >> s.sex >> s.race >> s.mail >> s.adress ;
	return is;
}

//���ļ���ȡ����
void File::readFromFile()
{
	inData.open("Ӣ��.txt");
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


//д���ļ�
void File::writeToFile(Hero &h )
{
	
	FILE::iterator it;
	outData.open("Ӣ��.txt",ios::trunc);
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
		cout<<"���ݴ��󣡣�";
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
