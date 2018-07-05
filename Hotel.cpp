

#include"stdafx.h"
#include"Hotel.h"
#include <Windows.h>


Hotel::Hotel()
{
	WALLCHAR = "■";
}


void Hotel::readFromFile()
{
	inData.open("商店.txt");
	string line;
	string data_read, temp;
	int t, i;
	//cout << "----------------------双儿商店------------------------------------------------------" << endl;
	while (getline(inData, line))
	{
		istringstream record(line);
		//cout << line << endl;
		while (record >> data_read)
		{

			if (data_read[1] == '.')
			{
				for (i = 2; i < data_read.size(); ++i)
				{

					temp += data_read[i];
				}
				equip.push_back(temp);
				temp = "";
			}

			if (data_read[2] == '.')
			{
				for (i = 3; i < data_read.size(); ++i)
				{

					temp += data_read[i];
					//cout << temp;
				}
				equip.push_back(temp);
				temp = "";
			}

			if (data_read[2] >= '0'&&data_read[2] <= '9')
			{
				t = atoi(data_read.c_str());//从字符串转换为字符
				price.push_back(t);
			}

		}

	}

	inData.close();
}

void Hotel::draw()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int i = 0;
	SetConsoleTextAttribute(hOut, 11);
	for (i = 0; i <= 15; ++i)
	{
		console.SetCoord(2, 20);
		cout << WALLCHAR;
		Sleep(100);
		console.SetCoord(4, 20);
		cout << WALLCHAR;
		Sleep(100);

		console.SetCoord(6 + 2 * i, 20 - i);
		cout << WALLCHAR;
		Sleep(100);
	}

	for (i = 0; i <= 40; ++i)
	{
		console.SetCoord(37 + i, 5);
		cout << "--";
		Sleep(100);
	}

	console.SetCoord(52, 3);
	cout << "欢";
	Sleep(100);

	console.SetCoord(56, 3);
	cout << "迎";
	Sleep(100);

	console.SetCoord(60, 3);
	cout << "光";
	Sleep(100);

	console.SetCoord(64, 3);
	cout << "临";
	Sleep(200);
	for (i = 0; i <= 15; ++i)
	{
		console.SetCoord(77 + 2 * i, 5 + i);
		cout << WALLCHAR;
		Sleep(100);
	}

	cout << "  请按任意键进入商店------";
	_getch();


}


void Hotel::apart()
{
	int i = 1, j = 1;
	system("cls");
	console.SetCoord(10, 4);
	for (i = 1; i <= 75; ++i)
	{
		cout << '*';
	}

	console.SetCoord(10, 7);
	for (i = 1; i <= 75; ++i)
	{
		cout << '*';
	}

	for (i = 1; i <= 75; i += 74)
	{
		if (i == 1)
		{
			for (j = 1; j <= 3; ++j)
			{
				console.SetCoord(10, 4 + j);
				cout << '*';
			}
		}

		if (i == 75)
		{
			for (j = 1; j <= 3; ++j)
			{
				console.SetCoord(84, 4 + j);
				cout << '*';
			}
		}

	}

	console.SetCoord(40, 6);
	cout << "双";
	Sleep(200);

	console.SetCoord(44, 6);
	cout << "儿";
	Sleep(200);

	console.SetCoord(48, 6);
	cout << "商";
	Sleep(200);

	console.SetCoord(52, 6);
	cout << "店";
	Sleep(200);

	for (i = 1; i <= 3; ++i)
	{
		for (j = 1; j <= 15; ++j)
		{
			if (i == 1)
			{
				console.SetCoord(35, 7 + j);
				cout << WALLCHAR;
			}
			if (i == 2)
			{
				console.SetCoord(60, 7 + j);
				cout << WALLCHAR;
			}

		}
	}

}

void Hotel::display()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, 14);
	readFromFile();
	draw();
	apart();
	int i = 0;
	Sleep(500);
	console.SetCoord(23, 9);
	cout << "[武器]";
	Sleep(500);

	console.SetCoord(42, 9);
	cout << "[补血剂]";
	Sleep(500);

	console.SetCoord(72, 9);
	cout << "[经验包]";
	Sleep(500);

	for (i = 0; i < equip.size(); ++i)
	{
		cout << setiosflags(ios::left);
		if (i <= 8)
		{
			console.SetCoord(10, 10 + i);

			cout << i+1 << "."  << setw(12)<< equip[i] << "  " << price[i] << "金币";
		}

		if (i > 8 && i <= 11)
		{
			console.SetCoord(37, 10 + i - 9);
			cout << i+1 << "."  << setw(10)<< equip[i]<< "  " << price[i] << "金币";
		}

		if (i > 11)
		{
			console.SetCoord(62, 10 + i - 12);
			cout << i+1  << "." << equip[i]  << setw(12)<< "  " << price[i] << "金币";
		}

	}
	console.SetCoord(0, 25);

}

/*void Hotel::writeToFile()
{
COOK::iterator it;
outData.open("商店.txt");
int id = 1;

for(it=cook.begin(); it!=cook.end(); it++)
{
outData << "  " << id <<"  " << it->first  << "  " << it->second <<endl;
++id;
}
outData.close();
}*/
