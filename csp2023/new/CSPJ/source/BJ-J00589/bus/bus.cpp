#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, m, k;
short a[20000][2] = {0};
int dfs(int pls, int c)
{
    int cnt = INT_MAX;
    if (pls == n)
    {
        return 1;
    }
    for (int i = 0; i < m; i++)
    {
        if (a[i][0] == pls)
        {
            int cnt1 = dfs(a[i][1], c + 1);
            if ((cnt1 + c) % k == 0)
            {
                cnt = cnt < cnt1 ? cnt : cnt1;
            }
        }
    }
    cnt++;
    return cnt;
}
signed main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 20000; i++)
    {
        a[i][0] = a[i][1] = -1;
    }
    cin >> n >> m >> k;
    int k1;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i][0] >> a[i][1] >> k1;
    }
    int ans = dfs(1, 0);
    if (ans == INT_MAX + 1ll)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << --ans << endl;
    }
    return 0;
}