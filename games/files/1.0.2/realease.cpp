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
void advancement(int);
void f1();
void f2();
void f3();
int eet();
int endt();
void ending(int);
void eggcheck(int);
//end



int nowee[5]={0,0,0,0,0},
    end[5]  ={0,0,0,0,0};
string infoee[5]={
	"N����?!�ǾͰ�Na2S2O3�ɣ�",
	"������",
	"",
	"",
	"" },
endinfo[5]={
	"Happy Ending",
	"Sad Ending",
	"Na2S2O3 Ending",
	"Protection Ending",
	"Sublimation Ending"};
bool endgame=false;int eastereggt=5;
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
//����Ĭ�ϵĿ���̨ǰ���ͱ�����ɫ��
//
//COLOR [attr]
//
//  attr        ָ������̨�������ɫ���ԡ�
//
//��ɫ����������ʮ����������ָ�� -- ��һ��
//��Ӧ�ڱ������ڶ�����Ӧ��ǰ����ÿ������
//����Ϊ�����κ�ֵ:
//
//    0 = ��ɫ       8 = ��ɫ
//    1 = ��ɫ       9 = ����ɫ
//    2 = ��ɫ       A = ����ɫ
//    3 = ǳ��ɫ     B = ��ǳ��ɫ
//    4 = ��ɫ       C = ����ɫ
//    5 = ��ɫ       D = ����ɫ
//    6 = ��ɫ       E = ����ɫ
//    7 = ��ɫ       F = ����ɫ
//
//���û�и����κβ�����������Ὣ��ɫ��ԭ�� CMD.EXE ����ʱ
//����ɫ�����ֵ���Ե�ǰ����̨
//���ڡ�/T �����п��ػ� DefaultColor ע���
//ֵ��
//
//�������ʹ����ͬ��
//ǰ���ͱ�����ɫ��ִ��
// COLOR ���COLOR ����Ὣ ERRORLEVEL ����Ϊ 1��
//
//ʾ��: "COLOR fc" ������ɫ�ϲ�������ɫ
//color():base16->10
//������
//���ө�
//���ᩧ
//���۩�



int ri(int start,int end){
	srand(time(0));
	return (rand()%(end-start+1))+start;
} 
int eet(){
	return nowee[0]+nowee[1]+nowee[2]+nowee[3]+nowee[4];
}
int endt(){
	return end[0]+end[1]+end[2]+end[3]+end[4];
}
char home(){
	cout<<"Welcome to Games By 28AZYC!\n";
	char c;cout<<"====Menu===="<<endl;
	cout<<"1. Na2S2O3"<<endl;
	cout<<"i. Info"<<endl;
	cout<<"c. Changelog"<<endl;
	cout<<"q. Quit"<<endl;
	cout<<"Please Choose:";c=_getch();return tolower(c);
}
void eggcheck(int id){
	if(id==0){
		if(_getch()=='a'&&_getch()=='2'&&_getch()=='S'&&_getch()=='2'&&_getch()=='O'&&_getch()=='3'){
			advancement(0);
		}
	}else if(id==1){
		if(_getch()=='o'&&_getch()=='m'&&_getch()=='o'){
			advancement(1);
		}
	}
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
	cl();cout<<"����"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��СA������д��һ������TA�����Լ������⣬�ڴ����թ�"<<endl;
	cout<<"����TA�Ļ��š������TA�����ҵ�СA��СA���ż����� ��"<<endl;
	cout<<"�����ŵ���������TA˵����Ҳϲ���㡣��ʱ��СA������"<<endl;
	cout<<"���֣����Ǿ�������ʼ�����ˡ��Ͽε�ʱ���Ժ������� ��"<<endl;
	cout<<"�����ֳ��˴˵���Ӱ�������������ĩҪһ��ȥ����   ��"<<endl;
	cout<<"���桭���ܿ�Ҫ��ĩ�����ˣ�������������ֻ�б˴ˣ� ��"<<endl;
	cout<<"��������������ϰ�������ദʱ��ı䳤��СA����TA��"<<endl;
	cout<<"���ϵĹ⻷��һ�����ʧ�����ǿ�ʼ������һЩì�ܺ� ��"<<endl;
	cout<<"�������������ڴ�ʱ��������һ������鱻��ʦ�ͼҳ� ��"<<endl;
	cout<<"��֪���ˡ���                                     ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��    The end!(Happy Ending)!Congratulations!    ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��           Press     to retry                  ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	color(6);SetPos(18,15);cout<<"[R]";
	color(15);ending(0);
	color(15);while(tolower(_getch())!='r'){}
}
void f1_2(){
	
}
void f1_1_3(){}
void f1_1_2(){
	cl();cout<<"����"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��СA������д��һ������TA�����Լ������⣬�ڴ����թ�"<<endl;
	cout<<"��СA����������ϲ����TA�������Լ������⣬����õ���"<<endl;
	cout<<"����TA�ľܾ�����������һ����СA�����جج�ģ����ϩ�"<<endl;
	cout<<"��Ҳ��֪����ʦ������Щʲô���ص������Լ��������� ��"<<endl;
	cout<<"�������ǹ�ͬϲ���ĸ�����ˢ�����ǵ������¼������ ��"<<endl;
	cout<<"�������ᡣ֮���һ��ʱ�䣬СAһֱ�����񣬲��ҩ�"<<endl;
	cout<<"����֪����������TA�ദ�������Ѿ������غ�����     ��"<<endl;
	cout<<"���ˡ���                                         ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��    The end!(Sad Ending)!Congratulations!      ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��           Press     to retry                  ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	color(6);SetPos(18,15);cout<<"[R]";
	color(15);ending(1);
	color(15);while(tolower(_getch())!='r'){}
}
void f1_2_1(){}
void f1_2_2(){}
void advancement(int id){
	SetPos(80,2);cout<<"����������������������������������������������������������������";
	SetPos(80,3);cout<<"��                              ��";
	SetPos(80,4);cout<<"��                              ��";
	SetPos(80,5);cout<<"����������������������������������������������������������������";
	SetPos(81,3);nowee[id]=1;cout<<"�Ѵ�ɲʵ�:"<<eet()<<"/"<<eastereggt;
	SetPos(82,4);cout<<infoee[id];
	Sleep(3000);
}
void ending(int id){
	SetPos(80,2);cout<<"����������������������������������������������������������������";
	SetPos(80,3);cout<<"��                              ��";
	SetPos(80,4);cout<<"��                              ��";
	SetPos(80,5);cout<<"����������������������������������������������������������������";
	SetPos(81,3);end[id]=1;cout<<"�Ѵ�ɽ�β:"<<endt()<<"/"<<5;
	SetPos(82,4);cout<<endinfo[id];
	Sleep(3000);
}
void f1(){
	cl();cout<<"����"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"���Ǵεİ༶��У�СA��TAһ��׼��һ������չʾ����"<<endl;
	cout<<"����һ��׼�������ʱ���СA����TA�ǳ��ƽ����⣬��"<<endl;
	cout<<"���������չ˵�СA���뷨����������������ô���Ŵ󷽩�"<<endl;
	cout<<"�������Ǹ�ʱ��ʼ��СA������������һ���ر�ĸо���"<<endl;
	cout<<"�����ص�ѧУ��СA���ǲ����������TA�ķ��򣬻����쩧"<<endl;
	cout<<"����TA��ż�����������TA���СA˵�˼��仰��СA�� ��"<<endl;
	cout<<"��һ���춼���ر��ġ��������TAû��ѧУ��СAһ�쩧"<<endl;
	cout<<"�����о����������ġ�TAǣ����СA���ģ�СA��ʶ�� ��"<<endl;
	cout<<"���Լ�����ϲ����TA�ˡ�                           ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��СAҪ��Ҫ���Լ����������TA?                   ��"<<endl;
	cout<<"�����������������������������������������������������ө�������������������������������������������"<<endl;
	cout<<"��         ��(Y)           ��        ��(N)        ��"<<endl;
	cout<<"�����������������������������������������������������ک�������������������������������������������"<<endl;
	char y=_getch();if(y=='Y'||y=='y'){f1_1();}else if(y=='n'){f1_2();}
	if(y=='N'){eggcheck(0);f1_2();}
}
void f2(){
	cl();
	cout<<"Games(Mainly Na2S2O3) by 28A_ZYC"<<endl;
	cout<<"Version: 1.0.2"<<endl;
	cout<<"Press     to return to the main menu.";
	color(6);SetPos(6,2);cout<<"[R]";
	color(15);while(tolower(_getch())!='r'){}
}
void f3(){
	cl();
	printf(""
	"V1.0.2\n"
	"  Added 1 function: changelog\n"
	"  Na2S2O3 has the secend ending\n"
	"  Added one nore easter eggs.\n"
	);
	cout<<"Press     to return to the main menu.";
	color(6);SetPos(6,5);cout<<"[R]";
	color(15);while(tolower(_getch())!='r'){}
}




int main(){
	while(endgame!=1){cl();color(15);
		switch(home()){
			case '1':f1();cl();break;
			case 'i':f2();cl();break;
			case 'c':f3();cl();break;
			case 'q':endgame=1;break;
			case 'h':eggcheck(1);
			default:break;
		}
	}	
}
