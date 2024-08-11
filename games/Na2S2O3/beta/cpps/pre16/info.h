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
#include "dgncx.h"
class fi{
	public:
		void fi(){
			dgncx.cl();
			cout<<"Games(Na2S2O3+Minesweeper) by 28A_ZYC"<<endl;
			cout<<"Version: 2.0.0 pre-realease 16"<<endl;
			cout<<"Press     to return to the main menu.";
			dgncx.color(6);dgncx.SetPos(6,2);cout<<"[R]";
			dgncx.color(15);while(tolower(_getch())!='r'){}
		}
}
