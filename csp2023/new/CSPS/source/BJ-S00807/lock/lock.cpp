#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair <int, int> pii;
inline int read ()
{
    int x = 0, f = 1;
    char c = getchar ();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar (); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar (); }
    return x * f;
}
int n, ans;
int a[10][10];
map <int, int> mp;
signed main ()
{
    freopen ("lock.in", "r", stdin);
    freopen ("lock.out", "w", stdout);
    n = read ();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 5; j++)
            a[i][j] = read ();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            int s = a[i][j];
            for (int k = 0; k <= 9; k++)
            {
                if (s == k) continue;
                a[i][j] = k;
                int sum = 0;
                for (int l = 1; l <= 5; l++) sum = sum * 10 + a[i][l];
                mp[sum]++;
            }
            a[i][j] = s;
        }
        for (int j = 1; j <= 4; j++)
        {
            int s = a[i][j], s2 = a[i][j + 1];
            for (int k = 1; k <= 9; k++)
            {
                a[i][j] = (s + k) % 10;
                a[i][j + 1] = (s2 + k) % 10;
                int sum = 0;
                for (int l = 1; l <= 5; l++) sum = sum * 10 + a[i][l];
                mp[sum]++;
            }
            a[i][j] = s; a[i][j + 1] = s2;
        }
    }
    for (auto v : mp)
        if (v.second == n) ans++;
    printf ("%lld\n", ans);
    return 0;
}