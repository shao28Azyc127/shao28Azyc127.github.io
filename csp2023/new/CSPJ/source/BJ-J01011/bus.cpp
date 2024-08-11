#include<bits/stdc++.h>
using namespace std;
int g[10005][10005];
int n,m,k,u,v,ans=2e9;
void dfs(int x,int s)
{
    if(x==n)
    {
        if(s%k==0) ans=min(ans,s);
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(g[x][i]!=-1&&g[x][i]<=s)
        {
            dfs(i,s+1);
        }
    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    memset(g,-1,sizeof(g));
    cin>>n>>m>>k;
    while(m--)
    {
        scanf("%d%d",&u,&v);
        scanf("%d",&g[u][v]);
    }
    dfs(1,k);
    if(ans!=2e9)cout<<ans;
    else cout<<-1;
    return 0;
}
