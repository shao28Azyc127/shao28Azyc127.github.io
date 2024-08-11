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




//decleartion before everything
void cl();
void color(const int);
void SetPos(COORD);
void SetPos(int,int);
void clear(int,int);
void print(int,int,const int);
void print(const pair<int,int>,const int);
int ri(int,int);
char home();
void f1_1();
void f1_1_1();
void f1_2();
void f1_1_3();
void f1_1_2();
void f1_2_1();
void f1_2_2();
void advancement(string);
void f1();
void f2();
void f3();
//end




bool endgame=false;int eastereggt=1,nowee;
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



//cmd.exe color [attr]
//设置默认的控制台前景和背景颜色。
//
//COLOR [attr]
//
//  attr        指定控制台输出的颜色属性。
//
//颜色属性由两个十六进制数字指定 -- 第一个
//对应于背景，第二个对应于前景。每个数字
//可以为以下任何值:
//
//    0 = 黑色       8 = 灰色
//    1 = 蓝色       9 = 淡蓝色
//    2 = 绿色       A = 淡绿色
//    3 = 浅绿色     B = 淡浅绿色
//    4 = 红色       C = 淡红色
//    5 = 紫色       D = 淡紫色
//    6 = 黄色       E = 淡黄色
//    7 = 白色       F = 亮白色
//
//如果没有给定任何参数，此命令会将颜色还原到 CMD.EXE 启动时
//的颜色。这个值来自当前控制台
//窗口、/T 命令行开关或 DefaultColor 注册表
//值。
//
//如果尝试使用相同的
//前景和背景颜色来执行
// COLOR 命令，COLOR 命令会将 ERRORLEVEL 设置为 1。
//
//示例: "COLOR fc" 在亮白色上产生淡红色
//color():base16->10
//┍─┓
//├┯┥
//┃┽┃
//└┷┚



int ri(int start,int end){
	srand(time(0));
	return (rand()%(end-start+1))+start;
} 
char home(){
	cout<<"Welcome to Games By 28AZYC!\n";
	char c;cout<<"====Menu===="<<endl;
	cout<<"1. Na2S2O3"<<endl;
	cout<<"2. Info"<<endl;
	cout<<"3. Changelog"<<endl;
	cout<<"q. Quit"<<endl;
	cout<<"Please Choose:";c=_getch();return c;
}
void f1_1(){
	int a=ri(1,21);
	if(a==21){
		f1_1_3();
	}else if(a%2==0){
		f1_1_1();
	}else{
		f1_1_2();
	} 
}
void f1_1_1(){
	cl();cout<<"剧情"<<endl;
	cout<<"┍────────────────────────────────────────────────────────┓"<<endl;
	cout<<"┃小A忐忑的写了一封信向TA表明自己的心意，期待着收         ┃"<<endl;
	cout<<"┃到TA的回信。两天后TA主动找到小A，小A怀着激动又紧张的心情┃"<<endl;
	cout<<"┃听到TA说：我也喜欢你。此时的小A激动万分，他们就这样开始 ┃"<<endl;
	cout<<"┃交往了。上课的时候脑海里总是浮现出彼此的身影，经常想的是┃"<<endl;
	cout<<"┃周末要一起去哪里玩……很快要期末考试了，他们俩的心中只有┃"<<endl;
	cout<<"┃彼此，静不下心来复习。随着相处时间的变长，小A觉得TA身上 ┃"<<endl;
	cout<<"┃的光环在一点点消失，他们开始出现了一些矛盾和争吵。而就在┃"<<endl;
	cout<<"┃此时，他们在一起的事情被老师和家长知道了……            ┃"<<endl;
	cout<<"├────────────────────────────────────────────────────────┥"<<endl;
	cout<<"┃The End! Congratulations!                               ┃"<<endl;
	cout<<"├──────────────────────────────────┯─────────────────────┥"<<endl;
	cout<<"┃               是(Y)              ┃        否(N)        ┃"<<endl;
	cout<<"┖──────────────────────────────────┶─────────────────────┙"<<endl;
	_getch();
}
void f1_2(){
	
}
void f1_1_3(){}
void f1_1_2(){}
void f1_2_1(){}
void f1_2_2(){}
void advancement(string inf){
	SetPos(80,2);cout<<"┍──────────────────────────────┐";
	SetPos(80,3);cout<<"┃                              ┃";
	SetPos(80,4);cout<<"┃                              ┃";
	SetPos(80,5);cout<<"└──────────────────────────────┚";
	SetPos(81,3);cout<<"已达成成就（彩蛋）:"<<nowee<<"/"<<eastereggt;nowee++;
	SetPos(82,4);cout<<inf;
	Sleep(3000);
}
void f1(){
	cl();cout<<"剧情"<<endl;
	cout<<"┍───────────────────────────────────────────────┓"<<endl;
	cout<<"┃那次的班级活动中，小A和TA一起准备一个才艺展示，┃"<<endl;
	cout<<"┃在一起准备的这段时间里，小A发现TA非常善解人意，┃"<<endl;
	cout<<"┃总是能照顾到小A的想法，表演起来又是那么自信大方┃"<<endl;
	cout<<"┃，从那个时候开始，小A心里萌生出了一种特别的感觉┃"<<endl;
	cout<<"┃。回到学校后小A总是不经意的望向TA的方向，会制造┃"<<endl;
	cout<<"┃和TA的偶遇。如果哪天TA多跟小A说了几句话，小A的 ┃"<<endl;
	cout<<"┃一整天都会特别开心。如果哪天TA没来学校，小A一天┃"<<endl;
	cout<<"┃都感觉心里空落落的。TA牵动着小A的心，小A意识到 ┃"<<endl;
	cout<<"┃自己好像喜欢上TA了。                           ┃"<<endl;
	cout<<"├───────────────────────────────────────────────┥"<<endl;
	cout<<"┃小A要不要把自己的心意告诉TA?                   ┃"<<endl;
	cout<<"├─────────────────────────┯─────────────────────┥"<<endl;
	cout<<"┃         是(Y)           ┃        否(N)        ┃"<<endl;
	cout<<"┖─────────────────────────┶─────────────────────┙"<<endl;
	char y=_getch();if(y=='Y'||y=='y'){f1_1();}else if(y=='N'||y=='n'){f1_2();}
	if(y=='N'){
		if(_getch()=='a'&&_getch()=='2'&&_getch()=='S'&&_getch()=='2'&&_getch()=='O'&&_getch()=='3'){
			advancement("N坏了?!那就按Na2S2O3吧！");
		}
	}
}
void f2(){
	cl();
	cout<<"Games(Mainly Na2S2O3) by 28A_ZYC"<<endl;
	cout<<"Version: 1.0.1 pre-realease 2"<<endl;
	cout<<"Press     to return to the main menu.";
	color(6);SetPos(6,2);cout<<"[R]";
	char r=_getch();if(r=='R'||r=='r'){color(15);return;}
	else{color(15);cl();f2();}
}
void f3(){
	cl();
	printf(""
	"V1.0.1\n"
	"  Has 3 functions:Na2S2O3, Info, Quit.\n"
	"  Na2S2O3 has the first part\n"
	"  Added 1 easter eggs.\n"
	);
	cout<<"Press     to return to the main menu.";
	color(6);SetPos(6,4);cout<<"[R]";
	char r=_getch();if(r=='R'||r=='r'){color(15);return;}
	else{color(15);cl();f2();}
}




int main(){
	while(endgame!=1){cl();color(15);
		switch(home()){
			case '1':f1();cl();break;
			case '2':f2();cl();break;
			case '3':f3();cl();break;
			case 'q':endgame=1;break;
			default:break;
		}
	}	
}
