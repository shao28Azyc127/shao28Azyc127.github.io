#include <bits/stdc++.h>
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define lob lower_bound
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 3000 + 10;
inline int read ()
{
    int x = 0, f = 1;
    char c = getchar ();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar (); }
    return x * f;
}
int n, m;
int mn[N], mx[N];
int ans[N];
signed main ()
{
    freopen ("dict.in", "r", stdin);
    freopen ("dict.out", "w", stdout);
    n = read (); m = read ();
    memset (mn, 0x3f, sizeof (mn));
    for (int i = 1; i <= n; i++, getchar ()) for (int j = 1; j <= m; j++)
    {
        char c = getchar ();
        mn[i] = min (mn[i], c - 'a');
        mx[i] = max (mx[i], c - 'a');
        ans[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) continue;
            if (mx[j] <= mn[i]) ans[i] = 0;
        }
    }
    for (int i = 1; i <= n; i++) printf ("%d", ans[i]); puts("");
    return 0;
}