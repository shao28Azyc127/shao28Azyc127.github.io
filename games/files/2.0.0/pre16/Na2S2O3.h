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
class f1:public mainfunc{
	public:
		int eet(){
			return nowee[0]+nowee[1]+nowee[2]+nowee[3]+nowee[4];
		}
		int endt(){
			return end[0]+end[1]+end[2]+end[3]+end[4];
		}
		void debug(){
			cl();cout<<"Debug Mode(Type \'f1_DEBUG\' to access)";
			f1();Sleep(1000);/*fi();*/Sleep(1000);
			f1_1_1();f1_1_2();f1_1_3();f1_2_1();f1_2_2();
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
			cout<<"┃知道了......                                   ┃"<<endl;
			cout<<"├───────────────────────────────────────────────┥"<<endl;
			cout<<"┃    The end!(Happy Ending)!Congratulations!    ┃"<<endl;
			cout<<"├───────────────────────────────────────────────┥"<<endl;
			cout<<"┃           Press     to retry                  ┃"<<endl;
			cout<<"┖───────────────────────────────────────────────┙"<<endl;
			color(6);dgncx.SetPos(18,15);cout<<"[R]";
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
			cout<<"┃也被卷入了舆论中心......                       ┃"<<endl;
			cout<<"├───────────────────────────────────────────────┥"<<endl;
			cout<<"┃   The end!(Na2S2O3 Ending)!Congratulations!   ┃"<<endl;
			cout<<"├───────────────────────────────────────────────┥"<<endl;
			cout<<"┃           Press     to retry                  ┃"<<endl;
			cout<<"┖───────────────────────────────────────────────┙"<<endl;
			color(6);dgncx.SetPos(18,10);cout<<"[R]";
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
			cout<<"┃了......                                       ┃"<<endl;
			cout<<"├───────────────────────────────────────────────┥"<<endl;
			cout<<"┃    The end!(Sad Ending)!Congratulations!      ┃"<<endl;
			cout<<"├───────────────────────────────────────────────┥"<<endl;
			cout<<"┃           Press     to retry                  ┃"<<endl;
			cout<<"┖───────────────────────────────────────────────┙"<<endl;
			color(6);dgncx.SetPos(18,12);cout<<"[R]";
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
			cout<<"┃入到了发展自我中......                         ┃"<<endl;
			cout<<"├───────────────────────────────────────────────┥"<<endl;
			cout<<"┃ The end!(Sublimation Ending)!Congratulations! ┃"<<endl;
			cout<<"├───────────────────────────────────────────────┥"<<endl;
			cout<<"┃           Press     to retry                  ┃"<<endl;
			cout<<"┖───────────────────────────────────────────────┙"<<endl;
			color(6);dgncx.SetPos(18,12);cout<<"[R]";
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
			cout<<"┃量守护着这个秘密，也守护着想要守护的人......   ┃"<<endl;
			cout<<"├───────────────────────────────────────────────┥"<<endl;
			cout<<"┃  The end!(Protection Ending)!Congratulations! ┃"<<endl;
			cout<<"├───────────────────────────────────────────────┥"<<endl;
			cout<<"┃           Press     to retry                  ┃"<<endl;
			cout<<"┖───────────────────────────────────────────────┙"<<endl;
			color(6);dgncx.SetPos(18,11);cout<<"[R]";
			color(15);ending(3);
			color(15);while(tolower(_getch())!='r'){}
		}
		void advancement(int id){
			dgncx.SetPos(80,2);cout<<"┍──────────────────────────────┐";
			dgncx.SetPos(80,3);cout<<"┃                              ┃";
			dgncx.SetPos(80,4);cout<<"┃                              ┃";
			dgncx.SetPos(80,5);cout<<"└──────────────────────────────┚";
			dgncx.SetPos(81,3);nowee[id]=1;cout<<"已达成彩蛋:"<<eet()<<"/"<<eastereggt;
			dgncx.SetPos(82,4);cout<<infoee[id];
			Sleep(3000);
		}
		void ending(int id){
			dgncx.SetPos(80,2);cout<<"┍──────────────────────────────┐";
			dgncx.SetPos(80,3);cout<<"┃                              ┃";
			dgncx.SetPos(80,4);cout<<"┃                              ┃";
			dgncx.SetPos(80,5);cout<<"└──────────────────────────────┚";
			dgncx.SetPos(81,3);end[id]=1;cout<<"已达成结尾:"<<endt()<<"/"<<5;
			dgncx.SetPos(82,4);cout<<endinfo[id];
			Sleep(3000);
		}
		void f1_main(){
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
			char y=_getch();if(y=='Y'||y=='y'){f1_1();}else if(y=='n'){f1_2();}
			if(y=='N'){eggcheck(0);f1_2();}
		}
}; 
