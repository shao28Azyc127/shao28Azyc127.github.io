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
		string deciToBin(int deci)                                //10����ת2���ƺ���
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
		string deciToBin_6bit(int deci)                                //10����ת2���ƺ���
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
		
		    for( auto x = in.cbegin(); (*x) != '=' && x != in.cend(); ++x)    //�ų��Ⱥ�
		        out0 += deciToBin_6bit(value.find(*x));
		
		    const int n = out0.length();
		
		    for(int i = 0; i < n; i += 8)           //ÿ8λ��ȡһ��
		    {
		        string subs = out0.substr(i, 8);    //��ȡ8λ
		        int j = 0;
		        int sum = 0;
		
		        for(auto &x : subs)
		        {
		            sum += (x - '0') * pow(2, 7 - j);
		            ++j;
		        }                                   //��Ȩչ�����õ�ASCII��
		
		        out1 += static_cast<char>(sum);     //ת��Ϊ��Ӧ�ַ�
		    }
		
		    return out1;
		
		}
		string encode(const string in)                //���ܺ���
		{
		    int i = 0;                            //�ܵĿ��Ʊ���
		    int k = 0;                          //24λ(4��6λ)���Ʊ���
		    const int n = in.length();     //���������г���
		    string subs;                        //Ҫ��Ӧ������Ӵ�
		    string out;                        //�������ַ���
		    string value("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/");       //��Ӧ�ַ�
		
		    while (n - i >= 24)            //���������������ֽ�
		    {
		        for (k = 0; k < 4; ++k)
		        {
		            subs = in.substr( i + k * 6, 6);            //ȡ��6λ
		
		            int sum = 0;
		            int j = 0;
		
		            for (auto & x : subs)
		            {
		                sum += (x - '0') * pow(2, 5 - j);
		                ++j;
		            }                                                                            //�õ��±�
		
		            out +=  value.at(sum);                                          //�����Ӧ�ַ�
		        }
		
		        i += 24;                                                                    //ǰ��24λ
		
		        if ( i % 76 == 0)
		            cout << endl;
		    }
		
		    if ( i != n)                                                                       //����ʣ�µĲ���24λ����
		    {
		        int charlen;                                              //ʣ�µĳ���
		
		        if ((n - i) % 6 == 0)
		            charlen = (n - i) / 6;
		        else
		            charlen = (n - i) / 6 + 1;
		
		        for (k = 0; k < charlen; ++k)
		        {
		            subs = in.substr( i + k * 6, i + (k + 1) * 6 - 1);            //ȡ��6λ
		
		            int sum = 0;
		            int j = 0;
		
		            for (auto & x : subs)
		            {
		                sum += (x - '0') * pow(2, 5 - j);
		                ++j;
		            }                                                                            //�õ��±�
		
		            out +=  value.at(sum);                                            //�����Ӧ�ַ�
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
