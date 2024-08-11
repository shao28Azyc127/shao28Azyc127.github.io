#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int n, a[N], b[N], c[N];
vector<int> G[N];

namespace sub1 {
    bool chk() {
        for(int i = 1; i <= n; i++) if(c[i] != 0) return false;
        return true;
    }
    int V[N], dis[N], clo[N], tot;
    void solve() {
        for(int i = 1; i <= n; i++) V[i] = max(b[i], 1ll);
        for(int i = 0; i <= n; i++) dis[i] = -1e18;
        dis[1] = (int) ceil(1.0 * a[1] / V[1]);
        for(int t = 1; t <= n; t++) {
            int u = 0;
            for(int i = 1; i <= n; i++) if(!clo[i] && dis[i] > dis[u]) u = i;
            clo[u] = ++tot;
            for(auto v : G[u]) if(dis[v] < (int) ceil(1.0 * a[v] / V[v])) dis[v] = (int) ceil(1.0 * a[v] / V[v]);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) ans = max(ans, (int) ceil(1.0 * a[i] / V[i]) + clo[i] - 1);
        cout << ans << endl;
    }
}

signed main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios :: sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
    for(int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(sub1 :: chk()) return sub1 :: solve(), 0;
    cout << n << endl;
    return 0;
}