#include<bits/stdc++.h>
//include from dgncx-snakev1.3.1.cpp
#include <iostream>
#include <deque>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <set>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
bool endgame=false;
void cl(){system("cls");}
//dgncx function
void color(const int a) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a); }
void SetPos(COORD a) { HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleCursorPosition(out, a); }
void SetPos(int i, int j) { COORD pos = { (SHORT)i, (SHORT)j }; SetPos(pos); }
void clear(int x, int y) {
	swap(x, y);
	SetPos(x+1, y + 1);
	putchar(' ');
}
void clear(const pair<int, int> p) { clear(p.first, p.second); }
void print(int x, int y, const int col = 2) {
	swap(x, y);
	SetPos(x + 1, y + 1);
	color(col);
	putchar('#');
	color(15);
}
void print(const pair<int, int> p, const int col = 2) { print(p.first, p.second, col); }
//dgncx part ends
char home(){
	cout<<"Welcome to Game Center!";
	char c;cout<<"====Menu===="<<endl;
	cout<<"1. Na2S2O3"<<endl;
	cout<<"2. Info"<<endl;
	cout<<"3. Quit"<<endl;
	cout<<"Please Choose:";c=_getch();return c;
}
void f1(){
	cout<<"�Ǵεİ༶��У�СA��TAһ��׼��һ������չʾ����һ��׼�������ʱ���СA����TA�ǳ��ƽ����⣬�������չ˵�СA���뷨����������������ô���Ŵ󷽣����Ǹ�ʱ��ʼ��СA������������һ���ر�ĸо����ص�ѧУ��СA���ǲ����������TA�ķ��򣬻������TA��ż�����������TA���СA˵�˼��仰��СA��һ���춼���ر��ġ��������TAû��ѧУ��СAһ�춼�о����������ġ�TAǣ����СA���ģ�СA��ʶ���Լ�����ϲ����TA�ˡ�";
}
void f2(){
	cl();
	cout<<"Games(Mainly Na2S2O3) by 28A_ZYC"<<endl;
	cout<<"Version: 1.0.0 pre-realease 6"<<endl;
	cout<<"Press     to return to the main menu.";
	color(6);SetPos(6,2);cout<<"[R]";
	char r=_getch();if(r=='R'||r=='r'){color(15);return;}
	else{color(15);cl();f2();}
}
int main(){
	while(endgame!=1){cl();color(15);
		switch(home()){
			case '1':f1();cl();break;
			case '2':f2();cl();break;
			case '3':endgame=1;break;
			default:break;
		}
	}	
}
