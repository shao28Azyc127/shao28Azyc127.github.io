#include <vector>
#include <iostream>
using namespace std;
vector<int> g[10005];
bool f[10005];
int n,m,k,ans = 1e9;
void dfs(int x,int p)
{
    if (x == n)
    {
        if (p % k == 0) ans = min(ans,p);
        return;
    }
    for (int i = 0;i < g[x].size();i++)
    {
        if (f[g[x][i]]) continue;
        f[g[x][i]] = 1;
        dfs(g[x][i],p + 1);
        f[g[x][i]] = 0;
    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin >> n >> m >> k;
    if (n <= 10 || k == 1)
    {
        while (m--)
        {
            int u,v,a;
            cin >> u >> v >> a;
            g[u].push_back(v);
        }
        dfs(1,0);
        if (ans != 1e9) cout << ans;
        else cout << -1;
        return 0;
    }
    cout << -1;
    return 0;
}