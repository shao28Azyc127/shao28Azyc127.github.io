#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int MAXN=2e9+7;
int n,m,k,ans=MAXN;
struct Node
{
    int v,a;
};
vector <Node> G[N];
void dfs(int x,int tim)
{
    if(x==n)
    {
        if(tim%k==0)
        {
            ans=min(ans,tim);
        }
        return;
    }
    if(tim>=ans) return;
    for(auto u:G[x])
    {
        int v=u.v;
        int a=u.a;
        if(tim<a) continue;
        dfs(v,tim+1);
    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    int ma=MAXN,da=0;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        ma=min(ma,w);
        da=max(da,w);
        G[u].push_back({v,w});
    }
    int d=ma/k,r=da/k;
    dfs(1,k);
   /* for(int i=d;i<=r;i++)
    {
        if(i*k+ans)
    }*/
    if(ans==MAXN) cout<<-1;
    else cout<<ans;
    
    return 0;
}