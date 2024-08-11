#include<bits/stdc++.h>
#define mod1 998244353
#define mod2 1000000007
using namespace std;
inline int read()
{
    int n=0,f=1,ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        n=n*10+ch-'0';
        ch=getchar();
    }
    return n*f;
}
unordered_map<long long,int>ma;
char s[2000005];
char sta[2000005];
int ha1[2000005],ha2[2000005];
int len;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n=read();
    scanf("%s",s+1);
    long long ans=0;
    ma[0]++;
    for(int i=1;i<=n;i++)
    {
        if(len!=0&&s[i]==sta[len])
        {
            len--;
        }
        else
        {
            sta[++len]=s[i];
            ha1[len]=(114514LL*ha1[len-1]+s[i]-'a'+1)%mod1;
            ha2[len]=(1919810LL*ha2[len-1]+s[i]-'a'+1)%mod2;
        }
        long long zt=1LL*mod2*ha1[len]+ha2[len];
        ans+=ma[zt];
        ma[zt]++;
    }
    printf("%lld\n",ans);
}