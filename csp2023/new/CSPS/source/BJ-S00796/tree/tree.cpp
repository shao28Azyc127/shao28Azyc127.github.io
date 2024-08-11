#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#define maxn 200005
#define mod 998244353
#define ll long long
#define eps 1e-7
using namespace std;
int n;
struct edge {
    int to, nxt;
} e[maxn << 1];
int p[maxn], eid = 0;
void addedge (int u, int v) {
    e[++eid] = (edge){v, p[u]}, p[u] = eid;
    e[++eid] = (edge){u, p[v]}, p[v] = eid;
}
ll a[maxn], b[maxn], c[maxn];
int sub1 = 1, sub2 = 1, sub3 = 1;
int f[maxn], dep[maxn];
void dfs (int u, int fa) {
    for (int i = p[u]; i; i = e[i].nxt) {
        int to = e[i].to;
        if (to == fa) continue;
        dep[to] = dep[u] + 1, f[to] = u;
        dfs (to, u);
    }
}
ll A[maxn], B[maxn], vis[maxn];
vector <int> g[maxn];
int check (int x) {
    for (int i = 1; i <= n; i++) B[i] = min(x+1-A[i], 1ll*n), vis[i] = 0, g[i].clear();
    for (int i = 1; i <= n; i++) g[B[i]].push_back(i);
    int now = 1; vis[1] = 1;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 0) continue;
        int m = g[i].size();
        for (int j = 0; j < m; j++) {
            int u = g[i][j];
            while (!vis[u]) now++, vis[u] = 1, u = f[u];
        }
        if (now > i) return 0;
    }
    return 1;
}
int main () {
    freopen ("tree.in", "r", stdin);
    freopen ("tree.out", "w", stdout);
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf ("%lld %lld %lld", a+i, b+i, c+i);
        if (c[i]) sub1 = 0;
    }
    for (int i = 1, u, v; i < n; i++) {
        scanf ("%d %d", &u, &v);
        addedge (u, v);
        if (u != 1) sub3 = 0;
        if (u != i || v != i+1) sub2 = 0;
    }
    dep[1] = 1, dfs (1, 1);
    if (sub1) {
        ll l = 0, r = 1000000000, ans, mid;
        for (int i = 1; i <= n; i++) A[i] = (a[i] + b[i] - 1) / b[i], l = max (l, A[i]);
        while (l <= r) {
            mid = l + r >> 1;
            if (check (mid)) ans = mid, r = mid-1;
            else l = mid+1;
        }
        printf ("%lld\n", ans);
        return 0;
    }
    if (sub2) {
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ll res;
            if (c[i] >= 0) {
                double R = sqrt((0.5+1.0*b[i]/c[i])*(0.5+1.0*b[i]/c[i]) + 2.0*a[i]/c[i] + 1.0*i*i - 1.0*i + 2.0*(i-1)*b[i]/c[i])
                 - 0.5 - 1.0*b[i]/c[i];
                res = ceil(R);
            } else {
                ll lim = (b[i] - 1) / (-c[i]);
                if (lim < i) res = a[i];
                else {
                    ll sum = (lim-i+1)*b[i] + (i+lim)*(lim-i+1)/2ll*c[i];
                    if (sum <= a[i]) res = lim + (a[i] - sum);
                    else {
                        double R = sqrt((0.5+1.0*b[i]/c[i])*(0.5+1.0*b[i]/c[i]) + 2.0*a[i]/c[i] + 1.0*i*i - 1.0*i + 2.0*(i-1)*b[i]/c[i])
                         - 0.5 - 1.0*b[i]/c[i];
                        res = ceil(R);
                    }
                }
            }
            ans = max (ans, res);
        }
        printf ("%lld\n", ans);
        return 0;
    }
    return 0;
}