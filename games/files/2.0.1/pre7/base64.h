/**
* @brief C++ base64 �����
* @author wid
* @date 2013-20-25
*
* @note ��������� bug �����ȱ��, �����Է���, лл!
*/
#ifndef BASE64_H
#define BASE64_H
#include<bits/stdc++.h>
#include "Na2S2O3.h"
using namespace std;
class base64{
	public:
		char base[64]; //�洢����������
		char table[256]; //�洢�����Ӧ��ԭ�����ַ�
		void init() { //Ԥ����� base[64] �� table[256] ��������
		    for(int i = 0; i < 26; i++) base[i] = 'A' + i; //��д��ĸ
		    for(int i = 0; i < 26; i++) base[26 + i] = 'a' + i; //Сд��ĸ
		    for(int i = 0; i < 10; i++) base[52 + i] = '0' + i; //����������
		    base[62] = '+', base[63] = '/'; //���⴦��Ӻź�б��
		    for(int i = 0; i < 256; i++) table[i] = 0xff;
		    for(int i = 0; i < 64; i++) table[base[i]] = i; //�����¼�������ַ���Ӧ�� ASCII ����
		    table['='] = 0;
		}
		string encode(string str) { //��str���б���
		    init();string ret; int i; //ret��¼����֮����ı���
		    for(i = 0; i + 3 <= str.size(); i += 3) { 
		        //��һ��������ַ���str[i]��str[i+1]��str[i+2]
		        ret += base[str[i] >> 2]; //str[i]>>2 ��ȡstr[i]�ĺ���λ
		        ret += base[(str[i] & 0x03) << 4 | str[i + 1] >> 4];
		        //str[i]&0x03 ��ȡstr[i]�ĺ���λ��str[i+1]>>4 ��ȡstr[i+1]ǰ��λ
		        ret += base[(str[i + 1] & 0x0f) << 2 | str[i + 2] >> 6];
		        //str[i+1]&0x0f ��ȡstr[i+1]�ĺ���λ��str[i+2]>>6 ��ȡstr[i+2]��ǰ��λ
		        ret += base[str[i + 2] & 0x3f]; //str[i+2]&0x3f ��ȡ str[i+2]�ĺ���λ
		    }
		    if(i < str.size()) { //����ʣ����ַ�û�б��룬���ı����Ȳ�Ϊ3�ı���
		        ret += base[str[i] >> 2]; //str[i]>>2 ��ȡstr[i]��ǰ��λ
		        if(i + 1 == str.size()) { //ʣ��һ���ַ���str[i]��
		            ret += base[(str[i] & 0x03) << 4];
		            //str[i]&0x03 ��ȡstr[i]�ĺ���λ��<<4�����ں��油�ĸ���
		            ret += "=="; //���������Ⱥ�
		        } else { //ʣ�������ַ���str[i]��str[i+1]��
		            ret += base[(str[i] & 0x03) << 4 | str[i + 1] >> 4];
		            //str[i]&0x03 ��ȡstr[i]����λ,str[i+1]>>4 ��ȡstr[i+1]��ǰ��λ
		            ret += base[(str[i + 1] & 0x0f) << 2];
		            //str[i+1]&0x0f ��ȡstr[i+1]����λ��<<2�����ں��油������
		            ret += "="; //����һ���Ⱥ�
		        }
		    }
		    return ret; //���ر���Ľ��
		}
		string decode (string str) { //��str���н���
		    init();string ret; int i; //ret��¼�������ı���
		    for (i = 0; i < str.size(); i += 4) {
		    //��һ����ĸ��ַ���str[i]��str[i+3]
		        ret += table[str[i]] << 2 | table[str[i + 1]] >> 4;
		        //ƴ��str[i]��str[i+1]��ǰ��λ
		        if (str[i + 2] != '=')
		            ret += (table[str[i + 1]] & 0x0f) << 4 | table[str[i + 2]] >> 2;
		        //ƴ��str[i+1]�ĺ���λ��str[i+2]��ǰ��λ
		        if (str[i + 3] != '=')
		            ret += (table[str[i + 2]] & 0x03) << 6 | table[str[i + 3]];
		        //ƴ��str[i+2]�ĺ���λ��str[i+3]
		    }
		    return ret; //���ؽ���Ľ��
		}
		void menub64(){
			while(1){
				err1:
				string op;cout<<"decode(0)&encode(1)&quit(84579):";cin>>op;
				if(op=="0"){
					string a;cout<<"string need to be decoded:";cin>>a;init();cout<<"decode:"<<decode(a)<<"\n";
				}else if(op=="1"){
					string a;cout<<"string need to be encoded:";cin>>a;init();cout<<"encode:"<<encode(a)<<"\n";
				}else if(op=="84579"){
					break;
				}else{
					system("start info1.vbs");cl();
					goto err1;
				}
			}
		}
	
}b64;
//int main(){
//	while(1){
//		err1:
//		string op;cout<<"decode(0)&encode(1):";cin>>op;
//		if(op=="0"){
//			string a;cout<<"string need to be decoded:";cin>>a;init();cout<<"decode:"<<decode(a)<<"\n";
//		}else if(op=="1"){
//			string a;cout<<"string need to be encoded:";cin>>a;init();cout<<"encode:"<<encode(a)<<"\n";
//		}else{
//			cout<<"There are some sort of error......\n\n";
//			goto err1;
//		}
//	}
//}
#endif
