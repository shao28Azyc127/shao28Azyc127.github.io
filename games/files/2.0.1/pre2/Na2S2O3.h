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
class f1:public dgncx{
	public: 
		bool endgame=false;int eastereggt=5;
		void cl(){system("cls");}
		void homes(){
			
			while(endgame!=1){cl();color(15);
				switch(homet()){
					case '1':fm1();cl();break;
					case '2':f2();cl();break;
					case 'f':f2();cl();break;
					case 'b':b64.menub64();break;
					case 's':a.main_menu();break;
					case 'c':f3();cl();break;
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
			"V2.0.0pre20\n"
			"  \n\n"
			"  编译成功了！！！！！\n"
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
			color(6);SetPos(4,11);cout<<"[R]";
			color(15);while(tolower(_getch())!='r'){}
		}
}; 
