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
	cl();cout<<"����"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��СA������д��һ������TA�����Լ������⣬�ڴ�����         ��"<<endl;
	cout<<"����TA�Ļ��š������TA�����ҵ�СA��СA���ż����ֽ��ŵ����驧"<<endl;
	cout<<"������TA˵����Ҳϲ���㡣��ʱ��СA������֣����Ǿ�������ʼ ��"<<endl;
	cout<<"�������ˡ��Ͽε�ʱ���Ժ������Ǹ��ֳ��˴˵���Ӱ����������ǩ�"<<endl;
	cout<<"����ĩҪһ��ȥ�����桭���ܿ�Ҫ��ĩ�����ˣ�������������ֻ�Щ�"<<endl;
	cout<<"���˴ˣ�������������ϰ�������ദʱ��ı䳤��СA����TA���� ��"<<endl;
	cout<<"���Ĺ⻷��һ�����ʧ�����ǿ�ʼ������һЩì�ܺ������������ک�"<<endl;
	cout<<"����ʱ��������һ������鱻��ʦ�ͼҳ�֪���ˡ���            ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��The End! Congratulations!                               ��"<<endl;
	cout<<"�����������������������������������������������������������������������ө�������������������������������������������"<<endl;
	cout<<"��               ��(Y)              ��        ��(N)        ��"<<endl;
	cout<<"�����������������������������������������������������������������������ک�������������������������������������������"<<endl;
	_getch();
}
void f1_2(){
	
}
void f1_1_3(){}
void f1_1_2(){}
void f1_2_1(){}
void f1_2_2(){}
void advancement(string inf){
	SetPos(80,2);cout<<"����������������������������������������������������������������";
	SetPos(80,3);cout<<"��                              ��";
	SetPos(80,4);cout<<"��                              ��";
	SetPos(80,5);cout<<"����������������������������������������������������������������";
	SetPos(81,3);cout<<"�Ѵ�ɳɾͣ��ʵ���:"<<nowee<<"/"<<eastereggt;nowee++;
	SetPos(82,4);cout<<inf;
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
	char y=_getch();if(y=='Y'||y=='y'){f1_1();}else if(y=='N'||y=='n'){f1_2();}
	if(y=='N'){
		if(_getch()=='a'&&_getch()=='2'&&_getch()=='S'&&_getch()=='2'&&_getch()=='O'&&_getch()=='3'){
			advancement("N����?!�ǾͰ�Na2S2O3�ɣ�");
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
