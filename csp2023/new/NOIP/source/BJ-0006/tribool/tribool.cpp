/*
    author: honglan0301

    2023-11-18 09:14:25
*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define int long long
#define mod 998244353

int c,T,n,m,u,v,a[100005],fa[200005],flag[200005],ans;
char opt;

int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}

signed main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>m; for(int i=1;i<=n;i++) a[i]=i;
        for(int i=1;i<=m;i++)
        {
            cin>>opt;
            if(opt=='T') cin>>u,a[u]=n+1;
            if(opt=='F') cin>>u,a[u]=-(n+1);
            if(opt=='U') cin>>u,a[u]=0;
            if(opt=='+') cin>>u>>v,a[u]=a[v];
            if(opt=='-') cin>>u>>v,a[u]=-a[v];
        }
        //for(int i=1;i<=n;i++) cout<<a[i]<<" "; cout<<endl;
        for(int i=0;i<=2*n;i++) fa[i]=i,flag[i]=0; ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0) fa[getfa(i)]=getfa(0),fa[getfa(i+n)]=getfa(0);
            if(a[i]>0&&a[i]<=n) fa[getfa(i)]=getfa(a[i]),fa[getfa(i+n)]=getfa(a[i]+n);
            if(a[i]<0&&a[i]>=-n) fa[getfa(i)]=getfa(n-a[i]),fa[getfa(i+n)]=getfa(-a[i]);
        }
        for(int i=1;i<=n;i++) if(getfa(i)==getfa(i+n)) fa[getfa(i)]=getfa(0);
        flag[getfa(0)]=1;
        for(int i=1;i<=n;i++) if(flag[getfa(i)]) ans++; cout<<ans<<endl;
    }
}
