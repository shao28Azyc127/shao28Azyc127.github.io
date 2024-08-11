#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
string s1[3010],s2[3010];
int f[200];
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==1)
    {

        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        string x;
        cin>>x;
        for(int j=0;j<x.size();j++)f[x[j]]++;
        string s="";
        for(int j='a';j<='z';j++)
        {
            while(f[j]!=0)
            {
                f[j]--;
                s+=char(j);
            }
        }
        s1[i]=s;
        string x2="";
        for(int i=s.size()-1;i>=0;i--)x2+=s[i];
        s2[i]=x2;
    }
    for(int i=1;i<=n;i++)
    {
        bool f=1;
        for(int j=1;j<=n;j++)
        {
            if(j!=i)
            {
                if(s1[i]>=s2[j])f=0;
            }
        }
        cout<<f;
    }
    return 0;
}
