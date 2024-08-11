#include<bits/stdc++.h>
using namespace std;
const int NR = 500;
int a[NR][NR];
bool b[NR][NR];
bool f[NR];
int n, m, k, ans = 1e9;
void dfs(int p, int st, int mx)
{
    if(p == n)
    {
        if(st % k == 0) ans = min(st + ((mx - 1) / k + 1) * k, ans);

        return ;
    }
    for(int i = 1; i <= n; i++)
    {
        if(b[p][i] && !f[i])
        {
            f[i] = true;
            dfs(i, st + 1, max(mx, a[p][i] - st));
            f[i] = false;
        }
    }
}
int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    bool f1 = true;
    cin >> n >> m >> k;
    if(n > 10 || m > 15)
    {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[x][y] = z;
        b[x][y] = true;
        f1 |= (z == 0);
    }
    dfs(1, 0, 0);
    if(ans == 1e9) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
