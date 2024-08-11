#include<bits/stdc++.h>
#pragma GCC(2)
using namespace std;
string s[100000] , head , sstruct[100][2];
int n , o , stmp = 0;
int main()
{
    freopen("struct.in" , "r" , stdin);
    freopen("struct.out" , "w" , stdout);
    cin >> n;
    while(n--)
    {
        cin >> o;
        if(o == 1)
        {
            int k , length = 1;
            cin >> head >> k;
            for(int i = 0 ; i < k ; i++)
            {
                cin >> sstruct[i][0] >> sstruct[i][1];
                if(sstruct[i][0] == "short")
                {
                    length = max(length , 2);
                }
                if(sstruct[i][0] == "int")
                {
                    length = max(length , 4);
                }
                if(sstruct[i][0] == "long")
                {
                    length = max(length , 8);
                }
            }
            for(int i = stmp ; i < length * k + stmp ; i++)
            {
                for(int j = i ; j < i + length ; j++)
                {
                    if(sstruct[i][0] == "byte")
                    {
                        if(j < i + 1)
                        {
                            s[i] == head + "." + sstruct[i][1];
                        }
                        else
                        {
                            s[i] == "ERR";
                        }
                    }
                    if(sstruct[i][0] == "short")
                    {
                        if(j < i + 2)
                        {
                            s[i] == head + "." + sstruct[i][1];
                        }
                        else
                        {
                            s[i] == "ERR";
                        }
                    }
                    if(sstruct[i][0] == "int")
                    {
                        if(j < i + 4)
                        {
                            s[i] == head + "." + sstruct[i][1];
                        }
                        else
                        {
                            s[i] == "ERR";
                        }
                    }
                    if(sstruct[i][0] == "long")
                    {
                        if(j < i + 8)
                        {
                            s[i] == head + "." + sstruct[i][1];
                        }
                        else
                        {
                            s[i] == "ERR";
                        }
                    }
                }
            }
            stmp += k * length;
        }
        if(o == 2)
        {
            string s1 , s2;
            cin >> s1 >> s2;
            if(s1 == "byte")
            {
                for(int i = stmp ; i < stmp + 1 ; i++)
                {
                    s[i] = s2;
                }
                stmp++;
            }
            if(s1 == "short")
            {
                for(int i = stmp ; i < stmp + 2 ; i++)
                {
                    s[i] = s2;
                }
                stmp+=2;
            }
            if(s1 == "int")
            {
                for(int i = stmp ; i < stmp + 4 ; i++)
                {
                    s[i] = s2;
                }
                stmp+=4;
            }
            if(s1 == "long")
            {
                for(int i = stmp ; i < stmp + 8 ; i++)
                {
                    s[i] = s2;
                }
                stmp+=8;
            }
        }
        if(o==3)
        {
            string q;
            cin >> q;
            for(int i = 0 ; i < n ; i++)
            {
                if(s[i] == q)
                {
                    cout << i;
                    break;
                }
            }
            cout << endl;
        }
        if(o==4)
        {
            int i;
            cin >> i;
            cout << s[i] << endl;
        }
    }
    return 0;
}
