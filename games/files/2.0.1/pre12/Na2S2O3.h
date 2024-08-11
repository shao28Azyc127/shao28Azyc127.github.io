#ifndef na
#define na
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
#include "songs.h"
#include "base64.h"
enum Scale{
    Rest=0,
    C8=108,B7=107,A7s=106,A7=105,G7s=104,G7=103,
    F7s=102,F7=101,E7=100,D7s=99,D7=98,C7s=97,
    C7=96,B6=95,A6s=94,A6=93,G6s=92,G6=91,F6s=90,
    F6=89,E6=88,D6s=87,D6=86,C6s=85,C6=84,B5=83,
    A5s=82,A5=81,G5s=80,G5=79,F5s=78,F5=77,E5=76,
    D5s=75,D5=74,C5s=73,C5=72,B4=71,A4s=70,A4=69,
    G4s=68,G4=67,F4s=66,F4=65,E4=64,D4s=63,D4=62,
    C4s=61,C4=60,B3=59,A3s=58,A3=57,G3s=56,G3=55,
    F3s=54,F3=53,E3=52,D3s=51,D3=50,C3s=49,C3=48,
    B2=47,A2s=46,A2=45,G2s=44,G2=43,F2s=42,F2=41,
    E2=40,D2s=39,D2=38,C2s=37,C2=36,B1=35,A1s=34,
    A1=33,G1s=32,G1=31,F1s=30,F1=29,E1=28,D1s=27,
    D1=26,C1s=25,C1=24,B0=23,A0s=22,A0=21
};
enum Voice{
    X1=C2,X2=D2,X3=E2,X4=F2,X5=G2,X6=A2,X7=B2,
    L1=C3,L2=D3,L3=E3,L4=F3,L5=G3,L6=A3,L7=B3,
    M1=C4,M2=D4,M3=E4,M4=F4,M5=G4,M6=A4,M7=B4,
    H1=C5,H2=D5,H3=E5,H4=F5,H5=G5,H6=A5,H7=B5,
    LOW_SPEED=500,MIDDLE_SPEED=400,HIGH_SPEED=300,_=0XFF
};
void RICKROLLing(){
    HMIDIOUT handle;
    midiOutOpen(&handle,0,0,0,CALLBACK_NULL);
    midiOutShortMsg(handle,0<<8|0xCD);
    int volume=0x7f;
	int voice=0;
	int sleep=1000;
    int RR[]={
//H1,H2,500,M5,1000,H2,1000,H3,125,H5,H4,H3,H1,1000,H1,1000,H2,0,500,M5,1000,H2,H1,109,
//M5,M5,M6,H1,M6,H1,1000,
//H1,H2,0,500,M5,1000,H2,1000,H3,125,H5,H4,H3,H1,1000,H1,1000,H2,0,500,M5,1000,H2,H1,
400,L6,L7,M1,M1,M2,600,L7,130,L6,2000,L5,
400,L6,L6,L7,M1,800,L6,400,L5,800,M5,400,M5,M2,200,M3,1200,M2,
400,L6,L6,L7,M1,L6,M1,800,M2,400,L7,L6,1600,L5,
400,L6,L6,L7,M1,L6,800,L5,400,M2,M2,M2,M3,600,M3,M2,
400,M1,M2,M3,M1,M2,M2,M2,M3,M2,L5, 
    };
    for(auto i:RR){
        if(i>108){sleep=i;continue;}
        else if(i==0){sleep=175;continue;}
        if(i==700){Sleep(200);sleep=400;continue;}
//        if(i==_){Sleep(200);continue;}
        if(i>10000){volume+=(i-10000);}
        voice=(volume<<16)+((i)<<8)+0x9D;
        midiOutShortMsg(handle,voice);
        Sleep(sleep);
        midiOutShortMsg(handle,0x7bbD);
    }
    midiOutClose(handle);
}
class f1:public dgncx{
	public: 
		bool endgame=false;int eastereggt=5;
		void cl(){system("cls");}
//		void main_menu(){
//			while(1){
//			cl();cl();
//			cout<<"=====菜单=====\n";
//			cout<<"i: 导入存档\n";
//			//cout<<"t: 使用早期创作的存档\n";
//			//cout<<"d: 调试一下\n";
//			cout<<"c: 创建存档\n";
//			cout<<"t. 频率表\n"; 
//			cout<<"q: 退出\n";
//			cout<<"请选择：\n"; 
//			char c=tolower(_getch());
//			switch(c){
//				case 'i':imp();break;
//				case 'd':debug_song();break;
//				case 'c':cre();break;
//				case 't':nttable();break;
//				case 'q':return;break;
//				default:system("start info1.vbs");
//			}
//			}
//		}
		void homes(){
			
			while(endgame!=1){cl();color(15);
				switch(homet()){
					case '1':fm1();cl();break;
					case '2':f2();cl();break;
					case 'f':f2();cl();break;
//					case 'b':menub64();break;
//					case 's':main_menu();break;
					case 'r':RICKROLLing();break;
					case 'c': f3();cl();break;
					case 'q':endgame=1;break;
					case 'm':eggcheck(1);break;
					case 'z':eggcheck(3);break;
					case '8':eggcheck(2);break;
					case 'd':eggcheck(114);break;
					case 'i':eggcheck(0);break;
					default:system("start info1.vbs");break;
				}
			}
		}
		
		int nowee[5]={0,0,0,0,0},
	    endid[5]={0,0,0,0,0};
		string infoee[5]={
			"你想导入存档？",
			"Minecraft!",
			"ylj:你什么意思啊？",
			"你把作者敲上去干嘛？",
			"调..调试模式？！" },
		endinfo[5]={
			"高兴的结局",
			"不高兴的结局",
			"原汁原味的硫代硫酸钠",
			"保护255实锤！",
			"这个结局有点怪"};
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
			cl();cout<<"调试模式（按“debug”就会出来！）";
			SetPos(0,2);color(0xE1);cout<<"调试模式（ZYC搞的）\n按“debug”还获得一个《踩蛋》！";
			color(15);eggcheck(5);
			fm1();Sleep(1000);f2();Sleep(1000);
			f1_1_1();f1_1_2();f1_1_3();f1_2_1();f1_2_2();
		}
		
		void eggcheck(int id){
			if(id==0){//import
				if(_getch()=='m'&&_getch()=='p'&&_getch()=='o'&&_getch()=='r'&&_getch()=='t'){
					advancement(0);
				}
			}else if(id==1){//minecraft
				if(_getch()=='i'&&_getch()=='n'&&_getch()=='e'&&_getch()=='c'&&_getch()=='r'&&_getch()=='a'&&_getch()=='f'&&_getch()=='t'){
					advancement(1);
				}
			}else if(id==2){//84579
				if(_getch()=='4'&&_getch()=='5'&&_getch()=='7'&&_getch()=='9'){
					advancement(2);
				}
			}else if(id==3){//zyc
				if(_getch()=='y'&&_getch()=='c'){
					advancement(3);
				}
			}else if(id==114){//debug
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
			cl();cout<<"剧情"<<endl;
			cout<<"┍───────────────────────────────────────────────┓"<<endl;
			cout<<"┃小A忐忑的写了一封信向TA表明自己的心意，期待着收┃"<<endl;
			cout<<"┃到TA的回信。两天后TA主动找到小A，小A怀着激动又 ┃"<<endl;
			cout<<"┃紧张的心情听到TA说：我也喜欢你。此时的小A激动万┃"<<endl;
			cout<<"┃分，他们就这样开始交往了。上课的时候脑海里总是 ┃"<<endl;
			cout<<"┃浮现出彼此的身影，经常想的是周末要一起去哪里   ┃"<<endl;
			cout<<"┃玩……很快要期末考试了，他们俩的心中只有彼此， ┃"<<endl;
			cout<<"┃静不下心来复习。随着相处时间的变长，小A觉得TA身┃"<<endl;
			cout<<"┃上的光环在一点点消失，他们开始出现了一些矛盾和 ┃"<<endl;
			cout<<"┃争吵。而就在此时，他们在一起的事情被老师和家长 ┃"<<endl;
			cout<<"┃知道了……                                     ┃"<<endl;
			cout<<"├───────────────────────────────────────────────┥"<<endl;
			cout<<"┃          没了！(高兴的结局)!恭喜！!           ┃"<<endl;
			cout<<"├───────────────────────────────────────────────┥"<<endl;
			cout<<"┃                 按   重来                     ┃"<<endl;
			cout<<"┖───────────────────────────────────────────────┙"<<endl;
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
			cl();cout<<"剧情"<<endl;
			cout<<"┍───────────────────────────────────────────────┓"<<endl;
			cout<<"┃小A向TA表白的事情被班里的同学知道了，这条爆炸性┃"<<endl;
			cout<<"┃的新闻迅速在班级内传播、蔓延，同学们议论纷纷， ┃"<<endl;
			cout<<"┃并且传到最后已经变了味道。小A很害怕，不知道怎么┃"<<endl;
			cout<<"┃应对这样的流言蜚语，小A感到无助与卑微，而此时TA┃"<<endl;
			cout<<"┃也被卷入了舆论中心……                         ┃"<<endl;
			cout<<"├───────────────────────────────────────────────┥"<<endl;
			cout<<"┃      没了！(原汁原味的硫代硫酸钠)!恭喜！!     ┃"<<endl;
			cout<<"├───────────────────────────────────────────────┥"<<endl;
			cout<<"┃                 按   重来                     ┃"<<endl;
			cout<<"┖───────────────────────────────────────────────┙"<<endl;
			color(6);SetPos(20,10);cout<<"[R]";
			color(15);ending(2);
			color(15);while(tolower(_getch())!='r'){}
		}
		void f1_1_2(){
			cl();cout<<"剧情"<<endl;
			cout<<"┍───────────────────────────────────────────────┓"<<endl;
			cout<<"┃小A鼓足勇气向喜欢的TA表明了自己的心意，结果得到┃"<<endl;
			cout<<"┃了TA的拒绝。接下来的一整天小A都浑浑噩噩的，课上┃"<<endl;
			cout<<"┃也不知道老师都讲了些什么，回到家里自己反复的听 ┃"<<endl;
			cout<<"┃着他们共同喜欢的歌曲，刷着他们的聊天记录，流下 ┃"<<endl;
			cout<<"┃了眼泪。之后的一段时间，小A一直打不起精神，并且┃"<<endl;
			cout<<"┃不知道该怎样与TA相处，好像已经做不回好朋友     ┃"<<endl;
			cout<<"┃了……                                         ┃"<<endl;
			cout<<"├───────────────────────────────────────────────┥"<<endl;
			cout<<"┃         没了！(不高兴的结局)!恭喜！!          ┃"<<endl;
			cout<<"├───────────────────────────────────────────────┥"<<endl;
			cout<<"┃                 按   重来                     ┃"<<endl;
			cout<<"┖───────────────────────────────────────────────┙"<<endl;
			color(6);SetPos(20,12);cout<<"[R]";
			color(15);ending(1);
			color(15);while(tolower(_getch())!='r'){}
		}
		void f1_2_1(){
			cl();cout<<"剧情"<<endl;
			cout<<"┍───────────────────────────────────────────────┓"<<endl;
			cout<<"┃TA的形象在小A的日记本中逐渐清晰。TA的成绩很棒，┃"<<endl;
			cout<<"┃为人开朗又热情。越是心仪的东西越是不敢靠近，小 ┃"<<endl;
			cout<<"┃A总是装作默然，但心里却溢满惴惴不安。小A觉得只 ┃"<<endl;
			cout<<"┃有优秀的人才可以和TA并肩站在灿烂的阳光下。小A  ┃"<<endl;
			cout<<"┃希望像TA吸引小A一样，有一天小A也能让TA侧目。一 ┃"<<endl;
			cout<<"┃向不太努力的小A把全部精力都投入到了学习中，投  ┃"<<endl;
			cout<<"┃入到了发展自我中……                           ┃"<<endl;
			cout<<"├───────────────────────────────────────────────┥"<<endl;
			cout<<"┃        没了！(这个结局有点怪)!恭喜！!         ┃"<<endl;
			cout<<"├───────────────────────────────────────────────┥"<<endl;
			cout<<"┃                 按   重来                     ┃"<<endl;
			cout<<"┖───────────────────────────────────────────────┙"<<endl;
			color(6);SetPos(20,12);cout<<"[R]";
			color(15);ending(4);
			color(15);while(tolower(_getch())!='r'){}
		}
		void f1_2_2(){
			cl();cout<<"剧情"<<endl;
			cout<<"┍───────────────────────────────────────────────┓"<<endl;
			cout<<"┃这份喜欢压在小A心头，小A不确定是否要告诉TA，不 ┃"<<endl;
			cout<<"┃确定告诉TA的结果会是什么？自己能否承担起这份结 ┃"<<endl;
			cout<<"┃果？是否是对彼此最好的选择？思索了一段时间，小 ┃"<<endl;
			cout<<"┃A决定以朋友的身份默默守护。小A在TA需要的时候提 ┃"<<endl;
			cout<<"┃供帮助，两个人互相鼓励，共同成长。小A用自己的力┃"<<endl;
			cout<<"┃量守护着这个秘密，也守护着想要守护的人……     ┃"<<endl;
			cout<<"├───────────────────────────────────────────────┥"<<endl;
			cout<<"┃          没了！(保护255实锤)!恭喜！!          ┃"<<endl;
			cout<<"├───────────────────────────────────────────────┥"<<endl;
			cout<<"┃                 按   重来                     ┃"<<endl;
			cout<<"┖───────────────────────────────────────────────┙"<<endl;
			color(6);SetPos(20,11);cout<<"[R]";
			color(15);ending(3);
			color(15);while(tolower(_getch())!='r'){}
		}
		void advancement(int id){
			SetPos(80,2);cout<<"┍──────────────────────────────┐";
			SetPos(80,3);cout<<"┃                              ┃";
			SetPos(80,4);cout<<"┃                              ┃";
			SetPos(80,5);cout<<"└──────────────────────────────┚";
			SetPos(81,3);nowee[id]=1;cout<<"已达成彩蛋:"<<eet()<<"/"<<eastereggt;
			SetPos(82,4);cout<<infoee[id];
			Sleep(500);
		}
		void ending(int id){
			SetPos(80,2);cout<<"┍──────────────────────────────┐";
			SetPos(80,3);cout<<"┃                              ┃";
			SetPos(80,4);cout<<"┃                              ┃";
			SetPos(80,5);cout<<"└──────────────────────────────┚";
			SetPos(81,3);endid[id]=1;cout<<"已达成结尾:"<<endt()<<"/"<<5;
			SetPos(82,4);cout<<endinfo[id];
			Sleep(500);
		}
		void fm1(){
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
			char y=_getch();if(y=='Y'||y=='y'){f1_1();}else if(y=='n'||y=='N'){f1_2();}
			//if(y=='i'){eggcheck(0);}
		}
		void f2(){
			cl();
			cout<<"28AZYC做的硫代硫酸钠"<<endl;
			cout<<"2.0.0pre19版"<<endl;
			cout<<"按   来返回主菜单";
			color(6);SetPos(2,2);cout<<"[R]";
			color(15);while(tolower(_getch())!='r'){}
		}
		void f3(){
			cl();
			printf(""
			"V2.0.1pre8\n"
			"  \n\n"
//			"  编译成功了！！！！！\n"
			"  如何清空踩蛋代码缓存区：按“i”，再按“r”" 
			"  那么我可以出新踩蛋了！！！！！\n"
			"  以前踩蛋达成方式（需要清空缓存区再按）：\n"
			"  1. debug\n"
			"  2. elephant\n"
			"  3. homo\n"
			"  4. geek\n"
			"  5. Na2S2O3(要在选择是否告诉那块（Y/N）按才有效！)\n"
			);
			cout<<"  按   回到主菜单"<<endl;
			SetPos(2,2);color(0xE1);cout<<"你居然找到了《更新日志》！";
			color(6);SetPos(4,10);cout<<"[R]";
			color(15);while(tolower(_getch())!='r'){}
		}
}; 
#endif
