#ifndef BASE64
#define BASE64

extern "C"{
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cctype>
class base64{
	public:
		string deciToBin(int deci)                                //10进制转2进制函数
		{
		
		    string hexStr(8, ' ' );
		    int Value = 0;
		    int i = 0;
		
		    for (; deci != 0; ++i, deci /= 2)
		    {
		        Value = deci % 2;
		        hexStr.at(i) =  Value + '0';
		    }
		
		    hexStr = hexStr.substr(0, i);
		
		    reverse(hexStr.begin(), hexStr.end());
		
		    if (hexStr.length() < 8)
		    {
		        string add( 8 - hexStr.length(), '0');
		        hexStr = add + hexStr;
		    }
		
		    return hexStr;
		}
		string deciToBin_6bit(int deci)                                //10进制转2进制函数
		{
		
		    string hexStr(6, ' ' );
		    int Value = 0;
		    int i = 0;
		
		    for (; deci != 0; ++i, deci /= 2)
		    {
		        Value = deci % 2;
		        hexStr.at(i) =  Value + '0';
		    }
		
		    hexStr = hexStr.substr(0, i);
		
		    reverse(hexStr.begin(), hexStr.end());
		
		    if (hexStr.length() < 6)
		    {
		        string add( 6 - hexStr.length(), '0');
		        hexStr = add + hexStr;
		    }
		
		    return hexStr;
		}
		string decode(const string in)
		{
		    string value("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/");
		    string out0;
		    string out1;
		    //string deciToBin_6bit(int);
		
		    for( auto x = in.cbegin(); (*x) != '=' && x != in.cend(); ++x)    //排除等号
		        out0 += deciToBin_6bit(value.find(*x));
		
		    const int n = out0.length();
		
		    for(int i = 0; i < n; i += 8)           //每8位提取一次
		    {
		        string subs = out0.substr(i, 8);    //提取8位
		        int j = 0;
		        int sum = 0;
		
		        for(auto &x : subs)
		        {
		            sum += (x - '0') * pow(2, 7 - j);
		            ++j;
		        }                                   //按权展开，得到ASCII码
		
		        out1 += static_cast<char>(sum);     //转换为相应字符
		    }
		
		    return out1;
		
		}
		string encode(const string in)                //加密函数
		{
		    int i = 0;                            //总的控制变量
		    int k = 0;                          //24位(4个6位)控制变量
		    const int n = in.length();     //二进制序列长度
		    string subs;                        //要对应输出的子串
		    string out;                        //输出结果字符串
		    string value("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/");       //对应字符
		
		    while (n - i >= 24)            //处理完整的三个字节
		    {
		        for (k = 0; k < 4; ++k)
		        {
		            subs = in.substr( i + k * 6, 6);            //取出6位
		
		            int sum = 0;
		            int j = 0;
		
		            for (auto & x : subs)
		            {
		                sum += (x - '0') * pow(2, 5 - j);
		                ++j;
		            }                                                                            //得到下标
		
		            out +=  value.at(sum);                                          //输出对应字符
		        }
		
		        i += 24;                                                                    //前进24位
		
		        if ( i % 76 == 0)
		            cout << endl;
		    }
		
		    if ( i != n)                                                                       //处理剩下的不足24位部分
		    {
		        int charlen;                                              //剩下的长度
		
		        if ((n - i) % 6 == 0)
		            charlen = (n - i) / 6;
		        else
		            charlen = (n - i) / 6 + 1;
		
		        for (k = 0; k < charlen; ++k)
		        {
		            subs = in.substr( i + k * 6, i + (k + 1) * 6 - 1);            //取出6位
		
		            int sum = 0;
		            int j = 0;
		
		            for (auto & x : subs)
		            {
		                sum += (x - '0') * pow(2, 5 - j);
		                ++j;
		            }                                                                            //得到下标
		
		            out +=  value.at(sum);                                            //输出对应字符
		        }
		
		        if ((n - i) % 16 == 0)
		            out += "=";
		
		        else
		            out += "==";
		
		    }
		
		    return out;
		}
};
}
#endif
