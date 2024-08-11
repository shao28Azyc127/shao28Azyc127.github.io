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
class dgncx{
	public:
	void color(const int a) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a); }
	void SetPos(COORD a) { HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleCursorPosition(out, a); }
	void SetPos(int i, int j) { COORD pos = { (SHORT)i, (SHORT)j }; SetPos(pos); }
	void clear(int x, int y) {
		swap(x, y);
		SetPos(x+1, y + 1);
		putchar(' ');
	}void cl(){system("cls");}
	void clear(const pair<int, int> p) { clear(p.first, p.second); }
	void print(int x, int y, const int col = 2) {
		swap(x, y);
		SetPos(x + 1, y + 1);
		color(col);
		putchar('#');
		color(15);
	}
	void print(const pair<int, int> p, const int col = 2) { print(p.first, p.second, col); }
	int ri(int start,int end){
		return (rand()%(end-start+1))+start;
	} char homet(){
		cout<<"Welcome to Games By 28AZYC!\n";
		char c;cout<<"====Menu===="<<endl;
		cout<<"1. Na2S2O3"<<endl;
		cout<<"2. Minesweeper"<<endl;
		cout<<"i. Info"<<endl;
		cout<<"c. Changelog"<<endl;
		cout<<"q. Quit"<<endl;
		cout<<"Please Choose:";c=_getch();return tolower(c);
	}
		
};
