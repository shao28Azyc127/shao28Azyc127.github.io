#include<bits/stdc++.h>
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
int main(){
	
} 
