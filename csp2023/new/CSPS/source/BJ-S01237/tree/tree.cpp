#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n, ans, t, b[maxn], c[maxn];
ll a[maxn];
vector<int> e[maxn];
bool vis[maxn];
priority_queue<pair<int, int> > pq;
int calc(int u, int cur) {
    int res = cur; for (int x = a[u]; x > 0; res++) x -= max(b[u] + (ll)res * c[u], 1ll);
    return res - cur;
}
int main() {
    ios::sync_with_stdio(false);
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v); e[v].push_back(u);
    }
    pq.emplace(calc(1, 1), 1); vis[1] = true;
    while (pq.size()) {
        auto [w, u] = pq.top(); pq.pop();
        ans = max(ans, calc(u, t + 1) + t); ++t;
        for (int v : e[u]) if (!vis[v]) vis[v] = true, pq.emplace(calc(v, t + 1), v);
    }
    cout << ans << '\n';
    return 0;
}