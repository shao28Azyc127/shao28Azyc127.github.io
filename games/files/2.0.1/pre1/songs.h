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
		void main_menu(){
			while(1){
			cl();cl();
			cout<<"=====菜单=====\n";
			cout<<"i: 导入存档\n";
			//cout<<"t: 使用早期创作的存档\n";
			//cout<<"d: 调试一下\n";
			cout<<"c: 创建存档\n";
			cout<<"q: 退出\n";
			cout<<"请选择：\n"; 
			char c=tolower(_getch());
			switch(c){
				case 'i':imp();break;
				case 'd':debug_song();break;
				//case 'c':cre();break;
				case 'q':return;break;
				default:system("start info1.vbs");
			}
			}
		}
}a;
}
#endif
