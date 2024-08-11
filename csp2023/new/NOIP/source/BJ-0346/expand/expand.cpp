#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

int c, n, m, q;

namespace solve1
{
    constexpr int N = 2e3 + 10;
    int x[N], y[N];
    int dp[N][N];
    int px[N], vx[N], py[N], vy[N];

    int calc()
    {
        int f = (x[1] - y[1] < 0 ? -1 : 1);
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if ((x[i] - y[j]) * f > 0)
                    dp[i][j] = (dp[i - 1][j] | dp[i][j - 1] | dp[i - 1][j - 1]);
                else
                    dp[i][j] = 0;
        return dp[n][m];
    }

    void main()
    {
        for (int i = 1; i <= n; i++)
            cin >> x[i];
        for (int i = 1; i <= n; i++)
            cin >> y[i];
        cout << calc();
        for (int i = 1; i <= q; i++)
        {
            int kx, ky;
            cin >> kx >> ky;
            for (int j = 1; j <= kx; j++)
                cin >> px[j] >> vx[j], swap(x[px[j]], vx[j]);
            for (int j = 1; j <= ky; j++)
                cin >> py[j] >> vy[j], swap(y[py[j]], vy[j]);
            cout << calc();
            for (int j = 1; j <= kx; j++)
                swap(x[px[j]], vx[j]);
            for (int j = 1; j <= ky; j++)
                swap(y[py[j]], vy[j]);
        }
        cout << endl;
    }
}

signed main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    cin >> c >> n >> m >> q;
    solve1::main();
}
