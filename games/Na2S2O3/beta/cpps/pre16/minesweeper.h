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
#include "mainfunc.h"
#include "dgncx.h"
class f2:public dgncx,public mainfunc{
	public:
		void f2(){
			while(endgame!=1){
				cl();color(15);
				switch(f2_HOME()){
					case '1':f2_1();cl();break;
					case '2':f2_2();cl();break;
					case '3':f2_3();cl();break;
					case '4':f2_4();cl();break;
					case 'q':endgame=1;break;
					
				}
			}
		}
		char f2_HOME(){
			cout<<"coming soon~"<<endl;
			cout<<"PS:there will be a lot of pre realease versions in 2.0.0\n";
			Sleep(1000);
			cout<<"=====Welcome to minesweeper!=====\n"<<endl;
			cout<<"Version:1.0.0 pre realease 8\n";
			cout<<"===MENU==="<<endl;
			cout<<"1.Small"<<endl;
			cout<<"2.Medium"<<endl;
			cout<<"3.Large"<<endl;
			cout<<"4.Custom"<<endl;
			cout<<"q.Quit"<<endl;
			cout<<"Please Choose:";return tolower(_getch());
		}
		void f2_1(){
			f2_GENERATE_MAPS(10,10,10);
			f2_PLAY();
		}
		void f2_2(){
			f2_GENERATE_MAPS(16,16,40);
			f2_PLAY();
		}
		void f2_3(){
			f2_GENERATE_MAPS(30,16,99);
			f2_PLAY();
		}
		void f2_4(){
			cout<<"lines:";
			int a,b,c;cin>>a;
			cout<<"rols:";cin>>b;
			cout<<"mines:";cin>>c;
			f2_GENERATE_MAPS(a,b,c);
			f2_PLAY();
		}
		void f2_GENERATE_MAPS(int l,int r,int m){
			int mines[m][2];
			bool chk[m];
			memset(chk,0,sizeof(chk));
			for(int i=0;i<m;i++){
				mines[i][0]=ri(0,l);
				mines[i][1]=ri(0,r);
			}f2_DRAWMAP(l,r);
		}
		void f2_DRAWMAP(int l,int r){
			cl();
			//map start
			cout<<"X ┃\n──┷" ;
			//cols
			for(int i=0;i<l;i++){
				dgncx.SetPos(4+3*i,0);
				printf("%-3d",i);
				dgncx.SetPos(4+3*i,1);
				printf("───");
				//Sleep(1000);
			}
			//rows
			for(int i=0;i<r;i++){
				dgncx.SetPos(0,2+3*i);
				printf("%-2d┃\n  ┃\n  ┃",i);
				Sleep(1000);
			}Sleep(3000);
			/*
			X ┃
			──┷
			Num  
			───
			
			Nu┃
		 	 m┃
			  ┃
			  
			 ┍─ ┓
			 ┃N┃
			 └─┚
			 
			 (red)
			 ┍─ ┓
			 ┃X┃
			 └─┚
			***
			*/
			Sleep(1000);
		}
		void f2_PLAY(){
			
		}
};

