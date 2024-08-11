#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10;

struct point
{
    int id, need;
    bool operator < (const point a) const
    {
        return need < a.need;
    }
} t;

int n, u, v, ans;
int a[maxn], b[maxn], c[maxn], ti[maxn];
vector <int> e[maxn];
priority_queue <point> q;

signed main ()
{
    freopen ("tree.in", "r", stdin);
    freopen ("tree.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1; i < n; i ++)
    {
        cin >> u >> v;
        e[u].push_back (v);
        e[v].push_back (u);
    }
    q.push ((point){1, ceil(a[1] * 1.0 / b[1])});
    for (int i = 0; i < n; i ++)
    {
        t = q.top ();
        ans = max (ans, t.need + i);
        q.pop ();
        for (int j = 0; j < e[t.id].size (); j ++)
        {
            q.push ((point) {e[t.id][j], ceil(a[i] * 1.0 / b[i])});
        }
    }
    cout << ans;
    return 0;
}
