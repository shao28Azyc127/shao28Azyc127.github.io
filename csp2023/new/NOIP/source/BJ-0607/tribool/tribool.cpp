#include<bits/stdc++.h>
using namespace std;

char s[100005];
int n,m,f[100005],p[100005],ans,c,t,a[100005],b[100005];

void build()
{
    for(int i=1;i<=n;++i)
        f[i]=i;
}

void lj(int a1,int b1)
{
    f[a1]=f[b1];
}

int check(int a1)
{
    return f[a1];
}

signed main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    if(c==5||c==6)
    {
        while(t--)
        {
            cin>>n>>m;
            char pf;
            int pf1,pf2;
            ans=0;
            while(m--)
            {
                cin>>pf;
                if(pf=='U') ans++,cin>>pf1;
                if(pf=='+') cin>>pf1>>pf2;
            }
            cout<<ans<<endl;
        }
        return 0;
    }
    while(t--)
    {
        cin>>n>>m;
        build();
        for(int i=1;i<=m;++i)
            cin>>s[i]>>a[i]>>b[i];
        for(int i=1;i<=m;++i)
            if(s[i]=='+')
            {
                lj(a[i],b[i]);
            }
        for(int i=1;i<=m;++i)
            if(s[i]=='-')
            {
                if(f[b[i]]!=b[i])
                    p[a[i]]++;
                if(p[a[i]]==2) lj(a[i],b[i]);
            }
        for(int i=1;i<=n;++i)
            if(f[i]==i) ans++;
        cout<<ans-1;
    }
    return 0;
}
