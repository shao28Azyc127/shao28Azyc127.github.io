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

		
};
class mainfunc:public dgncx{
	// Private section
	public:
		int nowee[5]={0,0,0,0,0},
    	end[5]  ={0,0,0,0,0};
		string infoee[5]={
			"N����?!�ǾͰ�Na2S2O3�ɣ�",
			"������",
			"Ele!",
			"Geek!",
			"" },
		endinfo[5]={
			"Happy Ending",
			"Sad Ending",
			"Na2S2O3 Ending",
			"Protection Ending",
			"Sublimation Ending"};
		bool endgame=false;int eastereggt=5;
		void home(){
			dgncx hhhhh;
			srand(time(0));
			while(endgame!=1){dgncx.cl();dgncx.color(15);
				switch(info()){
					case '1':f1();cl();break;
					case '2':f2();cl();break;
					case 'i':fi();cl();break;
					case 'q':endgame=1;break;
					case 'h':f1_EGGCHECK(1);break;
					case 'e':f1_EGGCHECK(2);break;
					case 'g':f1_EGGCHECK(3);break;
					case 'd':f1_EGGCHECK(114);break;
					default:break;
				}
			}
		}
		char info(){
			cout<<"Welcome to Games By 28AZYC!\n";
			char c;cout<<"====Menu===="<<endl;
			cout<<"1. Na2S2O3"<<endl;
			cout<<"2. Minesweeper"<<endl;
			cout<<"i. Info"<<endl;
			cout<<"c. Changelog"<<endl;
			cout<<"q. Quit"<<endl;
			cout<<"Please Choose:";c=_getch();return tolower(c);
		}
	protected:
		// Protected Declarations
};

/*
//decleartion before everything��
//dgncx 

//dgncx
//global
int ri(int,int);
char home();
//g
void f1_1();
void f1_1_1();
void f1_2();
void f1_1_3();
void f1_1_2();
void f1_2_1();
void f1_2_2();
void f1_ADVANCEMENT(int);
void f1();
void fi();
void fc();
int f1_EET();
int f1_ENDT();
void f1_ENDING(int);
void f1_EGGCHECK(int);
void f1_DEBUG();
void f2();
char f2_HOME();
void f2_1();
void f2_2();
void f2_3();
void f2_4();
void f2_PLAY();
void f2_GENERATE_MAPS(int,int,int);
void f2_DRAWMAP(int,int);
//end



int nowee[5]={0,0,0,0,0},
    end[5]  ={0,0,0,0,0};
string infoee[5]={
	"N����?!�ǾͰ�Na2S2O3�ɣ�",
	"������",
	"Ele!",
	"Geek!",
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
	return (rand()%(end-start+1))+start;
} 
int f1_EET(){
	return nowee[0]+nowee[1]+nowee[2]+nowee[3]+nowee[4];
}
int f1_ENDT(){
	return end[0]+end[1]+end[2]+end[3]+end[4];
}
void f1_DEBUG(){
	cl();cout<<"Debug Mode(Type \'f1_DEBUG\' to access)";
	f1();Sleep(1000);fi();Sleep(1000);
	f1_1_1();f1_1_2();f1_1_3();f1_2_1();f1_2_2();
}
char home(){
	cout<<"Welcome to Games By 28AZYC!\n";
	char c;cout<<"====Menu===="<<endl;
	cout<<"1. Na2S2O3"<<endl;
	cout<<"2. Minesweeper"<<endl;
	cout<<"i. Info"<<endl;
	cout<<"c. Changelog"<<endl;
	cout<<"q. Quit"<<endl;
	cout<<"Please Choose:";c=_getch();return tolower(c);
}
void f1_EGGCHECK(int id){
	if(id==0){
		if(_getch()=='a'&&_getch()=='2'&&_getch()=='S'&&_getch()=='2'&&_getch()=='O'&&_getch()=='3'){
			f1_ADVANCEMENT(0);
		}
	}else if(id==1){
		if(_getch()=='o'&&_getch()=='m'&&_getch()=='o'){
			f1_ADVANCEMENT(1);
		}
	}else if(id==2){
		if(_getch()=='l'&&_getch()=='e'&&_getch()=='p'&&_getch()=='h'&&_getch()=='a'&&_getch()=='n'&&_getch()=='t'){
			f1_ADVANCEMENT(2);
		}
	}else if(id==3){
		if(_getch()=='e'&&_getch()=='e'&&_getch()=='k'){
			f1_ADVANCEMENT(3);
		}
	}else if(id==114){
		if(_getch()=='e'&&_getch()=='b'&&_getch()=='u'&&_getch()=='g'){
			f1_DEBUG();
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
	cout<<"��֪����......                                   ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��    The end!(Happy Ending)!Congratulations!    ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��           Press     to retry                  ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	color(6);SetPos(18,15);cout<<"[R]";
	color(15);f1_ENDING(0);
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
	cout<<"��Ҳ����������������......                       ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��   The end!(Na2S2O3 Ending)!Congratulations!   ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��           Press     to retry                  ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	color(6);SetPos(18,10);cout<<"[R]";
	color(15);f1_ENDING(2);
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
	cout<<"����......                                       ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��    The end!(Sad Ending)!Congratulations!      ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��           Press     to retry                  ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	color(6);SetPos(18,12);cout<<"[R]";
	color(15);f1_ENDING(1);
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
	cout<<"���뵽�˷�չ������......                         ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"�� The end!(Sublimation Ending)!Congratulations! ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��           Press     to retry                  ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	color(6);SetPos(18,12);cout<<"[R]";
	color(15);f1_ENDING(4);
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
	cout<<"�����ػ���������ܣ�Ҳ�ػ�����Ҫ�ػ�����......   ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��  The end!(Protection Ending)!Congratulations! ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	cout<<"��           Press     to retry                  ��"<<endl;
	cout<<"��������������������������������������������������������������������������������������������������"<<endl;
	color(6);SetPos(18,11);cout<<"[R]";
	color(15);f1_ENDING(3);
	color(15);while(tolower(_getch())!='r'){}
}
void f1_ADVANCEMENT(int id){
	SetPos(80,2);cout<<"����������������������������������������������������������������";
	SetPos(80,3);cout<<"��                              ��";
	SetPos(80,4);cout<<"��                              ��";
	SetPos(80,5);cout<<"����������������������������������������������������������������";
	SetPos(81,3);nowee[id]=1;cout<<"�Ѵ�ɲʵ�:"<<f1_EET()<<"/"<<eastereggt;
	SetPos(82,4);cout<<infoee[id];
	Sleep(3000);
}
void f1_ENDING(int id){
	SetPos(80,2);cout<<"����������������������������������������������������������������";
	SetPos(80,3);cout<<"��                              ��";
	SetPos(80,4);cout<<"��                              ��";
	SetPos(80,5);cout<<"����������������������������������������������������������������";
	SetPos(81,3);end[id]=1;cout<<"�Ѵ�ɽ�β:"<<f1_ENDT()<<"/"<<5;
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
	if(y=='N'){f1_EGGCHECK(0);f1_2();}
}
void fi(){
	cl();
	cout<<"Games(Na2S2O3+Minesweeper) by 28A_ZYC"<<endl;
	cout<<"Version: 2.0.0 pre-realease 3"<<endl;
	cout<<"Press     to return to the main menu.";
	color(6);SetPos(6,2);cout<<"[R]";
	color(15);while(tolower(_getch())!='r'){}
}
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
	cout<<"X ��\n������" ;
	//cols
	for(int i=0;i<l;i++){
		SetPos(4+3*i,0);
		printf("%-3d",i);
		SetPos(4+3*i,1);
		printf("������");
		//Sleep(1000);
	}
	//rows
	for(int i=0;i<r;i++){
		SetPos(0,2+3*i);
		printf("%-2d��\n  ��\n  ��",i);
		Sleep(1000);
	}Sleep(3000);
	/*
	X ��
	������
	Num  
	������
	
	Nu��
 	 m��
	  ��
	  
	 ���� ��
	 ��N��
	 ������
	 
	 (red)
	 ���� ��
	 ��X��
	 ������
	***
	Sleep(1000);
}
void f2_PLAY(){
	
}



int main(){
	srand(time(0));
	while(endgame!=1){cl();color(15);
		switch(home()){
			case '1':f1();cl();break;
			case '2':f2();cl();break;
			case 'i':fi();cl();break;
			case 'q':endgame=1;break;
			case 'h':f1_EGGCHECK(1);
			case 'e':f1_EGGCHECK(2);
			case 'g':f1_EGGCHECK(3);
			case 'd':f1_EGGCHECK(114);
			default:break;
		}
	}	
}
*/
