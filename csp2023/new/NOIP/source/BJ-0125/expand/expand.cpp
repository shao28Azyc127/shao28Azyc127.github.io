#include <bits/stdc++.h>
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define lob lower_bound
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 5e5 + 10;
const int inf = 0x3f3f3f3f;
inline int read ()
{
    int x = 0, f = 1;
    char c = getchar ();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar (); }
    return x * f;
}
int n, m, Q, test;
int a[N], b[N];
int a2[N], b2[N];
int ls[N << 1], len;
struct query {
    int x, y;
    vector <pii> vec[2];
} q[100];
inline int find (int x) { return lob (ls + 1, ls + len + 1, x) - ls; }
void solve ()
{
    if (test == 1)
    {
        if (a[1] == b[1]) printf ("0");
        else printf ("1");
        return ;
    }
    if (test == 2)
    {
        if (a[1] > b[1] && a[n] < b[m]) { printf ("0"); return ; }
        else printf ("1");
        return ;
    }
    if (8 <= test && test <= 14)
    {
        int mx = 0;
        for (int i = 1; i <= n; i++) mx = max (mx, a[i]);
        if (mx >= b[m]) { printf ("0"); return ; }
        int p = 1;
        for (int i = 1; i <= m; i++)
        {
            while (a[p] >= b[i] && p <= n) p++;
            if (p > n) { printf ("0"); return ; }
        }
        printf ("1");
        return ;
    }
    if (a[1] == b[1] || a[n] == b[m]) { printf ("0"); return ; }
    if (a[1] > b[1] && a[n] < b[m]) { printf ("0"); return ; }
    bool flag = true;
    if (a[1] < b[1])
    {
        if (n <= m)
        {
            int now = 1, mn = inf;
            for (int i = 1; i <= m; i++)
            {
                while (now <= n && now <= i) { mn = min (a[now], mn); now++; }
                if (b[i] <= mn) { flag = false; break; }
            }
        }
        else
        {
            int now = 1, mx = 0;
            for (int i = 1; i <= n; i++)
            {
                while (now <= m && now <= i) { mx = max (b[now], mx); now++; }
                if (a[i] >= mx) { flag = false; break; }
            }
        }
    }
    else
    {
        if (n <= m)
        {
            int now = 1, mx = 0;
            for (int i = 1; i <= m; i++)
            {
                while (now <= n && now <= i) { mx = max (a[now], mx); now++; }
                if (b[i] >= mx) { flag = false; break; }
            }
        }
        else
        {
            int now = 1, mn = inf;
            for (int i = 1; i <= n; i++)
            {
                while (now <= m && now <= i) { mn = min (b[now], mn); now++; }
                if (a[i] <= mn) { flag = false; break; }
            }
        }
    }
    printf ("%d", flag);
}
signed main ()
{
    freopen ("expand.in", "r", stdin);
    freopen ("expand.out", "w", stdout);
    test = read (); n = read (), m = read (); Q = read ();
    for (int i = 1; i <= n; i++) a[i] = read (), ls[++len] = a[i];
    for (int i = 1; i <= m; i++) b[i] = read (), ls[++len] = b[i];
    for (int i = 1; i <= Q; i++)
    {
        q[i].x = read (), q[i].y = read ();
        for (int j = 1; j <= q[i].x; j++)
        {
            int k = read (), v = read ();
            q[i].vec[0].pb (mk(k, v));
            ls[++len] = v;
        }
        for (int j = 1; j <= q[i].y; j++)
        {
            int k = read (), v = read ();
            q[i].vec[1].pb (mk(k, v));
            ls[++len] = v;
        }
    }
    sort (ls + 1, ls + len + 1);
    len = unique (ls + 1, ls + len + 1) - ls - 1;
    for (int i = 1; i <= n; i++) a[i] = find (a[i]);
    for (int i = 1; i <= m; i++) b[i] = find (b[i]);
    solve ();
    for (int iq = 1; iq <= Q; iq++)
    {
        for (int i = 1; i <= n; i++) a2[i] = a[i];
        for (int i = 1; i <= m; i++) b2[i] = b[i];
        for (auto i : q[iq].vec[0]) a[i.fi] = find(i.se);
        for (auto i : q[iq].vec[1]) b[i.fi] = find(i.se);
        solve ();
        for (int i = 1; i <= n; i++) a[i] = a2[i];
        for (int i = 1; i <= m; i++) b[i] = b2[i];
    }
    return 0;
}
/*
708 689 658 719 631 678 
687 694 610 714 701 641 
*/