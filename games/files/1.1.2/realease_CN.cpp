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
void debug();
//endid



int nowee[5]={0,0,0,0,0},
    endid[5]={0,0,0,0,0};
string infoee[5]={
	"N����?!�ǾͰ�Na2S2O3�ɣ�",
	"������",
	"Ele!",
	"Geek!",
	"��..����ģʽ����" },
endinfo[5]={
	"���˵Ľ��",
	"�����˵Ľ��",
	"ԭ֭ԭζ�����������",
	"����255ʵ����",
	"�������е��"};
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
	return endid[0]+endid[1]+endid[2]+endid[3]+endid[4];
}
void debug(){
	cl();cout<<"����ģʽ������debug���ͻ��������";
	SetPos(0,2);color(0xE1);cout<<"����ģʽ��ZYC��ģ�\n����debug�������һ�����ȵ�����";
	color(15);eggcheck(5);
	f1();Sleep(1000);f2();Sleep(1000);
	f1_1_1();f1_1_2();f1_1_3();f1_2_1();f1_2_2();
}
char home(){
	cout<<"28AZYC������������ƣ�֮��׼���ӵ��ģ�\n"; 
	cout<<"С��ʾ��������5���ʵ���ʵ������Դ�ɣ���ɷ�ʽ����2.0.0pre18�Ժ��һ������ɹ��İ汾������\n\n"; 
	char c;cout<<"====Menu===="<<endl;
	cout<<"1. ���������"<<endl;
	cout<<"i. һЩ��Ϣ"<<endl;
	//cout<<"c. Changelog"<<endl;
	cout<<"q. �˳���Ϸ"<<endl;
	cout<<"ѡһ���ɣ�";c=_getch();return tolower(c);
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
	}else if(id==2){
		if(_getch()=='l'&&_getch()=='e'&&_getch()=='p'&&_getch()=='h'&&_getch()=='a'&&_getch()=='n'&&_getch()=='t'){
			advancement(2);
		}
	}else if(id==3){
		if(_getch()=='e'&&_getch()=='e'&&_getch()=='k'){
			advancement(3);
		}
	}else if(id==114){
		if(_getch()=='e'&&_getch()=='b'&&_getch()=='u'&&_getch()=='g'){
			debug();
		}
	}else if(id==5){
		if(_getch()=='d'&&_getch()=='e'&&_getch()=='b'&&_getch()=='u'&&_getch()=='g'){
			advancement(4);
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
	cout<<"��          û�ˣ�(���˵Ľ��)!��ϲ��!           ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��                 ��   ����                     ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	color(6);SetPos(20,15);cout<<"[R]";
	color(15);ending(0);
	color(15);while(tolower(_getch())!='r'){}
}
void f1_2(){
	int a=ri(1,2);
	if(a%2==0){
		f1_2_1();
	}else{
		f1_2_2();
	}
}
void f1_1_3(){
	cl();cout<<"����"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��СA��TA��׵����鱻�����ͬѧ֪���ˣ�������ը�ԩ�"<<endl;
	cout<<"��������Ѹ���ڰ༶�ڴ��������ӣ�ͬѧ�����۷׷ף� ��"<<endl;
	cout<<"�����Ҵ�������Ѿ�����ζ����СA�ܺ��£���֪����ô��"<<endl;
	cout<<"��Ӧ���������������СA�е������뱰΢������ʱTA��"<<endl;
	cout<<"��Ҳ���������������ġ���                         ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��      û�ˣ�(ԭ֭ԭζ�����������)!��ϲ��!     ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��                 ��   ����                     ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	color(6);SetPos(20,10);cout<<"[R]";
	color(15);ending(2);
	color(15);while(tolower(_getch())!='r'){}
}
void f1_1_2(){
	cl();cout<<"����"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��СA����������ϲ����TA�������Լ������⣬����õ���"<<endl;
	cout<<"����TA�ľܾ�����������һ����СA�����جج�ģ����ϩ�"<<endl;
	cout<<"��Ҳ��֪����ʦ������Щʲô���ص������Լ��������� ��"<<endl;
	cout<<"�������ǹ�ͬϲ���ĸ�����ˢ�����ǵ������¼������ ��"<<endl;
	cout<<"�������ᡣ֮���һ��ʱ�䣬СAһֱ�����񣬲��ҩ�"<<endl;
	cout<<"����֪����������TA�ദ�������Ѿ������غ�����     ��"<<endl;
	cout<<"���ˡ���                                         ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��         û�ˣ�(�����˵Ľ��)!��ϲ��!          ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��                 ��   ����                     ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	color(6);SetPos(20,12);cout<<"[R]";
	color(15);ending(1);
	color(15);while(tolower(_getch())!='r'){}
}
void f1_2_1(){
	cl();cout<<"����"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��TA��������СA���ռǱ�����������TA�ĳɼ��ܰ�����"<<endl;
	cout<<"��Ϊ�˿��������顣Խ�����ǵĶ���Խ�ǲ��ҿ�����С ��"<<endl;
	cout<<"��A����װ��ĬȻ��������ȴ�����㷲�����СA����ֻ ��"<<endl;
	cout<<"����������˲ſ��Ժ�TA����վ�ڲ��õ������¡�СA  ��"<<endl;
	cout<<"��ϣ����TA����СAһ������һ��СAҲ����TA��Ŀ��һ ��"<<endl;
	cout<<"����̫Ŭ����СA��ȫ��������Ͷ�뵽��ѧϰ�У�Ͷ  ��"<<endl;
	cout<<"���뵽�˷�չ�����С���                           ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��        û�ˣ�(�������е��)!��ϲ��!         ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��                 ��   ����                     ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	color(6);SetPos(20,12);cout<<"[R]";
	color(15);ending(4);
	color(15);while(tolower(_getch())!='r'){}
}
void f1_2_2(){
	cl();cout<<"����"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"�����ϲ��ѹ��СA��ͷ��СA��ȷ���Ƿ�Ҫ����TA���� ��"<<endl;
	cout<<"��ȷ������TA�Ľ������ʲô���Լ��ܷ�е�����ݽ� ��"<<endl;
	cout<<"�������Ƿ��ǶԱ˴���õ�ѡ��˼����һ��ʱ�䣬С ��"<<endl;
	cout<<"��A���������ѵ����ĬĬ�ػ���СA��TA��Ҫ��ʱ���� ��"<<endl;
	cout<<"���������������˻����������ͬ�ɳ���СA���Լ�������"<<endl;
	cout<<"�����ػ���������ܣ�Ҳ�ػ�����Ҫ�ػ����ˡ���     ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��          û�ˣ�(����255ʵ��)!��ϲ��!          ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��                 ��   ����                     ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	color(6);SetPos(20,11);cout<<"[R]";
	color(15);ending(3);
	color(15);while(tolower(_getch())!='r'){}
}
void advancement(int id){
	SetPos(80,2);cout<<"����������������������������������������������������������������";
	SetPos(80,3);cout<<"��                              ��";
	SetPos(80,4);cout<<"��                              ��";
	SetPos(80,5);cout<<"����������������������������������������������������������������";
	SetPos(81,3);nowee[id]=1;cout<<"�Ѵ�ɲʵ�:"<<eet()<<"/"<<eastereggt;
	SetPos(82,4);cout<<infoee[id];
	Sleep(500);
}
void ending(int id){
	SetPos(80,2);cout<<"����������������������������������������������������������������";
	SetPos(80,3);cout<<"��                              ��";
	SetPos(80,4);cout<<"��                              ��";
	SetPos(80,5);cout<<"����������������������������������������������������������������";
	SetPos(81,3);endid[id]=1;cout<<"�Ѵ�ɽ�β:"<<endt()<<"/"<<5;
	SetPos(82,4);cout<<endinfo[id];
	Sleep(500);
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
	cout<<"28AZYC�������������"<<endl;
	cout<<"1.1.2��"<<endl;
	cout<<"��   ���������˵�";
	color(6);SetPos(2,2);cout<<"[R]";
	color(15);while(tolower(_getch())!='r'){}
}
void f3(){
	cl();
	printf(""
	"V1.1.2\n"
	"  \n"
	"  ���˵���ģʽ��\n"
	"  ���ڸ����ˣ�\n"
	"  �ּ���һ���ȵ���\n"
	);
	cout<<"  ��   �ص����˵�"<<endl;
	SetPos(2,2);color(0xE1);cout<<"���Ȼ�ҵ��ˡ�������־����";
	color(6);SetPos(4,5);cout<<"[R]";
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
			case 'e':eggcheck(2);
			case 'g':eggcheck(3);
			case 'd':eggcheck(114);
			default:break;
		}
	}cl();cout<<"��л����qwq\n\n";system("pause");
	return 0;
}
