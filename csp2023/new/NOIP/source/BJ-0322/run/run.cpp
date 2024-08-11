#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int n,m,k,d;
int ans;
const int maxn=1005;
int b[maxn];
int a[maxn];
int xx[maxn];
int yy[maxn];
int vv[maxn];
void dfs(int x)
{
    if(x>n)
    {
        for(int i=1;i<=n;i++)b[i]=a[i];
        for(int i=1;i<=n;i++)
        {
            if(b[i]==0)continue;
            b[i]=b[i-1]+b[i];
        }
        for(int i=1;i<=n;i++)if(b[i]>k)return;
        int res=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i])res-=d;
        }
        for(int i=1;i<=m;i++)
        {
            if(b[xx[i]]>=yy[i])res+=vv[i];
        }
        if(res>ans)
        {
            ans=res;
        }
        return;
    }
    for(int i=0;i<=1;i++)
    {
        a[x]=i;
        dfs(x+1);
    }
}
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,t;cin>>c>>t;
    ans=0;
    while(t--)
    {
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++)
        {
            int x,y,v;cin>>x>>y>>v;
            xx[i]=x;
            yy[i]=y;
            vv[i]=v;
        }
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}