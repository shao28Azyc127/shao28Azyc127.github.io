#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 5, M = 1e6 + 5;
int n, m, k, f[N], l = M, r = -1, ans = M;
vector<pair<int, int>> g[N];
int dfs(int x, int s) {
    // cout<<"vis point "<<x<<" at "<<s<<endl;
    if(x == n && s % k == 0) {
        ans = min(ans, s);
        return 1;
    }
    f[x] = 1;
    for(auto i : g[x]) {
        if(i.second <= s && !f[i.first])
            if(dfs(i.first, s + 1)) return 1;
    }
    f[x] = 0;
    return 0;
}
signed main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin>>u>>v>>w;
        g[u].push_back({v, w});
        l = min(l, w);
        r = max(r, w);
    }
    l = ceil(l * 1.0 / k) * k;
    r = ceil(r * 1.0 / k) * k;
    for(int i = l; i <= r; i += k) dfs(1, i);
    if(ans == M) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}