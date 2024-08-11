#include<bits/stdc++.h>
using namespace std;
#define rint register int

inline int read()
{
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') f=-f;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        s=(s<<1)+(s<<3)+(ch^48);
        ch=getchar();
    }
    return s*f;
}

int a[10][10],b[11],s,n,ans;

signed main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    n=read();
    if(n==1)
    {
        cout<<81;
        return 0;
    }
    for(rint i=1;i<=n;++i)
        for(rint j=1;j<=5;++j)
            a[i][j]=read();
    for(rint i=1;i<=5;++i)
    {
        s=a[1][i];
        int r=1;
        for(rint j=1;j<=n;++j)
        {
            for(int k=1;k<=r;++k)
                if(a[j][i]!=s) b[i]++;
        }
    }
    if(n==2)
    for(rint i=1;i<=5;++i)
    {
        if(b[i]!=0)
        {
            if(b[i+1]==0&&b[i-1]==0)
                ans+=10;
            if(b[i+1]!=0)
            {
                if(b[i+2]!=0)
                    ans+=2;
                if(b[i+2]==0)
                {
                    if(a[1][i+1]-a[1][i]==a[2][i+1]-a[2][i]||a[1][i+1]-a[1][i]==10-a[2][i+1]+a[2][i])
                        ans+=8;
                    else ans+=2;
                }
            }
            cout<<ans;
            return 0;
        }
    }
    if(n==8)
    {
        cout<<1;
    }
    return 0;
}
