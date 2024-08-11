#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int NR = 1e4+4;
int ans = 1e9;
int n, m, k;
vector<int> g[NR], q[NR];// q[i][j] kai fang shi jian
int f[NR][1001];
int dfs(int x, int t)
{
//printf("dfs(%d %d)\n", x, t);
    if(x == n && t % k == 0){return t;}
    int ret = 1e9;
    if(t >1000)
    {
    for(int i = 0; i < g[x].size(); i++)
    {
        int y = g[x][i],  a = q[x][i];
//printf("{%d %d}\n", y, a);
        if(t < a) continue;
        ret = min(ret, dfs(y, t+1));
    }
    }
    else
    {
        if(f[x][t] != -1) return f[x][t];
        for(int i = 0; i < g[x].size(); i++)
        {
            int y = g[x][i],  a = q[x][i];
    //printf("{%d %d}\n", y, a);
            if(t < a) continue;
            ret = min(ret, dfs(y, t+1));
        }
        f[x][t] = ret;
    }
    return ret;
}
int main()
{
    memset(f, -1, sizeof(f));
    //freopen("bus2.in", "r", stdin);
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    int l = 1e9, r = 0;
    for(int i = 1; i <= m; i++)
    {
        int u, v, a;
        scanf("%d %d %d", &u, &v, &a);
        g[u].push_back(v);
        q[u].push_back(a);
//cout << u << " " << v << " " << a << endl;
        if(u == 1) l = min(l, a);
        r = max(r, a);
    }
    //cout << l << " " << r <<endl;
//printf("[%d, %d]\n", l/k, r/k+1);
    for(int i = l/k; i <= r/k+2; i++)
    {
        ans = min(ans, dfs(1, i * k));
    }
    if(ans == 1e9) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
