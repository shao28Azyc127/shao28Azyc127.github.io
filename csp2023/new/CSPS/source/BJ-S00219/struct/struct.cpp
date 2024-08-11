#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector <string> a;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    cin>>n;
    int cnt=0;
    while(n--)
    {
        int opt;
        cin>>opt;
        if(opt==2)
        {
            string s1,s2;
            cin>>s1>>s2;
            cout<<cnt<<endl;
            if(s1[0]=='b')
            {
                a.push_back(s2);
                cnt++;
            }
            if(s1[0]=='s')
            {
                a.push_back(s2);
                a.push_back(s2);
                cnt+=2;
            }
            if(s1[0]=='i')
            {
                a.push_back(s2);
                a.push_back(s2);
                a.push_back(s2);
                a.push_back(s2);
                cnt+=4;
            }
            if(s1[0]=='l')
            {
                a.push_back(s2);
                a.push_back(s2);
                a.push_back(s2);
                a.push_back(s2);
                a.push_back(s2);
                a.push_back(s2);
                a.push_back(s2);
                a.push_back(s2);
                cnt+=8;
            }
        }
        if(opt==3)
        {
            string s1;
            cin>>s1;
            for(int i=0;i<=cnt;i++)
            {
                if(a[i]==s1)
                {
                    cout<<i<<endl;
                    break;
                }
            }
        }
        if(opt==4)
        {
            int t1;
            cin>>t1;
            cout<<a[t1]<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
