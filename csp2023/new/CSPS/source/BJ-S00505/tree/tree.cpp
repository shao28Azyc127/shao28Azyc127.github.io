#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
const ll MAXN = 1e5;
ll n;
ll a[MAXN + 5], b[MAXN + 5], c[MAXN + 5], qr[MAXN + 5], ma[MAXN + 5];
vector<ll> vec[MAXN + 5];
void dfs(ll u, ll fa, ll dep) {
    ma[u] = qr[u];
    for (vector<ll>::iterator it = vec[u].begin(); it != vec[u].end(); it++) {
        ll v = *it;
        if (v == fa) continue;
        dfs(v, u, dep + 1);
        ma[u] = max(ma[u], ma[v]);
    }
}
struct Node {
    ll id, mat;
    inline bool operator<(const Node &tmp) const {
        return mat > tmp.mat;
    }
};
priority_queue<Node> q;
bool vis[MAXN + 5];
inline ll calc(ll id, ll l, ll r) {
    return (r - l + 1) * b[id] + (l + r) * (r - l + 1) / 2 * c[id];
}
bool check(ll x) {
    for (ll i = 1; i <= n; i++) {
        ll l = 1, r = x, p = x;
        while (l <= r) {
            ll mid = l + r >> 1;
            if (mid < x && calc(i, mid, x) < calc(i, mid + 1, x)) {
                p = mid + 1;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        l = 1, r = p;
        while (l <= r) {
            ll mid = l + r >> 1;
            if (calc(i, mid, x) <= 0) {
                p = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        ll tmp = calc(i, p, x);
        if (tmp <= a[i]) qr[i] = p + a[i] - tmp;
        else {
            l = 1, r = p;
            ll res = -1;
            while (l <= r) {
                ll mid = l + r >> 1;
                if (calc(i, mid, x) >= a[i]) {
                    res = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if (res == -1) return 0;
            qr[i] = res;
        }
    }
    dfs(1, 0, 0);
    q.push({1, ma[1]});
    memset(vis, 0, sizeof(vis));
    ll dt = 0;
    while (!q.empty()) {
        ll u = q.top().id;
        q.pop();
        dt++;
        if (ma[u] < dt) return 0;
        vis[u] = 1;
        ll mi = 1e18, pos;
        for (vector<ll>::iterator it = vec[u].begin(); it != vec[u].end(); it++) {
            ll v = *it;
            if (vis[v]) continue;
            q.push({v, ma[v]});
        }
    }
    return 1;
}
int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
    for (ll i = 1; i < n; i++) {
        ll u, v;
        scanf("%lld%lld", &u, &v);;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    ll l = 1, r = 1e9, ans = -1;
    while (l <= r) {
        ll mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
