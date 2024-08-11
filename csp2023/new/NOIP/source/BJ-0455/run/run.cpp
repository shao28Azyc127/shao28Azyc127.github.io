#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Ch
{
    long long x, y, v;
}c[100010];

bool cmp(Ch x, Ch y)
{
    if (x.x != y.x) return x.x < y.x;
    return x.y < y.y;
}

long long f[1010][100010];

int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    int C, T;
    cin >> C >> T;
    while (T--)
    {
        int n, m, k, d;
        cin >> n >> m >> k >> d;
        for (int i = 1; i <= m; i++)
        {
            cin >> c[i].x >> c[i].y >> c[i].v;
        }
        sort(c + 1, c + m + 1, cmp);
        for (int i = 2; i <= m; i++)
        {
            if (c[i].x == c[i - 1].x)
            {
                c[i].v += c[i - 1].v;
            }
        }
        int cur = 1;
        memset(f, -0x3f3f, sizeof(f));
        f[0][0] = 0;
        for (int t = 1; t <= 1000; t++)
        {
            if (t > c[cur].x) cur++;
            for (int j = 0; j <= k; j++)
            {
                f[t][0] = max(f[t][0], f[t - 1][j]);
            }
            for (int j = 1; j <= k; j++)
            {
                if (t == c[cur].x && c[cur + 1].x == c[cur].x && j > c[cur + 1].y) cur++;
                if (t == c[cur].x && j > c[cur].y) f[t][j] = f[t - 1][j - 1] + c[cur].v - d;
                else f[t][j] = f[t - 1][j - 1] - d;
            }
        }
        long long ans = 0;
        for (int i = 0; i <= k; i++)
        {
            ans = max(ans, f[1000][i]);
        }
        cout << ans << endl;
    }
    return 0;
}

