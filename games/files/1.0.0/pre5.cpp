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
	cout<<"Games(Mainly Na2S2O3) by 28A_ZYC"<<endl;
	cout<<"Version: 1.0.0 pre-realease 5";
}
int main(){
	switch(home()){
		case '1':f1();if(endgame){break;}
		case '2':f2();
		case '3':break;
		default:system("cls"); 
	}
}
