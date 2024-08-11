# include "bits/stdc++.h"

using namespace std;
const int maxn = 1e5 + 10;
int C, t, n, m, k, d, ans;
int a[maxn], b[maxn], c[maxn];

int main ()
{
    freopen ("run.in", "r", stdin);
    freopen ("run.out", "w", stdout);
    scanf ("%d%d", &C, &t);
    while (t--)
    {
        ans = 0;
        scanf ("%d%d%d%d", &n, &m, &k, &d);
        for (int i = 1 ; i <= m ; i++)
        {
            scanf ("%d%d%d", a + i, b + i, c + i);
            ans += c[i];
        }
        for (int i = 1 , cnt = 0 ; i <= n ; i++, cnt++)
            if (cnt < k)
                ans -= d;
            else
                cnt = 0;
        printf ("%d\n", ans);
        
    }
    return (0);
}