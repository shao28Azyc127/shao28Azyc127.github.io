#include <bits/stdc++.h>
using namespace std;
const int inf=2147483647;
int n,m,k;
int a[1020][1020],vis[1020];
int ans=inf;
void dfs(int pos,int t)
{
    if(pos==n&&t%k==0)
    {
        if(t<ans)
        {
            ans=t;
        }
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0&&a[pos][i]!=inf&&t>=a[pos][i])
        {
            vis[i]=1;
            dfs(i,t+1);
            vis[i]=0;
        }
    }
    return ;
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    memset(a,inf,sizeof(a));
    int maxn=-1;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,t;
        cin>>u>>v>>t;
        a[u][v]=t;
        if(t>maxn)
        {
            maxn=t;
        }
    }
    for(int i=maxn;i>=0;i--)
    {
        vis[1]=1;
        dfs(1,i);
    }
    if(ans==inf)
    {
        cout << -1;
        return 0;
    }
    cout <<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}