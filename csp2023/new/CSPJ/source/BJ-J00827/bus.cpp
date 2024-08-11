#include<bits/stdc++.h>
using namespace std;
int n, m, k, u, v, w, t[10002], ans = 1e9;
struct pi
{
    int a, b;
}e[10002][102];
void dfs(int id, int tm, int mx)
{
    if(id == n)
    {
    	if(mx % k != 0)
    	{
    	    mx += k - mx % k;
    	}
    	if(tm % k == 0)
    	{
    	    ans = min(ans, mx + tm);
    	}
    	return;
    }
    for(int i = 1;i <= t[id];++i)
    {
    	dfs(e[id][i].a, tm + 1, max(mx, e[id][i].b - tm));
    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;++i)
    {
    	cin >> u >> v >> w;
    	e[u][++t[u]].a = v;
    	e[u][t[u]].b = w;
    }
    dfs(1, 0, 0);
    cout << ans;
    return 0;
}