#include<bits/stdc++.h>
using namespace std;

const int N = 10;
int q[N][7];

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
            scanf("%d", &q[i][j]);
    }
    int a[6] = {0, 0, 0, 0, 0, 0};
    int ans = 0;
    while (true)
    {
        bool ok = true;
        for (int i = 1; i <= n; i++)
        {
            int cnt = 0, rq = 0, ls = 0;
            for (int j = 1; j <= 5; j++)
            {
                if (a[j] != q[i][j])
                {
                    cnt++;
                    if (cnt > 2)
                    {
                        ok = false;
                        break;
                    }
                    if (cnt == 2 && ((a[j] - q[i][j] + 10) % 10 != rq || j != ls + 1))
                    {
                        ok = false;
                        break;
                    }
                    rq = (a[j] - q[i][j] + 10) % 10;
                    ls = j;
                }
            }
            if (cnt == 0) ok = false;
        }
        if (ok) ans++;
        for (int i = 5; i >= 0; i--)
            if (a[i] < 9)
            {
                a[i]++;
                break;
            }
            else a[i] = 0;
        if (a[0] == 1) break;
    }
    printf("%d\n", ans);
    return 0;
}
