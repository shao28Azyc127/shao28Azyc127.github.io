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
			int b1=a1-32;int b2=a2-32;int b3=a3=32;
			if(b1>94||b2>94||b3>94){
				cout<<"��Դ浵��������������(Err Code 1)";_sleep(1000);
				cl();return;
			}
			_beep(2000+(b1*94+b2),b3*100);
		}
		//encode����decode���� 
		void imp(){
			cout<<"������浵��";
			string p;cin>>p;
			string cundang=decode(p);
//			if((sizeof(cundang)-1)%3!=0){
//				cout<<"��Ĵ浵�������������룡(Err Code 2)";_sleep(1000);cl();return;
//			}
			for(int i=0;i<sizeof(cundang)-1;i+=3){
				playnote(cundang[i],cundang[i+1],cundang[i+2]);
			}
		}
		void main_menu(){
			while(1){
			cl();cl();
			cout<<"=====�˵�=====\n";
			cout<<"i: ����浵\n";
			cout<<"d: ����һ��\n";
			//cout<<"c: �����浵\n";
			cout<<"q: �˳�\n";
			cout<<"��ѡ��\n"; 
			char c=tolower(_getch());
			switch(c){
				case 'i':imp();break;
				case 'c':debug_song();break;
				//case 'c':cre();break;
				case 'q':return;break;
				default:system("start info1.vbs");
			}
			}
		}
}a;
}
#endif
