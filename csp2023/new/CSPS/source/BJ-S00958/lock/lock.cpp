#include <bits/stdc++.h>
using namespace std;
int n, v[10][6];
int work(int x, int y)
{
    if (x < y) return y - x;
    else return y + 10 - x;
}
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 5; j++)
            scanf("%d", &v[i][j]);
    int ans = 0;
    for (int a = 0; a <= 9; a++)
    {
        for (int b = 0; b <= 9; b++)
        {
            for (int c = 0; c <= 9; c++)
            {
                for (int d = 0; d <= 9; d++)
                {
                    for (int e = 0; e <= 9; e++)
                    {
                        bool vis = 1;
                        for (int i = 1; i <= n; i++)
                        {
                            if (a == v[i][1] && b == v[i][2] && c == v[i][3] && d == v[i][4] && e == v[i][5])
                            {
                                vis = 0;
                                break;
                            }
                            int x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0;
                            if (v[i][1] != a) x1 = 1;
                            if (v[i][2] != b) x2 = 1;
                            if (v[i][3] != c) x3 = 1;
                            if (v[i][4] != d) x4 = 1;
                            if (v[i][5] != e) x5 = 1;
                            if (x1 + x2 + x3 + x4 + x5 > 2)
                            {
                                vis = 0;
                                break;
                            }
                            if (x1 + x3 == 2 || x1 + x4 == 2 || x1 + x5 == 2 || x2 + x4 == 2 || x2 + x5 == 2 || x3 + x5 == 2)
                            {
                                vis = 0;
                                break;
                            }
                            if (x1 + x2 == 2)
                            {
                                bool f = 0;
                                if (work(a, v[i][1]) == work(b, v[i][2])) f = 1;
                                if (work(v[i][1], a) == work(v[i][2], b)) f = 1;
                                if (!f) vis = 0;
                            }
                            if (x2 + x3 == 2)
                            {
                                bool f = 0;
                                if (work(b, v[i][2]) == work(c, v[i][3])) f = 1;
                                if (work(v[i][2], b) == work(v[i][3], c)) f = 1;
                                if (!f) vis = 0;
                            }
                            if (x3 + x4 == 2)
                            {
                                bool f = 0;
                                if (work(c, v[i][3]) == work(d, v[i][4])) f = 1;
                                if (work(v[i][3], c) == work(v[i][4], d)) f = 1;
                                if (!f) vis = 0;
                            }
                            if (x4 + x5 == 2)
                            {
                                bool f = 0;
                                if (work(d, v[i][4]) == work(e, v[i][5])) f = 1;
                                if (work(v[i][4], d) == work(v[i][5], e)) f = 1;
                                if (!f) vis = 0;
                            }
                            if (!vis) break;
                        }
                        if (vis == 1) ans++;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
