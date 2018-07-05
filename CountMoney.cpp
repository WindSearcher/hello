
#include"stdafx.h"
#include"CountMoney.h"

void CountMoney::order(Hero &h)
{
   
	int choice;
    int a[100] , i = 0;
    int shop[101];

    hotel.display();//intersting
	cout<<"=============================================================================="<<endl<<endl;
	cout << "英雄拥有金币: " << h.i_Money << endl << endl;
	    while(1)
		{
			//try
			//{
			cout<<"请输入装备代码(0表示结束购买)>>";
			cin>>choice;
			try{
			   if(choice > 15 )  throw 1;
			}
			catch(int ){
			   cout<<"请重新输入装备代码(0表示结束购买)>>";
			   cin>>choice;
			}
			if(choice == 0)
				break;
			shop[i] = choice - 1;
			car.push_back(hotel.equip[choice-1]);
			cout<<"请输入数量 >> ";
			cin>>a[i];
			++i;
		}
		count(a , shop , h);
}


void CountMoney::count(int a[] ,int shop[] , Hero &h)
{
	
	int i = 0,id = 1,j=0;
	int pay = 0;
  	cout<<"===================================\n\t\t购买清单"<<endl;
    for(vector<string>::iterator it = car.begin() ; it!=car.end();++it,++i)
	{
	   cout << "[ " << *it << " x " << a[i] << " 件 ]" << " = "  << hotel.price[shop[i]]*a[i] << endl;
	   pay += hotel.price[shop[i]]*a[i]; 
	}
    cout<<endl;   
    cout<<"===================================\n\t\t"<<endl;
    cout<<"\t\t应付款(金币):"<< pay <<endl;
    if(h.i_Money>=pay)
	{
		h.i_Money -= pay;
		cout<<"\t\t还剩(金币):"<< h.i_Money << endl;
		h.i_Atk=h.i_Atk+(pay/10);
		cout<<"\t\t战力";
		Sleep(500);
		cout<<"》";
		Sleep(500);
		cout<<"》";
		cout<<(pay/10);
		cout<<h.i_Atk;
	}
    else
	{
		cout<<"\t\t金币不足!"<<endl;
	}
	cout << "按任意键继续";
	_getch();
	_getch();
}
