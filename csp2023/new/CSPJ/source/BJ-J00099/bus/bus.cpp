#include<bits/stdc++.h>
using namespace std;

int n,m,k,ans=1e9;
int g[20005][20005];
bool flag=true;

void dfs(int step,int s)
{
    if(step==n)
    {
        if(s%k!=0)
            return ;
        ans=min(ans,s);
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(g[step][i]==-1)
            continue;
        dfs(i,s+1);
    }
}

int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    for(int i=1;i<=10000;i++)
    {
        for(int j=1;j<=10000;j++)
        {
            g[i][j]=-1;
        }
    }


    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,a;
        cin>>u>>v>>a;
        g[u][v]=a;
        if(a!=0)
            flag=false;
    }
    if(flag)
    {
        dfs(1,k);
        if(ans==1e9)
            ans=-1;
        cout<<ans<<endl;
    }

    return 0;
}
