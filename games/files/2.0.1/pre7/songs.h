#ifndef songs
#define songs

#include<bits/stdc++.h>
using namespace std;
extern "C"{
#include "dgncx.h"
#include "base64.h"
class songs:public dgncx,public base64 {
	public:
		enum Scale

		{
		
		  Rest = 0, C8 = 108, B7 = 107, A7s = 106, A7 = 105, G7s = 104, G7 = 103, F7s = 102, F7 = 101, E7 = 100,
		
		  D7s = 99, D7 = 98, C7s = 97, C7 = 96, B6 = 95, A6s = 94, A6 = 93, G6s = 92, G6 = 91, F6s = 90, F6 = 89,
		
		  E6 = 88, D6s = 87, D6 = 86, C6s = 85, C6 = 84, B5 = 83, A5s = 82, A5 = 81, G5s = 80, G5 = 79, F5s = 78,
		
		  F5 = 77, E5 = 76, D5s = 75, D5 = 74, C5s = 73, C5 = 72, B4 = 71, A4s = 70, A4 = 69, G4s = 68, G4 = 67,
		
		  F4s = 66, F4 = 65, E4 = 64, D4s = 63, D4 = 62, C4s = 61, C4 = 60, B3 = 59, A3s = 58, A3 = 57, G3s = 56,
		
		  G3 = 55, F3s = 54, F3 = 53, E3 = 52, D3s = 51, D3 = 50, C3s = 49, C3 = 48, B2 = 47, A2s = 46, A2 = 45,
		
		  G2s = 44, G2 = 43, F2s = 42, F2 = 41, E2 = 40, D2s = 39, D2 = 38, C2s = 37, C2 = 36, B1 = 35, A1s = 34,
		
		  A1 = 33, G1s = 32, G1 = 31, F1s = 30, F1 = 29, E1 = 28, D1s = 27, D1 = 26, C1s = 25, C1 = 24, B0 = 23,
		
		  A0s = 22, A0 = 21
		
		};
		
		enum Voice
		
		{
		
		  X1 = C2, X2 = D2, X3 = E2, X4 = F2, X5 = G2, X6 = A2, X7 = B2,
		
		  L1 = C3, L2 = D3, L3 = E3, L4 = F3, L5 = G3, L6 = A3, L7 = B3,
		
		  M1 = C4, M2 = D4, M3 = E4, M4 = F4, M5 = G4, M6 = A4, M7 = B4,
		
		  H1 = C5, H2 = D5, H3 = E5, H4 = F5, H5 = G5, H6 = A5, H7 = B5,
		
		  LOW_SPEED = 500, MIDDLE_SPEED = 400, HIGH_SPEED = 300,
		
		  _ = 0XFF
		
		};
		void song_rickroll()
			
			{
			
			  HMIDIOUT handle;
			
			  midiOutOpen(&handle, 0, 0, 0, CALLBACK_NULL);
			
			  midiOutShortMsg(handle, 34<< 8 | 0xC0);
			
			  int volume = 0x7f;
			
			  int voice = 0x0;
			
			  int sleep = 1000;
			
			  int wind[] =
			
			  {
			M1,M2,0,400,L5,500,M2,1000,M3,
			//    400,0,L7,M1,M2,M3,300,L3,0,M5,M3,300,L2,L5,2,_,0,L7,M1,M2,M3,300,L2,0,M5,M3,M2,M3,M1,M2,L7,M1,300,L5,0,L7,M1,M2,M3,300,L3,0,M5,M3,300,L2,L5,2,_,0,L7,M1,M2,M3,300,L2,0,M5,M3,M2,M3,M1,M2,L7,M1,300,L5,
			//
			//    0,L7,M1,M2,M3,300,L3,0,M5,M3,300,L2,L5,2,_,0,L7,M1,M2,M3,300,L2,0,M5,M3,M2,M3,M1,M2,L7,M1,300,L5,0,L7,M1,M2,M3,300,L3,0,M5,M3,300,L2,L5,2,_,
			//
			//    0,M6,M3,M2,L6,M3,L6,M2,M3,L6,_,_,_,
			//
			//    M2,700,0,M1,300,M2,700,0,M1,300,M2,M3,M5,0,M3,700,300,M2,700,0,M1,300,M2,700,0,M1,M2,M3,M2,M1,300,L5,_,
			//
			//    M2,700,0,M1,300,M2,700,0,M1,300,M2,M3,M5,0,M3,700,300,M2,700,0,M3,300,M2,0,M1,700,300,M2,_,_,_,
			//
			//    M2,700,0,M1,300,M2,700,0,M1,300,M2,M3,M5,0,M3,700,300,M2,700,0,M3,300,M2,0,M1,700,300,L6,_,
			//
			//    0,M3,M2,M1,M2,300,M1,_,0,M3,M2,M1,M2,300,M1,700,0,L5,M3,M2,M1,M2,300,M1,_,_,_,
			//
			//    M1,M2,M3,M1,M6,0,M5,M6,300,_,700,0,M1,300,M7,0,M6,M7,300,_,_,M7,0,M6,M7,300,_,M3,0,H1,H2,H1,M7,300,M6,M5,M6,0,M5,M6,_,M5,M6,M5,300,M6,0,M5,M2,300,_,0,M5,700,300,M3,_,_,_,
			//
			//    M1,M2,M3,M1,M6,0,M5,M6,300,_,700,0,M1,300,M7,0,M6,M7,300,_,_,M7,0,M6,M7,300,_,M3,0,H1,H2,H1,M7,300,M6,M5,M6,0,H3,H3,300,_,M5,M6,0,H3,H3,300,_,0,M5,700,300,M6,_,_,_,_,_,
			//
			//    H1,H2,H3,0,H6,H5,300,_,0,H6,H5,300,_,0,H6,H5,300,_,0,H2,H3,300,H3,0,H6,H5,300,_,0,H6,H5,300,_,0,H6,H5,300,_,0,H2,H3,300,H2,0,H1,M6,300,_,0,H1,H1,300,H2,0,H1,300,M6,700,0,_,300,H1,700,H3,_,0,H3,H4,H3,H2,H3,300,H2,700,
			//
			//    H1,H2,H3,0,H6,H5,_,H6,H5,_,H6,H5,300,_,H3,H3,0,H6,H5,_,H6,H5,_,H6,H5,700,300,H3,700,H2,0,H1,M6,700,300,
			//
			//    H3,700,H2,0,H1,300,M6,700,H1,H1,_,_,_,_,_,
			//
			//    0,M6,300,H3,700,H2,0,H1,M6,700,300,H3,H2,700,300,0,H1,M6,300,700,H1,H1,_,_,
			//
			//    0,L7,M1,M2,M3,300,L3,0,M5,M3,300,L2,L5,2,_,0,L7,M1,M2,M3,300,L2,0,M5,M3,M2,M3,M1,M2,L7,M1,300,L5,0,L7,M1,M2,M3,300,L3,0,M5,M3,300,L2,L5,2,_,
			//
			//    0,M6,M3,M2,L6,M3,L6,M2,M3,L6,_,_,_,
			//
			//    
			//
			//    M2,700,0,M1,300,M2,700,0,M1,300,M2,M3,M5,0,M3,700,300,M2,700,0,M1,300,M2,700,0,M1,M2,M3,M2,M1,300,L5,_,
			//
			//    M2,700,0,M1,300,M2,700,0,M1,300,M2,M3,M5,0,M3,700,300,M2,700,0,M3,300,M2,0,M1,700,300,M2,_,_,_,
			//
			//    M2,700,0,M1,300,M2,700,0,M1,300,M2,M3,M5,0,M3,700,300,M2,700,0,M3,300,M2,0,M1,700,300,L6,_,
			//
			//    0,M3,M2,M1,M2,300,M1,_,0,M3,M2,M1,M2,300,M1,700,0,L5,M3,M2,M1,M2,300,M1,_,_,_,
			//
			//    M1,M2,M3,M1,M6,0,M5,M6,300,_,700,0,M1,300,M7,0,M6,M7,300,_,_,M7,0,M6,M7,300,_,M3,0,H1,H2,H1,M7,300,M6,M5,M6,0,M5,M6,_,M5,M6,M5,300,M6,0,M5,M2,300,_,0,M5,700,300,M3,_,_,_,
			//
			//    M1,M2,M3,M1,M6,0,M5,M6,300,_,700,0,M1,300,M7,0,M6,M7,300,_,_,M7,0,M6,M7,300,_,M3,0,H1,H2,H1,M7,300,M6,M5,M6,0,H3,H3,300,_,M5,M6,0,H3,H3,300,_,0,M5,700,300,M6,_,_,_,_,_,
			//
			//
			//
			//    H1,H2,H3,0,H6,H5,300,_,0,H6,H5,300,_,0,H6,H5,300,_,0,H2,H3,300,H3,0,H6,H5,300,_,0,H6,H5,300,_,0,H6,H5,300,_,0,H2,H3,300,H2,0,H1,M6,300,_,0,H1,H1,300,H2,0,H1,300,M6,700,0,_,300,H1,700,H3,_,0,H3,H4,H3,H2,H3,300,H2,700,
			//
			//    H1,H2,H3,0,H6,H5,_,H6,H5,_,H6,H5,300,_,H3,H3,0,H6,H5,_,H6,H5,_,H6,H5,700,300,H3,700,H2,0,H1,M6,700,300,
			//
			//    H3,700,H2,0,H1,300,M6,700,H1,H1,_,_,_,_,_,
			//
			//
			//
			//    H1,H2,H3,0,H6,H5,300,_,0,H6,H5,300,_,0,H6,H5,300,_,0,H2,H3,300,H3,0,H6,H5,300,_,0,H6,H5,300,_,0,H6,H5,300,_,0,H2,H3,300,H2,0,H1,M6,300,_,0,H1,H1,300,H2,0,H1,300,M6,700,0,_,300,H1,700,H3,_,0,H3,H4,H3,H2,H3,300,H2,700,
			//
			//    H1,H2,H3,0,H6,H5,_,H6,H5,_,H6,H5,300,_,H3,H3,0,H6,H5,_,H6,H5,_,H6,H5,700,300,H3,700,H2,0,H1,M6,700,300,
			//
			//    H3,700,H2,0,H1,300,M6,700,H1,H1,_,_,_,_,_,
			//
			//
			//
			//    H1,H2,H3,0,H6,H5,300,_,0,H6,H5,300,_,0,H6,H5,300,_,0,H2,H3,300,H3,0,H6,H5,300,_,0,H6,H5,300,_,0,H6,H5,300,_,0,H2,H3,300,H2,0,H1,M6,300,_,0,H1,H1,300,H2,0,H1,300,M6,700,0,_,300,H1,700,H3,_,0,H3,H4,H3,H2,H3,300,H2,700,
			//
			//    H1,H2,H3,0,H6,H5,_,H6,H5,_,H6,H5,300,_,H3,H3,0,H6,H5,_,H6,H5,_,H6,H5,700,300,H3,700,H2,0,H1,M6,700,300,
			//
			//    H3,700,H2,0,H1,300,M6,700,H1,H1,_,_,_,_,_,
			//
			//
			//
			//    0,M6,300,H3,700,H2,0,H1,M6,700,300,H3,H2,700,300,0,H1,M6,300,700,H1,H1,_,_,_,_,_,_,_,
			
			  };
			
			  for (auto i : wind) {
			
			    if (i == LOW_SPEED || i == HIGH_SPEED || i == MIDDLE_SPEED) {
			
			      sleep = i;//Sleep(i/2);
			
			      continue;
			
			    }
			
			    if (i == 0) { sleep = 175;continue; }
			
			    if (i == 700) { Sleep(175);continue; }
			
			    if (i == _) {
			
			      Sleep(500);
			
			      continue;
			
			    }
			
			    // if (i == 900) volume += 100;
			
			    voice = (volume << 16) + ((i) << 8) + 0x90;
			
			    
			
			    
			
			    midiOutShortMsg(handle, voice);
			
			//    cout << voice << endl;
			
			    Sleep(sleep);
			
			  }
			
			  midiOutClose(handle);
			
			}

		void debug_song(){
			_beep(400,1000);
		}
		void playnote(char a1,char a2,char a3){
			int b1=a1;int b2=a2;int b3=a3;
//			if(b1>94||b2>94||b3>94){
//				cout<<"你的存档有误，请重新输入(Err Code 1)";_sleep(1000);
//				cl();return;
//			}
//			cout<<"Debug info:\n";
//			printf("b1:%d, b2:%d, b3:%d, a1:%d, a2:%d, a3:%d\n",b1,b2,b3,a1,a2,a3);
//			cout<<"Freq: "<<(b1*94+b2)<<endl;
//			cout<<"Time: "<<b3*100<<endl;
//			cout<<"Note will be played in 2000 milisecs.\n\n\n";
//			_sleep(2000);
			_beep((b1*255+b2),b3*520);
		}
		void cre(){
			cout<<"请输入频率：";int freq,dur;
			cin>>freq;cout<<"请输入时长(单位：ms)：";cin>>dur;
			char nt[3];
			nt[0]=freq/255;nt[1]=freq-freq/255;nt[2]=dur/20;
			string note;
			note=nt;
			printf("这个音符的存档为： [ %s ] ",encode(note).c_str());
		}
		//YWJj   abc
		//cXdx   qwq
		//YWJjcXdx abcqwq
		//encode加密decode解密 
		void imp(){
			cout<<"请输入存档：\n";
			cout<<"另外，这是我们早期制作好的：\n";
			//never gonna give you up
			//dur: 500 milisecs for a note
			cout<<"1. Never gonna give you up: ";
			color(0xE1);
			cout<<"[  ";
			color(15);
			cout<<"cmlja3JvbGxfZWFybHltYWRlXzE=";
			color(0xE1);
			cout<<"]  \n\n";
			color(15);color(15);
			
			SetPos(13,5);string p;cin>>p;
			if(p=="cmlja3JvbGxfZWFybHltYWRlXzE="){
				song_rickroll();
			}
			else{
			string cundang=decode(p);
//			if((cundang.length())%3!=0){
//				cout<<"你的存档有误，请重新输入！(Err Code 2)";_sleep(1000);cl();return;
//			}
			for(int i=0;i<cundang.length();i+=3){
//				printf("%d,%c,%c,%c,%d,%d,%d\n",i,cundang[i],cundang[i+1],cundang[i+2],cundang[i],cundang[i+1],cundang[i+2]);
				playnote(cundang[i],cundang[i+1],cundang[i+2]);
			}
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
