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
#include "Na2S2O3.h"
#include "minesweeper.h" 
class mainfunc:public dgncx{
	// Private section
	public:
		int nowee[5]={0,0,0,0,0},
    	end[5]  ={0,0,0,0,0};
		
		bool endgame=false;int eastereggt=5;
		void cl(){system("cls");}
		void homes(){
			dgncx hhhhh;//f1 hi;
			while(endgame!=1){hhhhh.cl();hhhhh.color(15);
				switch(hhhhh.homet()){
//					case '1':hi.f1_main();cl();break;
//					case '2':f2();cl();break;
//					case 'i':fi();cl();break;
//					case 'q':endgame=1;break;
//					case 'h':eggcheck(1);
//					case 'e':eggcheck(2);
//					case 'g':eggcheck(3);
//					case 'd':eggcheck(114);
					default:break;
				}
			}
		}
		int ri(int start,int end){
			return (rand()%(end-start+1))+start;
		} 
	protected:
		// Protected Declarations
};
