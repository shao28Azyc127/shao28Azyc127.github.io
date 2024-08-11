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
	cout<<"那次的班级活动中，小A和TA一起准备一个才艺展示，在一起准备的这段时间里，小A发现TA非常善解人意，总是能照顾到小A的想法，表演起来又是那么自信大方，从那个时候开始，小A心里萌生出了一种特别的感觉。回到学校后小A总是不经意的望向TA的方向，会制造和TA的偶遇。如果哪天TA多跟小A说了几句话，小A的一整天都会特别开心。如果哪天TA没来学校，小A一天都感觉心里空落落的。TA牵动着小A的心，小A意识到自己好像喜欢上TA了。";
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
