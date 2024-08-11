#ifndef songs
#define songs

#include<bits/stdc++.h>
using namespace std;
extern "C"{
#include "dgncx.h"
#include "base64.h"
class songs:public dgncx,public base64 {
	public:
		void debug_song(){
			_beep(400,1000);
		}
		void playnote(char a1,char a2,char a3){
			int b1=a1-32;int b2=a2-32;int b3=a3-32;
			if(b1>94||b2>94||b3>94){
				cout<<"你的存档有误，请重新输入(Err Code 1)";_sleep(1000);
				cl();return;
			}
			cout<<"Debug info:\n";
			printf("b1:%d, b2:%d, b3:%d, a1:%d, a2:%d, a3:%d\n",b1,b2,b3,a1,a2,a3);
			cout<<"Freq: "<<(b1*94+b2)<<endl;
			cout<<"Time: "<<b3*100<<endl;
			cout<<"Note will be played in 2000 milisecs.\n\n\n";
			_sleep(2000);
			_beep((b1*94+b2),b3*100);
		}
		void cre(){
			cout<<"请输入频率：";int freq,dur;
			cin>>freq;cout<<"请输入时长(单位：100ms)：";cin>>dur;
			char nt[3];
			nt[0]=freq/94+32;nt[1]=freq-freq/94+32;nt[2]=dur+32;
			string note;
			note=nt;
			printf("这个音符的存档为： [ %s ] ",encode(note).c_str());
		}
		//YWJj   abc
		//cXdx   qwq
		//YWJjcXdx abcqwq
		//encode加密decode解密 
		void imp(){
			cout<<"请输入存档：";
			string p;cin>>p;
			string cundang=decode(p);
			if((cundang.length())%3!=0){
				cout<<"你的存档有误，请重新输入！(Err Code 2)";_sleep(1000);cl();return;
			}
			for(int i=0;i<cundang.length();i+=3){
				printf("%d,%c,%c,%c,%d,%d,%d\n",i,cundang[i],cundang[i+1],cundang[i+2],cundang[i],cundang[i+1],cundang[i+2]);
				playnote(cundang[i],cundang[i+1],cundang[i+2]);
			}
		}
		void nttable(){
			cl();
printf("+-----+------+\n");
printf("| Note| Freq |\n");
printf("+-----+------+\n");
printf("| A2  | 27   |\n");
printf("| #A2 | 29   |\n");
printf("| B2  | 31   |\n");
printf("| C1  | 33   |\n");
printf("| #C1 | 35   |\n");
printf("| D1  | 37   |\n");
printf("| #D1 | 39   |\n");
printf("| E1  | 41   |\n");
printf("| F1  | 44   |\n");
printf("| #F1 | 46   |\n");
printf("| G1  | 49   |\n");
printf("| #G1 | 52   |\n");
printf("| A1  | 55   |\n");
printf("| #A1 | 58   |\n");
printf("| B1  | 62   |\n");
printf("| C   | 65   |\n");
printf("| #C  | 69   |\n");
printf("| D   | 73   |\n");
printf("| #D  | 78   |\n");
printf("| E   | 82   |\n");
printf("| F   | 87   |\n");
printf("| #F  | 92   |\n");
printf("| G   | 98   |\n");
printf("| #G  | 104  |\n");
printf("| A   | 110  |\n");
printf("| #A  | 107  |\n");
printf("| B   | 123  |\n");
printf("| c   | 131  |\n");
printf("| #c  | 139  |\n");
printf("| d   | 147  |\n");
printf("| #d  | 155  |\n");
printf("| e   | 165  |\n");
printf("| f   | 175  |\n");
printf("| #f  | 185  |\n");
printf("| g   | 196  |\n");
printf("| #g  | 208  |\n");
printf("| a   | 220  |\n");
printf("| #a  | 233  |\n");
printf("| b   | 247  |\n");
printf("| c1  | 262  |\n");
printf("| #c1 | 277  |\n");
printf("| d1  | 294  |\n");
printf("| #d1 | 311  |\n");
printf("| e1  | 330  |\n");
printf("| f1  | 349  |\n");
printf("| #f1 | 370  |\n");
printf("| g1  | 392  |\n");
printf("| #g1 | 415  |\n");
printf("| a1  | 440  |\n");
printf("| #a1 | 466  |\n");
printf("| b1  | 492  |\n");
printf("| c2  | 523  |\n");
printf("| #c2 | 554  |\n");
printf("| d2  | 587  |\n");
printf("| #d2 | 622  |\n");
printf("| e2  | 659  |\n");
printf("| f2  | 698  |\n");
printf("| #f2 | 740  |\n");
printf("| g2  | 783  |\n");
printf("| #g2 | 831  |\n");
printf("| a2  | 880  |\n");
printf("| #a2 | 932  |\n");
printf("| b2  | 987  |\n");
printf("| c3  | 1046 |\n");
printf("| #c3 | 1109 |\n");
printf("| d3  | 1175 |\n");
printf("| #d3 | 1244 |\n");
printf("| e3  | 1319 |\n");
printf("| f3  | 1396 |\n");
printf("| #f3 | 1480 |\n");
printf("| g3  | 1568 |\n");
printf("| #g3 | 1661 |\n");
printf("| a3  | 1760 |\n");
printf("| #a3 | 1864 |\n");
printf("| b3  | 1975 |\n");
printf("| c4  | 2093 |\n");
printf("| #c4 | 2218 |\n");
printf("| d4  | 2349 |\n");
printf("| #d4 | 2489 |\n");
printf("| e4  | 2637 |\n");
printf("| f4  | 2793 |\n");
printf("| #f4 | 2960 |\n");
printf("| g4  | 3136 |\n");
printf("| #g4 | 3322 |\n");
printf("| a4  | 3520 |\n");
printf("| #a4 | 3729 |\n");
printf("| b4  | 3951 |\n");
printf("| c5  | 4186 |\n");
printf("+-----+------+\n");
cout<<"按";color(6);cout<<"[R]";
			color(15);cout<<"退出";
			color(15);while(tolower(_getch())!='r'){}
		}
		void main_menu(){
			while(1){
			cl();cl();
			cout<<"=====菜单=====\n";
			cout<<"i: 导入存档\n";
			//cout<<"t: 使用早期创作的存档\n";
			//cout<<"d: 调试一下\n";
			cout<<"c: 创建存档\n";
			cout<<"t. 频率表\n"; 
			cout<<"q: 退出\n";
			cout<<"请选择：\n"; 
			char c=tolower(_getch());
			switch(c){
				case 'i':imp();break;
				case 'd':debug_song();break;
				case 'c':cre();break;
				case 't':nttable();break;
				case 'q':return;break;
				default:system("start info1.vbs");
			}
			}
		}
}a;
}
#endif
