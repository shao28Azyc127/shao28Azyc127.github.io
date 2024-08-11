#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MAXN = 1e4, MAXM = 2e4;
ll n, m, k, tot = 0;
ll head[MAXN + 5];
struct Edge {
    ll to, st, nxt;
} edge[MAXM + 5];
inline void addEdge(ll u, ll v, ll st) {
    edge[++tot].to = v;
    edge[tot].st = st;
    edge[tot].nxt = head[u];
    head[u] = tot;
}
inline ll lstk(ll x) {
    return ceil(x * 1.0 / k) * k;
}
inline ll calc(ll x, ll y) {
    if (x >= y) return x;
    return lstk(y - x);
}
ll cnt1 = 0, cnt2 = 0;
struct Node {
    ll dis, ft;
    inline bool operator<(const Node &tmp) const {
        bool p1 = (dis % k == 0), p2 = (tmp.dis % k == 0);
        if (p1 == p2) return ft < tmp.ft;
        return p1 > p2;
    }
} a[MAXM + 5], b[MAXM + 5];
void dfs1(ll u, ll dep, ll mit) {
    if (u == n) {
        a[++cnt1].dis = dep;
        a[cnt1].ft = mit;
        return;
    }
    for (ll i = head[u]; i; i = edge[i].nxt) {
        ll v = edge[i].to, st = edge[i].st;
        dfs1(v, dep + 1, calc(dep + 1, st));
    }
}
void dfs2(ll u, ll dep, ll mit) {
    if (u == 1) {
        b[++cnt2].dis = dep;
        b[cnt2].ft = mit;
        return;
    }
    for (ll i = head[u]; i; i = edge[i].nxt) {
        ll v = edge[i].to, st = edge[i].st;
        dfs1(v, dep + 1, calc(dep, st));
    }
}
int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &k);
    while (m--) {
        ll u, v, st;
        scanf("%lld%lld%lld", &u, &v, &st);
        addEdge(u, v, st);
    }
    dfs1(1, 0, 1e18);
    dfs2(n, 0, 1e18);
    for (ll i = 1; i <= cnt1; i++) a[i].ft = lstk(a[i].ft);
    for (ll i = 1; i <= cnt2; i++) b[i].ft = lstk(b[i].ft);
    sort(a + 1, a + cnt1 + 1);
    ll f1 = 1;
    while (f1 <= cnt1 && a[f1].dis % k == 0) f1++;
    if (f1 == 1) {
        printf("-1\n");
        return 0;
    }
    // for (ll i = 1; i <= cnt1; i++) cout << a[i].dis << " " << a[i].ft << endl;
    ll ans = 1e18;
    for (ll i = 1; i < f1; i++) {
        if (a[i].dis % k == 0) ans = min(ans, a[i].dis + a[i].ft);
    }
    printf("%lld\n", ans);
    return 0;
}
