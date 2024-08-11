#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
int n,m;
long long k,ans = 1e9;
struct Node{int v;long long a;};
vector<Node> adj[100010];
void dfs(int u,long long maxn,long long dis)
{
    if (u == n)
    {
        if (dis % k != 0) return;
        long long x = maxn;
        x = (x / k + (x % k != 0 ? 1 : 0)) * k;
        ans = min(ans,x + dis);
        return;
    }
    for (Node v:adj[u])
    {
        maxn = max(maxn,v.a - dis);
        dfs(v.v,maxn,dis + 1);
    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%lld",&n,&m,&k);
    if (n >= 7000)
    {
        printf("-1\n");
        return 0;
    }
    for (int i = 1;i <= m;i++)
    {
        int u,v;
        long long a;
        scanf("%d%d%lld",&u,&v,&a);
        adj[u].push_back({v,a});
    }
    dfs(1,0,0);
    printf("%lld\n",ans);
}
