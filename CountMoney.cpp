
#include"stdafx.h"
#include"CountMoney.h"

void CountMoney::order(Hero &h)
{
   
	int choice;
    int a[100] , i = 0;
    int shop[101];

    hotel.display();//intersting
	cout<<"=============================================================================="<<endl<<endl;
	cout << "Ӣ��ӵ�н��: " << h.i_Money << endl << endl;
	    while(1)
		{
			//try
			//{
			cout<<"������װ������(0��ʾ��������)>>";
			cin>>choice;
			try{
			   if(choice > 15 )  throw 1;
			}
			catch(int ){
			   cout<<"����������װ������(0��ʾ��������)>>";
			   cin>>choice;
			}
			if(choice == 0)
				break;
			shop[i] = choice - 1;
			car.push_back(hotel.equip[choice-1]);
			cout<<"���������� >> ";
			cin>>a[i];
			++i;
		}
		count(a , shop , h);
}


void CountMoney::count(int a[] ,int shop[] , Hero &h)
{
	
	int i = 0,id = 1,j=0;
	int pay = 0;
  	cout<<"===================================\n\t\t�����嵥"<<endl;
    for(vector<string>::iterator it = car.begin() ; it!=car.end();++it,++i)
	{
	   cout << "[ " << *it << " x " << a[i] << " �� ]" << " = "  << hotel.price[shop[i]]*a[i] << endl;
	   pay += hotel.price[shop[i]]*a[i]; 
	}
    cout<<endl;   
    cout<<"===================================\n\t\t"<<endl;
    cout<<"\t\tӦ����(���):"<< pay <<endl;
    if(h.i_Money>=pay)
	{
		h.i_Money -= pay;
		cout<<"\t\t��ʣ(���):"<< h.i_Money << endl;
		h.i_Atk=h.i_Atk+(pay/10);
		cout<<"\t\tս��";
		Sleep(500);
		cout<<"��";
		Sleep(500);
		cout<<"��";
		cout<<(pay/10);
		cout<<h.i_Atk;
	}
    else
	{
		cout<<"\t\t��Ҳ���!"<<endl;
	}
	cout << "�����������";
	_getch();
	_getch();
}
