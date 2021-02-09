#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <cstdio>
#include <vector>


using namespace std;


typedef std::string str;


class Frame
{
public:
	int m_MaxHP;
	int m_Dff;
	int m_Att;
	int m_Hp;
	string m_Wp; //当前武器
	string m_pro;

	//背包
	std::vector<string> bag; 
	
public:
	//战斗选项
	void ATT(string b_name, 
		int b_lev, 
		int b_Hp, 
		int b_Dff, 
		int b_Att);               
	
	//查看自身信息
	void Check();    

	//商店
	void Shop();                  


	//主循环
	void MuenLoop();
	//
	void 

public:
	//职业选择
	int pro();    

	//职业的打印
	void proS(int op_p); 

	//初始化
	void _init_();

	//拾取物品
	void PuItem(str item, int lev);

public:
	//Consle

	//设置鼠标指针的位置
	inline void Curpath(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hout, coord);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}  
	//设置控制台文字颜色
	inline void SColor(int COLOR, string a = "绿色=1  黄色=2   红色=3   洋红色=4   青色=5 ")
	{
		if (COLOR == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		// 绿
		if (COLOR == 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED); // 黄色

		if (COLOR == 3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED); //红色

		if (COLOR == 4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE); //洋红色

		if (COLOR == 5) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); //青色
	}
	//将控制台文字颜色重置为默认
	inline void SColor()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);   //还原白色
	}

};

void Frame::ATT(string b_name, int b_lev, int b_Hp, int b_Dff, int b_Att)
{
	//参数为Boss的参数
	//打印战斗页


}

void Frame::Check()
{


}

void Frame::Shop()
{


}

int Frame::pro()
{
	int op_p = 1;
	proS(op_p);

	while (1)
	{
		int key_q = _getch();

		if (op_p == 1 && key_q == 77)
		{
			op_p = 2;
			proS(op_p);

		}
		if (op_p == 2 && key_q == 75)
		{
			op_p = 1;
			proS(op_p);
		}
		if (key_q == 13)
		{
			return op_p;
		}
	}
}
void Frame::proS(int op_p)
{	
	if (op_p == 1)
	{
		SColor(4);

		Curpath(13, 1);
		SColor(2);

		std::cout << "<战士>";

		SColor(4);

		std::cout << "     <射手>" << endl;
	}
	if (op_p == 2)
	{
		SColor(4);

		Curpath(13, 1);
		SColor(4);

		std::cout << "<战士>";

		SColor(2);

		std::cout << "     <射手>" << endl;
	}
	if (op_p == -1)
	{
		Curpath(13, 1);
		SColor(4);

		std::cout << "<战士>";
		std::cout << "     <射手>" << endl;
	}

	//input
}

void Frame::_init_()
{
	if (pro() == 1)
	{
		this->proS(-1);

		//战士
		m_pro = "战士";
		m_MaxHP = 15;
		m_Att = 8;
		m_Dff = 3;
		m_Wp = "初始木剑";

		bag.push_back(m_Wp);
	}
	else
	{
		proS(-1);

		//射手
		m_pro = "射手";
		m_MaxHP = 8;
		m_Att = 12;
		m_Dff = 1;
		m_Wp = "初始弓箭";

		bag.push_back(m_Wp);
	}

	Sleep(1500);

	system("cls");
	Curpath(0, 0);

	bag.push_back("新手头盔");
	bag.push_back("新手上装");
	bag.push_back("新手裤裤");
	bag.push_back("老八靴");

	PuItem(bag[0], 1);
	PuItem(bag[1], 1);
	PuItem(bag[2], 1);
	PuItem(bag[3], 1);
	PuItem(bag[4], 1);

	Sleep(800);
	SColor(2);
	std::cout << "已穿戴!" << endl;
	SColor();
	Sleep(1500);
	system("cls");
	std::cout << "世界跳转中..." << endl;
	Sleep(1588);
	system("cls");
}

void Frame::PuItem(str item, int lev)
{
	if (lev == 1)
	{
		SColor();
		std::cout << "恭喜你获得了: ";
		SColor(1);
		std::cout << item;
		SColor();
		std::cout << " !!" << endl;
	}
	Sleep(600);

}

void Frame::MuenLoop()
{
	while (true)
	{
		
	}
}