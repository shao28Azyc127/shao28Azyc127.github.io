#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int NR = 1e5 + 5;

int n;
long long d;
long long ans = 1e9;
long long v[NR];
long long w[NR];
long long s[NR];//shen yu de lu cheng he
long long mn[NR];

void dfs(int x, long long money, long long dis)
{
    if (dis < 0)
        return;
    //cout << x << ' ' << money << ' ' << dis << '\n';
    if (x == n || dis >= s[x])
    {
        ans = min(ans, money);
        return;
    }

    if (money + (s[x] - dis) * mn[x] / d >= ans)
        return;

    for (int i = max((v[x] - dis) / d, 0ll);i * d - d < s[x] - dis;i ++)
        dfs(x + 1, money + w[x] * i, dis + d * i - v[x]);
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin >> n >> d;
    for (int i = 1;i < n;i ++)
        cin >> v[i];
    for (int i = 1;i <= n;i ++)
        cin >> w[i];
    for (int i = n - 1;i >= 1;i --)
        s[i] = s[i + 1] + v[i];
    mn[n] = w[n];
    for (int i = n - 1;i >= 1;i --)
        mn[i] = min(mn[i + 1], w[i]);

    if (mn[1] == w[1])
    {
        if (s[1] % d == 0)
            cout << s[1] / d * w[1];
        else
            cout << (s[1] / d + 1) * w[1];
        return 0;
    }
    dfs(1, 0, 0);

    cout << ans;
    return 0;
}
