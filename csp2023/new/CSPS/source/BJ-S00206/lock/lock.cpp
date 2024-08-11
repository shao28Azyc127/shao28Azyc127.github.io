#include<map>
#include<iostream>
#include<cstdio>
using namespace std;
long long n,x,ans=0;
string s[10],t;
map<string,long long>mp;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
    {
        s[i]=" ";
        for(int j=1;j<=5;++j)
        {
            scanf("%lld",&x);
            s[i] += char(x+'0');
        }
    }
    for(int j=1;j<=n;++j)
    {
        for(int i=1;i<=5;++i)
        {
            for(char a='0';a<='9';++a)
                if(a!=s[j][i])
                {
                    t=s[j];
                    t[i]=a;
                    mp[t]++;
                }
        }
    }
    for(int j=1;j<=n;++j)
    {
        for(int i=1;i<5;++i)
        {
            for(int k=1;k<=9;++k)
                if(char('0'+(k+s[j][i]-'0')%10)!=s[j][i+1] ||
                   char('0'+(k+s[j][i+1]-'0')%10)!=s[j][i])
                {
                    t=s[j];
                    t[i]=char('0'+(k+s[j][i]-'0')%10);
                    t[i+1]=char('0'+(k+s[j][i+1]-'0')%10);
                    ++mp[t];
                }
        }
    }
    for(auto i=mp.begin();i!=mp.end();++i)
        if(i->second==n)
        {
            ++ans;
        }
    printf("%lld\n",ans);
    return 0;
}
