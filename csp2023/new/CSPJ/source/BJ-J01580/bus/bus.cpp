#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;
int a[20005][20005];
bool f[20005];
int n,m,k;
int dfs(int x,int nu)
{
    if(x==n-1)return nu%k==0?nu:-0x3f3f3f;
    int y=-1;
    for(int i=0;i<n;i++)
    {
        if(a[x][i]!=0 && f[i]==0 && x!=i && nu>=a[x][i]-1)
        {
            f[i]=1;
            y=max(i,nu+1);
            f[i]=0;
        }
    }
    return y;
}
int main()
{
    memset(a,0,sizeof(a));
    memset(f,0,sizeof(f));
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    bool p=0;
    int f=-10;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int t,g,b;
        cin>>t>>g>>b;
        a[t-1][g-1]=b+1;
        if(b!=0)p=1;
        f=max(f,b);
    }
    if(p==0)cout<<dfs(0,0);
    else{
        int tt=-1;
        for(int i=0;i<f/k+10;i++)
        {
            int r=dfs(0,i*k);
            if(r!=-1)tt=min(tt,r);
        }
        cout<<tt;
    }

    return 0;
}
