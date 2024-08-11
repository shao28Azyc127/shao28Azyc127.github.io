#include <bits/stdc++.h>
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define lob lower_bound
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 1e5 + 10;
inline int read ()
{
    int x = 0, f = 1;
    char c = getchar ();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar (); }
    return x * f;
}
int n, m, test;
int t[N];
struct q {
    char c;
    int x, y;
} q[N];
// struct Se {
//     int fa[N];
//     void init () { for (int i = 1; i <= n; i++) fa[i] = i; }
//     int find (int x) { return x == fa[x] ? x : fa[x] = find (fa[x]); }
// }S;
int a[N], b[N];
int ans = 0;
void dfs (int x)
{
    if (x == n + 1)
    {
        for (int i = 1; i <= n; i++) b[i] = a[i];
        for (int i = 1; i <= m; i++)
        {
            if (q[i].c == 'T') b[q[i].x] = 0;
            if (q[i].c == 'F') b[q[i].x] = 1;
            if (q[i].c == 'U') b[q[i].x] = 2;
            if (q[i].c == '+') b[q[i].x] = b[q[i].y];
            if (q[i].c == '-')
            {
                if (b[q[i].y] == 2) b[q[i].x] = 2;
                else b[q[i].x] = (b[q[i].y] ^ 1);
            }
        }
        for (int i = 1; i <= n; i++) if (a[i] != b[i]) return ;
        int cnt = 0;
        for (int i = 1; i <= n; i++) cnt += (a[i] == 2);
        ans = min (ans, cnt);
        return ;
    }
    a[x] = 0;
    dfs (x + 1);
    a[x] = 1;
    dfs (x + 1);
    a[x] = 2;
    dfs (x + 1);
}
void solve ()
{
    memset (t, 0, sizeof (t));
    n = read (), m = read ();
    for (int i = 1; i <= m; i++)
    {
        q[i].c = getchar ();
        if (q[i].c == 'T' || q[i].c == 'F' || q[i].c == 'U') q[i].x = read ();
        else q[i].x = read (), q[i].y = read ();
    }
    if (test <= 2)
    {
        ans = 0x3f3f3f3f;
        dfs (1);
        printf ("%d\n", ans);
    }
    else if (3 <= test && test <= 4)
    {
        for (int i = 1; i <= m; i++)
        {
            if (q[i].c == 'T') t[q[i].x] = 1;
            if (q[i].c == 'F') t[q[i].x] = 2;
            if (q[i].c == 'U') t[q[i].x] = 3;
        }ans=0;
        for (int i = 1; i <= n; i++) ans += (t[i] == 3);
        printf ("%d\n", ans);
    }
    else if (5 <= test && test <= 6)
    {
        for (int i = 1; i <= m; i++)
        {
            if (q[i].c == 'U') t[q[i].x] = 1;
            else t[q[i].x] = t[q[i].y];
        }ans=0;
        for (int i = 1; i <= n; i++) ans += (t[i] == 1);
        printf ("%d\n", ans);
    }
}
signed main ()
{
    freopen ("tribool.in", "r", stdin);
    freopen ("tribool.out", "w", stdout);
    test = read (); int t = read ();
    while (t--) solve ();
    return 0;
}