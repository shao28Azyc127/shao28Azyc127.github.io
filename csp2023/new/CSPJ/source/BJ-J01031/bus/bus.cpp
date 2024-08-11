#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
int n, m, k, ans = 2e9;
bool vis[1000010];
struct R{int p, t;};
vector<R> e[1000010], r;
void dfs(int step, int time, int maxn)
{
    if(step == n)
    {
        if(time % k == 0)r.push_back(R{time, maxn});
        return;
    }
    for(int i = 0;i < e[step].size();i++)
    {
        R it = e[step][i];
        if(!vis[it.p])dfs(it.p, time + 1, max(maxn, max(0, it.t - time)));
    }
}
int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    memset(vis, 0, sizeof(vis));
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++)
    {
        int x, y, a;
        cin >> x >> y >> a;
        e[x].push_back(R{y, a});
    }
    vis[1] = true;
    dfs(1, 0, 0);
    for(int i = 0;i < r.size();i++)
    {
        ans = min(ans, int(ceil(r[i].t * 1.0 / k) * k + r[i].p));
    }
    if(ans == 2e9)cout << "-1\n";
    else cout << ans << "\n";
    return 0;
}