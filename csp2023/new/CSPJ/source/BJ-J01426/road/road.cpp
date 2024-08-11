#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
    int x=0,w=1;
    char ch=0;
    while(ch<'0'||'9'<ch)
    {
        if(ch=='-')w=-1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9')
    {
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    return x*w;
}
const int maxn=1e5+10;
int n,d;
int v[maxn],a[maxn],dp[maxn],f[maxn],s[maxn];
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n=read(),d=read();
    for(int i=1;i<n;++i)v[i]=read();
    for(int i=1;i<=n;++i)a[i]=read(),dp[i]=1e18;
    for(int i=2;i<=n;++i)s[i]=s[i-1]+v[i-1];
    dp[1]=0;
    if(n>1e4)
    {
        if(s[n]%d==0)cout<<s[n]/d*a[1]<<endl;
        else cout<<(s[n]/d+1)*a[1]<<endl;
        return 0;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<i;++j)
        {
            int dis=s[i]-s[j]-f[j];
            if(dis<0)dis=0;
            int p=0;
            if(dis%d==0)
            {
                p=dis/d;
            }
            else p=dis/d+1;
            if(dp[i]>dp[j]+p*a[j])
            {
                dp[i]=dp[j]+p*a[j];
                if(p!=0)f[i]=p*d-dis;
                else f[i]=f[j]-s[i]+s[j];
            }
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
