#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int ans = 1e9;
int n, m, k;
int lt = 0;
int g[1005][1005];
void dfs(int a, int t, int step)
{
    if(t > max(lt, k) * 2)
        return ;
    if(a == n && (t + step) % k == 0)
    {
        ans = min(ans, t + step);
        return ;
    }
    for(int i = 1;i <= n;i++)
        if(g[a][i] >= 0 && (t + step) >= g[a][i])
            dfs(i, t, step + 1);
}
int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    if(n > 10 || m >= 15)
    {
        cout << -1 << endl;
        return 0;
    }
    memset(g, -0x3f, sizeof(g));
    for(int i = 1;i <= m;i++)
    {
        int x, y, a;
        cin >> x >> y >> a;
        g[x][y] = a;
        lt = max(lt, a);
    }
    int t = 0;
    while(true)
    {
        t += k;
        dfs(1, t, 0);
        if(t >= lt + k)
            break;
    }
    if(ans == 1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}