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
char home(){
	cout<<"Welcome to Game Center!";
	char c;cout<<"====Menu===="<<endl;
	cout<<"1. Na2S2O3"<<endl;
	cout<<"2. Info"<<endl;
	cout<<"3. Quit"<<endl;
	cout<<"Please Choose:";c=_getch();return c;
}
void f1_1(){
	
}
void f1_2(){
	
}
void advancement(string inf){
	SetPos(80,2);cout<<1;system("pause");
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
	char y=_getch();if(y=='Y'||y=='y'){f1_1();}else if(y=='N'||y=='n'){f1_2();}
	if(y=='N'){
		if(_getch()=='a'&&_getch()=='2'&&_getch()=='S'&&_getch()=='2'&&_getch()=='O'&&_getch()=='3'){
			advancement("Na2S2O3");
		}
	}
}
void f2(){
	cl();
	cout<<"Games(Mainly Na2S2O3) by 28A_ZYC"<<endl;
	cout<<"Version: 1.0.0 pre-realease 8"<<endl;
	cout<<"Press     to return to the main menu.";
	color(6);SetPos(6,2);cout<<"[R]";
	char r=_getch();if(r=='R'||r=='r'){color(15);return;}
	else{color(15);cl();f2();}
}
int main(){
	while(endgame!=1){cl();color(15);
		switch(home()){
			case '1':f1();cl();break;
			case '2':f2();cl();break;
			case '3':endgame=1;break;
			default:break;
		}
	}	
}
