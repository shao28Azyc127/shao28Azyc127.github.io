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
				cout<<"��Ĵ浵��������������(Err Code 1)";_sleep(1000);
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
		//encode����decode���� 
		void imp(){
			cout<<"������浵��";
			string p;cin>>p;
			string cundang=decode(p);
			if((cundang.length())%3!=0){
				cout<<"��Ĵ浵�������������룡(Err Code 2)";_sleep(1000);cl();return;
			}
			for(int i=0;i<cundang.length();i+=3){
				printf("%d,%c,%c,%c,%d,%d,%d\n",i,cundang[i],cundang[i+1],cundang[i+2],cundang[i],cundang[i+1],cundang[i+2]);
				playnote(cundang[i],cundang[i+1],cundang[i+2]);
			}
		}
		void main_menu(){
			while(1){
			cl();cl();
			cout<<"=====�˵�=====\n";
			cout<<"i: ����浵\n";
			//cout<<"t: ʹ�����ڴ����Ĵ浵\n";
			//cout<<"d: ����һ��\n";
			cout<<"c: �����浵\n";
			cout<<"q: �˳�\n";
			cout<<"��ѡ��\n"; 
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
