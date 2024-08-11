#include <bits/stdc++.h>
using namespace std;
bool b[1004][1004];
int ans=1e9;
int n,m,k;
void dfs(int i,int t)
{
    if(i==n)
    {
        if(t%k==0)ans=min(ans,t);
        return ;
    }
    for(int j=1;j<=n;j++)
    {
        if(b[i][j]==1)
        {
            dfs(j,t+1);
        }
    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,a;
        cin>>u>>v>>a;
        b[u][v]=1;
    }
    dfs(1,0);
    if(ans==1e9)ans=-1;
    cout<<ans;
    return 0;
}
