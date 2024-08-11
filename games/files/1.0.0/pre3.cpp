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
	char c;cout<<"====Menu====";
	cout<<"1. Na2S2O3"<<endl;
	cout<<"2. Info"<<endl;
	cout<<"3. Quit"<<endl;
	cout<<"Please Choose:";c=_getch();return c;
}
void f1(){
	
}
void f2(){
	cout<<"Games(Mainly Na2S2O3) by 28A_ZYC"<<endl;
	cout<<"Version: 1.0.0 pre-realease 3";
}
int main(){
	
} 
