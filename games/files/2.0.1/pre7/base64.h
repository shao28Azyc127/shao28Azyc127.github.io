/**
* @brief C++ base64 编解码
* @author wid
* @date 2013-20-25
*
* @note 若代码存在 bug 或程序缺陷, 请留言反馈, 谢谢!
*/
#ifndef BASE64_H
#define BASE64_H
#include<bits/stdc++.h>
#include "Na2S2O3.h"
using namespace std;
class base64{
	public:
		char base[64]; //存储编码表的数组
		char table[256]; //存储编码对应的原来的字符
		void init() { //预处理出 base[64] 和 table[256] 两个数组
		    for(int i = 0; i < 26; i++) base[i] = 'A' + i; //大写字母
		    for(int i = 0; i < 26; i++) base[26 + i] = 'a' + i; //小写字母
		    for(int i = 0; i < 10; i++) base[52 + i] = '0' + i; //阿拉伯数字
		    base[62] = '+', base[63] = '/'; //特殊处理加号和斜杠
		    for(int i = 0; i < 256; i++) table[i] = 0xff;
		    for(int i = 0; i < 64; i++) table[base[i]] = i; //反向记录编码后的字符对应的 ASCII 代码
		    table['='] = 0;
		}
		string encode(string str) { //对str进行编码
		    init();string ret; int i; //ret记录编码之后的文本串
		    for(i = 0; i + 3 <= str.size(); i += 3) { 
		        //这一组的三个字符是str[i]、str[i+1]、str[i+2]
		        ret += base[str[i] >> 2]; //str[i]>>2 提取str[i]的后六位
		        ret += base[(str[i] & 0x03) << 4 | str[i + 1] >> 4];
		        //str[i]&0x03 提取str[i]的后两位，str[i+1]>>4 提取str[i+1]前四位
		        ret += base[(str[i + 1] & 0x0f) << 2 | str[i + 2] >> 6];
		        //str[i+1]&0x0f 提取str[i+1]的后四位，str[i+2]>>6 提取str[i+2]的前两位
		        ret += base[str[i + 2] & 0x3f]; //str[i+2]&0x3f 提取 str[i+2]的后六位
		    }
		    if(i < str.size()) { //还有剩余的字符没有编码，即文本长度不为3的倍数
		        ret += base[str[i] >> 2]; //str[i]>>2 提取str[i]的前六位
		        if(i + 1 == str.size()) { //剩下一个字符（str[i]）
		            ret += base[(str[i] & 0x03) << 4];
		            //str[i]&0x03 提取str[i]的后两位，<<4可以在后面补四个零
		            ret += "=="; //补充两个等号
		        } else { //剩下两个字符（str[i]和str[i+1]）
		            ret += base[(str[i] & 0x03) << 4 | str[i + 1] >> 4];
		            //str[i]&0x03 提取str[i]后两位,str[i+1]>>4 提取str[i+1]的前四位
		            ret += base[(str[i + 1] & 0x0f) << 2];
		            //str[i+1]&0x0f 提取str[i+1]后四位，<<2用来在后面补两个零
		            ret += "="; //补充一个等号
		        }
		    }
		    return ret; //返回编码的结果
		}
		string decode (string str) { //对str进行解码
		    init();string ret; int i; //ret记录解码后的文本串
		    for (i = 0; i < str.size(); i += 4) {
		    //这一组的四个字符是str[i]到str[i+3]
		        ret += table[str[i]] << 2 | table[str[i + 1]] >> 4;
		        //拼接str[i]和str[i+1]的前两位
		        if (str[i + 2] != '=')
		            ret += (table[str[i + 1]] & 0x0f) << 4 | table[str[i + 2]] >> 2;
		        //拼接str[i+1]的后四位和str[i+2]的前四位
		        if (str[i + 3] != '=')
		            ret += (table[str[i + 2]] & 0x03) << 6 | table[str[i + 3]];
		        //拼接str[i+2]的后两位和str[i+3]
		    }
		    return ret; //返回解码的结果
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
